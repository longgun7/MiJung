#pragma once
#include "shop.h"
#include "gameNode.h"
#include "playMap.h"

class playerManager;

class barScnen : public gameNode
{
private:
	playerManager * _pm;
	playMap* _map;
	shop * _shop;

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
	void sceneChange(void);

};

