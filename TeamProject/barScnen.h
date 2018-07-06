#pragma once
#include"gameNode.h"
#include "item.h"
class barScnen : public gameNode
{
private:

	vector<item*>			_vShop;
	vector<item*>::iterator _viShop;

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
};

