#include "stdafx.h"
#include "battleScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	IMAGEMANAGER->addImage("스킬선택창", "image/ui/스킬선택창.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("스킬선택창2", "image/ui/스킬선택창2.bmp", 350, 375, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("기본기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("개인기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("단체기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("도구아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("모드아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("특수기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("기본기아이콘")->setFrameX(5);
	IMAGEMANAGER->findImage("개인기아이콘")->setFrameX(6);
	IMAGEMANAGER->findImage("단체기아이콘")->setFrameX(7);
	IMAGEMANAGER->findImage("도구아이콘")->setFrameX(1);
	IMAGEMANAGER->findImage("모드아이콘")->setFrameX(8);
	IMAGEMANAGER->findImage("특수기아이콘")->setFrameX(9);

	IMAGEMANAGER->addFrameImage("SKILLBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameX(6);
	IMAGEMANAGER->addFrameImage("SKILLCHOICEBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->setFrameX(7);
	IMAGEMANAGER->addFrameImage("MONCHECKBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("MONCHECKBUTTON")->setFrameX(7);
	

	_isTurn = false;
	_choiceIndex = 0;
	_skillIndex = 0;
	_monIndex = 0;

	_choiceX=357;
	_choiceY=125;

	_skillX = 327;
	_skillY = 225;

	_monX = 660;
	_monY = 570;

	_isSkillCheck = false;
	_isMonCheck = false;

	return S_OK;
}

void battleScene::release(void)
{
}

void battleScene::update(void)
{
	CAMERA->setPosition(0, 0);

	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isTurn)_isTurn = true;
		else if (_isTurn) _isTurn = false;
	}

	if(_isTurn)
	{
		if(KEYMANAGER->isOnceKeyDown(VK_LEFT)&&!_isSkillCheck)
		{
			_choiceIndex--;
			if (_choiceIndex < 0) _choiceIndex = 5;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)&&!_isSkillCheck)
		{
			_choiceIndex++;
			if (_choiceIndex > 5) _choiceIndex = 0;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (!_isSkillCheck)
			{
				_skillIndex--;
				if (_skillIndex < 0) _skillIndex = 2;
			}
			else if(_isSkillCheck)
			{
				_monIndex--;
				if (_monIndex < 0)_monIndex = 3;	//나중에 몬스터 벡터 사이즈로 바꿔야함
			}
			
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (!_isSkillCheck)
			{
				_skillIndex++;
				if (_skillIndex > 2) _skillIndex = 0;
			}
			else if (_isSkillCheck)
			{
				_monIndex++;
				if (_monIndex > 3)_monIndex = 0;	//나중에 몬스터 벡터 사이즈로 바꿔야함
			}
		}
		if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if(!_isSkillCheck)
			{
				IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameY(1);
				IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->setFrameY(1);
				_isSkillCheck = true;
			}
			
		}
		if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
		{
			IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameY(0);
			IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->setFrameY(0);
			_isSkillCheck = false;
		}
		
		for(int i=0;i<6;i++)
		{
			if(_choiceIndex == i)
			{
				_choiceX = 357 + i * 50;
			}
		}

		for(int i=0;i<3;i++)
		{
			if(_skillIndex ==i)
			{
				_skillY = 225 + i * 50;
			}
		}
		for(int i=0;i<4;i++)//나중에 벡터사이즈 만큼으로 바꿔야함
		{
			if(_monIndex ==i)
			{
				_monY = 570 + i * 40;
			}
		}
	}
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_isTurn)
	{
		IMAGEMANAGER->findImage("스킬선택창")->render(CAMERA->getCameraDC(), 320, 0);
		IMAGEMANAGER->findImage("스킬선택창2")->render(CAMERA->getCameraDC(), 320, 175);
		IMAGEMANAGER->findImage("기본기아이콘")->frameRender(CAMERA->getCameraDC(), 345, 75);
		IMAGEMANAGER->findImage("개인기아이콘")->frameRender(CAMERA->getCameraDC(), 395, 75);
		IMAGEMANAGER->findImage("단체기아이콘")->frameRender(CAMERA->getCameraDC(), 445, 75);
		IMAGEMANAGER->findImage("도구아이콘")->frameRender(CAMERA->getCameraDC(), 495, 75);
		IMAGEMANAGER->findImage("모드아이콘")->frameRender(CAMERA->getCameraDC(), 545, 75);
		IMAGEMANAGER->findImage("특수기아이콘")->frameRender(CAMERA->getCameraDC(), 595, 75);

		IMAGEMANAGER->findImage("SKILLBUTTON")->frameRender(CAMERA->getCameraDC(), _choiceX, _choiceY);
		IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->frameRender(CAMERA->getCameraDC(), _skillX, _skillY);
		
	}
	if (_isSkillCheck)
	{
		IMAGEMANAGER->findImage("MONCHECKBUTTON")->frameRender(CAMERA->getCameraDC(), _monX, _monY);
	}
	fontUI();
}

void battleScene::fontUI(void)
{
	HFONT font, ofont;
	char charName[] = "아타호";
	char charName2[] = "스마슈";

	char str[] = "배틀씬";
	char str1[] = "기본기";
	char str2[] = "개인기";
	char str3[] = "단체기";
	char str4[] = "도구";
	char str5[] = "모드";
	char str6[] = "특수기";

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	if(_isTurn)
	{
		TextOut(CAMERA->getCameraDC(), 345, 25, charName, strlen(charName));
		if (_choiceIndex == 0) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str1, strlen(str1));
		if (_choiceIndex == 1) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
		if (_choiceIndex == 2) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
		if (_choiceIndex == 3) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str4, strlen(str4));
		if (_choiceIndex == 4) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str5, strlen(str5));
		if (_choiceIndex == 5) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str6, strlen(str6));
	}

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
