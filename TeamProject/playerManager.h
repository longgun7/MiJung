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
	player * _ataho;    //��Ÿȣ
	player2* _smasyu;   //������
	itemManager* _itemManager; //������ �Ŵ��� ���漱��

	//��Ÿȣ
	vector<tagInventory>  _vA_WeapInven; //���� ��� ����
	vector<tagInventory>::iterator  _viA_WeapInven;

	vector<tagInventory>  _vA_ArmorInven; //�� ��� ����
	vector<tagInventory>::iterator  _viA_ArmorInven;

	//������
	vector<tagInventory>  _vS_WeapInven; //���� ��� ����
	vector<tagInventory>::iterator  _viS_WeapInven;

	vector<tagInventory>  _vS_ArmorInven; //�� ��� ����
	vector<tagInventory>::iterator  _viS_ArmorInven;

	//����
	vector<tagInventory>  _vPorInven; //���� ��� ����
	vector<tagInventory>::iterator  _viPorInven;

public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();

	void getItemValue(); //���� ������ ����
	player* getPlayer() { return _ataho; }
	
	void itemManagerAdressLink(itemManager* im) { _itemManager = im;}
	player* getPlayer() { return _ataho; }
	playerManager();
	~playerManager();
};

