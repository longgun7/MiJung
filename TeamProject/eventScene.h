#pragma once
#include "gameNode.h"
#include "playMap.h"

class playerManager;
class eventScene : public gameNode
{
private:
	//eventMode * _event;
	playMap * _map;
	playerManager*	_pm;

	int _soundFrame;
	int _alphaNum;
	bool _isEventMode;
public:
	eventScene();
	~eventScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void sceneChange(void);
};

