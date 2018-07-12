#include "stdafx.h"
#include "playSceneManager.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"

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

	_isStatus = false;
	
	_map = new playMap;
	_map->init();
	
	
	//���漱��	
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();

	_pm->getPlayer()->setplayMapMemoryAddressLink(_map);


	setProgressBar();	//���α׷����� ����!

	return S_OK;
}

void playSceneManager::release(void)
{
	
}

void playSceneManager::update(void)
{
	_pm->update();
	_em->update();
	_im->update();
	
	sceneChange();
	battleSceneChange();
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("Ÿ���");
		_pm->getPlayer()->setSceneMode(FIELDMODE, DOWN);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE,S_DOWN);
		SOUNDMANAGER->stop(_nowSong);
		_nowSong = "TownTheMa";
		if (!SOUNDMANAGER->isPlaySound(_nowSong))
		{
			SOUNDMANAGER->play(_nowSong, 1.0f);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("��Ʋ��");
		_pm->getPlayer()->setSceneMode(BATTLEMODE, FIGHTREADY);
		_pm->getPlayer2()->setSceneMode(S_BATTLEMODE, S_FIGHTREADY);
		SOUNDMANAGER->stop(_nowSong);
		int randumSound;
		randumSound = RND->getInt(2);
		if (randumSound == 0)
		{
			_nowSong = "BattleTheMa1";
			if (!SOUNDMANAGER->isPlaySound(_nowSong))
			{
				SOUNDMANAGER->play(_nowSong, 1.0f);
			}
		}
		else if (randumSound == 1)
		{
			_nowSong = "BattleTheMa2";
			if (!SOUNDMANAGER->isPlaySound(_nowSong))
			{
				SOUNDMANAGER->play(_nowSong, 1.0f);
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("�ʵ��");
		_pm->getPlayer()->setSceneMode(FIELDMODE, DOWN);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_DOWN);
		SOUNDMANAGER->stop(_nowSong);
		_nowSong = "FiledTheMa";
		if (!SOUNDMANAGER->isPlaySound(_nowSong))
		{
			SOUNDMANAGER->play(_nowSong, 1.0f);
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("������");
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		SCENEMANAGER->changeScene("�̺�Ʈ��");
	}
	
	updateProgressBar();
	_map->setTilePos(_pm->getPlayer()->getRC(), OBJ_PLAYER1);
}

void playSceneManager::render(void)
{
	_map->render();
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("�⺻status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);

	renderProgressBar();	//���α׷����� ����

	
	_pm->render();
	_em->render();
	_im->render();
		
	// ������Ʈ ����
	_map->objRender();

	fontUI();
}

void playSceneManager::sceneAdd(void)
{

	SCENEMANAGER->addScene("���¾�", new statusScene);
	SCENEMANAGER->addScene("Ÿ���", new townScene);
	SCENEMANAGER->addScene("�ʵ��", new fieldScene);
	SCENEMANAGER->addScene("��Ʋ��", new battleScene);
	SCENEMANAGER->addScene("������", new barScnen);
	SCENEMANAGER->addScene("�̺�Ʈ��", new eventScene);
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
	IMAGEMANAGER->addFrameImage("��ų1", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ų2", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ų3", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ų4", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ų5", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
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
void playSceneManager::updateProgressBar(void)
{
	_hp1->update();
	_hp1->setGauge(_pm->getPlayer()->getAttribute().currentHp, _pm->getPlayer()->getAttribute().maxHp);
	_hp2->update();
	_hp2->setGauge(_pm->getPlayer2()->getAttribute().currentHp, _pm->getPlayer2()->getAttribute().maxHp);
	_mp1->update();
	_mp1->setGauge(_pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	_mp2->update();
	_mp2->setGauge(_pm->getPlayer2()->getAttribute().currentMp, _pm->getPlayer2()->getAttribute().maxMp);
	_exp1->update();
	_exp1->setGauge(_pm->getPlayer()->getAttribute().currentExp, _pm->getPlayer()->getAttribute().maxExp);
	_exp2->update();
	_exp2->setGauge(_pm->getPlayer2()->getAttribute().currentExp, _pm->getPlayer2()->getAttribute().maxExp);
}

void playSceneManager::renderProgressBar(void)
{
	_hp1->render();
	_hp2->render();
	_mp1->render();
	_mp2->render();
	_exp1->render();
	_exp2->render();
}

// ����(���� �ݵ�� �ʿ�)
void playSceneManager::sceneChange(void)
{	
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		if (_map->getCurrentTileName() == "field2Tile")
		{
			sceneMapPlayerSetting("field1Tile", 1235, 2000);
		}
		else if (_map->getCurrentTileName() == "event")
		{
			sceneMapPlayerSetting("field2Tile", 360, 2750);
		}
		if (_map->getCurrentTileName() == "field3Tile")
		{
			SCENEMANAGER->changeScene("�̺�Ʈ��");
			sceneMapPlayerSetting("event", 500, 1950);
		}
		if (SCENEMANAGER->getSceneName() == "Ÿ���")
		{
			SCENEMANAGER->changeScene("������");
			sceneMapPlayerSetting("InHouse", 500, 500);
		}
		break;

	case OBJ_DOWNPORTAL:
		if (_map->getCurrentTileName() == "field1Tile")
		{
			sceneMapPlayerSetting("field2Tile", 100, 100);
		}
		else if (_map->getCurrentTileName() == "field2Tile")
		{
			sceneMapPlayerSetting("event", 100, 100);
		}
		else if (SCENEMANAGER->getSceneName() == "�̺�Ʈ��")
		{
			SCENEMANAGER->changeScene("�ʵ��");
			sceneMapPlayerSetting("field3Tile", 100, 100);
		}
		if (SCENEMANAGER->getSceneName() == "������")
		{
			SCENEMANAGER->changeScene("Ÿ���");
			sceneMapPlayerSetting("town", 500, 500);
		}
		break;

	case OBJ_LEFTPORTAL:
		if (SCENEMANAGER->getSceneName() == "�ʵ��")
		{
			SCENEMANAGER->changeScene("Ÿ���");
			sceneMapPlayerSetting("town", 2310, 1050);
		}
		break;

	case OBJ_RIGHTPORTAL:
		if (SCENEMANAGER->getSceneName() == "Ÿ���")
		{
			SCENEMANAGER->changeScene("�ʵ��");
			sceneMapPlayerSetting("field1Tile", 100, 100);
		}
		break;

	}

	
}

void playSceneManager::sceneMapPlayerSetting(string loadMap, float x, float y)
{
	_pm->getPlayer()->setX(x);	_pm->getPlayer()->setY(y);
	_pm->getPlayer2()->setX(x);	_pm->getPlayer2()->setY(y);

	if (SCENEMANAGER->getSceneName() == "Ÿ���" || SCENEMANAGER->getSceneName() == "�ʵ��" ||
		SCENEMANAGER->getSceneName() == "������")
	{
		_pm->getPlayer()->setSceneMode(FIELDMODE, RIGHT);
		_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_RIGHT);
		_map->load(loadMap);
	}
	else if (SCENEMANAGER->getSceneName() == "��Ʋ��")
	{
		_pm->getPlayer()->setSceneMode(BATTLEMODE, FIGHTREADY);
		_pm->getPlayer2()->setSceneMode(S_BATTLEMODE, S_FIGHTREADY);

	}
}

void playSceneManager::battleSceneChange(void)
{	
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;

	if (SCENEMANAGER->getSceneName() == "�ʵ��" &&
		(_pm->getPlayer()->getMove() == LEFTMOVE ||
		_pm->getPlayer()->getMove() == RIGHTMOVE || 
		_pm->getPlayer()->getMove() == UPMOVE || 
		_pm->getPlayer()->getMove() == DOWNMOVE))
	{
		if (_map->getTiles()[idY * TILEX + idX].terrain == TR_MOVE ||
			_map->getTiles()[idY * TILEX + idX].obj < OBJ_UPPORTAL)
		{
			if (RND->getFloat(100) < 1.1f)
			{	
				_savePlayerPosX = _pm->getPlayer()->getX();
				_savePlayerPosY = _pm->getPlayer()->getY();
				SCENEMANAGER->changeScene("��Ʋ��");
				sceneMapPlayerSetting("��Ʋ��", 100, 400);
				_em->randEnemy();
			}
		}
	}
	else if (SCENEMANAGER->getSceneName() == "��Ʋ��")
	{
		if((_pm->getPlayer()->getAttribute().currentHp <= 0 && _pm->getPlayer2()->getAttribute().currentHp > 0) ||
			(_pm->getPlayer()->getAttribute().currentHp > 0 && _pm->getPlayer2()->getAttribute().currentHp <= 0) ||
			(_em->getVEnmey().size() <= 0))
		{
			if (!(_pm->getPlayer2()->getIsExpSet()))
			{
				SCENEMANAGER->changeScene("�ʵ��");
				sceneMapPlayerSetting("field1Tile", _savePlayerPosX, _savePlayerPosY);
			}
		}
	}

}

