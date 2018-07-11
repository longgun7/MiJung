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

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);
	SCENEMANAGER->addScene("������", new mapToolScene);
	SCENEMANAGER->changeScene("��ŸƮ��");
	_psm = new playSceneManager;
	_psm->init();
	
	_startScene = new startScene;
	_startScene->init();
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
	SCENEMANAGER->update();
	if (!_startScene->getIsPlay())_startScene->update();
	if(_startScene->getIsPlay()) _psm->update();
	
	
	
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

	
	if (_startScene->getIsPlay())
	{
		_psm->render();
	}
	SCENEMANAGER->render();
	
	TIMEMANAGER->render(CAMERA->getCameraDC());

	//================�� �����ε� �ǵ帮�� ���� =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}



