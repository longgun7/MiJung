#pragma once
#include "singletonBase.h"
#include <map>

//씬을 위한 게임노드 전방선언
class gameNode;

//씬 간에 데이터 교환을 위한 클래스 전방선언
class playerManager;
class itemManager;
class enemyManager;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

private:
	static gameNode*	_currentScene;	//현재 씬
	mapSceneList		_mSceneList;

	playerManager* _pm;
	enemyManager* _em;
	itemManager* _im;

public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//씬 추가 함수
	gameNode* addScene(string sceneName, gameNode* scene);

	//씬 변경
	HRESULT changeScene(string sceneName);

	void setPlayerManagerLink(playerManager* pm) { _pm = pm; }
	playerManager* getPlayerManagerLink() { return _pm; }
	void setItemManagerLink(itemManager* im) { _im = im; }
	itemManager* getItemManagerLink() { return _im; }
	void setEnemyManagerLink(enemyManager* em) { _em = em; }
	enemyManager* getEnemyManagerLink() { return _em; }

	//현재 씬 이름이 무엇인지 받아오는 접근자
	string getSceneName();

};

