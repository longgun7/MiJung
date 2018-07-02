#pragma once
#include "gameNode.h"
#include "skeleton.h"

#define MAXSKELETON 20

class enemyManager : public gameNode
{
private:

	typedef vector<skeleton*> vSkeleton;					// skeleton�� ��� ���� ����
	typedef vector<skeleton*>::iterator viSkeleton;			// ���� �������� iterator ����

private:

	vSkeleton _vSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	viSkeleton _viSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	skeleton* _skeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	enemyManager();
	~enemyManager();
};

