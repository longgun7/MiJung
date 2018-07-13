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
	IMAGEMANAGER->addImage("배틀장면대나무", "image/battleScene/배틀장면 대나무.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배틀장면언덕", "image/battleScene/배틀장면 언덕.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배틀장면절벽", "image/battleScene/배틀장면 절벽.bmp", 1000, 550, true, RGB(255, 0, 255));

	sceneAdd();
	basicUI();

	_isStatus = false;

	//전방선언	
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	setProgressBar();	//프로그래스바 셋팅!

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
	
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("타운씬");
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
		SCENEMANAGER->changeScene("배틀씬");
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
		SCENEMANAGER->changeScene("필드씬");
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
		SCENEMANAGER->changeScene("술집씬");
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		SCENEMANAGER->changeScene("이벤트씬");
		SOUNDMANAGER->stop(_nowSong);
		_nowSong = "eventTheMa";
		if (!SOUNDMANAGER->isPlaySound(_nowSong))
		{
			SOUNDMANAGER->play(_nowSong, 1.0f);
		}
	}
	
	updateProgressBar();
}

void playSceneManager::render(void)
{
	//if (SCENEMANAGER->getSceneName() == "배틀씬") IMAGEMANAGER->findImage("배틀장면절벽")->render(getMemDC());
	//else 	_map->render();
	_map->render();

	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TIMEMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("기본status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);

	renderProgressBar();	//프로그래스바 렌더
		
	_pm->render();
	_em->render();
	_im->render();
		
	// 오브젝트 렌더
	if (SCENEMANAGER->getSceneName() != "배틀씬")
	{
		if(SCENEMANAGER->getSceneName() != "이벤트씬")
			_map->objRender();
	}

	fontUI();
}

void playSceneManager::sceneAdd(void)
{

	SCENEMANAGER->addScene("상태씬", new statusScene);
	SCENEMANAGER->addScene("타운씬", new townScene);
	SCENEMANAGER->addScene("필드씬1", new fieldScene);
	SCENEMANAGER->addScene("필드씬2", new field2Scene);
	SCENEMANAGER->addScene("필드씬3", new field3Scene);
	SCENEMANAGER->addScene("배틀씬", new battleScene);
	SCENEMANAGER->addScene("술집씬", new barScnen);
	SCENEMANAGER->addScene("이벤트씬", new eventScene);
	SCENEMANAGER->addScene("플레이씬", new playScene);
	
}

void playSceneManager::basicUI(void)
{

	IMAGEMANAGER->addFrameImage("HP", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("MP", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EXP", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("테두리", "image/ui/게임테두리.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기본status", "image/ui/기본status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스킬1", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스킬2", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스킬3", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스킬4", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스킬5", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
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

	char charName[] = "아타호";
	char charName1[] = "스마슈";
	
	char currentLevel1[128];
	sprintf_s(currentLevel1, "%d", _pm->getPlayer()->getAttribute().level);
	char currentLevel2[128];
	sprintf_s(currentLevel2, "%d", _pm->getPlayer2()->getAttribute().level);

	char currentHP1[128];	//아타호 현재체력 / 최대체력
	sprintf_s(currentHP1, "%d / %d", _pm->getPlayer()->getAttribute().currentHp, _pm->getPlayer()->getAttribute().maxHp);
	char currentHP2[128];	//스마슈 현재체력 / 최대체력
	sprintf_s(currentHP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentHp, _pm->getPlayer2()->getAttribute().maxHp);

	char currentMP1[128];	//아타호 현재마력 / 최대마력
	sprintf_s(currentMP1, "%d / %d", _pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	char currentMP2[128];	//스마슈 현재마력 / 최대마력
	sprintf_s(currentMP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentMp, _pm->getPlayer2()->getAttribute().maxMp);

	char currentEXP1[128];	//아타호 현재경험치 / 최대경험치
	sprintf_s(currentEXP1, "%d / %d", _pm->getPlayer()->getAttribute().currentExp / _pm->getPlayer()->getAttribute().level, 100);
	
	char currentEXP2[128];	//스마슈 현재경험치 / 최대경험치
	sprintf_s(currentEXP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentExp / _pm->getPlayer2()->getAttribute().level, 100);
	
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

	char playerMoney[128];
	sprintf_s(playerMoney, "%d G", _pm->getTagMoney().money);

	font = CreateFont(20, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY - 150, charName, strlen(charName));
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY - 100, charName1, strlen(charName1));
	if(SCENEMANAGER->getSceneName() != "배틀씬")
	{
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 300, WINSIZEY - 50, "번 돈", strlen("번 돈"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, WINSIZEY - 50, playerMoney, strlen(playerMoney));
	}
	if (SCENEMANAGER->getSceneName() == "배틀씬")
	{
		for(int i=0;i<_em->getVEnmey().size();i++)
		{
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 300, (WINSIZEY - 170)+40*i,
				_em->getVEnmey()[i]->getTagEnmey().name.c_str(),
				strlen(_em->getVEnmey()[i]->getTagEnmey().name.c_str()));
		}
		
	}
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	HFONT font2, ofont2;
	font2 = CreateFont(15, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
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
//프로그래스바 세팅
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
