#pragma once
#include "gameNode.h"
#include "player.h"
#include "player2.h"

class playerManager :public gameNode
{
private:
	player * _ataho;
	player2* _smasyu;
public:

	HRESULT init();
	void update();
	void render();
	void release();

	playerManager();
	~playerManager();
};

