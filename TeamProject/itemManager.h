#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager : public gameNode
{
private:
	item* _weapon;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

