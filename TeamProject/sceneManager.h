#pragma once
#include "singletonBase.h"
#include <map>

//���� ���� ���ӳ�� ���漱��
class gameNode;

//�� ���� ������ ��ȯ�� ���� Ŭ���� ���漱��
class playerManager;
class itemManager;
class enemyManager;
class playMap;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>				mapSceneList;
	typedef map<string, gameNode*>::iterator	mapSceneIter;

private:
	static gameNode*	_currentScene;	//���� ��
	mapSceneList		_mSceneList;

	playerManager* _pm;
	enemyManager* _em;
	itemManager* _im;
	playMap*		_map;

	float _px, _py;

	string _sceneName;
	bool _isShop;
	bool _isChange;
	bool _isInHouseTalk;
	int _frameCount;
	int _alphaValue;
public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰� �Լ�
	gameNode* addScene(string sceneName, gameNode* scene);

	//�� ����
	HRESULT changeScene(string sceneName);

	//void setPlayerManagerLink(playerManager* pm) { _pm = pm; }
	playerManager* getPlayerManagerLink() { return _pm; }
	//void setItemManagerLink(itemManager* im) { _im = im; }
	itemManager* getItemManagerLink() { return _im; }
	//void setEnemyManagerLink(enemyManager* em) { _em = em; }
	enemyManager* getEnemyManagerLink() { return _em; }
	//void setCurrentSceneName(string sceneName) { _sceneName = sceneName; }
	playMap* getPlayMapLink() { return _map; }
	
	string getCurrentSceneName() { return _sceneName; }
	void setIsShop(bool isShop) { _isShop = isShop; }
	void setIsInHouseTalk(bool isInHouseTalk) { _isInHouseTalk = isInHouseTalk; }
	bool getIsInHouseTalk() { return _isInHouseTalk; }
	bool getIsShop() { return _isShop; }
	
	void setPlayerScenePosition(float x, float y) { _px = x, _py = y; }
	POINT getPlayerScenePosition() { return PointMake(_px, _py); }

	//���� �� �̸��� �������� �޾ƿ��� ������
	string getSceneName();

};

