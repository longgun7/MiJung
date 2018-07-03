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
	
public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setItem();

	item* getA_Weapon() { return _a_Weapon; }
	item* getA_Armor() { return _a_Armor; }
	item* getS_Weapon() { return _s_Weapon; }
	item* getS_Armor() { return _s_Armor; }
	item* getPortion() { return _potion; }
};

