#pragma once
#include "gameNode.h"
#include "playMap.h"
#include <vector>

class playerManager;
class enemyManager;
class itemManager;

class field2Scene : public gameNode
{
private:
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;
	playMap* _map;

public:
	field2Scene();
	~field2Scene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);

	void sceneChange(void);

};

