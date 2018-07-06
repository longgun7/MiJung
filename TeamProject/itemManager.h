#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager : public gameNode
{
private:
	item* _a_Weapon;
	item* _a_Armor;
	item* _potion;
	
	item* _s_Weapon;
	item* _s_Armor;
	
	item* _pItem;
	item* _shopItem;
	
public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setItem();

	void itemMakeSet(string itemName, float x, float y);

	//item* getPItem() { return _a_Weapon; }
	//item* getPItem() { return _a_Armor; }
	//item* getPItem() { return _s_Weapon; }
	//item* getPItem() { return _s_Armor; }
	item* getPortion() { return _potion; }

	item* getPItem() { return _pItem; }
	item* getShopItem() { return _shopItem; }

};

