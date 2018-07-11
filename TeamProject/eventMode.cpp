#include "stdafx.h"
#include "eventMode.h"


HRESULT eventMode::init()
{
	SOUNDMANAGER->addSound("³«»ç", "falling.bmp", true, false);
	_pm = SCENEMANAGER->getPlayerManagerLink();
	return S_OK;
}

void eventMode::update()
{
	if (_pm->getPlayer()->getIsJumping() == true)
	{
		SOUNDMANAGER->play("³«»ç", 1.0f);
	}
}

void eventMode::render()
{
	
}

void eventMode::release()
{
	
}

eventMode::eventMode()
{
}


eventMode::~eventMode()
{
}
