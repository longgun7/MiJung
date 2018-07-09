#include "stdafx.h"
#include "playMap.h"


playMap::playMap()
{
}


playMap::~playMap()
{
}

HRESULT playMap::init()
{
	IMAGEMANAGER->addFrameImage("town", "image/maptool/town.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�������", 3750, 3750);

	load();

	return S_OK;
}

void playMap::release()
{
}

void playMap::update()
{

}

void playMap::render()
{
	/*
	//����
	for (int i = CAMERA->getPosition().y / TILESIZE; i < CAMERA->getPosition().y / TILESIZE + SHOWTILEY; i++)
	{
	for (int j = CAMERA->getPosition().x / TILESIZE; j < CAMERA->getPosition().x / TILESIZE + SHOWTILEX; ++j)
	{
	//���� �Ӽ��� �ƴϸ� �׸�������
	if (_tiles[i * TILEX + j].terrain == TR_NONE)	continue;

	IMAGEMANAGER->frameRender("town", getMemDC(),
	_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
	_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY);

	}
	}

	//������Ʈ
	for (int i = CAMERA->getPosition().y / TILESIZE; i < CAMERA->getPosition().y / TILESIZE + SHOWTILEY; i++)
	{
	for (int j = CAMERA->getPosition().x / TILESIZE; j < CAMERA->getPosition().x / TILESIZE + SHOWTILEX; ++j)
	{
	//������Ʈ �Ӽ��� �ƴϸ� �׸�������
	if (_tiles[i * TILEX + j].obj == OBJ_NONE)	continue;

	IMAGEMANAGER->frameRender("town", getMemDC(),
	_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
	_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY);
	}
	}
	*/

	//IMAGEMANAGER->findImage("�������")->render(getMemDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->render("�������", getMemDC());
}

void playMap::load()
{
	HANDLE file;
	DWORD load;

	file = CreateFile("town.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);
	//ReadFile(file, _pos, sizeof(int) * 2, &load, NULL);

	CloseHandle(file);

	// Ÿ��
	int maxTileX = 0, maxTileY = 0;
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_tiles[i * TILEX + j].terrain == TR_NONE) break;

			maxTileX = j;
			maxTileY = i;
			IMAGEMANAGER->frameRender("town", IMAGEMANAGER->findImage("�������")->getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY);
		}
	}

	CAMERA->setMaxPositon(maxTileX * TILESIZE, maxTileY * TILESIZE);
	
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_tiles[i * TILEX + j].obj == OBJ_NONE) continue;

			IMAGEMANAGER->frameRender("town", IMAGEMANAGER->findImage("�������")->getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY);
		}
	}

	//for (int i = 0; i < TILEX * TILEY; ++i)
	//{
	//	if (_tiles[i].obj == OBJ_TANK1) _tiles[i].obj = OBJ_NONE;
	//}
	//
	//memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	//
	//// �Ӽ� ����
	//for (int i = 0; i < TILEX * TILEY; ++i)
	//{
	//	if (_tiles[i].terrain == TR_WALL)  _attribute[i] |= ATTR_UNMOVE;
	//	if (_tiles[i].obj == OBJ_EAT)	   _attribute[i] |= ATTR_EAT;
	//}
}

void playMap::setTilePos(RECT rc, OBJECT obj)
{
	int tilePosX = rc.left / TILEX;
	int tilePosY = rc.bottom - TILESIZE / TILEY;

	POINT camera = CAMERA->getPosition();
	for (int i = camera.y / TILESIZE; i < camera.y / TILESIZE + SHOWTILEY; ++i)
	{
		for (int j = camera.x / TILESIZE; j < camera.x / TILESIZE + SHOWTILEX; ++j)
		{
			if (tilePosX == j && tilePosY == i) _tiles[i * TILEX + j].obj = obj;
		}
	}
}
