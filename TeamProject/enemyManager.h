#pragma once
#include "gameNode.h"
#include "fildSkeleton.h"
#include "enemys.h"

#define MAXSKELETON 20
#define PLAYMAPSIZEY 525 

class player;
class player2;

class enemyManager : public gameNode
{
private:

	typedef vector<fildSkeleton*> vFildSkeleton;					// skeleton을 담는 벡터 선언
	typedef vector<fildSkeleton*>::iterator viFildSkeleton;			// 벡터 접근자인 iterator 선언

	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;

private:

	vFildSkeleton _vFildSkeleton;		// 벡터를 사용하기 위한 _vSkeleton 선언
	viFildSkeleton _viFildSkeleton;		// 벡터를 사용하기 위한 _viSkeleton 선언

	player* _ataho;
	player2* _smasu;
	
	fildSkeleton* _fildSkeleton;		// 스켈레톤 함수를 사용하기 위해 선언
	
	int _randNum;
	int _interval;

	int _enemyIndex;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy();

	void setPlayerAddressLink(player* _player) { _ataho = _player; }
	void setPlayer2AddressLink(player2* _player2) { _smasu = _player2; }

	enemyManager();
	~enemyManager();
};