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
	_pm = new playerManager;
	_pm->init();

	_im = new itemManager;
	_im->init();
	
	_em = new enemyManager;
	_em->init();

	//아타호와 에너미 매니저 전방선언
	_em->setPlayerAddressLink(_pm->getPlayer());
	SCENEMANAGER->changeScene("스타트씬");
	
	//전방선언
	_pm->itemManagerAdressLink(_im);
	_pm->getPlayer()->EnemyManagerAdressLink(_em);
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

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		for (int i = 0; i < _em->getSpearMan().size(); ++i)
		{
			_em->getSpearMan()[i]->setHitMotion(SPEAR_MAN_HIT);
		}
	}
	SCENEMANAGER->update();
}

void playGround::render(void)
{

	//흰색도화지 한 장 깔아둔다
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	//============== 이 위로는 건드리지 말자 ==============

	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());

	_pm->render();
	_em->render();

	_im->render();

	TIMEMANAGER->render(CAMERA->getCameraDC());


	//================이 밑으로도 건드리지 말자 =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}

void playGround::sceneAdd(void)
{

	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("엔드씬", new endScene);

}

