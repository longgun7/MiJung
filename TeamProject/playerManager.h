#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

struct tagInventory
{
	string name;
	int atk;
	int def;
	int luck;
	int cri;
	int speed;
	
};

class itemManager;
class playerManager :public gameNode
{
private:
	player * _ataho;    //아타호
	player2* _smasyu;   //스마슈
	itemManager* _itemManager; //아이템 매니저 전방선언

	//아타호
	vector<tagInventory>  _vA_WeapInven; //무기 담는 벡터
	vector<tagInventory>::iterator  _viA_WeapInven;

	vector<tagInventory>  _vA_ArmorInven; //방어구 담는 벡터
	vector<tagInventory>::iterator  _viA_ArmorInven;

	//스마슈
	vector<tagInventory>  _vS_WeapInven; //무기 담는 벡터
	vector<tagInventory>::iterator  _viS_WeapInven;

	vector<tagInventory>  _vS_ArmorInven; //방어구 담는 벡터
	vector<tagInventory>::iterator  _viS_ArmorInven;

	//포션
	vector<tagInventory>  _vPorInven; //포션 담는 벡터
	vector<tagInventory>::iterator  _viPorInven;

public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();

	void getItemValue(); //받을 아이템 종류
	player* getPlayer() { return _ataho; }
	
	void itemManagerAdressLink(itemManager* im) { _itemManager = im;}
	player* getPlayer() { return _ataho; }
	playerManager();
	~playerManager();
};

