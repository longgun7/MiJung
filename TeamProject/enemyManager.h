#pragma once
#include "gameNode.h"
#include "fildSkeleton.h"
#include "enemys.h"
#include "playerManager.h"

#define MAXSKELETON 20
#define PLAYMAPSIZEY 525 

class playerManager;

class enemyManager : public gameNode
{
private:

	vector<enemy*>			 _vEnemy;
	vector<enemy*>::iterator _viEnemy;

private:

	//vFildSkeleton _vFildSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	//viFildSkeleton _viFildSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	playerManager* _pm;
	
	fildSkeleton* _fildSkeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����
	
	int _randNum;
	int _interval;

	int _enemyIndex;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnmey(float x ,float y);
	void hitEnemy(int index, int damage);

	vector<enemy*>			 getVEnmey() { return _vEnemy; }
	vector<enemy*>::iterator getVIEnmey() { return _viEnemy; }

	void AdressLinkPlayerManager(playerManager* pm) { _pm = pm; }

	enemyManager();
	~enemyManager();
};