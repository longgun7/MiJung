#pragma once
#include "gameNode.h"
#include "playerManager.h"

class eventMode :	public gameNode
{
	playerManager* _pm;

	int _soundFrame;
	int _alphaNum;

public:
	HRESULT init();
	void update();
	void render();
	void release();

	
	eventMode();
	~eventMode();
};

