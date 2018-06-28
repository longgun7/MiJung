#pragma once
#include "enemy.h"

class dragon : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	dragon();
	~dragon();
};

