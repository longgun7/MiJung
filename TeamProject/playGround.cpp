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
	_pm = new playerManager;
	_pm->init();

	_im = new itemManager;
	_im->init();
	
	_em = new enemyManager;
	_em->init();

	//��Ÿȣ�� ���ʹ� �Ŵ��� ���漱��
	
	SCENEMANAGER->changeScene("��ŸƮ��");
	
	//���漱��
	_pm->itemManagerAdressLink(_im);
	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();

	_pm->release();
	_em->release();
}

void playGround::update(void)
{
	gameNode::update();

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

	_pm->render();
	_em->render();

	_im->render();

	TIMEMANAGER->render(CAMERA->getCameraDC());


	//================�� �����ε� �ǵ帮�� ���� =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);

}

