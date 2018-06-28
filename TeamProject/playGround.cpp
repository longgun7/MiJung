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

	SCENEMANAGER->changeScene("��ŸƮ��");

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

	//�����ȭ�� �� �� ��Ƶд�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//============== �� ���δ� �ǵ帮�� ���� ==============

	SCENEMANAGER->render();

	SetTextColor(getMemDC(), RGB(255, 0, 255));
	TIMEMANAGER->render(getMemDC());

	//================�� �����ε� �ǵ帮�� ���� =============
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);

}

