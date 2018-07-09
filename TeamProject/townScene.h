#pragma once
#include"gameNode.h"
class playerManager;
class enemyManager;
class itemManager;

class townScene : public gameNode
{
private:
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;
public:
	townScene();
	~townScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
};

