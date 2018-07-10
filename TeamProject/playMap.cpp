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

	IMAGEMANAGER->addImage("¿©µµøÏ∏ ", 3750, 3750);

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
	IMAGEMANAGER->findImage("¿©µµøÏ∏ ")->render(getMemDC(), CAMERA->getPosition().x, CAMERA->getPosition().y, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);
}

void playMap::load()
{
	HANDLE file;
	DWORD load;

	file = CreateFile("town.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	// ≈∏¿œ
	int maxTileX = 0, maxTileY = 0;
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_tiles[i * TILEX + j].terrain == TR_NONE) break;

			maxTileX = j;
			maxTileY = i;
			IMAGEMANAGER->frameRender("town", IMAGEMANAGER->findImage("¿©µµøÏ∏ ")->getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY);
		}
	}

	CAMERA->setMaxPositon(maxTileX * TILESIZE, maxTileY * TILESIZE);

	//for (int i = 0; i < TILEY; ++i)
	//{
	//	for (int j = 0; j < TILEX; ++j)
	//	{
	//		if (_tiles[i * TILEX + j].obj == OBJ_NONE) continue;
	//
	//		IMAGEMANAGER->frameRender("town", IMAGEMANAGER->findImage("¿©µµøÏ∏ ")->getMemDC(),
	//			_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
	//			_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY);
	//	}
	//}
}

void playMap::setTilePos(RECT rc, OBJECT obj)
{
	vector<pair<int, int>> vTilePos;
	for (int i = rc.top; i < rc.bottom; i += TILESIZE)
	{
		for (int j = rc.left; j < rc.right; j += TILESIZE)
		{
			vTilePos.push_back(make_pair(j / TILEX, i / TILEY));
		}
	}

	//POINT camera = CAMERA->getPosition();
	//for (int i = camera.y / TILESIZE; i < camera.y / TILESIZE + SHOWTILEY; ++i)
	//{
	//	for (int j = camera.x / TILESIZE; j < camera.x / TILESIZE + SHOWTILEX; ++j)
	//	{
	//		if (_tiles[i * TILEX + j].obj == obj)
	//		{
	//
	//		}
	//
	//		for (int k = 0; k < vTilePos.size(); ++k)
	//		{				
	//			if (vTilePos[k].first == j && vTilePos[k].second == i)
	//			{
	//				_tiles[i * TILEX + j].obj = obj;
	//			}
	//		}
	//	}
	//}

}
