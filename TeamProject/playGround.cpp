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

	SCENEMANAGER->changeScene("스타트씬");

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();


}

void playGround::update(void)
{
	gameNode::update();


	SCENEMANAGER->update();

}

void playGround::render(void)
{

	//흰색도화지 한 장 깔아둔다
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== 이 위로는 건드리지 말자 ==============

	SCENEMANAGER->render();

	SetTextColor(getMemDC(), RGB(255, 0, 255));
	TIMEMANAGER->render(getMemDC());

	//================이 밑으로도 건드리지 말자 =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("엔드씬", new endScene);

}

