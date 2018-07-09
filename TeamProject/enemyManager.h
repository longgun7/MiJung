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

	//vFildSkeleton _vFildSkeleton;		// 벡터를 사용하기 위한 _vSkeleton 선언
	//viFildSkeleton _viFildSkeleton;		// 벡터를 사용하기 위한 _viSkeleton 선언

	playerManager* _pm;
	
	fildSkeleton* _fildSkeleton;		// 스켈레톤 함수를 사용하기 위해 선언
	
	int _randNum;
	int _enemyIndex;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy(float x ,float y);						// 적 배치 함수
	void setDirection(int index, DIRECTION direction);		// 몇번째 적 상태를 넣어주는 함수
	void hitEnemy(int index, int damge);					// 몇번째 애가 데미지를 받았는지
	void hitPlayer();										// 플레이어한테 데미지 주는 함수
	void randEnemy();										// 무작위로 적 생성되게 하는 함수

	vector<enemy*>			 getVEnmey() { return _vEnemy; }
	vector<enemy*>::iterator getVIEnmey() { return _viEnemy; }

	void AdressLinkPlayerManager(playerManager* pm) { _pm = pm; }

	enemyManager();
	~enemyManager();
};