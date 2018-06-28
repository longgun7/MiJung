#pragma once
#include "enemy.h"

class spirit : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	spirit();
	~spirit();
};

