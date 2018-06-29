#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

class itemManager;
class playerManager :public gameNode
{
private:
	player * _ataho;    //아타호
	player2* _smasyu;   //스마슈
	inventory* _inven;  //인벤토리
	
	//인벤토리 벡터
	vector<inventory*>				_vInven;   
	vector<inventory*>::iterator    _viInven;	
	itemManager* _itemManager;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	void itemManagerAdressLink(itemManager* im) { _itemManager = im;}
	playerManager();
	~playerManager();
};

