#pragma once
#include"gameNode.h"
#include "item.h"
class barScnen : public gameNode
{
private:

	vector<item*>			_vShop;
	vector<item*>::iterator _viShop;

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
};

