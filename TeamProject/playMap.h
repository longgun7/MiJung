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
	string _currentTile;

public:
	playMap();
	~playMap();

	HRESULT init();
	void release();
	void update();
	void render();
	void objRender();

	void load(string tileName);

	//타일 접근자
	tagTile* getTiles() { return _tiles; }
	//각 플레이어와 에너미가 어느 타일에 있는지 위치 세팅
	void setTilePos(RECT rc, OBJECT obj);
	// 현재 타일 이름 가져오기(필드씬에서 현재 타일이 어떤 타일인지 알기 위함)
	string getCurrentTileName() { return _currentTile; }
};

