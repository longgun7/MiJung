#include "stdafx.h"
#include "playSceneManager.h"


playSceneManager::playSceneManager()
{
}


playSceneManager::~playSceneManager()
{
}

HRESULT playSceneManager::init(void)
{
	sceneAdd();

	SCENEMANAGER->changeScene("스타트씬");

	//플레이어매니저 
	_pm = new playerManager;
	_pm->init();

	_im = new itemManager;
	_im->init();

	_em = new enemyManager;
	_em->init();

	//아타호와 에너미 매니저 전방선언



	//전방선언
	_pm->itemManagerAdressLink(_im);
	return S_OK;
}

void playSceneManager::release(void)
{
	_pm->release();
	_em->release();
}

void playSceneManager::update(void)
{
	SCENEMANAGER->update();
	
	if (_pm->getPlayer()->getSCENEMODE() == FIELDMODE || _pm->getPlayer()->getSCENEMODE() == BATTLEMODE)
	{
		_pm->update();
		_em->update();
		_im->update();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("타운씬");
		_pm->getPlayer()->setScene(FIELDMODE,WINSIZEX/2,WINSIZEY/2, DOWN);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE, WINSIZEX / 2, WINSIZEY / 2 - 50,S_DOWN);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("배틀씬");
		_pm->getPlayer()->setScene(BATTLEMODE, 100, 400, FIGHTREADY);
		_pm->getPlayer2()->setSceneMode(S_BATTLEMODE, 100, 300, S_FIGHTREADY);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("필드씬");
		_pm->getPlayer()->setScene(FIELDMODE,WINSIZEX / 2, WINSIZEY / 2, DOWN);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE, WINSIZEX / 2, WINSIZEY / 2 - 50, S_DOWN);
	}

}

void playSceneManager::render(void)
{
	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());
	if (_pm->getPlayer()->getSCENEMODE() == FIELDMODE || _pm->getPlayer()->getSCENEMODE() == BATTLEMODE)
	{
		_pm->render();
		_em->render();
		_im->render();
	}
}

void playSceneManager::sceneAdd(void)
{

	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("엔드씬", new endScene);
	SCENEMANAGER->addScene("상태씬", new statusScene);
	SCENEMANAGER->addScene("타운씬", new townScene);
	SCENEMANAGER->addScene("필드씬", new fieldScene);
	SCENEMANAGER->addScene("배틀씬", new battleScene);
	SCENEMANAGER->addScene("술집씬", new barScnen);
	SCENEMANAGER->addScene("맵툴씬", new mapToolScene);
	SCENEMANAGER->addScene("플레이씬", new playScene);

}