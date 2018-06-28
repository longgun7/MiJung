#pragma once
#include "enemy.h"

class skeleton : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	skeleton();
	~skeleton();
};

