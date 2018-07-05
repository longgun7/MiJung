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

	vector<enemy*>			 _vEnemy;
	vector<enemy*>::iterator _viEnemy;

private:

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

	void setEnmey();
	void setPlayerAddressLink(player* _player) { _ataho = _player; }
	void setPlayer2AddressLink(player2* _player2) { _smasu = _player2; }
	void hitEnemy(int index, int damage);

	vector<enemy*>			 getVEnmey() { return _vEnemy; }
	vector<enemy*>::iterator getVIEnmey() { return _viEnemy; }

	enemyManager();
	~enemyManager();
};