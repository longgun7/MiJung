#include "stdafx.h"
#include "playerManager.h"


HRESULT playerManager::init()
{
	
	//¾ÆÅ¸È£ init()
	_ataho = new player;
	_ataho->init();
	
	//½º¸¶½´ init()	
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
