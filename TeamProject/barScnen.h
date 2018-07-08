#pragma once
#include"gameNode.h"
#include <vector>
#include "itemManager.h"


struct tagShop
{
	string name;
	int num;
	int cost;
};

class  itemManager;

class barScnen : public gameNode
{
private:

	vector<tagShop*>			_vShop;
	vector<tagShop*>::iterator  _viShop;

	itemManager* _im;

	bool _isShopCheck;		//������ üũ�Ǿ���?
	bool _isHotelCheck;		//������ üũ�Ǿ���?

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

