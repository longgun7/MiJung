#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager : public gameNode
{
private:

	item* _potion;
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
	void shopItemSet(string itemName, float x, float y);

	item* getPortion() { return _potion; }

	item* getPItem() { return _pItem; }
	item* getShopItem() { return _shopItem; }


};

