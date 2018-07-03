#pragma once
#include "gameNode.h"
#include "skeleton.h"
#include "spearMan.h"

#define MAXSKELETON 20

class enemyManager : public gameNode
{
private:

	typedef vector<skeleton*> vSkeleton;					// skeleton을 담는 벡터 선언
	typedef vector<skeleton*>::iterator viSkeleton;			// 벡터 접근자인 iterator 선언

	typedef vector<spearMan*> vSpearMan;
	typedef vector<spearMan*>::iterator viSpearMan;

private:

	vSkeleton _vSkeleton;		// 벡터를 사용하기 위한 _vSkeleton 선언
	viSkeleton _viSkeleton;		// 벡터를 사용하기 위한 _viSkeleton 선언

	vSpearMan _vSpearMan;
	viSpearMan _viSpearMan;

	skeleton* _skeleton;		// 스켈레톤 함수를 사용하기 위해 선언

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSkeleton();
	void setSpearMan();

	enemyManager();
	~enemyManager();
};

