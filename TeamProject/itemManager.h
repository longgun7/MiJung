#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager : public gameNode
{
private:
	item* _weapon;
	item*  _potion;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setItem();

	item* getWeapon() { return _weapon; }
	item* getPortion() { return _potion; }
	
};

