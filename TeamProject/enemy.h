#pragma once
#include "gameNode.h"

class enemy :public gameNode
{

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	enemy();
	~enemy();

};

