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
	player * _ataho;    //��Ÿȣ
	player2* _smasyu;   //������
	itemManager* _itemManager; //������ �Ŵ��� ���漱��

	vector<tagInventory>  _vItemInven; //����, �� ��� ����
	vector<tagInventory>::iterator  _viItemInven;

	vector<tagInventory>  _vPortionInven; //���� ��� ����
	vector<tagInventory>::iterator  _viPortionInven;

public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();

	void getItemValue(); //���� ������ ����
	
	void itemManagerAdressLink(itemManager* im) { _itemManager = im;}
	playerManager();
	~playerManager();
};

