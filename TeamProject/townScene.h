#pragma once
#include"gameNode.h"
#include "playMap.h"
#include "npc.h"

class playerManager;
class enemyManager;
class itemManager;

class townScene : public gameNode
{
private:
	playerManager *		_pm;
	enemyManager *		_em;
	itemManager*		_im;
	npc*				_npc;
	playMap*			_map;

	bool _isTemp;

public:
	townScene();
	~townScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void npcTileSetting();
	void npcCollision();

	void fontUI(void);
	void sceneChange(void);
	
};

