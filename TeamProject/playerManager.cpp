#include "stdafx.h"
#include "playerManager.h"


HRESULT playerManager::init()
{
	
	//아타호 init()
	_ataho = new player;
	_ataho->init();
	
	//스마슈 init()	
	_smasyu = new player2;
	_smasyu->init();

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

	//인벤토리
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->update();
	}
}

void playerManager::render()
{
	//플레이어
	_ataho->render();
	_smasyu->render();

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

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
