#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager : public gameNode
{
private:

	item* _potion;
	item* _pItem;
	
public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setItem();

	void itemMakeSet(string itemName, float x, float y);
	void potionMakeSet(string potionName, float x, float y);
	
	item* getPItem()	  { return _pItem; }
	item* getPortion()	  { return _potion; }
	
};

