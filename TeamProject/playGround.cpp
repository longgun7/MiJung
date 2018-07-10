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

	SCENEMANAGER->addScene("½ºÅ¸Æ®¾À", new startScene);
	SCENEMANAGER->addScene("¿£µå¾À", new endScene);
	SCENEMANAGER->addScene("¸ÊÅø¾À", new mapToolScene);
	SCENEMANAGER->changeScene("½ºÅ¸Æ®¾À");
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

	//Èò»öµµÈ­Áö ÇÑ Àå ±ò¾ÆµÐ´Ù
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(CAMERA->getCameraDC(), brush);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, PATCOPY);
	SelectObject(CAMERA->getCameraDC(), oldbrush);
	DeleteObject(brush);

	//============== ÀÌ À§·Î´Â °Çµå¸®Áö ¸»ÀÚ ==============

	
	if (_startScene->getIsPlay())
	{
		_psm->render();
	}
	SCENEMANAGER->render();
	
	TIMEMANAGER->render(CAMERA->getCameraDC());

	//================ÀÌ ¹ØÀ¸·Îµµ °Çµå¸®Áö ¸»ÀÚ =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}



