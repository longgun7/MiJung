#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

enum INVENATTRIBUTE
{
	MOUNTING, UNMOUNTING, MOUNTINGEND,DIFFRENTMOUNTING
};
struct tagInventory
{
	image* img;
	RECT rc;
	int x;
	int y;
	string name;
	int atk;
	int def;
	int luck;
	int cri;
	int speed;
	int hp;
	int mp;
};

struct saveBeforItem
{

	int atk;
	int def;
	int luck;
	int cri;
	int speed;
	
};
struct tagMoney
{
	int money;
	int moneyFrame;
};
class itemManager;
class enemyManager;
class playerManager :public gameNode
{
private:
	player * _ataho;    //��Ÿȣ
	player2* _smasyu;   //������
	itemManager* _im; //������ �Ŵ��� ���漱��
	enemyManager* _em; // ���ʹ� �Ŵ��� ���漱��
	saveBeforItem _A_saveBeforWeapon;
	saveBeforItem _A_saveBeforArmor;
	saveBeforItem _S_saveBeforWeapon;
	saveBeforItem _S_saveBeforArmor;
	saveBeforItem _saveBeforPortion;
	INVENATTRIBUTE _invenAttribute; //��������
	tagMoney _gold;
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
	
	int _mountingIndex;
public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();
	void mounting();
	void getItemValue(); //���� ������ ����
	void inventory(); //�κ��丮
	void setMoney(); // ���ʹ� ����

	player* getPlayer() { return _ataho; }
	player2* getPlayer2() { return _smasyu; }
	
	playerManager();
	~playerManager();
};

