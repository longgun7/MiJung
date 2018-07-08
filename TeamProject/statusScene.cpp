#include "stdafx.h"
#include "statusScene.h"



statusScene::statusScene()
{
}

statusScene::~statusScene()
{
}

HRESULT statusScene::init(void)
{
	IMAGEMANAGER->addImage("statusMain", "image/ui/statusMain.bmp", 650, 550, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice", "image/ui/statusChoice.bmp", 350, 150, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice2", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));
	
	IMAGEMANAGER->addFrameImage("캐릭터이미지", "image/ui/캐릭터이미지.bmp", 1000, 250, 8, 2, false, RGB(0, 0, 0));
	IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(0);

	IMAGEMANAGER->addFrameImage("스킬", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("도구", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("장비", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("소지", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("모드", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("환경설정", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("스킬")->setFrameX(0);
	IMAGEMANAGER->findImage("도구")->setFrameX(1);
	IMAGEMANAGER->findImage("장비")->setFrameX(2);
	IMAGEMANAGER->findImage("소지")->setFrameX(3);
	IMAGEMANAGER->findImage("모드")->setFrameX(8);
	IMAGEMANAGER->findImage("환경설정")->setFrameX(4);

	IMAGEMANAGER->addFrameImage("아이템", "image/ui/아이템.bmp", 600, 250, 12, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터선택UP", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("캐릭터선택DOWN", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("캐릭터선택UP")->setFrameX(7);
	IMAGEMANAGER->findImage("캐릭터선택DOWN")->setFrameX(8);

	IMAGEMANAGER->addFrameImage("SETTINGBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameX(6);
	IMAGEMANAGER->addFrameImage("INVENBUTTON", "image/ui/UI버튼.bmp",450, 75, 18, 3, true, RGB(255, 0, 255));


	_uiX = WINSIZEX - 314;
	_uiY = 100;

	_setIndex = 0;
	_invenIndex = 0;
	
	_isCheck = false;
	_isItemCheck = false;

	_isState = false;

	return S_OK;
}

void statusScene::release(void)
{

}

void statusScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if(!_isCheck)
		{
			SCENEMANAGER->changeScene("타운씬");
		}
		else
		{
			IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(0);
			_isCheck = false;
		}
		
	}
	//if (KEYMANAGER->isOnceKeyDown(VK_F1))
	//{
	//	SCENEMANAGER->changeScene("필드씬");
	//}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if(!_isCheck)
		{
			IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(
				IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() + 1);
			if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()>1)
			{
				IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(0);
			}
		}
		
	}
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if(!_isCheck)
		{
			IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(
				IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() - 1);
			if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()<0)
			{
				IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(1);
			}
		}
	}

	if(KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if(!_isCheck)
		{
			_setIndex--;
			if (_setIndex < 0)
			{
				_setIndex = 5;
			}
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if(!_isCheck)
		{
			_setIndex++;
			if (_setIndex>5)
			{
				_setIndex = 0;
			}
		}
		
	}
	if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(1);
		_isCheck = true;
	}

	
	for(int i=0;i<6;i++)
	{
		if(_setIndex ==i)
		{
			_uiX = WINSIZEX - 314 +i*50;
		}
	}

}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(CAMERA->getCameraDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(CAMERA->getCameraDC(), 650, 150);
	IMAGEMANAGER->findImage("캐릭터이미지")->frameRender(CAMERA->getCameraDC(), 60, 50);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);
	IMAGEMANAGER->findImage("스킬")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 325, 50);
	IMAGEMANAGER->findImage("도구")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 275, 50);
	IMAGEMANAGER->findImage("장비")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 225, 50);
	IMAGEMANAGER->findImage("소지")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 175, 50);
	IMAGEMANAGER->findImage("모드")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 125, 50);
	IMAGEMANAGER->findImage("환경설정")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 75, 50);

	IMAGEMANAGER->findImage("SETTINGBUTTON")->frameRender(CAMERA->getCameraDC(), _uiX, _uiY);

	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0&&!_isCheck)
	{
		IMAGEMANAGER->findImage("캐릭터선택DOWN")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 527);
		
	}
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1 && !_isCheck)
	{
		IMAGEMANAGER->findImage("캐릭터선택UP")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 0);
	}
	char str123[128];

	
	fontUI();
	loadData();

}

void statusScene::loadData()
{
	vector<string> vStr;

	vStr = TXTDATA->txtLoad("playerData.txt");
	_player1Data.level = (atoi(vStr[0].c_str()));
	_player1Data.currentHp = (atoi(vStr[1].c_str()));
	_player1Data.maxHp = (atoi(vStr[2].c_str()));
	_player1Data.currentMp = (atoi(vStr[3].c_str()));
	_player1Data.maxMp = (atoi(vStr[4].c_str()));
	_player1Data.currentExp = (atoi(vStr[5].c_str()));
	_player1Data.maxExp = (atoi(vStr[6].c_str()));
	_player1Data.atk = (atoi(vStr[7].c_str()));
	_player1Data.def = (atoi(vStr[8].c_str()));
	_player1Data.speed = (atoi(vStr[9].c_str()));
	_player1Data.luck = (atoi(vStr[10].c_str()));

	vector<string> vStr1;

	vStr1 = TXTDATA->txtLoad("player2Data.txt");
	_player2Data.level = (atoi(vStr1[0].c_str()));
	_player2Data.currentHp = (atoi(vStr1[1].c_str()));
	_player2Data.maxHp = (atoi(vStr1[2].c_str()));
	_player2Data.currentMp = (atoi(vStr1[3].c_str()));
	_player2Data.maxMp = (atoi(vStr1[4].c_str()));
	_player2Data.currentExp = (atoi(vStr1[5].c_str()));
	_player2Data.maxExp = (atoi(vStr1[6].c_str()));
	_player2Data.atk = (atoi(vStr1[7].c_str()));
	_player2Data.def = (atoi(vStr1[8].c_str()));
	_player2Data.speed = (atoi(vStr1[9].c_str()));
	_player2Data.luck = (atoi(vStr1[10].c_str()));

}

void statusScene::fontUI(void)
{
	
	HFONT font, ofont;
	
	char strName1[] = "아타호";
	char strName2[] = "스마슈";
	
	char str1[] = "레벨";
	char str2[] = "체력";
	char str3[] = "기력";
	char str4[] = "경험";
	char str5[] = "공격력";
	char str6[] = "방어력";
	char str7[] = "기술력";
	char str8[] = "순발력";
	char str9[] = "운";

	char str10[] = "무기";
	char str11[] = "방어구";

	char str12[] = "개인기";
	char str13[] = "도구";
	char str14[] = "무기";
	char str15[] = "소지";
	char str16[] = "모드";
	char str17[] = "환경설정";
	
	char str18[] = "보통";
	char str19[] = "돌격";
	char str20[] = "방어";
	char str21[] = "선제";
	char str22[] = "반격";
	
	char currentHP1[128];	//아타호 현재체력 / 최대체력
	sprintf_s(currentHP1, "%d / %d", _player1Data.currentHp, _player1Data.maxHp);
	char currentHP2[128];	//스마슈 현재체력 / 최대체력
	sprintf_s(currentHP2, "%d / %d", _player2Data.currentHp, _player2Data.maxHp);

	char currentMP1[128];	//아타호 현재마력 / 최대마력
	sprintf_s(currentMP1, "%d / %d", _player1Data.currentMp, _player1Data.maxMp);
	char currentMP2[128];	//스마슈 현재마력 / 최대마력
	sprintf_s(currentMP2, "%d / %d", _player2Data.currentMp, _player2Data.maxMp);
	
	char currentEXP1[128];	//아타호 현재경험치 / 최대경험치
	sprintf_s(currentEXP1, "%d / %d", _player1Data.currentExp, _player1Data.maxExp);
	char currentEXP2[128];	//스마슈 현재경험치 / 최대경험치
	sprintf_s(currentEXP2, "%d / %d", _player2Data.currentExp, _player2Data.maxExp);

	//플레이어 1,2 능력치
	char level1[128];	sprintf(level1, "%d", _player1Data.level);
	char atk1[128];		sprintf_s(atk1,"%d", _player1Data.atk);
	char def1[128];		sprintf_s(def1, "%d", _player1Data.def);
	char speed1[128];	sprintf_s(speed1, "%d", _player1Data.speed);
	char luck1[128];	sprintf_s(luck1, "%d", _player1Data.luck);

	char level2[128];	sprintf(level2, "%d", _player2Data.level);
	char atk2[128];		sprintf_s(atk2, "%d", _player2Data.atk);
	char def2[128];		sprintf_s(def2, "%d", _player2Data.def);
	char speed2[128];	sprintf_s(speed2, "%d", _player2Data.speed);
	char luck2[128];	sprintf_s(luck2, "%d", _player2Data.luck);

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)//아타호 능력치
	{
		TextOut(CAMERA->getCameraDC(),20, 20, strName1, strlen(strName1));
		TextOut(CAMERA->getCameraDC(), 410, 40, level1, strlen(level1));
		TextOut(CAMERA->getCameraDC(), 410, 80, currentHP1, strlen(currentHP1));
		TextOut(CAMERA->getCameraDC(), 410, 120, currentMP1, strlen(currentMP1));
		TextOut(CAMERA->getCameraDC(), 410, 160, currentEXP1, strlen(currentEXP1));
		TextOut(CAMERA->getCameraDC(), 410, 210, atk1, strlen(atk1));
		TextOut(CAMERA->getCameraDC(), 410, 250, def1, strlen(def1));
		TextOut(CAMERA->getCameraDC(), 410, 290, speed1, strlen(speed1));
		TextOut(CAMERA->getCameraDC(), 410, 330, luck1, strlen(luck1));
		
	}
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)//스마슈 능력치
	{
		TextOut(CAMERA->getCameraDC(), 20, 20, strName2, strlen(strName2));
		TextOut(CAMERA->getCameraDC(), 410, 40, level2, strlen(level2));
		TextOut(CAMERA->getCameraDC(), 410, 80, currentHP2, strlen(currentHP2));
		TextOut(CAMERA->getCameraDC(), 410, 120, currentMP2, strlen(currentMP2));
		TextOut(CAMERA->getCameraDC(), 410, 160, currentEXP2, strlen(currentEXP2));
		TextOut(CAMERA->getCameraDC(), 410, 210, atk2, strlen(atk2));
		TextOut(CAMERA->getCameraDC(), 410, 250, def2, strlen(def2));
		TextOut(CAMERA->getCameraDC(), 410, 290, speed2, strlen(speed2));
		TextOut(CAMERA->getCameraDC(), 410, 330, luck2, strlen(luck2));
	}
	//캐릭터 정보
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 40, str1, strlen(str1));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 80, str2, strlen(str2));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120, str3, strlen(str3));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 160, str4, strlen(str4));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 210, str5, strlen(str5));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 250, str6, strlen(str6));
	//TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 290, str7, strlen(str7)); //기술력 삭제
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 290, str8, strlen(str8));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 330, str9, strlen(str9));

	//착용장비
	TextOut(CAMERA->getCameraDC(), 20, WINSIZEY/2-190, str10, strlen(str10));
	TextOut(CAMERA->getCameraDC(), 20, WINSIZEY/2-100, str11, strlen(str11));

	


	//인벤토리
	if (_setIndex == 0) TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, str12, strlen(str12));
	if (_setIndex == 1) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str13, strlen(str13));
	if (_setIndex == 2) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str14, strlen(str14));
	if (_setIndex == 3) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str15, strlen(str15));
	if (_setIndex == 4) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str16, strlen(str16));
	if (_setIndex == 5) TextOut(CAMERA->getCameraDC(), WINSIZEX - 225, 160, str17, strlen(str17));
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
