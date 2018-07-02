#include "stdafx.h"
#include "mapToolScene.h"


mapToolScene::mapToolScene()
{
}

mapToolScene::~mapToolScene()
{
}

HRESULT mapToolScene::init(void)
{
	IMAGEMANAGER->addImage("타일셋배경", "image/maptool/tileSetbackground2.bmp", 1000, 336, true, RGB(255, 0, 255));
	_sampleImg = IMAGEMANAGER->addFrameImage("mapTiles", "image/maptool/town2.bmp", 1000, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택한타일", "image/maptool/selectTile.bmp", 25, 25, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("미니맵", 3750, 3750);

	setup();
	_zoom = 1.0f;

	return S_OK;
}

void mapToolScene::release(void)
{
}

void mapToolScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("스타트씬");

	// 줌인
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_zoom += 1.0f;	if (_zoom > 9.0f) _zoom = 9.0f;

		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				SetRect(&_tiles[i * TILEX + j].rc,
					j * TILESIZE * _zoom,
					i * TILESIZE * _zoom,
					j * TILESIZE * _zoom + TILESIZE * _zoom,
					i * TILESIZE * _zoom + TILESIZE * _zoom);
			}
		}
	}
	// 줌아웃
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_zoom -= 1.0f;	if (_zoom < 1) _zoom = 1;

		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				SetRect(&_tiles[i * TILEX + j].rc,
					j * TILESIZE * _zoom,
					i * TILESIZE * _zoom,
					j * TILESIZE * _zoom + TILESIZE * _zoom,
					i * TILESIZE * _zoom + TILESIZE * _zoom);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_isLButtonDown = true;
		if (!_isLButtonFirstDown) { _ptFirstClick = _ptBGMouse; _isLButtonFirstDown = true; }
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) _isLButtonDown = _isLButtonFirstDown = false;
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (!_isShowTileSet) { _vCurrentTile.clear(); _isShowTileSet = true; }
		else _isShowTileSet = false;
	}

	if (_isLButtonDown) setMap();

	// 카메라 좌표 설정
	if (!_isShowTileSet) CAMERA->setPosition(_ptMouse.x, _ptMouse.y);
	setShowTileIndex();
}

void mapToolScene::render(void)
{
	for (int i = startIdY; i < endIdY; ++i)
	{
		for (int j = startIdX; j < endIdX; ++j)
		{
			IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY,
				_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left,
				_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top);

		}
	}

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = startIdY; i < endIdY; ++i)
		{
			for (int j = startIdX; j < endIdX; ++j)
			{
				SetTextColor(getMemDC(), RGB(0, 200, 200));
				SetBkMode(getMemDC(), TRANSPARENT);
				char str[128];
				sprintf_s(str, "%d", i * TILEX + j);
				TextOut(getMemDC(), _tiles[i * TILEX + j].rc.left + (_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left) / 2 - 10
					, _tiles[i * TILEX + j].rc.top + (_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top) / 2 - 10
					, str, strlen(str));
			}
		}
	}

	// 타일셋 	
	if (_isShowTileSet)
	{
		IMAGEMANAGER->findImage("타일셋배경")->render(CAMERA->getCameraDC(), 0, WINSIZEY - 336);
		// 타일셋 그림
		_sampleImg->render(CAMERA->getCameraDC(), 10, WINSIZEY - _sampleImg->getHeight() - 5);

		// 선택한 타일셋이 무언인지 알려주는 사각형, 선으로 표시, 안쪽 색은 투명색
		/*HPEN pen = CreatePen(PS_DOT, 3, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(CAMERA->getCameraDC(), pen);
		SelectObject(CAMERA->getCameraDC(), GetStockObject(NULL_BRUSH));

		RECT crc = RectMake(_currentTile.x * TILESIZE, _currentTile.y * TILESIZE + WINSIZEY - _sampleImg->getHeight(), TILESIZE * 2, TILESIZE);
		Rectangle(CAMERA->getCameraDC(), crc.left, crc.top, crc.right, crc.bottom);

		SelectObject(getMemDC(), oldpen);
		DeleteObject(pen);*/
		for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
		{
			IMAGEMANAGER->findImage("선택한타일")->render(CAMERA->getCameraDC(), _viCurrentTile->x * TILESIZE + 10, _viCurrentTile->y * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5);
		}
	}

	// 미니맵 기능(작동되면 즉시 엄청 느려짐)
	if (KEYMANAGER->isToggleKey('M'))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				IMAGEMANAGER->frameRender("mapTiles", getMemDC(),
					_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
					_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY,
					_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left,
					_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top);
			}
		}

		getBackBuffer()->render(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY);
	}

}

void mapToolScene::setup()
{
	// 타일 기본 셋팅
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tiles[i * TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);

			_tiles[i * TILEX + j].terrainFrameX = 2;
			_tiles[i * TILEX + j].terrainFrameY = 0;
			_tiles[i * TILEX + j].objFrameX = 0;
			_tiles[i * TILEX + j].objFrameY = 0;
			_tiles[i * TILEX + j].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
			_tiles[i * TILEX + j].obj = OBJ_NONE;
		}
	}

	//타일셋 (샘플타일)
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			//렉트 셋팅 함수 SetRect
			//렉트 메모리 번지, left, top, right, bottom
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				j * TILESIZE + 10,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5,
				j * TILESIZE + TILESIZE + 10,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() + TILESIZE - 5);
		}
	}

}

// 보여질 타일 인덱스 번호 설정
void mapToolScene::setShowTileIndex()
{
	POINT camera = CAMERA->getPosition();
	startIdX = (camera.x / (TILESIZE*_zoom) > 0) ? camera.x / (TILESIZE * _zoom) - 1 : 0;
	endIdX = (camera.x / (TILESIZE*_zoom) + SHOWTILEX >= TILEX) ? TILEX : camera.x / (TILESIZE * _zoom) + SHOWTILEX + 1;
	startIdY = (camera.y / (TILESIZE*_zoom) > 0) ? camera.y / (TILESIZE * _zoom) - 1 : 0;
	endIdY = (camera.y / (TILESIZE*_zoom) + SHOWTILEY >= TILEY) ? TILEY : camera.y / (TILESIZE * _zoom) + SHOWTILEY + 1;

}


vector<tagCurrentTile> mapToolScene::sortVCurrentTile()
{
	// 퀵소트
	qsort(&_vCurrentTile[0], _vCurrentTile.size(), sizeof(_vCurrentTile[0]),
		[](const void *a, const void *b)->int {	// 람다식 사용(람다는 연산 속도가 10배정도 빠르다. 자주쓰면 좋다.)

												// 타일 인덱스 번호로 비교하여 정렬
		int num1 = ((tagCurrentTile *)(a))->y * TILEX + ((tagCurrentTile *)(a))->x;    // void 포인터를 tagCurrentTile 포인터로 변환한 뒤 역참조하여 값을 가져옴
		int num2 = ((tagCurrentTile *)(b))->y * TILEX + ((tagCurrentTile *)(b))->x;    // void 포인터를 tagCurrentTile 포인터로 변환한 뒤 역참조하여 값을 가져옴

		if (num1 < num2)  return -1;  // a가 b보다 작을 때는 -1 반환
		if (num1 > num2)  return 1;   // a가 b보다 클 때는 1 반환
		return 0;    // a와 b가 같을 때는 0 반환	
	});

	return _vCurrentTile;
}

void mapToolScene::setMap()
{
	// 타일셋을 선택했을때 선택한 타일이 어떤 것인지 세팅, 타일셋 선택중일땐 맵에 그릴 수 없다.
	if (_isShowTileSet)
	{
		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
			{
				tagCurrentTile currentTile;
				currentTile.x = _sampleTile[i].terrainFrameX;
				currentTile.y = _sampleTile[i].terrainFrameY;

				// 이미 선택했던 타일이면, 선택한 타일 벡터에 넣지 않는다.
				for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
				{
					if (_viCurrentTile->x == currentTile.x && _viCurrentTile->y == currentTile.y) return;
				}

				_vCurrentTile.push_back(currentTile);
			}
		}

		return;
	}
	// 선택한 타일이 하나도 없다면 setMap() 종료
	if (_vCurrentTile.size() <= 0) return;

	// 현재 선택한 타일 정렬
	sortVCurrentTile();

	// 타일 2개 이상 선택했을때, 여러개 선택된 타일 그리기
	for (int i = startIdY; i < endIdY; ++i)
	{
		for (int j = startIdX; j < endIdX; ++j)
		{
			if (PtInRect(&_tiles[i * TILEX + j].rc, _ptBGMouse))
			{
				_ptLastClick = _ptBGMouse;
				int countX = 0, countY = 0;
				for (int k = 0; k < _vCurrentTile.size(); ++k)
				{
					if (k > 1 && _vCurrentTile[k].y > _vCurrentTile[k - 1].y)	++countY, countX = 0;

					_tiles[(i + countY) * TILEX + (j + countX)].terrainFrameX = _vCurrentTile[k].x;
					_tiles[(i + countY) * TILEX + (j + countX)].terrainFrameY = _vCurrentTile[k].y;
					_tiles[(i + countY) * TILEX + (j + countX)].terrain = terrainSelect(_vCurrentTile[k].x, _vCurrentTile[k].y);

					++countX;
				}
			}
		}
	}

	// 타일1개만 선택했을때, 사각형 영역으로 타일 그리기
	int rcX, rcY;
	(_ptFirstClick.x < _ptLastClick.x) ? rcX = _ptFirstClick.x : rcX = _ptLastClick.x;
	(_ptFirstClick.y < _ptLastClick.y) ? rcY = _ptFirstClick.y : rcY = _ptLastClick.y;
	RECT rc = RectMake(rcX, rcY, abs(_ptFirstClick.x - _ptLastClick.x), abs(_ptFirstClick.y - _ptLastClick.y));

	for (int i = rc.top / TILESIZE; i <= rc.bottom / TILESIZE; ++i)
	{
		for (int j = rc.left / TILESIZE; j <= rc.right / TILESIZE; ++j)
		{
			if (_vCurrentTile.size() > 1) return;
			_tiles[i * TILEX + j].terrainFrameX = _vCurrentTile[0].x;
			_tiles[i * TILEX + j].terrainFrameY = _vCurrentTile[0].y;
			_tiles[i * TILEX + j].terrain = terrainSelect(_vCurrentTile[0].x, _vCurrentTile[0].y);
		}
	}
}

TERRAIN mapToolScene::terrainSelect(int frameX, int frameY)
{
	if (frameX == 3 && frameY == 0)
	{
		return TR_END;
	}

	return TR_WALL;
}

OBJECT mapToolScene::objSelect(int frameX, int frameY)
{
	return OBJ_NONE;
}
