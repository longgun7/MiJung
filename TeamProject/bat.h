#pragma once
#include "enemy.h"

class bat : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	bat();
	~bat();
};

