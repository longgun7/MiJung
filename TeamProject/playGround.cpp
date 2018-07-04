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
	_psm = new playSceneManager;
	_psm->init();

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();
	_psm->release();
	
}

void playGround::update(void)
{
	gameNode::update();
	_psm->update();
	

	_pm->update();
	_em->update();

	_im->update();

	SCENEMANAGER->update();
}

void playGround::render(void)
{

	//�����ȭ�� �� �� ��Ƶд�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(CAMERA->getCameraDC(), brush);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, PATCOPY);
	SelectObject(CAMERA->getCameraDC(), oldbrush);
	DeleteObject(brush);

	//============== �� ���δ� �ǵ帮�� ���� ==============

	
	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());

	_im->render();

	_pm->render();
	_em->render();

	TIMEMANAGER->render(CAMERA->getCameraDC());
	_psm->render();

	//================�� �����ε� �ǵ帮�� ���� =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}



