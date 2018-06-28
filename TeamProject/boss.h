#pragma once
#include "gameNode.h"

class boss : public gameNode
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	boss();
	~boss();
};

