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

	_tileSetName = "town";
	_sampleImg = IMAGEMANAGER->findImage(_tileSetName);
	_drawTileImg = IMAGEMANAGER->findImage(_tileSetName);
	_ctrl = CTRL_TOWN;

	string str[6] = { "town", "InHouse", "field1Tile", "field2Tile", "field3Tile", "event" };
	for (int i = 0; i < 6; ++i)
	{
		_button[i].ctrlName = str[i];
		_button[i].rc = RectMake(i * 120, WINSIZEY - _sampleImg->getHeight() - 45, 120, 45);
	}
	_button[CTRL_SAVE].rc = IMAGEMANAGER->findImage("SAVE��ư")->boundingBox();

	_zoom = 1.0f;
	_isShowMoveTile = _isImageCopy = false;
	_isStopMoveCamera = true;

	setup();
	load();

	return S_OK;
}

void mapToolScene::release(void)
{
}

void mapToolScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("��ŸƮ��");

	keyInput();
	if (_isLButtonDown && !_isShowMoveTile)
	{
		_ptLastClick = _ptBGMouse;
		setMap();
	}

	_isStopMoveCamera = ((KEYMANAGER->isToggleKey('V')) ? true : false);

	// ī�޶� ��ǥ ����
	if (!_isShowTileSet && _isStopMoveCamera) CAMERA->setPosition(_ptMouse.x, _ptMouse.y, true);
	setShowTileIndex();

	autoSave(); // �ڵ����� ���似�̺�
}

void mapToolScene::render(void)
{
	// �̴ϸ� ���
	if (_isShowMiniMap)
	{
		IMAGEMANAGER->findImage("�̴ϸ�")->render(getMemDC(), 0, 0, WINSIZEX, WINSIZEY);
		return;
	}

	// ����
	for (int i = startIdY; i < endIdY; ++i)
	{
		for (int j = startIdX; j < endIdX; ++j)
		{
			if (_tiles[i * TILEX + j].terrain == TR_NONE)
			{
				HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				HPEN pen = CreatePen(PS_SOLID, 1, RGB(150, 150, 150));
				HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);
				Rectangle(getMemDC(), _tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
					_tiles[i * TILEX + j].rc.right, _tiles[i * TILEX + j].rc.bottom);
				SelectObject(getMemDC(), oldBrush);// GetStockObject(NULL_BRUSH));
				SelectObject(getMemDC(), oldPen);
				DeleteObject(brush);
				DeleteObject(pen);
			}
			else
			{
				IMAGEMANAGER->frameRender(_tileSetName, getMemDC(),
					_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
					_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY,
					_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left,
					_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top);
			}
		}
	}

	if (KEYMANAGER->isToggleKey('P'))
	{
		for (int i = startIdY; i < endIdY; ++i)
		{
			for (int j = startIdX; j < endIdX; ++j)
			{
				if (_tiles[i * TILEX + j].obj == OBJ_NONE) continue;

				IMAGEMANAGER->frameRender(_tileSetName, getMemDC(),
					_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
					_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY,
					(_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left),
					(_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top));

			}
		}
	}


	// Ÿ�� �ε��� ��ȣ
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = startIdY; i < endIdY; ++i)
		{
			for (int j = startIdX; j < endIdX; ++j)
			{
				SetTextColor(getMemDC(), RGB(0, 200, 200));
				SetBkMode(getMemDC(), TRANSPARENT);
				char str[128];
				sprintf_s(str, "%d %d", _tiles[i * TILEX + j].terrain, i * TILEX + j); // i * TILEX + j);
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
		for (int i = 0; i < 6; ++i)
		{
			IMAGEMANAGER->findImage("��Ÿ�ϼ¹�ư")->frameRender(CAMERA->getCameraDC(), i * 120, WINSIZEY - _sampleImg->getHeight() - 50, i, 0);
		}
		IMAGEMANAGER->findImage("SAVE��ư")->render(CAMERA->getCameraDC());

		IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->frameRender(CAMERA->getCameraDC(), 0, WINSIZEY - 336);

		// Ÿ�ϼ� �׸�
		_sampleImg->render(CAMERA->getCameraDC(), 6, WINSIZEY - _sampleImg->getHeight() - 5);

		// ������ Ÿ�ϼ��� �������� �˷��ִ� �簢��
		for (_viCurrentTile = _vCurrentTile.begin(); _viCurrentTile != _vCurrentTile.end(); ++_viCurrentTile)
		{
			IMAGEMANAGER->findImage("������Ÿ��")->render(CAMERA->getCameraDC(), _viCurrentTile->x * TILESIZE + 6, _viCurrentTile->y * TILESIZE + WINSIZEY - _sampleImg->getHeight() - 5);
		}

		// Ÿ�� �����ϼ� �ִ��� ���� ����
		if (_isShowMoveTile)
		{
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
	}

}

void mapToolScene::setImageInit()
{
	IMAGEMANAGER->addFrameImage("Ÿ�ϼ¹��", "image/maptool/tileSetbackground3.bmp", 1000, 2100, 1, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ÿ��", "image/maptool/selectTile.bmp", 25, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ�Ͽ�����OX", "image/maptool/ox.bmp", 50, 25, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("town", "image/maptool/town.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("InHouse", "image/maptool/inHouse.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field1Tile", "image/maptool/field1.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field2Tile", "image/maptool/field2.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field3Tile", "image/maptool/field3.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("event", "image/maptool/event.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("��Ÿ�ϼ¹�ư", "image/maptool/ButtonScene.bmp", 720, 45, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("SAVE��ư", "image/maptool/Buttonsave.bmp", WINSIZEX - 55, WINSIZEY - 325 - 50, 55, 45, true, RGB(255, 0, 255));;

	IMAGEMANAGER->addImage("�̴ϸ�", TILESIZEX, TILESIZEY);
	IMAGEMANAGER->addImage("�������", BACKGROUNDX, BACKGROUNDY);
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

			_tiles[i * TILEX + j].terrainFrameX = 0;
			_tiles[i * TILEX + j].terrainFrameY = 0;
			_tiles[i * TILEX + j].objFrameX = 0;
			_tiles[i * TILEX + j].objFrameY = 0;
			_tiles[i * TILEX + j].terrain = terrainSelect(_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY);
			_tiles[i * TILEX + j].obj = objSelect(_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY);
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
			_sampleTile[i * SAMPLETILEX + j].terrain = terrainSelect(j, i);
			_sampleTile[i * SAMPLETILEX + j].obj = objSelect(j, i);

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
	if (_vCurrentTile.size() <= 0 || _isShowTileSet) return;

	// ���� ������ Ÿ�� ����
	sortVCurrentTile();

	// Ÿ�� �׸���
	int drawStartX = _ptFirstClick.x / TILESIZE, drawStartY = _ptFirstClick.y / TILESIZE;
	int drawEndX = _ptLastClick.x / TILESIZE, drawEndY = _ptLastClick.y / TILESIZE;

	if (drawStartX > drawEndX) swap(drawStartX, drawEndX);
	if (drawStartY > drawEndY) swap(drawStartY, drawEndY);

	for (int i = drawStartY; i <= drawEndY; ++i)
	{
		for (int j = drawStartX; j <= drawEndX; ++j)
		{
			int countX = 0, countY = 0;
			for (int k = 0; k < _vCurrentTile.size(); ++k)
			{
				if (k > 0 && _vCurrentTile[k].y > _vCurrentTile[k - 1].y)	++countY, countX = 0;

				_tiles[(i + countY) * TILEX + (j + countX)].objFrameX = _vCurrentTile[k].x;
				_tiles[(i + countY) * TILEX + (j + countX)].objFrameY = _vCurrentTile[k].y;
				_tiles[(i + countY) * TILEX + (j + countX)].obj = objSelect(_vCurrentTile[k].x, _vCurrentTile[k].y);
				if (_tiles[(i + countY) * TILEX + (j + countX)].obj == OBJ_ROPE) _tiles[(i + countY) * TILEX + (j + countX)].terrain = TR_MOVE;

				if (_tiles[(i + countY) * TILEX + (j + countX)].obj == OBJ_NONE)
				{
					_tiles[(i + countY) * TILEX + (j + countX)].terrainFrameX = _vCurrentTile[k].x;
					_tiles[(i + countY) * TILEX + (j + countX)].terrainFrameY = _vCurrentTile[k].y;
					_tiles[(i + countY) * TILEX + (j + countX)].terrain = terrainSelect(_vCurrentTile[k].x, _vCurrentTile[k].y);
				}

				++countX;
			}
		}
	}

}
// �����ϼ� �ִ� Ÿ��, �����ϼ� ���� Ÿ�� �ٲٱ�
void mapToolScene::setChangeMoveTile()
{
	bool _isbreak = false;
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		if (_isbreak) break;
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			if (PtInRect(&_sampleTile[i * SAMPLETILEX + j].rcTile, _ptMouse))
			{
				(_sampleTile[i * SAMPLETILEX + j].terrain == TR_MOVE) ? _sampleTile[i * SAMPLETILEX + j].terrain = TR_UNMOVE : _sampleTile[i * SAMPLETILEX + j].terrain = TR_MOVE;

				for (int ii = 0; ii < TILEY; ++ii)
				{
					for (int jj = 0; jj < TILEX; ++jj)
					{
						if (_tiles[ii * TILEX + jj].terrainFrameX == j &&
							_tiles[ii * TILEX + jj].terrainFrameY == i)
						{
							_tiles[ii * TILEX + jj].terrain = _sampleTile[i * SAMPLETILEX + j].terrain;
						}
					}
				}

				_isbreak = true;
				break;
			}
		}
	}


}

void mapToolScene::keyInput()
{
	// ����
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_zoom += 0.5f;	if (_zoom > 9.0f) _zoom = 9.0f;

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
		_isLButtonDown = true;
		if (!_isLButtonFirstDown) { _ptFirstClick = _ptBGMouse; _isLButtonFirstDown = true; }
		if (_isShowTileSet) buttonClick();
		if (_isShowMoveTile) setChangeMoveTile();
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

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		(_isShowMoveTile) ? _isShowMoveTile = false : _isShowMoveTile = true;
	}

	if (KEYMANAGER->isToggleKey('M'))
	{
		miniMapCopy();
	}
	else _isShowMiniMap = false;
}

void mapToolScene::buttonClick()
{
	for (int i = 0; i < 6; ++i)
	{
		if (PtInRect(&_button[i].rc, _ptMouse))
		{
			_tileSetName = _button[i].ctrlName;

			_sampleImg = IMAGEMANAGER->findImage(_tileSetName);
			_drawTileImg = IMAGEMANAGER->findImage(_tileSetName);
			IMAGEMANAGER->findImage("Ÿ�ϼ¹��")->setFrameY(i);
			_ctrl = (CTRL)i;
			load();
			break;
		}
	}

	if (PtInRect(&_button[CTRL_SAVE].rc, _ptMouse))
	{
		save();
	}
}

void mapToolScene::autoSave()
{
	if ((int)(TIMEMANAGER->getWorldTime()) % 60 == 0)
	{
		save();
	}

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

	//for (int i = 0; i < TILEY; ++i)
	//{
	//for (int j = 0; j < TILEX; ++j)
	//{
	//	if (_tiles[i * TILEX + j].terrain == TR_UNMOVE)
	//		_tiles[i * TILEX + j].terrain = TR_NONE;
	//if(_tiles[i * TILEX + j].terrain == TR_MOVE)
	//	_tiles[i * TILEX + j].terrain = TR_UNMOVE;
	//else if (_tiles[i * TILEX + j].terrain == TR_UNMOVE)
	//	_tiles[i * TILEX + j].terrain = TR_MOVE;
	////else if (_tiles[i * TILEX + j].terrain == TR_MOVE)
	////	_tiles[i * TILEX + j].terrain = TR_DOOR;
	//else if (_tiles[i * TILEX + j].terrain == 7)
	//	_tiles[i * TILEX + j].terrain = TR_NONE;
	//
	//	if(_tiles[i * TILEX + j].obj == 6)
	//		_tiles[i * TILEX + j].obj = OBJ_NONE;
	//if (_tiles[i * TILEX + j].obj == 5)
	//_tiles[i * TILEX + j].obj = OBJ_NONE;
	//else if (_tiles[i * TILEX + j].terrain == TR_MOVE)
	//	_tiles[i * TILEX + j].terrain = TR_UNMOVE;
	//else if (_tiles[i * TILEX + j].terrain == TR_DOOR)
	//	_tiles[i * TILEX + j].terrain = TR_MOVE;
	//else if (_tiles[i * TILEX + j].terrain == TR_LEFTPORTAL)
	//	_tiles[i * TILEX + j].terrain = TR_DOOR;
	//}
	//}

	CloseHandle(file);
}

void mapToolScene::miniMapCopy()
{
	if (_isShowMiniMap) return;

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			IMAGEMANAGER->frameRender(_tileSetName, IMAGEMANAGER->findImage("�̴ϸ�")->getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY,
				_tiles[i * TILEX + j].rc.right - _tiles[i * TILEX + j].rc.left,
				_tiles[i * TILEX + j].rc.bottom - _tiles[i * TILEX + j].rc.top);
		}
	}

	_isShowMiniMap = true;

}

TERRAIN mapToolScene::terrainSelect(int frameX, int frameY)
{
	for (int i = 0; i < 3; ++i)
	{
		if (frameX == i && frameY == 0)
		{
			return TR_NONE;
		}

		if (frameX == 2 && frameY == 0)
		{
			return TR_DOOR;
		}
	}

	return TR_UNMOVE;
}

OBJECT mapToolScene::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 12) return OBJ_UPPORTAL;
	if (frameX == 1 && frameY == 12) return OBJ_DOWNPORTAL;
	if (frameX == 2 && frameY == 12) return OBJ_LEFTPORTAL;
	if (frameX == 3 && frameY == 12) return OBJ_RIGHTPORTAL;

	int objStartX = 0, objStartY = 0, objEndX = 0, objEndY = 0;
	switch (_ctrl)
	{
	case CTRL_TOWN:
	{
		if (frameX == 4 && frameY == 12) return OBJ_NPC;

		for (int j = 16; j <= 28; ++j) if (frameX == j && frameY == 10) return OBJ_EXIST;
		for (int j = 33; j <= 38; ++j) if (frameX == j && frameY == 10) return OBJ_EXIST;
		if (frameX == 32 && frameY == 12) return OBJ_NONE;

		objStartX = 12; objStartY = 11, objEndX = 34, objEndY = SAMPLETILEY;
	}
	break;
	case CTRL_INHOUSE:
	{
		if (frameX == 4 && frameY == 12) return OBJ_NPC;
		if (frameX == 5 && frameY == 12) return OBJ_SHOP;
		if (frameX == 6 && frameY == 12) return OBJ_MOTEL;

		objStartX = 21; objStartY = 10, objEndX = SAMPLETILEX, objEndY = SAMPLETILEY;
	}
	break;
	case CTRL_FIELD1:
	{
		for (int i = 6; i <= 7; ++i)
			for (int j = 35; j <= 36; ++j)
				if (frameX == j && frameY == i) return OBJ_EXIST;

		if (frameX == 26 && frameY == 8 || frameX == 27 && frameY == 8) return OBJ_EXIST;

		objStartX = 35; objStartY = 10, objEndX = SAMPLETILEX, objEndY = SAMPLETILEY;
	}
	break;
	case CTRL_FIELD2:
	{
		for (int j = 3; j <= 35; ++j) if (frameX == j && (frameY == 0 || frameY == 1)) return OBJ_EXIST;

		for (int i = 2; i <= 3; ++i)
			for (int j = 10; j <= 35; ++j)
				if (frameX == j && frameY == i) return OBJ_EXIST;

		for (int j = 10; j <= 18; ++j)
			if (frameX == j && frameY == 4) return OBJ_EXIST;

	}
	break;
	case CTRL_FIELD3:
	{
		for (int i = 0; i <= 4; ++i)
		{
			for (int j = 18; j <= 21; ++j)
			{
				if (frameX == j && frameY == i) return OBJ_EXIST;
			}
		}

		for (int j = 22; j <= 32; ++j)
		{
			if (frameX == j && frameY == 0) return OBJ_EXIST;
		}

		for (int i = 0; i <= 6; ++i)
		{
			for (int j = 32; j <= 38; ++j)
			{
				if ((frameX == 34 && frameY == 0) || (frameX == 37 && frameY == 0) ||
					(frameX == 38 && frameY == 0) || (frameX == 38 && frameY == 1) ||
					(frameX == 32 && frameY == 4) || (frameX == 32 && frameY == 5) ||
					(frameX == 32 && frameY == 6)) 	continue;

				if (frameX == j && frameY == i) return OBJ_EXIST;
			}
		}

		for (int j = 21; j <= 30; ++j) { if (frameX == j && frameY == 7) return OBJ_EXIST; }
		for (int j = 21; j <= 26; ++j) { if (frameX == j && frameY == 8) return OBJ_EXIST; }
		for (int j = 22; j <= 37; ++j) { if (frameX == j && frameY == 11) return OBJ_EXIST; }
	}
	break;
	case CTRL_EVENT:
	{
		if (frameX == 5 && frameY == 12) return OBJ_ROPEEND;

		if ((frameX == 36 || frameX == 37) && frameY == 4) return OBJ_EXIST;
		if (frameX == 36 && frameY == 3) return OBJ_EXIST;

		if ((frameX == 37 || frameX == 38) && frameY == 3) return OBJ_ROPE;

		for (int i = 5; i <= 7; ++i)
			for (int j = 17; j <= 19; ++j)
				if (frameX == j && frameY == i) return OBJ_EXIST;


		objStartX = 19; objStartY = 0, objEndX = 36, objEndY = 3;
	}
	break;
	}

	for (int i = objStartY; i < objEndY; ++i)
		for (int j = objStartX; j < objEndX; ++j)
			if (frameX == j && frameY == i) return OBJ_EXIST;

	return OBJ_NONE;
}
