#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"

HRESULT playerManager::init()
{
	
	//��Ÿȣ init()
	_ataho = new player;
	_ataho->init();
	
	//������ init()	
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());

	//�κ��丮 init()
	for (int i = 0; i < 2; i++)
	{
		_inven = new inventory;
		_inven->init();

		_vInven.push_back(_inven);
	}

	return S_OK;
}

void playerManager::update()
{
	//�÷��̾�
	_ataho->update();
	_smasyu->update();
	_smasyu->angleManager(_ataho->getX(), _ataho->getY());
	eventMode(); //��Ÿȣ ������ �� �������� ���� �������� �ϴ� �Լ�
	//�κ��丮
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->update();
	}
}

void playerManager::render()
{
	//�÷��̾�
	if (_ataho->getY() > _smasyu->getY())
	{
		_smasyu->render();
		_ataho->render();
	}
	else
	{
		_ataho->render();
		_smasyu->render();
	}
	//�κ��丮
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->render();
	}
}

void playerManager::release()
{
	//�÷��̾�
	_ataho->release();
	_smasyu->release();

	//�κ��丮
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->release();
	}
}

void playerManager::eventMode()
{
	if (_ataho->getSCENEMODE() == EVENTMODE)
	{
		if (_ataho->getIsJumping() == true)
		{
			_smasyu->setIsJumping(true);
		}
	}
}

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
