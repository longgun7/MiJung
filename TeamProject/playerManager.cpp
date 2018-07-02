#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"

HRESULT playerManager::init()
{
	
	//아타호 init()
	_ataho = new player;
	_ataho->init();
	
	//스마슈 init()	
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());

	//인벤토리 init()
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
	//플레이어
	_ataho->update();
	_smasyu->update();
	_smasyu->angleManager(_ataho->getX(), _ataho->getY());
	eventMode(); //아타호 떨어질 때 스마슈도 같이 떨어지게 하는 함수
	//인벤토리
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->update();
	}
}

void playerManager::render()
{
	//플레이어
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
	//인벤토리
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->render();
	}
}

void playerManager::release()
{
	//플레이어
	_ataho->release();
	_smasyu->release();

	//인벤토리
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
