#pragma once
#include "enemy.h"

class wildBoar : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	wildBoar();
	~wildBoar();
};

