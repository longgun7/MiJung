#pragma once
#include "shop.h"
#include "gameNode.h"
#include "playMap.h"
#include "npc.h"

class playerManager;

class barScnen : public gameNode
{
private:
	playerManager *		_pm;
	npc*				_npc;
	playMap*			_map;
	shop *				_shop;

	bool _isShopCheck;		//상점이 체크되었늬?
	bool _isHotelCheck;		//여관이 체크되었늬?

public:
	barScnen();
	~barScnen();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void npcTileSetting();
	void npcCollision();
	
	void fontUI(void);
	void sceneChange(void);

};

