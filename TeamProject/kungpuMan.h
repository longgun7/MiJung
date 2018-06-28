#pragma once
#include "enemy.h"

class kungpuMan : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	kungpuMan();
	~kungpuMan();
};

