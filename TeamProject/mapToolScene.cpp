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
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("��ŸƮ��");

	keyInput();
	if (_isLButtonDown && !_isShowMoveTile) setMap();

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

	// Ÿ�ϼ� 	
	if (_isShowTileSet)
	{
		// Ÿ�ϼ� ��ư
		_townButtonImg->render(CAMERA->getCameraDC());
		_InHouseButtonImg->render(CAMERA->getCameraDC());
		_field1ButtonImg->render(CAMERA->getCameraDC());
		_field2ButtonImg->render(CAMERA->getCameraDC());
		_field3ButtonImg->render(CAMERA->getCameraDC());
		_saveButtonImg->render(CAMERA->getCameraDC());

		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->render(CAMERA->getCameraDC(), 0, WINSIZEY - 336);
		// Ÿ�ϼ� �׸�
		_sampleImg->render(CAMERA->getCameraDC(), 6, WINSIZEY - _sampleImg->getHeight() - 5);

		// ������ Ÿ�ϼ��� �������� �˷��ִ� �簢��, ������ ǥ��, ���� ���� �����
		for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
		{
			IMAGEMANAGER->findImage("������Ÿ��")->render(CAMERA->getCameraDC(), _viCurrentTile->x * TILESIZE + 6, _viCurrentTile->y * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5);
		}
	}

	// Ÿ�� �����ϼ� �ִ��� ���� ����
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

				IMAGEMANAGER->findImage("Ÿ�Ͽ�����OX")->frameRender(CAMERA->getCameraDC(), _sampleTile[ii * SAMPLETILEX + jj].rcTile.left, _sampleTile[ii * SAMPLETILEX + jj].rcTile.top,
					frameX, 0);
			}
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

void mapToolScene::setImageInit()
{
	//IMAGEMANAGER->addImage("Ÿ�ϼ¹��", "image/maptool/tileSetbackground2.bmp", 1000, 336, true, RGB(255, 0, 255));	
	IMAGEMANAGER->addFrameImage("Ÿ�ϼ¹��", "image/maptool/tileSetbackground3.bmp", 1000, 1750, 1, 5, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("field1Tile", "image/maptool/field1.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field2Tile", "image/maptool/field2.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field3Tile", "image/maptool/field3.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("InHouse", "image/maptool/inHouse.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	_sampleImg = IMAGEMANAGER->addFrameImage("town", "image/maptool/town.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("������Ÿ��", "image/maptool/selectTile.bmp", 25, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ�Ͽ�����OX", "image/maptool/ox.bmp", 50, 25, 2, 1, true, RGB(255, 0, 255));

	_townButtonImg = IMAGEMANAGER->addImage("Ÿ���ư", "image/maptool/Buttontown.bmp", 0, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));
	_InHouseButtonImg = IMAGEMANAGER->addImage("�ǳ���ư", "image/maptool/ButtoninHouse.bmp", 120, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field1ButtonImg = IMAGEMANAGER->addImage("�ʵ�1��ư", "image/maptool/Buttonfield1.bmp", 240, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field2ButtonImg = IMAGEMANAGER->addImage("�ʵ�2��ư", "image/maptool/Buttonfield2.bmp", 360, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_field3ButtonImg = IMAGEMANAGER->addImage("�ʵ�3��ư", "image/maptool/Buttonfield3.bmp", 480, WINSIZEY - _sampleImg->getHeight() - 50, 120, 45, true, RGB(255, 0, 255));;
	_saveButtonImg = IMAGEMANAGER->addImage("SAVE��ư", "image/maptool/Buttonsave.bmp", WINSIZEX - 55, WINSIZEY - _sampleImg->getHeight() - 50, 55, 45, true, RGB(255, 0, 255));;

	IMAGEMANAGER->addImage("�̴ϸ�", 3750, 3750);

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

			_tiles[i * TILEX + j].terrainFrameX = 1;
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
			_sampleTile[i * SAMPLETILEX + j].objFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].objFrameY = i;
			_sampleTile[i * SAMPLETILEX + j].terrain = terrainSelect(j, i);// _sampleTile[i].terrainFrameX, _tiles[i].terrainFrameY);
			_sampleTile[i * SAMPLETILEX + j].obj = OBJ_NONE;

			//��Ʈ ���� �Լ� SetRect
			//��Ʈ �޸� ����, left, top, right, bottom
			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				j * TILESIZE + 6,
				i * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5,
				j * TILESIZE + TILESIZE + 6,
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
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(0);
		load();
	}
	if (PtInRect(&_InHouseButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "InHouse";
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(1);
		load();
	}
	if (PtInRect(&_field1ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field1Tile";
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(2);
		load();
	}
	if (PtInRect(&_field2ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field2Tile";
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(3);
		load();
	}
	if (PtInRect(&_field3ButtonImg->boundingBox(), _ptMouse))
	{
		_tileSetName = "field3Tile";
		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(4);
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
