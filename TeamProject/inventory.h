#pragma once
#include "gameNode.h"
#include <vector>




class inventory :public gameNode
{
private:

public:

	HRESULT init();
	void update();
	void render();
	void release();

	void set();
	inventory();
	~inventory();
};

