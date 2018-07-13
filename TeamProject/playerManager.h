#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"
#include "inventory.h"

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
	image* img;
	int atk;
	int def;
	int luck;
	int cri;
	int speed;
	string name;
	
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
	vector<tagInventory>  _vPoInven; //���� ��� ����
	vector<tagInventory>::iterator  _viPoInven;

	int _mountingIndex;
	int _HPpoIndex;
	int _MPpoIndex;
public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();
	void mounting(int frameX, int setIndex, int invenTypeIndex, int invenIndex);
			//��Ÿȣ���� ���������� , ���ǰ������۹�ȣ , ������ �������ȣ, ����� ������ ��ȣ 
	void getItemValue(string itemName); //���� ������ ����
	void setEnemyDead(); // ���ʹ� 
	void setMoney(int money);
	void invenClear();

	
	player* getPlayer() { return _ataho; }
	player2* getPlayer2() { return _smasyu; }
	
	vector<tagInventory>  getVA_WeapInven() { return _vA_WeapInven; }//��Ÿȣ ���� ��� ����
	vector<tagInventory>::iterator getVIA_WeapInven() { return _viA_WeapInven; }
	
	vector<tagInventory>  getVA_ArmorInven() { return _vA_ArmorInven; }//��Ÿȣ �� ��� ����
	vector<tagInventory>::iterator getVIA_ArmorInven() { return _viA_ArmorInven; }

	vector<tagInventory>  getVS_WeapInven() { return _vS_WeapInven; }//������ ���� ��� ����
	vector<tagInventory>::iterator getVIS_WeapInven() { return _viS_WeapInven; }
	
	vector<tagInventory>  getVS_ArmorInven() { return _vS_ArmorInven; }//������ �� ��� ����
	vector<tagInventory>::iterator getVIS_ArmorInven() { return _viS_ArmorInven; }

	vector<tagInventory>  getV_PoInven() { return _vPoInven; }//���� ��� ����
	vector<tagInventory>::iterator getVI_PoInven() { return _viPoInven; }

	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; }
	void setItemManagerAdressLink(itemManager* im) { _im = im; }

	int getHpPoIndex() { return _HPpoIndex; }
	int getMpPoIndex() { return _MPpoIndex; }
	void setHpPoindex(int num) { _HPpoIndex = num; }
	void setMpPoindex(int num) { _MPpoIndex = num; }
	tagMoney getTagMoney() { return _gold; }
	void setGold(int num) { _gold.money = num; }

	string getA_WeapItemName() { return _A_saveBeforWeapon.name; }
	string getA_ArmorItemName() { return _A_saveBeforArmor.name; }
	string getS_WeapItemName() { return _S_saveBeforWeapon.name; }
	string getS_ArmorItemName() { return _S_saveBeforArmor.name; }

	image* getA_WeapItemImage() { return _A_saveBeforWeapon.img; }
	image* getA_ArmorItemImage() { return _A_saveBeforArmor.img; }
	image* getS_WeapItemImage() { return _S_saveBeforWeapon.img; }
	image* getS_ArmorItemImage() { return _S_saveBeforArmor.img; }
	
	void  setA_WeapItemName(string name) { _A_saveBeforWeapon.name = name; }
	void  setA_ArmorItemName(string name) { _A_saveBeforArmor.name = name; }
	void  setS_WeapItemName(string name) { _S_saveBeforWeapon.name = name; }
	void  setS_ArmorItemName(string name) { _S_saveBeforArmor.name = name; }


	playerManager();
	~playerManager();
};

