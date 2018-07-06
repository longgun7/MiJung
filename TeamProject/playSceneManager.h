#pragma once
#include "progressBar.h"
#include "gameNode.h"
#include "startScene.h"
#include "endScene.h"
#include"playScene.h"
#include"statusScene.h"
#include"townScene.h"
#include"fieldScene.h"
#include"battleScene.h"
#include"barScnen.h"
#include"mapToolScene.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"


class playSceneManager : public gameNode
{
private:
	playerManager * _pm;
	itemManager* _im;
	enemyManager* _em;

	bool _isStatus;

	//플레이어 1,2 프로그래스 바
	progressBar* _hp1;
	progressBar* _hp2;
	progressBar* _mp1;
	progressBar* _mp2;
	progressBar* _exp1;
	progressBar* _exp2;
public:
	playSceneManager();
	~playSceneManager();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void sceneAdd(void);
	void basicUI(void);
	void fontUI(void);
	void setProgressBar(void);
};

