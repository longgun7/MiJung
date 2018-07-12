#pragma once
#include "progressBar.h"
#include "gameNode.h"
#include "startScene.h"
#include "endScene.h"
#include"playScene.h"
#include"statusScene.h"
#include"townScene.h"
#include"fieldScene.h"
#include"field2Scene.h"
#include"field3Scene.h"
#include"battleScene.h"
#include"eventScene.h"
#include"barScnen.h"
class playerManager;
class enemyManager;
class itemManager;

class playSceneManager : public gameNode
{
private:
	playerManager * _pm;
	itemManager* _im;
	enemyManager* _em;
	bool _isStatus;
	string _nowSong;
	string _beforeScene;
	//플레이어 1,2 프로그래스 바
	progressBar* _hp1;
	progressBar* _hp2;
	progressBar* _mp1;
	progressBar* _mp2;
	progressBar* _exp1;
	progressBar* _exp2;

	float _savePlayerPosX, _savePlayerPosY;
	bool _isGoFieldScene;

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

	void renderProgressBar(void);
	void updateProgressBar(void);
};

