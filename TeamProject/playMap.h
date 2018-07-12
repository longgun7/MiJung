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
	vector<tagTile>				_vPortal;
	vector<tagTile>::iterator	_viPortal;
	vector<pair<OBJECT, POINT>> vTilePos;

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

	//Ÿ�� ������
	tagTile* getTiles() { return _tiles; }
	//�� �÷��̾�� ���ʹ̰� ��� Ÿ�Ͽ� �ִ��� ��ġ ����
	void setTilePos(RECT rc, OBJECT obj);

	// ������Ʈ�� ���� ��� Ÿ�Ͽ� �ִ��� �޾ƿ���
	POINT getTileIndex(RECT rc, OBJECT obj);

	// ���� Ÿ�� �̸� ��������(�ʵ������ ���� Ÿ���� � Ÿ������ �˱� ����)
	string getCurrentTileName() { return _currentTile; }
};

