#pragma once
#include "gameNode.h"
#include "skeleton.h"
#include "spearMan.h"

#define MAXSKELETON 20

class player;
class player2;

class enemyManager : public gameNode
{
private:

	typedef vector<skeleton*> vSkeleton;					// skeleton을 담는 벡터 선언
	typedef vector<skeleton*>::iterator viSkeleton;			// 벡터 접근자인 iterator 선언

	typedef vector<spearMan*> vSpearMan;					// spearMan을 담는 벡터 선언
	typedef vector<spearMan*>::iterator viSpearMan;			// 벡터 접근자는 iterator 선언 

private:

	vSkeleton _vSkeleton;		// 벡터를 사용하기 위한 _vSkeleton 선언
	viSkeleton _viSkeleton;		// 벡터를 사용하기 위한 _viSkeleton 선언

	vSpearMan _vSpearMan;
	viSpearMan _viSpearMan;

	player* _ataho;
	player2* _smasu;
	skeleton* _skeleton;		// 스켈레톤 함수를 사용하기 위해 선언
	spearMan * _spearMan;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSkeleton();
	void setSpearMan();

	void hitDamge();
	void hitSpearMan(int index, int damage);

	void setPlayerAddressLink(player* _player) { _ataho = _player; }
	void setPlayer2AddressLink(player2* _player2) { _smasu = _player2; }
	vector<spearMan*> getSpearMan()
	{
		for (int i = 0; i < _vSpearMan.size(); ++ i)
		{
			return _vSpearMan;
		}
	}
	enemyManager();
	~enemyManager();
};