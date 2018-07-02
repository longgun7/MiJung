#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init(void)
{
	gameNode::init(true);

	//씬 추가
	sceneAdd();
	//플레이어매니저 
	_PM = new playerManager;
	_PM->init();

	_im = new itemManager;
	_im->init();

	
	SCENEMANAGER->changeScene("스타트씬");

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();

	_PM->release();
}

void playGround::update(void)
{
	gameNode::update();

	_PM->update();

	_im->update();

	SCENEMANAGER->update();

}

void playGround::render(void)
{

	//흰색도화지 한 장 깔아둔다
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== 이 위로는 건드리지 말자 ==============

	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());

	_PM->render();

	_im->render();

	//================이 밑으로도 건드리지 말자 =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("엔드씬", new endScene);

}

