#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

class itemManager;
class playerManager :public gameNode
{
private:
	player * _ataho;    //��Ÿȣ
	player2* _smasyu;   //������
	inventory* _inven;  //�κ��丮
	
	//�κ��丮 ����
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

