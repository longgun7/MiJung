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
	player * _ataho;    //아타호
	player2* _smasyu;   //스마슈
	itemManager* _im; //아이템 매니저 전방선언
	enemyManager* _em; // 에너미 매니저 전방선언
	saveBeforItem _A_saveBeforWeapon;
	saveBeforItem _A_saveBeforArmor;
	saveBeforItem _S_saveBeforWeapon;
	saveBeforItem _S_saveBeforArmor;
	saveBeforItem _saveBeforPortion;
	INVENATTRIBUTE _invenAttribute; //장착상태
	tagMoney _gold;
	
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
	vector<tagInventory>  _vPoInven; //포션 담는 벡터
	vector<tagInventory>::iterator  _viPoInven;
	
	int _mountingIndex;
public:

	HRESULT init();
	void update();
	void render();
	void release();
	void eventMode();
	void mounting();
	void getItemValue(); //받을 아이템 종류
	void inventory(); //인벤토리
	void setEnemyDead(); // 에너미 

	player* getPlayer() { return _ataho; }
	player2* getPlayer2() { return _smasyu; }
	
	vector<tagInventory>  getVA_WeapInven() { return _vA_WeapInven; }//아타호 무기 담는 벡터
	vector<tagInventory>::iterator getVIA_WeapInven() { return _viA_WeapInven; }
	
	vector<tagInventory>  getVA_ArmorInven() { return _vA_ArmorInven; }//아타호 방어구 담는 벡터
	vector<tagInventory>::iterator getVIA_ArmorInven() { return _viA_ArmorInven; }

	vector<tagInventory>  getVS_WeapInven() { return _vS_WeapInven; }//스마슈 무기 담는 벡터
	vector<tagInventory>::iterator getVIS_WeapInven() { return _viS_WeapInven; }
	
	vector<tagInventory>  getVS_ArmorInven() { return _vS_ArmorInven; }//스마슈 방어구 담는 벡터
	vector<tagInventory>::iterator getVIS_ArmorInven() { return _viS_ArmorInven; }

	vector<tagInventory>  getV_PoInven() { return _vPoInven; }//포션 담는 벡터
	vector<tagInventory>::iterator getVI_PoInven() { return _viPoInven; }

	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; }
	void setItemManagerAdressLink(itemManager* im) { _im = im; }

	playerManager();
	~playerManager();
};

