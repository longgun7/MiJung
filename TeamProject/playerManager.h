#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

struct tagInventory
{
	string name;
	int _atk;
	int _def;
	int _luck;
	int _cri;
	int _speed;
	
};

class itemManager;
class playerManager :public gameNode
{
private:
	player * _ataho;    //아타호
	player2* _smasyu;   //스마슈
	itemManager* _itemManager; //아이템 매니저 전방선언

	vector<tagInventory>  _vItemInven; //무기, 방어구 담는 벡터
	vector<tagInventory>::iterator  _viItemInven;

	vector<tagInventory>  _vPortionInven; //포션 담는 벡터
	vector<tagInventory>::iterator  _viPortionInven;

public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();

	void getItemValue(); //받을 아이템 종류
	
	void itemManagerAdressLink(itemManager* im) { _itemManager = im;}
	playerManager();
	~playerManager();
};

