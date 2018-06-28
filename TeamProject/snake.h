#pragma once
#include "enemy.h"

class snake : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	snake();
	~snake();
};

