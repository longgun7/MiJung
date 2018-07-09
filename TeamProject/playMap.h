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

	//Ÿ�� ������
	tagTile* getTiles() { return _tiles; }
	//�� �÷��̾�� ���ʹ̰� ��� Ÿ�Ͽ� �ִ��� ��ġ ����
	void setTilePos(RECT rc, OBJECT obj);
	//void setCurrentScene();
};

