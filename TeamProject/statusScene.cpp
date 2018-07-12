#include "stdafx.h"
#include "statusScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"


statusScene::statusScene()
{
}

statusScene::~statusScene()
{
}

HRESULT statusScene::init(void)
{
	addImage();
	
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	_uiX = WINSIZEX - 314;
	_uiY = 100;

	_invenX = WINSIZEX - 340;
	_invenY = 210;

	_setIndex = 0;
	_invenIndex = 0;
	_invenTypeIndex = 0;
	
	_isCheck = false;
	_isItemCheck = false;

	return S_OK;
}

void statusScene::release(void)
{

}

void statusScene::update(void)
{
	
	keyManager();	//상태창 키관리
	iconChange();	//아이콘 변경
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
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0) 
	{
		
		_pm->getA_WeapItemImage()->frameRender(CAMERA->getCameraDC(), 50, 210);
		_pm->getA_ArmorItemImage()->frameRender(CAMERA->getCameraDC(), 50, 310);
		
	}
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
	{
		_pm->getS_WeapItemImage()->frameRender(CAMERA->getCameraDC(), 50, 210);
		_pm->getS_ArmorItemImage()->frameRender(CAMERA->getCameraDC(), 50, 310);
	}

	if (_isCheck)
	{
		IMAGEMANAGER->findImage("INVENBUTTON")->frameRender(CAMERA->getCameraDC(), _invenX, _invenY);
		if(_setIndex==0||_setIndex==2)
		{
			if (_invenTypeIndex == 0 || _invenTypeIndex == 1)IMAGEMANAGER->findImage("LEFTBUTTON")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 75, 500);
			if (_invenTypeIndex == 2 || _invenTypeIndex == 1)IMAGEMANAGER->findImage("RIGHTBUTTON")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 325, 500);
		}
		
	}
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

	//세팅 인덱스에 맞는 이미지 렌더
	if (_setIndex==0 || _setIndex>3)
	{
		IMAGEMANAGER->findImage("스킬1")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200);
		if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1 && _invenTypeIndex == 0&&_setIndex==0) {}
		else
		{
			IMAGEMANAGER->findImage("스킬2")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 250);
			if (_setIndex != 5)
			{
				IMAGEMANAGER->findImage("스킬3")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 300);
			}
		}
		if (_setIndex == 4)
		{
			IMAGEMANAGER->findImage("스킬4")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 350);
			IMAGEMANAGER->findImage("스킬5")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 400);
		}
	}
	if (_setIndex == 1)
	{
		if (_pm->getV_PoInven().size() != 0)
		{
			for (int i = 0; i<_pm->getV_PoInven().size(); i++)
			{
				_pm->getV_PoInven()[i].img->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200+50*i);
			}
		}
	}
	if (_setIndex == 2)
	{
		if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
		{
			if (_invenTypeIndex == 0)
			{
				if (_pm->getVA_WeapInven().size() != 0)
				{
					for (int i = 0; i<_pm->getVA_WeapInven().size(); i++)
					{
						_pm->getVA_WeapInven()[i].img->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200 + 50 * i);
					}
				}
			}
			if (_invenTypeIndex == 1)
			{
				if (_pm->getVA_ArmorInven().size() != 0)
				{
					for (int i = 0; i<_pm->getVA_ArmorInven().size(); i++)
					{
						_pm->getVA_ArmorInven()[i].img->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200 + 50 * i);
					}
				}
			}
		}
		if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
		{
			if (_invenTypeIndex == 0)
			{
				if (_pm->getVS_WeapInven().size() > 0)
				{
					for (int i = 0; i<_pm->getVS_WeapInven().size(); i++)
					{
						_pm->getVS_WeapInven()[i].img->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200 + 50 * i);
					}
				}
			}
			if (_invenTypeIndex == 1)
			{
				if (_pm->getVS_ArmorInven().size() > 0)
				{
					for (int i = 0; i<_pm->getVS_ArmorInven().size(); i++)
					{
						_pm->getVS_ArmorInven()[i].img->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 200 + 50 * i);
					}
				}
			}
		}

	}
	fontUI();
}
//키매니저
void statusScene::keyManager(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if (!_isCheck)
		{
			SCENEMANAGER->changeScene(SCENEMANAGER->getCurrentSceneName());		
		}
		else
		{
			IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(0);
			_invenIndex = 0;
			_isCheck = false;
		}

	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (!_isCheck)
		{
			IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(
				IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() + 1);
			if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()>1)
			{
				IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(0);
			}
		}
		else if (_isCheck)
		{
			_invenIndex++;
			if (_setIndex == 0) { if (_invenIndex > 2)_invenIndex = 0; }
			if (_setIndex == 1)
			{
				if (_pm->getV_PoInven().size() != 0) //포션이 한개라도 있으면
				{
					if (_invenIndex > _pm->getV_PoInven().size() - 1)_invenIndex = 0;
				}
				else //포션이 없으면
				{
					_invenIndex = 0;
				}
			}
			if (_setIndex == 2)
			{
				if(IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()==0)	//아타호
				{
					if (_invenTypeIndex == 0)
					{
						if (_pm->getVA_WeapInven().size() != 0)
						{
							if (_invenIndex > _pm->getVA_WeapInven().size() - 1)_invenIndex = 0;
						}

					}
					if (_invenTypeIndex == 1)
					{
						if (_pm->getVA_ArmorInven().size() != 0)
						{
							if (_invenIndex > _pm->getVA_ArmorInven().size() - 1)_invenIndex = 0;
						}
					}
				}
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)	//스마슈
				{
					if (_invenTypeIndex == 0)
					{
						if (_pm->getVS_WeapInven().size() != 0)
						{
							if (_invenIndex > _pm->getVS_WeapInven().size() - 1)_invenIndex = 0;
						}

					}
					if (_invenTypeIndex == 1)
					{
						if (_pm->getVS_ArmorInven().size() != 0)
						{
							if (_invenIndex > _pm->getVS_ArmorInven().size() - 1)_invenIndex = 0;
						}
					}
				}
			}
			if (_setIndex == 3) { if (_invenIndex > 1)_invenIndex = 0; }
			if (_setIndex == 4) { if (_invenIndex > 4)_invenIndex = 0; }
			if (_setIndex == 5) { if (_invenIndex > 1)_invenIndex = 0; }

		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (!_isCheck)
		{
			IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(
				IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() - 1);
			if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()<0)
			{
				IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(1);
			}
		}
		else if (_isCheck)
		{
			_invenIndex--;
			if (_setIndex == 0) { if (_invenIndex < 0)_invenIndex = 2; }
			if (_setIndex == 1)
			{
				if (_invenIndex <0)_invenIndex = _pm->getV_PoInven().size()-1;
			}
			if (_setIndex == 2)
			{
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
				{
					if (_invenTypeIndex == 0)
					{
						if (_invenIndex < 0)_invenIndex = _pm->getVA_WeapInven().size() - 1;
					}
					if (_invenTypeIndex == 1)
					{
						if (_invenIndex < 0)_invenIndex = _pm->getVA_ArmorInven().size() - 1;
					}
				}
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
				{
					if (_invenTypeIndex == 0)
					{
						if (_invenIndex < 0)_invenIndex = _pm->getVS_WeapInven().size() - 1;
					}
					if (_invenTypeIndex == 1)
					{
						if (_invenIndex < 0)_invenIndex = _pm->getVS_ArmorInven().size() - 1;
					}
				}	
			}
			if (_setIndex == 3) { if (_invenIndex < 0)_invenIndex = 1; }
			if (_setIndex == 4) { if (_invenIndex < 0)_invenIndex = 4; }
			if (_setIndex == 5) { if (_invenIndex < 0)_invenIndex = 1; }
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_invenIndex = 0;
		if (!_isCheck)
		{
			_setIndex--;
			if (_setIndex < 0)
			{
				_setIndex = 5;
			}
		}
		else if (_isCheck)
		{
			_invenTypeIndex--;
			if(_setIndex==0)
			{
				if (_invenTypeIndex<0)
				{
					_invenTypeIndex = 2;
				}
			}
			if(_setIndex==2)
			{
				if (_invenTypeIndex<0)
				{
					_invenTypeIndex = 1;
				}
			}
			
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_invenIndex = 0;
		if (!_isCheck)
		{
			_setIndex++;
			if (_setIndex>5)
			{
				_setIndex = 0;
			}
		}
		else if (_isCheck)
		{
			_invenTypeIndex++;
			if(_setIndex==0)
			{
				if (_invenTypeIndex>2)
				{
					_invenTypeIndex = 0;
				}
			}
			if (_setIndex == 2)
			{
				if (_invenTypeIndex>1)
				{
					_invenTypeIndex = 0;
				}
			}
			
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(1);
		if (_isCheck)
		{
			itemChoice();
		}
		if(!_isCheck)_isCheck = true;
	
	}

	for (int i = 0; i<6; i++)
	{
		if (_setIndex == i)
		{
			_uiX = WINSIZEX - 314 + i * 50;
		}
	}
	for (int i = 0; i<5; i++)
	{
		if (_invenIndex == i)
		{
			_invenY = 210 + i * 50;
		}
	}
}
//이미지 매니저에 이미지 추가
void statusScene::addImage(void)
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
	IMAGEMANAGER->addFrameImage("INVENBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("INVENBUTTON")->setFrameX(7);
	IMAGEMANAGER->addFrameImage("LEFTBUTTON", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RIGHTBUTTON", "image/ui/UI버튼.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("LEFTBUTTON")->setFrameX(6);
	IMAGEMANAGER->findImage("RIGHTBUTTON")->setFrameX(5);
}
//아이콘 선택
void statusScene::iconChange(void)
{
	switch (_setIndex)
	{
		//스킬
		case 0:
			if (_invenTypeIndex == 0)//기본기
			{
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬2")->setFrameX(11);
					IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬3")->setFrameX(11);
					IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
				}
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
				}
			}
			if (_invenTypeIndex == 1)//개인기
			{
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬2")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬3")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
				}
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬2")->setFrameX(16);
					IMAGEMANAGER->findImage("스킬2")->setFrameY(2);
					IMAGEMANAGER->findImage("스킬3")->setFrameX(16);
					IMAGEMANAGER->findImage("스킬3")->setFrameY(2);
				}
			}
			if (_invenTypeIndex == 2)//단체기
			{
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬2")->setFrameX(10);
					IMAGEMANAGER->findImage("스킬2")->setFrameY(2);
					IMAGEMANAGER->findImage("스킬3")->setFrameX(14);
					IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
				}
				if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
				{
					IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
					IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬2")->setFrameX(17);
					IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
					IMAGEMANAGER->findImage("스킬3")->setFrameX(16);
					IMAGEMANAGER->findImage("스킬3")->setFrameY(2);
				}
			}

		break;
		//모드
		case 4:
			IMAGEMANAGER->findImage("스킬1")->setFrameX(8);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(1);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(8);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(1);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(8);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(1);
			IMAGEMANAGER->findImage("스킬4")->setFrameX(8);
			IMAGEMANAGER->findImage("스킬4")->setFrameY(1);
			IMAGEMANAGER->findImage("스킬5")->setFrameX(8);
			IMAGEMANAGER->findImage("스킬5")->setFrameY(1);
		break;
		//환경설정
		case 5:
			IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(3);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(11);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(3);
		break;
	}
}
//아이템 선택
void statusScene::itemChoice(void)
{
	if(_pm->getVA_ArmorInven().size() != 0
		&& _pm->getVA_WeapInven().size() != 0 
		&& _pm->getVA_ArmorInven().size() != 0
		&& _pm->getVS_WeapInven().size() != 0
		&& _pm->getVS_ArmorInven().size() != 0 
		)
	{
		if (_setIndex == 1 && _pm->getV_PoInven().size() == 0);
		else
			_pm->mounting(IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX(), _setIndex, _invenTypeIndex, _invenIndex);
	}
}
//텍스트
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

	char str12[] = "기본기";
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
	sprintf_s(currentHP1, "%d / %d", _pm->getPlayer()->getAttribute().currentHp,_pm->getPlayer()->getAttribute().maxHp);
	char currentHP2[128];	//스마슈 현재체력 / 최대체력
	sprintf_s(currentHP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentHp, _pm->getPlayer2()->getAttribute().maxHp);

	char currentMP1[128];	//아타호 현재마력 / 최대마력
	sprintf_s(currentMP1, "%d / %d", _pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	char currentMP2[128];	//스마슈 현재마력 / 최대마력
	sprintf_s(currentMP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentMp, _pm->getPlayer2()->getAttribute().maxMp);
	
	char currentEXP1[128];	//아타호 현재경험치 / 최대경험치
	if (_pm->getPlayer()->getAttribute().currentExp == 0)
	{
		sprintf_s(currentEXP1, "%d / %d", 0, _pm->getPlayer()->getAttribute().maxExp / (_pm->getPlayer()->getAttribute().maxExp / 100));
	}
	else
	{
		sprintf_s(currentEXP1, "%d / %d", _pm->getPlayer()->getAttribute().currentExp / (_pm->getPlayer()->getAttribute().currentExp / 100), _pm->getPlayer()->getAttribute().maxExp / (_pm->getPlayer()->getAttribute().maxExp / 100));
	}

	char currentEXP2[128];	//스마슈 현재경험치 / 최대경험치

	if (_pm->getPlayer2()->getAttribute().currentExp == 0)
	{
		sprintf_s(currentEXP2, "%d / %d", 0, _pm->getPlayer2()->getAttribute().maxExp / (_pm->getPlayer2()->getAttribute().maxExp / 100));
	}
	else
		sprintf_s(currentEXP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentExp / (_pm->getPlayer2()->getAttribute().currentExp / 100), _pm->getPlayer2()->getAttribute().maxExp / (_pm->getPlayer2()->getAttribute().maxExp / 100));

	//플레이어 1,2 능력치
	char level1[128];	sprintf(level1, "%d", _pm->getPlayer()->getAttribute().level);
	char atk1[128];		sprintf_s(atk1,"%d", _pm->getPlayer()->getAttribute().atk);
	char def1[128];		sprintf_s(def1, "%d", _pm->getPlayer()->getAttribute().def);
	char speed1[128];	sprintf_s(speed1, "%d", _pm->getPlayer()->getAttribute().speed);
	char luck1[128];	sprintf_s(luck1, "%d", _pm->getPlayer()->getAttribute().luck);

	char level2[128];	sprintf(level2, "%d", _pm->getPlayer2()->getAttribute().level);
	char atk2[128];		sprintf_s(atk2, "%d", _pm->getPlayer2()->getAttribute().atk);
	char def2[128];		sprintf_s(def2, "%d", _pm->getPlayer2()->getAttribute().def);
	char speed2[128];	sprintf_s(speed2, "%d", _pm->getPlayer2()->getAttribute().speed);
	char luck2[128];	sprintf_s(luck2, "%d", _pm->getPlayer2()->getAttribute().luck);

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	//아타호 능력치
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 0)
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
		
		TextOut(CAMERA->getCameraDC(), 100, 220, 
			_pm->getA_WeapItemName().c_str(),
			strlen(_pm->getA_WeapItemName().c_str()));
		
		TextOut(CAMERA->getCameraDC(), 100, 320,
			_pm->getA_ArmorItemName().c_str(),
			strlen(_pm->getA_ArmorItemName().c_str()));
		
		
	}
	//스마슈 능력치
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
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
		TextOut(CAMERA->getCameraDC(), 100, 220,
			_pm->getS_WeapItemName().c_str(),
			strlen(_pm->getS_WeapItemName().c_str()));

		TextOut(CAMERA->getCameraDC(), 100, 320,
			_pm->getS_ArmorItemName().c_str(),
			strlen(_pm->getS_ArmorItemName().c_str()));
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
	
	//인벤토리 이름
	if (_setIndex == 0) 
	{
		if (_invenTypeIndex == 0)TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, str12, strlen(str12));
		if (_invenTypeIndex == 1)TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, "개인기", strlen("개인기"));
		if (_invenTypeIndex == 2)TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, "단체기", strlen("단체기"));
	}
	if (_setIndex == 1) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str13, strlen(str13));
	if (_setIndex == 2) 
	{
		if (_invenTypeIndex == 0)TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str14, strlen(str14));
		if (_invenTypeIndex == 1)TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, "방어구", strlen("방어구"));
	}
	if (_setIndex == 3) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str15, strlen(str15));
	if (_setIndex == 4) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str16, strlen(str16));
	if (_setIndex == 5) TextOut(CAMERA->getCameraDC(), WINSIZEX - 225, 160, str17, strlen(str17));
	//아타호 일때 인벤토리 텍스트
	if(IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()==0)
	{
		
		if(_setIndex==0)
		{
			if(_invenTypeIndex==0)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212,"정권",strlen("정권"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "돌려차기", strlen("돌려차기"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "다리후리기", strlen("다리후리기"));
			}
			if (_invenTypeIndex == 1)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "호격권", strlen("호격권"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "맹호스페셜", strlen("맹호스페셜"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "맹호광파참", strlen("맹호광파참"));
			}
			if (_invenTypeIndex == 2)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "맹호난무", strlen("맹호난무"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "노익장대폭발", strlen("노익장대폭발"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "취호염무", strlen("취호염무"));
			}
		}
		//아타호 장비
		if (_setIndex == 2)
		{
			if (_invenTypeIndex == 0) //무기
			{
				for(int i=0;i<_pm->getVA_WeapInven().size();i++)
				{
					TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212+50*i,
						_pm->getVA_WeapInven()[i].name.c_str(),
						strlen(_pm->getVA_WeapInven()[i].name.c_str()));
				}
				
			}
			if (_invenTypeIndex == 1) //방어구
			{
				for (int i = 0; i < _pm->getVA_ArmorInven().size(); i++)
				{
					TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212 + 50 * i,
						_pm->getVA_ArmorInven()[i].name.c_str(),
						strlen(_pm->getVA_ArmorInven()[i].name.c_str()));
				}
			}
			
		}	
	}
	//스마슈 일때 인벤토리 텍스트
	if (IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() == 1)
	{
		if (_setIndex == 0)
		{
			if (_invenTypeIndex == 0)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "베기", strlen("베기"));
				
			}
			if (_invenTypeIndex == 1)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "대타격", strlen("대타격"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "난도질", strlen("난도질"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "절사어면", strlen("절사어면"));
			}
			if (_invenTypeIndex == 2)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "백인일섬", strlen("백인일섬"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "분신", strlen("분신"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "용오름", strlen("용오름"));
			}
		}
		//스마슈 장비
		if (_setIndex == 2)
		{
			if (_invenTypeIndex == 0) //무기
			{
				for (int i = 0; i<_pm->getVS_WeapInven().size(); i++)
				{
					TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212 + 50 * i,
						_pm->getVS_WeapInven()[i].name.c_str(),
						strlen(_pm->getVS_WeapInven()[i].name.c_str()));
				}

			}
			if (_invenTypeIndex == 1) //방어구
			{
				for (int i = 0; i < _pm->getVS_ArmorInven().size(); i++)
				{
					TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212 + 50 * i,
						_pm->getVS_ArmorInven()[i].name.c_str(),
						strlen(_pm->getVS_ArmorInven()[i].name.c_str()));
				}
			}

		}
	}
	//도구 텍스트 (포션 인벤토리 일때)
	if (_setIndex == 1)
	{
		if (_pm->getV_PoInven().size() != 0)
		{
			for (int i = 0; i<_pm->getV_PoInven().size(); i++)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212 + 50 * i,
					_pm->getV_PoInven()[i].name.c_str(),
					strlen(_pm->getV_PoInven()[i].name.c_str()));
			}
		}
	}
	//소지품 텍스트
	if (_setIndex == 3)
	{

	}
	//모드 텍스트
	if (_setIndex == 4)
	{
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "보통", strlen("보통"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "돌격", strlen("돌격"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 312, "방어", strlen("방어"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 362, "선제", strlen("선제"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 412, "반격", strlen("반격"));

	}
	//환결설정 텍스트
	if (_setIndex == 5)
	{
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 212, "사운드", strlen("사운드"));
		TextOut(CAMERA->getCameraDC(), WINSIZEX - 250, 262, "종료", strlen("종료"));
	}
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
