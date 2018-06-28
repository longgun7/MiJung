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
	


	return S_OK;
}

void playerManager::update()
{
	_ataho->update();
	_smasyu->update();
}

void playerManager::render()
{
	_ataho->render();
	_smasyu->render();
}

void playerManager::release()
{
	_ataho->release();
	_smasyu->release();
}

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
