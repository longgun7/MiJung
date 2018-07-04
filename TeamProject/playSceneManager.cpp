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

	SCENEMANAGER->changeScene("��ŸƮ��");

	//�÷��̾�Ŵ��� 
	_pm = new playerManager;
	_pm->init();

	_im = new itemManager;
	_im->init();

	_em = new enemyManager;
	_em->init();

	//��Ÿȣ�� ���ʹ� �Ŵ��� ���漱��



	//���漱��
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
		SCENEMANAGER->changeScene("Ÿ���");
		_pm->getPlayer()->setScene(FIELDMODE,WINSIZEX/2,WINSIZEY/2, DOWN);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE, WINSIZEX / 2, WINSIZEY / 2 - 50,S_DOWN);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("��Ʋ��");
		_pm->getPlayer()->setScene(BATTLEMODE, 100, 400, FIGHTREADY);
		_pm->getPlayer2()->setSceneMode(S_BATTLEMODE, 100, 300, S_FIGHTREADY);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("�ʵ��");
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

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);
	SCENEMANAGER->addScene("���¾�", new statusScene);
	SCENEMANAGER->addScene("Ÿ���", new townScene);
	SCENEMANAGER->addScene("�ʵ��", new fieldScene);
	SCENEMANAGER->addScene("��Ʋ��", new battleScene);
	SCENEMANAGER->addScene("������", new barScnen);
	SCENEMANAGER->addScene("������", new mapToolScene);
	SCENEMANAGER->addScene("�÷��̾�", new playScene);

}