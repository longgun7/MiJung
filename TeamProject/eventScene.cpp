#include "stdafx.h"
#include "eventScene.h"


eventScene::eventScene()
{
}


eventScene::~eventScene()
{
}

HRESULT eventScene::init(void)
{
	_event = new eventMode;
	_event->init();
	
	return S_OK;
}

void eventScene::release(void)
{
	_event->release();

}

void eventScene::update(void)
{
	_event->update();

}

void eventScene::render(void)
{
	_event->render();
}
