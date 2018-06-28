#pragma once
#include "gameNode.h"

class enemyManager : public gameNode
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	enemyManager();
	~enemyManager();
};

