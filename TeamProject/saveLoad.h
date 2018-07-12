#pragma once
#include "gameNode.h"

class playerManager;

class saveLoad : public gameNode
{
	playerManager* _pm;
public:

	HRESULT init();
	void save(int index);
	void loadInt(int index);
	saveLoad();
	~saveLoad();
};

