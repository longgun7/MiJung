#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	enemy();
	~enemy();
};

