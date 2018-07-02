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
	IMAGEMANAGER->addImage("Ÿ�ϼ¹��", "image/maptool/tileSetbackground2.bmp", 1000, 336, true, RGB(255, 0, 255));
	_sampleImg = IMAGEMANAGER->addFrameImage("mapTiles", "image/maptool/town2.bmp", 1000, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��", "image/maptool/selectTile.bmp", 25, 25, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�̴ϸ�", 3750, 3750);

	setup();
	_zoom = 1.0f;

	return S_OK;
}

void mapToolScene::release(void)
{
}

void mapToolScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("��ŸƮ��");

	// ����
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
	// �ܾƿ�
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

	// ī�޶� ��ǥ ����
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

	// Ÿ�ϼ� 	
	if (_isShowTileSet)
	{
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->render(CAMERA->getCameraDC(), 0, WINSIZEY - 336);
		// Ÿ�ϼ� �׸�
		_sampleImg->render(CAMERA->getCameraDC(), 10, WINSIZEY - _sampleImg->getHeight() - 5);

		// ������ Ÿ�ϼ��� �������� �˷��ִ� �簢��, ������ ǥ��, ���� ���� �����
		/*HPEN pen = CreatePen(PS_DOT, 3, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(CAMERA->getCameraDC(), pen);
		SelectObject(CAMERA->getCameraDC(), GetStockObject(NULL_BRUSH));

		RECT crc = RectMake(_currentTile.x * TILESIZE, _currentTile.y * TILESIZE + WINSIZEY - _sampleImg->getHeight(), TILESIZE * 2, TILESIZE);
		Rectangle(CAMERA->getCameraDC(), crc.left, crc.top, crc.right, crc.bottom);

		SelectObject(getMemDC(), oldpen);
		DeleteObject(pen);*/
		for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
		{
			IMAGEMANAGER->findImage("������Ÿ��")->render(CAMERA->getCameraDC(), _viCurrentTile->x * TILESIZE + 10, _viCurrentTile->y * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5);
		}
	}

	// �̴ϸ� ���(�۵��Ǹ� ��� ��û ������)
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
	// Ÿ�� �⺻ ����
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

	//Ÿ�ϼ� (����Ÿ��)
	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			//��Ʈ ���� �Լ� SetRect
			//��Ʈ �޸� ����, left, top, right, bottom
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				j * TILESIZE + 10,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5,
				j * TILESIZE + TILESIZE + 10,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() + TILESIZE - 5);
		}
	}

}

// ������ Ÿ�� �ε��� ��ȣ ����
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
	// ����Ʈ
	qsort(&_vCurrentTile[0], _vCurrentTile.size(), sizeof(_vCurrentTile[0]),
		[](const void *a, const void *b)->int {	// ���ٽ� ���(���ٴ� ���� �ӵ��� 10������ ������. ���־��� ����.)

												// Ÿ�� �ε��� ��ȣ�� ���Ͽ� ����
		int num1 = ((tagCurrentTile *)(a))->y * TILEX + ((tagCurrentTile *)(a))->x;    // void �����͸� tagCurrentTile �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
		int num2 = ((tagCurrentTile *)(b))->y * TILEX + ((tagCurrentTile *)(b))->x;    // void �����͸� tagCurrentTile �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

		if (num1 < num2)  return -1;  // a�� b���� ���� ���� -1 ��ȯ
		if (num1 > num2)  return 1;   // a�� b���� Ŭ ���� 1 ��ȯ
		return 0;    // a�� b�� ���� ���� 0 ��ȯ	
	});

	return _vCurrentTile;
}

void mapToolScene::setMap()
{
	// Ÿ�ϼ��� ���������� ������ Ÿ���� � ������ ����, Ÿ�ϼ� �������϶� �ʿ� �׸� �� ����.
	if (_isShowTileSet)
	{
		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
			{
				tagCurrentTile currentTile;
				currentTile.x = _sampleTile[i].terrainFrameX;
				currentTile.y = _sampleTile[i].terrainFrameY;

				// �̹� �����ߴ� Ÿ���̸�, ������ Ÿ�� ���Ϳ� ���� �ʴ´�.
				for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
				{
					if (_viCurrentTile->x == currentTile.x && _viCurrentTile->y == currentTile.y) return;
				}

				_vCurrentTile.push_back(currentTile);
			}
		}

		return;
	}
	// ������ Ÿ���� �ϳ��� ���ٸ� setMap() ����
	if (_vCurrentTile.size() <= 0) return;

	// ���� ������ Ÿ�� ����
	sortVCurrentTile();

	// Ÿ�� 2�� �̻� ����������, ������ ���õ� Ÿ�� �׸���
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

	// Ÿ��1���� ����������, �簢�� �������� Ÿ�� �׸���
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
