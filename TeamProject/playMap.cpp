#include "stdafx.h"
#include "playMap.h"


playMap::playMap()
{
}


playMap::~playMap()
{
}

HRESULT playMap::init(MAPSCENE mapscene)
{
	IMAGEMANAGER->addFrameImage("town", "image/maptool/town.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("InHouse", "image/maptool/inHouse.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field1Tile", "image/maptool/field1.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field2Tile", "image/maptool/field2.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("field3Tile", "image/maptool/field3.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("event", "image/maptool/event.bmp", 975, 325, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("윈도우맵", 3750, 3750);

	string str[6] = { "town", "InHouse", "field1Tile", "field2Tile", "field3Tile", "event" };
	for (int i = 0; i < 6; ++i)
	{
		if (i == mapscene) _currentTile = str[i];
	}

	load(_currentTile);

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
	IMAGEMANAGER->findImage("윈도우맵")->render(getMemDC(), CAMERA->getPosition().x, CAMERA->getPosition().y, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);
}

void playMap::objRender()
{
	POINT camera = CAMERA->getPosition();
	for (int i = camera.y / TILESIZE; i < camera.y / TILESIZE + SHOWTILEY; ++i)
	{
		for (int j = camera.x / TILESIZE; j < camera.x / TILESIZE + SHOWTILEX; ++j)
		{
			if (_tiles[i * TILEX + j].obj == OBJ_NONE) continue;
			else if (_tiles[i * TILEX + j].obj == OBJ_NPC) continue;
			else if (_tiles[i * TILEX + j].obj >= OBJ_UPPORTAL) continue;			

			IMAGEMANAGER->frameRender(_currentTile, getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].objFrameX, _tiles[i * TILEX + j].objFrameY);
		}
	}
}

void playMap::load(string tileName)
{
	HANDLE file;
	DWORD load;

	_currentTile = tileName;
	string str = _currentTile + ".map";
	file = CreateFile((char*)str.c_str(), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	// 타일
	int maxTileX = 0, maxTileY = 0;
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_tiles[i * TILEX + j].terrain == TR_NONE) continue;

			maxTileX = j;
			maxTileY = i;
			IMAGEMANAGER->frameRender(_currentTile, IMAGEMANAGER->findImage("윈도우맵")->getMemDC(),
				_tiles[i * TILEX + j].rc.left, _tiles[i * TILEX + j].rc.top,
				_tiles[i * TILEX + j].terrainFrameX, _tiles[i * TILEX + j].terrainFrameY);
		}
	}

	CAMERA->setMaxPositon(maxTileX * TILESIZE, maxTileY * TILESIZE);

	// 오브젝트 속성이 있는 타일만 담기
	_vObjectTile.clear();
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_tiles[i * TILEX + j].obj == OBJ_NONE ||
				_tiles[i * TILEX + j].obj == OBJ_EXIST) continue;

			_vObjectTile.push_back(make_pair(PointMake(j, i), _tiles[i * TILEX + j]));
		}
	}
}

void playMap::portal(float x, float y)
{
}


void playMap::setTilePos(RECT rc, OBJECT obj)
{
	for (int i = rc.top; i < rc.bottom; i += TILESIZE)
	{
		for (int j = rc.left; j < rc.right; j += TILESIZE)
		{
			_vTilePos.push_back(make_pair(obj, PointMake(j / TILEX, i / TILEY)));
		}
	}
}

POINT playMap::getTileIndex(RECT rc, OBJECT obj)
{
	POINT camera = CAMERA->getPosition();
	for (int i = camera.y / TILESIZE; i < camera.y / TILESIZE + SHOWTILEY; ++i)
	{
		for (int j = camera.x / TILESIZE; j < camera.x / TILESIZE + SHOWTILEX; ++j)
		{
			// 총 제트오더 사각형 크기 중, 중앙 타일길이를 기준으로 측정한다.
			if ((rc.left / TILESIZE == j && rc.top / TILESIZE == i) ||
				_tiles[i * TILEX + j].obj == obj)
				return PointMake(j, i);
		}
	}

	return PointMake(NULL, NULL);
}
