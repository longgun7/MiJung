#include "stdafx.h"
#include "eventManager.h"


HRESULT eventManager::init()
{
	_pm = new playerManager;
	_pm->init();
	return S_OK;
}

void eventManager::render()
{
	_pm->render();
}

void eventManager::update()
{
	_pm->update();
}

void eventManager::release()
{
}

eventManager::eventManager()
{
}


eventManager::~eventManager()
{
}
