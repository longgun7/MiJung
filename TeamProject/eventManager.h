#pragma once
#include "gameNode.h"
#include "playerManager.h"

class eventManager :public gameNode
{
	playerManager* _pm;

public:
		
	HRESULT init();
	void render();
	void update();
	void release();
	
	eventManager();
	~eventManager();
};

