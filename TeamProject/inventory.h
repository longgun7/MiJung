#pragma once
#include "gameNode.h"
#include <vector>




class inventory :public gameNode
{
private:
	int _att;
	int _luck;
	int _cri;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	void setWeapon(int att, int luck, int cri);
	inventory();
	~inventory();
};

