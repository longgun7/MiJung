#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include <vector>

class playMap : public gameNode
{
private:
	vector<POINT>			_vPosition;
	vector<POINT>::iterator _viPosition;

	tagTile	_tiles[TILEX * TILEY];

public:
	playMap();
	~playMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();

	//타일 접근자
	tagTile* getTiles() { return _tiles; }
	//각 플레이어와 에너미가 어느 타일에 있는지 위치 세팅
	void setTilePos(RECT rc, OBJECT obj);
	//void setCurrentScene();
};

