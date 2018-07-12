#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include <vector>

class playMap : public gameNode
{
private:
	vector<tagTile>				_vPortal;
	vector<tagTile>::iterator	_viPortal;

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
	void portal(float x, float y);

	//Ÿ�� ������
	tagTile* getTiles() { return _tiles; }
	//�� �÷��̾�� ���ʹ̰� ��� Ÿ�Ͽ� �ִ��� ��ġ ����
	void setTilePos(RECT rc, OBJECT obj);
	// ���� Ÿ�� �̸� ��������(�ʵ������ ���� Ÿ���� � Ÿ������ �˱� ����)
	string getCurrentTileName() { return _currentTile; }
};

