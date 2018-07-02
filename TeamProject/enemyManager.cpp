#include "stdafx.h"
#include "enemyManager.h"


HRESULT enemyManager::init()
{

	for (int i = 0; i < MAXSKELETON; i++)
	{
		_skeleton = new skeleton;										// _skeleton �Ҵ�
		_skeleton->init();												// _skeleton.init�Լ� ȣ��
		_skeleton->setSkeleton(RND->getInt(1000), RND->getInt(750));	// ���̷����� x : 0 ~ 1000, y : 0 ~ 750���̿� �����ϰ� �Ѹ���.

		_vSkeleton.push_back(_skeleton);								// ���Ϳ� ��´�
	}

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->update();
	}

}

void enemyManager::render()
{
	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->render();
	}
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
