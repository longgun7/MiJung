#pragma once
#include "gameNode.h"
#include "playerManager.h"
class eventMode :	public gameNode
{
	playerManager* _pm;
public:
	HRESULT init();
	void update();
	void render();
	void release();

	
	eventMode();
	~eventMode();
};

