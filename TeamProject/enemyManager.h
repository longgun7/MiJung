#pragma once
#include "gameNode.h"
#include "skeleton.h"
#include "spearMan.h"

#define MAXSKELETON 20

class enemyManager : public gameNode
{
private:

	typedef vector<skeleton*> vSkeleton;					// skeleton�� ��� ���� ����
	typedef vector<skeleton*>::iterator viSkeleton;			// ���� �������� iterator ����

	typedef vector<spearMan*> vSpearMan;
	typedef vector<spearMan*>::iterator viSpearMan;

private:

	vSkeleton _vSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	viSkeleton _viSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	vSpearMan _vSpearMan;
	viSpearMan _viSpearMan;

	skeleton* _skeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����

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

