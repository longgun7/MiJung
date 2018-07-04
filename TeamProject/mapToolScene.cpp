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
	setImageInit();
	setup();
	
	_tileSetName = _tileName = "town";
	load();

	_zoom = 1.0f;
	_isShowMoveTile = false;

	return S_OK;
}

void mapToolScene::release(void)
{
}

void mapToolScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("스타트씬");

	keyInput();
	if (_isLButtonDown && !_isShowMoveTile) setMap();

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
			IMAGEMANAGER->frameRender(_tileName, getMemDC(),
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
		// 타일셋 버튼
		_townButtonImg->render(CAMERA->getCameraDC());
		_InHouseButtonImg->render(CAMERA->getCameraDC());
		_field1ButtonImg->render(CAMERA->getCameraDC());
		_field2ButtonImg->render(CAMERA->getCameraDC());
		_field3ButtonImg->render(CAMERA->getCameraDC());
		_saveButtonImg->render(CAMERA->getCameraDC());

		IMAGEMANAGER->findImage("타일셋배경")->render(CAMERA->getCameraDC(), 0, WINSIZEY - 336);
		// 타일셋 그림
		_sampleImg->render(CAMERA->getCameraDC(), 6, WINSIZEY - _sampleImg->getHeight() - 5);

		// 선택한 타일셋이 무언인지 알려주는 사각형, 선으로 표시, 안쪽 색은 투명색
		for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
		{
			IMAGEMANAGER->findImage("선택한타일")->render(CAMERA->getCameraDC(), _viCurrentTile->x * TILESIZE + 6, _viCurrentTile->y * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5);
		}
	}

	// 타일 움직일수 있는지 여부 렌더
	if (_isShowMoveTile)
	{
		//Rectangle(CAMERA->getCameraDC(), drawRc.left, drawRc.top, drawRc.right, drawRc.bottom);
		for (int ii = 0; ii < SAMPLETILEY; ++ii)
		{
			for (int jj = 0; jj < SAMPLETILEX; ++jj)
			{
				int frameX;
				if (_sampleTile[ii * SAMPLETILEX + jj].terrain == TR_MOVE) frameX = 0;
				else if (_sampleTile[ii * SAMPLETILEX + jj].terrain == TR_UNMOVE) frameX = 1;

				IMAGEMANAGER->findImage("타일움직임OX")->frameRender(CAMERA->getCameraDC(), _sampleTile[ii * SAMPLETILEX + jj].rcTile.left, _sampleTile[ii * SAMPLETILEX + jj].rcTile.top,
					frameX, 0);
			}
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

void mapToolScene::setImageInit()
{
	//IMAGEMANAGER->addImage("타일셋배경", "image/maptool/tileSetbackground2.bmp", 1000, 336, true, RGB(255, 0, 255));	
	IMAGEMANAGER->addFrameImage("타일셋배경", "image/maptool/tileSetbackground3.bmp", 1000, 1750, 1, 5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("field1Tile", "image/maptool/field1.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field2Tile", "image/maptool/field2.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field3Tile", "image/maptool/field3.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("InHouse", "image/maptool/inHouse.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	_sampleImg = IMAGEMANAGER->addFrameImage("town", "image/maptool/town.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("선택한타일", "image/maptool/selectTile.bmp", 25, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("타일움직임OX", "image/maptool/ox.bmp", 50, 25, 2, 1, true, RGB(255, 0, 255));

	_townButtonImg = IMAGEMANAGER->addImage("타운버튼", "image/maptool/Buttontown.bmp", 0, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));
	_InHouseButtonImg = IMAGEMANAGER->addImage("실내버튼", "image/maptool/ButtoninHouse.bmp", 120, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field1ButtonImg = IMAGEMANAGER->addImage("필드1버튼", "image/maptool/Buttonfield1.bmp", 240, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field2ButtonImg = IMAGEMANAGER->addImage("필드2버튼", "image/maptool/Buttonfield2.bmp", 360, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field3ButtonImg = IMAGEMANAGER->addImage("필드3버튼", "image/maptool/Buttonfield3.bmp", 480, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_saveButtonImg = IMAGEMANAGER->addImage("SAVE버튼", "image/maptool/Buttonsave.bmp", WINSIZEX - 55, WINSIZEY - _sampleImg->getHeight() - 50, 55, 45, true, RGB(255, 0, 255));;

	IMAGEMANAGER->addImage("미니맵", 3750, 3750);

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

			_tiles[i * TILEX + j].terrainFrameX = 1;
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
			_sampleTile[i * SAMPLETILEX + j].objFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].objFrameY = i;
			_sampleTile[i * SAMPLETILEX + j].terrain = terrainSelect(j, i);// _sampleTile[i].terrainFrameX, _tiles[i].terrainFrameY);
			_sampleTile[i * SAMPLETILEX + j].obj = OBJ_NONE;

			//렉트 셋팅 함수 SetRect
			//렉트 메모리 번지, left, top, right, bottom
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				j * TILESIZE + 6,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5,
				j * TILESIZE + TILESIZE + 6,
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

void mapToolScene::setMoveTile()
{
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
	{
		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			(_sampleTile[i].terrain == TR_MOVE) ? _sampleTile[i].terrain = TR_UNMOVE : _sampleTile[i].terrain = TR_MOVE;
			return;
		}
	}
}

void mapToolScene::keyInput()
{
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
		_zoom -= 0.5f;	if (_zoom < 0.5f) _zoom = 0.5f;

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
		buttonClick();
		_isLButtonDown = true;
		if (!_isLButtonFirstDown) { _ptFirstClick = _ptBGMouse; _isLButtonFirstDown = true; }
		if (_isShowMoveTile) setMoveTile();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_isLButtonDown = _isLButtonFirstDown = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (!_isShowTileSet) { _vCurrentTile.clear(); _isShowTileSet = true; }
		else _isShowTileSet = _isShowMoveTile = false;
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		(_isShowMoveTile) ? _isShowMoveTile = false : _isShowMoveTile = true;
	}

}

void mapToolScene::buttonClick()
{
	if (PtInRect(&_townButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "town";
		IMAGEMANAGER->findImage("타일셋배경")->setFrameY(0);
		load();
	}
	if (PtInRect(&_InHouseButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "InHouse";
		IMAGEMANAGER->findImage("타일셋배경")->setFrameY(1);
		load();
	}
	if (PtInRect(&_field1ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field1Tile";
		IMAGEMANAGER->findImage("타일셋배경")->setFrameY(2);
		load();
	}
	if (PtInRect(&_field2ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field2Tile";
		IMAGEMANAGER->findImage("타일셋배경")->setFrameY(3);
		load();
	}
	if (PtInRect(&_field3ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field3Tile";
		IMAGEMANAGER->findImage("타일셋배경")->setFrameY(4);
		load();
	}

	if (PtInRect(&_saveButtonImg->boundingBox(), _ptMouse))
	{
		save();
	}

	_tileName = _tileSetName;
	_sampleImg = IMAGEMANAGER->findImage(_tileSetName);
}

void mapToolScene::save()
{
	HANDLE file;
	DWORD save;

	string str = _tileSetName + ".map";
	file = CreateFile((char*)str.c_str(), GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &save, NULL);

	CloseHandle(file);
}

void mapToolScene::load()
{
	HANDLE file;
	DWORD load;

	string str = _tileSetName + ".map";
	file = CreateFile((char*)str.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);
}

TERRAIN mapToolScene::terrainSelect(int frameX, int frameY)
{
	for (int i = 0; i < 5; ++i)
	{
		if (frameX == i && frameY == 0)
		{
			return TR_MOVE;
		}
	}
	return TR_UNMOVE;
}

OBJECT mapToolScene::objSelect(int frameX, int frameY)
{
	return OBJ_NONE;
}
