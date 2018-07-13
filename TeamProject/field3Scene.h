#pragma once
#include "gameNode.h"
#include "playMap.h"
#include "fildSkeleton.h"
#include <vector>

class playerManager;
class enemyManager;
class itemManager;

class field3Scene : public gameNode
{
private:
	vector<fildSkeleton>			_vSkeleton;
	vector<fildSkeleton>::iterator	_viSkeleton;

	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;
	playMap* _map;
public:
	field3Scene();
	~field3Scene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
	void fieldSettingEnemy(void);

	void sceneChange(void);
};

