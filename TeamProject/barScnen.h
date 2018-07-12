#pragma once
#include "shop.h"
#include "saveLoad.h"
#include "gameNode.h"
#include "playMap.h"
#include "npc.h"

class playerManager;

class barScnen : public gameNode
{
private:
	
	npc*				_npc;
	playMap*			_map;
	shop *				_shop;
	playerManager * _pm;
	
	saveLoad* _sl;
	

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
	void sceneChange(void);

};

