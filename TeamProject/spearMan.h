#pragma once
#include "enemy.h"
class spearMan : public enemy
{
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	spearMan();
	~spearMan();
};

