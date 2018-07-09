#pragma once
#include"gameNode.h"
#include <vector>


struct tagShop
{
	string name;
	int num;
	int cost;
};
class playerManager;
class enemyManager;
class itemManager;
class barScnen : public gameNode
{
private:

	vector<tagShop*>			_vShop;
	vector<tagShop*>::iterator  _viShop;

	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	bool _isShopCheck;		//상점이 체크되었늬?
	bool _isHotelCheck;		//여관이 체크되었늬?

public:
	barScnen();
	~barScnen();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
	void setItem();
	void buyItem();

	//void AdressLinkItemManager(itemManager* im) { _im = im; }
};

