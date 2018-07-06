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

	basicUI();
	
	//�÷��̾�Ŵ��� 
	_pm = new playerManager;
	_pm->init();

	_im = new itemManager;
	_im->init();

	_em = new enemyManager;
	_em->init();

	_isStatus = false;
	

	
	//��Ÿȣ�� ���ʹ� �Ŵ��� ���漱��

	//���漱��
	_pm->itemManagerAdressLink(_im);
	_em->AdressLinkPlayerManager(_pm);

	
	_pm->getPlayer()->setEnemyManagerAdressLink(_em);
	_pm->getPlayer2()->setEnemyManagerAdressLink(_em);

	setProgressBar();


	return S_OK;
}

void playSceneManager::release(void)
{
	_pm->release();
	_em->release();
}

void playSceneManager::update(void)
{
	
	
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
	
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("������");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		
		SCENEMANAGER->changeScene("������");
	}
	if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{

		if (!_isStatus) { SCENEMANAGER->changeScene("���¾�"); _isStatus = true; }
		else if (_isStatus) { _isStatus = false; }	//���߿� �ڽ��� �ִ������� ���ư�����
		
	}
	_hp1->update();
	_hp1->setGauge(_pm->getPlayer()->getAttribute().currentHp, _pm->getPlayer()->getAttribute().maxHp);
	_hp2->update();
	_hp2->setGauge(_pm->getPlayer()->getAttribute().currentHp, _pm->getPlayer()->getAttribute().maxHp);
	_mp1->update();
	_mp1->setGauge(_pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	_mp2->update();
	_mp2->setGauge(_pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	_exp1->update();
	_exp1->setGauge(_pm->getPlayer()->getAttribute().currentExp, _pm->getPlayer()->getAttribute().maxExp);
	_exp2->update();
	_exp2->setGauge(_pm->getPlayer()->getAttribute().currentExp, _pm->getPlayer()->getAttribute().maxExp);
	
}

void playSceneManager::render(void)
{
	
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("�⺻status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);

	_hp1->render();
	_hp2->render();
	_mp1->render();
	_mp2->render();
	_exp1->render();
	_exp2->render();

	if (_pm->getPlayer()->getSCENEMODE() == FIELDMODE || _pm->getPlayer()->getSCENEMODE() == BATTLEMODE)
	{
		_pm->render();
		_em->render();
		_im->render();
	}
	
	fontUI();
	
}

void playSceneManager::sceneAdd(void)
{

	SCENEMANAGER->addScene("���¾�", new statusScene);
	SCENEMANAGER->addScene("Ÿ���", new townScene);
	SCENEMANAGER->addScene("�ʵ��", new fieldScene);
	SCENEMANAGER->addScene("��Ʋ��", new battleScene);
	SCENEMANAGER->addScene("������", new barScnen);
	SCENEMANAGER->addScene("������", new mapToolScene);
	SCENEMANAGER->addScene("�÷��̾�", new playScene);

}

void playSceneManager::basicUI(void)
{
	IMAGEMANAGER->addFrameImage("HP", "image/ui/UI��ư.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MP", "image/ui/UI��ư.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EXP", "image/ui/UI��ư.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("HP")->setFrameX(0);
	IMAGEMANAGER->findImage("HP")->setFrameY(2);
	IMAGEMANAGER->findImage("MP")->setFrameX(1);
	IMAGEMANAGER->findImage("MP")->setFrameY(2);
	IMAGEMANAGER->findImage("EXP")->setFrameX(2);
	IMAGEMANAGER->findImage("EXP")->setFrameY(2);

	
}

void playSceneManager::fontUI(void)
{
	HFONT font, ofont;

	char charName[] = "��Ÿȣ";
	char charName1[] = "������";
	
	char str1[] = "����";
	
	char currentLevel1[128];
	sprintf_s(currentLevel1, "%d", _pm->getPlayer()->getAttribute().level);
	char currentLevel2[128];
	sprintf_s(currentLevel2, "%d", _pm->getPlayer2()->getAttribute().level);

	char currentHP1[128];	//��Ÿȣ ����ü�� / �ִ�ü��
	sprintf_s(currentHP1, "%d / %d", _pm->getPlayer()->getAttribute().currentHp, _pm->getPlayer()->getAttribute().maxHp);
	char currentHP2[128];	//������ ����ü�� / �ִ�ü��
	sprintf_s(currentHP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentHp, _pm->getPlayer2()->getAttribute().maxHp);

	char currentMP1[128];	//��Ÿȣ ���縶�� / �ִ븶��
	sprintf_s(currentMP1, "%d / %d", _pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	char currentMP2[128];	//������ ���縶�� / �ִ븶��
	sprintf_s(currentMP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentMp, _pm->getPlayer2()->getAttribute().maxMp);

	char currentEXP1[128];	//��Ÿȣ �������ġ / �ִ����ġ
	sprintf_s(currentEXP1, "%d / %d", _pm->getPlayer()->getAttribute().currentExp, _pm->getPlayer()->getAttribute().maxExp);
	char currentEXP2[128];	//������ �������ġ / �ִ����ġ
	sprintf_s(currentEXP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentExp, _pm->getPlayer2()->getAttribute().maxExp);

	char currentAtk1[128];
	sprintf_s(currentAtk1, "%d", _pm->getPlayer()->getAttribute().atk);
	char currentAtk2[128];
	sprintf_s(currentAtk2, "%d", _pm->getPlayer2()->getAttribute().atk);

	char currentDef1[128];
	sprintf_s(currentDef1, "%d", _pm->getPlayer()->getAttribute().def);
	char currentDef2[128];
	sprintf_s(currentDef2, "%d", _pm->getPlayer2()->getAttribute().def);

	char currentSpeed1[128];
	sprintf_s(currentSpeed1, "%d", _pm->getPlayer()->getAttribute().speed);
	char currentSpeed2[128];
	sprintf_s(currentSpeed2, "%d", _pm->getPlayer2()->getAttribute().speed);
	char currentLuck1[128];
	sprintf_s(currentLuck1, "%d", _pm->getPlayer()->getAttribute().luck);
	char currentLuck2[128];
	sprintf_s(currentLuck2, "%d", _pm->getPlayer2()->getAttribute().luck);

	font = CreateFont(20, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY - 150, charName, strlen(charName));
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY - 100, charName1, strlen(charName1));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 175, WINSIZEY - 75, str1, strlen(str1));

	
	if(_isStatus)//����â�� ������ 
	{
		if(IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX()==0)
		{
			TextOut(CAMERA->getCameraDC(), 480, 45, currentLevel1, strlen(currentLevel1));
			TextOut(CAMERA->getCameraDC(), 480, 85, currentHP1, strlen(currentHP1));
			TextOut(CAMERA->getCameraDC(), 480, 125, currentMP1, strlen(currentMP1));
			TextOut(CAMERA->getCameraDC(), 480, 165, currentEXP1, strlen(currentEXP1));
			TextOut(CAMERA->getCameraDC(), 480, 205, currentAtk1, strlen(currentAtk1));
			TextOut(CAMERA->getCameraDC(), 480, 245, currentDef1, strlen(currentDef1));
			TextOut(CAMERA->getCameraDC(), 480, 285, currentSpeed1, strlen(currentSpeed1));
			TextOut(CAMERA->getCameraDC(), 480, 325, currentLuck1, strlen(currentLuck1));
		}
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)
		{
			TextOut(CAMERA->getCameraDC(), 480, 45, currentLevel2, strlen(currentLevel2));
			TextOut(CAMERA->getCameraDC(), 480, 85, currentHP2, strlen(currentHP2));
			TextOut(CAMERA->getCameraDC(), 480, 125, currentMP2, strlen(currentMP2));
			TextOut(CAMERA->getCameraDC(), 480, 165, currentEXP2, strlen(currentEXP2));
			TextOut(CAMERA->getCameraDC(), 480, 205, currentAtk2, strlen(currentAtk2));
			TextOut(CAMERA->getCameraDC(), 480, 245, currentDef2, strlen(currentDef2));

			TextOut(CAMERA->getCameraDC(), 480, 285, currentSpeed2, strlen(currentSpeed2));
			TextOut(CAMERA->getCameraDC(), 480, 325, currentLuck2, strlen(currentLuck2));
		}
	}
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	HFONT font2, ofont2;
	font2 = CreateFont(15, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont2 = (HFONT)SelectObject(CAMERA->getCameraDC(), font2);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	TextOut(CAMERA->getCameraDC(), 250, WINSIZEY - 160, currentHP1, strlen(currentHP1));
	TextOut(CAMERA->getCameraDC(), 250, WINSIZEY - 110, currentHP2, strlen(currentHP2));

	TextOut(CAMERA->getCameraDC(), 390, WINSIZEY - 160, currentMP1, strlen(currentMP1));
	TextOut(CAMERA->getCameraDC(), 390, WINSIZEY - 110, currentMP2, strlen(currentMP2));

	TextOut(CAMERA->getCameraDC(), 540, WINSIZEY - 160, currentEXP1, strlen(currentEXP1));
	TextOut(CAMERA->getCameraDC(), 540, WINSIZEY - 110, currentEXP2, strlen(currentEXP2));

	SelectObject(CAMERA->getCameraDC(), ofont2);
	DeleteObject(font2);
}
//���α׷����� ����
void playSceneManager::setProgressBar(void)
{
	_hp1 = new progressBar;
	_hp1->init(210, WINSIZEY - 150, 137, 12);

	_hp2 = new progressBar;
	_hp2->init(210, WINSIZEY - 100, 137, 12);

	_mp1 = new progressBar;
	_mp1->init(355, WINSIZEY - 150, 137, 12);

	_mp2 = new progressBar;
	_mp2->init(355, WINSIZEY - 100, 137, 12);

	_exp1 = new progressBar;
	_exp1->init(500, WINSIZEY - 150, 137, 12);

	_exp2 = new progressBar;
	_exp2->init(500, WINSIZEY - 100, 137, 12);
	
}
