#pragma once
#include "gameNode.h"
#include "startScene.h"
#include "endScene.h"
#include"mapToolScene.h"
#include "playSceneManager.h"

//환세이취호전 시작
class playGround : public gameNode
{
private:
	playSceneManager * _psm;
	startScene* _startScene;

	bool _isPlay;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void musicInit();

	playGround();
	~playGround();
};

