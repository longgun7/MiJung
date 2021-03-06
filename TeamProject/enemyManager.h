#pragma once
#include "gameNode.h"
#include "fildSkeleton.h"
#include "enemys.h"
#include "playerManager.h"
#include "gameEffect.h"

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
	gameEffect*	   _ge;
	fildSkeleton* _fildSkeleton;		// 스켈레톤 함수를 사용하기 위해 선언
	
	int _randNum;						// 적이 몇마리가 생성될지
	int _enemyIndex;					// 몇번째 적인지
	int _hitIndex;						// 몇번째 애가 공격했는지
	int _hitCount;						// 공격 모션을 길게해주는 카운트
	int _hitTume;						// 공격 텀
	image* _img;						// 데미지 수치 이미지
	int _randAttack;
	bool _attackEnd;
	bool _start;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy(float x ,float y);						// 적 배치 함수
	void hitEnemy(int index, int damge);					// 몇번째 애가 데미지를 받았는지
	void hitPlayer();										// 플레이어한테 데미지 주는 함수
	void randEnemy();										// 무작위로 적 생성되게 하는 함수
	void removeEnemy(int arrNum);							// 적을 지워주는 함수
	void setAttackEnd(bool attackEnd) { _attackEnd = attackEnd; }
	bool getAttackEnd() { return _attackEnd; }
	bool getStart() { return _start; }
	void setStart(bool start) { _start = start; }
	vector<enemy*>			 getVEnmey() { return _vEnemy; }			// 외부에서 에너미 벡터에 접근 가능하게 반환
	vector<enemy*>::iterator getVIEnmey() { return _viEnemy; }			// 외부에서 에너미 벡터 이터레이터에 접근 가능하게 반환

	void setAdressLinkPlayerManager(playerManager* pm) { _pm = pm; }		// 전방선언한 플레이어 매니저의 정보를 가져온다

	enemyManager();
	~enemyManager();
};