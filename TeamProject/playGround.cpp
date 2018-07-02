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

	//�� �߰�
	sceneAdd();
	//�÷��̾�Ŵ��� 
	_PM = new playerManager;
	_PM->init();

	_im = new itemManager;
	_im->init();

	
	SCENEMANAGER->changeScene("��ŸƮ��");

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

	//�����ȭ�� �� �� ��Ƶд�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== �� ���δ� �ǵ帮�� ���� ==============

	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());

	_PM->render();

	_im->render();

	//================�� �����ε� �ǵ帮�� ���� =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);

}

