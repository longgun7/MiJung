#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include <vector>

enum MAPSCENE
{
	TOWN,
	BAR,
	FIELD1,
	FIELD2,
	FIELD3,
	EVENT
};

class playMap : public gameNode
{
private:
	vector<pair<POINT, tagTile>>				_vObjectTile;
	vector<pair<POINT, tagTile>>::iterator		_viObjectTile;
	vector<pair<OBJECT, POINT>>					_vTilePos;

	tagTile	_tiles[TILEX * TILEY];
	string _currentTile;

public:
	playMap();
	~playMap();

	HRESULT init(MAPSCENE mapscene);
	void release();
	void update();
	void render();
	void objRender();

	void load(string tileName);
	void portal(float x, float y);

	// 타일 접근자
	tagTile* getTiles() { return _tiles; }
	// 특정 오브젝트 속성이 있는 타일만 담겨있는 벡터 접근자
	vector<pair<POINT, tagTile>> getVObjectTile() { return _vObjectTile; }
	
	//각 플레이어와 에너미가 어느 타일에 있는지 위치 세팅
	void setTilePos(RECT rc, OBJECT obj);

	// 오브젝트가 현재 어느 타일에 있는지 받아오기
	POINT getTileIndex(RECT rc, OBJECT obj);
};

