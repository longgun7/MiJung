#include "stdafx.h"
#include "playerManager.h"


HRESULT playerManager::init()
{
	
	//��Ÿȣ init()
	_ataho = new player;
	_ataho->init();
	
	//������ init()	
	_smasyu = new player2;
	_smasyu->init();

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

	//�κ��丮
	for (_viInven = _vInven.begin(); _viInven != _vInven.end(); ++_viInven)
	{
		(*_viInven)->update();
	}
}

void playerManager::render()
{
	//�÷��̾�
	_ataho->render();
	_smasyu->render();

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

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
