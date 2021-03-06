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
	addImage();

	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	IMAGEMANAGER->addImage("배틀장면대나무","image/battleScene/배틀장면 대나무.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배틀장면언덕", "image/battleScene/배틀장면 언덕.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배틀장면절벽", "image/battleScene/배틀장면 절벽.bmp", 1000, 550, true, RGB(255, 0, 255));

	_isTurn = true;
	_choiceIndex = 0;
	_skillIndex = 0;
	_monIndex = 0;

	_sChoiceIndex = 0;
	_sSkillIndex = 0;
	_sMonIndex = 0;

	_choiceX=357;
	_choiceY=125;

	_skillX = 327;
	_skillY = 245;

	_monX = 660;
	_monY = 570;

	totalMoney = totalExp = 0;
	sceneCount = _isSceneCount = 0;

	_gameTurn = ATAHO_CHOICE;

	_isSkillCheck = false;
	_isMonCheck = false;
	_isFight = false;
	_isAtahoSkillFire = false;
	_isSumsuSkillFire = false;
	_playerTurn = ATAHO_TURN;

	CAMERA->setPosition(0, 0);
	_em->randEnemy();
	_pm->getPlayer()->setX(100); _pm->getPlayer()->setY(400);
	_pm->getPlayer2()->setX(100); _pm->getPlayer2()->setY(400);
	_pm->getPlayer()->setSceneMode(BATTLEMODE, FIGHTREADY);
	_pm->getPlayer2()->setSceneMode(S_BATTLEMODE, S_FIGHTREADY);

	//_em->randEnemy();

	int randumSound;
	randumSound = RND->getInt(2);
	if (randumSound == 0)
	{
		_nowSong = "BattleTheMa1";
		if (!SOUNDMANAGER->isPlaySound(_nowSong))
		{
			SOUNDMANAGER->play(_nowSong, 0.5f);
		}
	}
	else if (randumSound == 1)
	{
		_nowSong = "BattleTheMa2";
		if (!SOUNDMANAGER->isPlaySound(_nowSong))
		{
			SOUNDMANAGER->play(_nowSong, 0.5f);
		}
	}

	for (int i = 0; i < _em->getVEnmey().size(); ++i)
	{
		progressBar* bar = new progressBar;
		bar->init(WINSIZEX - 200, (WINSIZEY - 170) + 40 * i, 137, 12);
		_vEnemyHpBar.push_back(bar);
	}

	return S_OK;
}

void battleScene::release(void)
{
}

void battleScene::update(void)
{
	iconChange();

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && !_isSkillCheck)
	{
		if (_gameTurn == ATAHO_CHOICE)
		{
			_choiceIndex--;
			if (_choiceIndex < 0) _choiceIndex = 5;
		}
		else if (_gameTurn == SUMSU_CHOICE)
		{
			_sChoiceIndex--;
			if (_sChoiceIndex < 0) _sChoiceIndex = 5;
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && !_isSkillCheck)
	{
		if (_gameTurn == ATAHO_CHOICE)
		{
			_choiceIndex++;
			if (_choiceIndex > 5) _choiceIndex = 0;
			_skillIndex = 0;
		}
		else if (_gameTurn == SUMSU_CHOICE)
		{
			_sChoiceIndex++;
			if (_sChoiceIndex > 5) _sChoiceIndex = 0;
			_sSkillIndex = 0;
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (!_isSkillCheck)
		{
			if(_gameTurn==ATAHO_CHOICE)
			{	
				if (_choiceIndex == 3)
				{
					if (_pm->getV_PoInven().size() != 0)
					{
						_skillIndex--;
						if (_skillIndex < 0) _skillIndex = _pm->getV_PoInven().size() - 1;
					}
				}
				else if (_choiceIndex == 4)
				{
					_skillIndex--;
					if (_skillIndex < 0) _skillIndex = 4;
				}
				else if (_choiceIndex == 5)
				{
					_skillIndex = 0;
				}
				else
				{
					_skillIndex--;
					if (_skillIndex < 0) _skillIndex = 2;
				}
			}
			else if (_gameTurn == SUMSU_CHOICE)
			{
				if (_sChoiceIndex == 0)
				{
					_sSkillIndex = 0;
				}
				else if (_sChoiceIndex == 3)
				{
					if (_pm->getV_PoInven().size() != 0)
					{
						_sSkillIndex--;
						if (_sSkillIndex < 0) _sSkillIndex = _pm->getV_PoInven().size() - 1;
					}
				}
				else if (_sChoiceIndex == 4)
				{
					_sSkillIndex--;
					if (_sChoiceIndex < 0) _sSkillIndex = 4;
				}
				else if (_sChoiceIndex == 5)
				{
					_sSkillIndex = 0;
				}
				else
				{
					_sSkillIndex--;
					if (_sSkillIndex < 0) _sSkillIndex = 2;
				}
			}
		}
		else if (_isMonCheck)
		{
			if(_gameTurn==ATAHO_CHOICE)
			{
				_monIndex--;
				if (_monIndex < 0)_monIndex = _em->getVEnmey().size() - 1;				
			}
			else if(_gameTurn == SUMSU_CHOICE)
			{
				_sMonIndex--;
				if (_sMonIndex < 0)_sMonIndex = _em->getVEnmey().size() - 1;				
			}
			
			
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (!_isSkillCheck)
		{
			if (_gameTurn == ATAHO_CHOICE)
			{
				if (_choiceIndex == 3)
				{
					if (_pm->getV_PoInven().size() != 0)
					{
						_skillIndex++;
						if (_skillIndex > _pm->getV_PoInven().size() - 1) _skillIndex = 0;
					}
				}
				else if (_choiceIndex == 4)
				{
					_skillIndex++;
					if (_skillIndex > 4) _skillIndex = 0;
				}
				else if (_choiceIndex == 5)
				{
					_skillIndex = 0;
				}
				else
				{
					_skillIndex++;
					if (_skillIndex > 2) _skillIndex = 0;
				}
			}
			else if (_gameTurn == SUMSU_CHOICE)
			{
				if (_sChoiceIndex == 0)
				{
					_sSkillIndex = 0;
				}
				else if (_sChoiceIndex == 3)
				{
					if (_pm->getV_PoInven().size() != 0)
					{
						_sSkillIndex++;
						if (_sSkillIndex > _pm->getV_PoInven().size() - 1) _sSkillIndex = 0;
					}
				}
				else if (_sChoiceIndex == 4)
				{
					_sSkillIndex++;
					if (_sChoiceIndex > 4) _sSkillIndex = 0;
				}
				else if (_sChoiceIndex == 5)
				{
					_sSkillIndex = 0;
				}
				else
				{
					_sSkillIndex++;
					if (_sSkillIndex > 2) _sSkillIndex = 0;
				}
			}
		}
		else if (_isMonCheck)
		{
			if (_gameTurn == ATAHO_CHOICE)
			{
				_monIndex++;
				if (_monIndex > _em->getVEnmey().size() - 1)_monIndex = 0;
			}
			else if (_gameTurn == SUMSU_CHOICE)
			{
				_sMonIndex++;
				if (_sMonIndex > _em->getVEnmey().size() - 1)_sMonIndex = 0;
			}

		}
	}

	for (int i = 0; i < _em->getVEnmey().size(); ++i)
	{
		if (_em->getVEnmey()[_monIndex]->getTagEnmey().hp <= 0)
		{
			_monIndex++;
			if (_monIndex > _em->getVEnmey().size()-1) _monIndex = 0;
			break;
		}
		if (_em->getVEnmey()[_sMonIndex]->getTagEnmey().hp <= 0)
		{
			_sMonIndex++;
			if (_sMonIndex > _em->getVEnmey().size()-1) _sMonIndex = 0;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if(_gameTurn==ATAHO_CHOICE)
		{
			_isSkillCheck = true;
			if(_isMonCheck)
			{
				_isSkillCheck = false;
				_isMonCheck = false;
				_isAtahoSkillFire = true;
				_gameTurn = (_pm->getPlayer2()->getMove() != S_NOCKDOWN) ? SUMSU_CHOICE : ATAHO_ATTACK;
			}
			else if(_choiceIndex>1)
			{
				_isAtahoSkillFire = true;
				_isSkillCheck = false;
				_gameTurn = (_pm->getPlayer2()->getMove() != S_NOCKDOWN) ? SUMSU_CHOICE : ATAHO_ATTACK;

			}
			else if(_choiceIndex<2)
			{
				_isMonCheck = true;
			}

		}
		else if(_gameTurn == SUMSU_CHOICE)
		{
			_isSkillCheck = true;
			if (_isMonCheck)
			{
				_isSkillCheck = false;
				_isMonCheck = false;
				_gameTurn = (_pm->getPlayer()->getMove() != NOCKDOWN) ? ATAHO_ATTACK : SUMSU_ATTACK;
			}
			else if (_sChoiceIndex>1)
			{
				_isSkillCheck = false;
				_gameTurn = (_pm->getPlayer()->getMove() != NOCKDOWN) ? ATAHO_ATTACK : SUMSU_ATTACK;

			}
			else if (_sChoiceIndex<2)
			{
				_isMonCheck = true;
			}

		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameY(0);
		IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->setFrameY(0);
		_isSkillCheck = false;
		_isMonCheck = false;
		if (_playerTurn == SUMSU_TURN)
		{
			_playerTurn = ATAHO_TURN;
		}
	}
		
	
	switch (_gameTurn)
	{
		case ATAHO_CHOICE:
			atahoSkillCheck();
		break;
		case SUMSU_CHOICE:
			sumsuSkillCheck();
		break;
		case ATAHO_ATTACK:
			if(_isAtahoSkillFire)
			{
				_pm->getPlayer()->setSkil(_choiceIndex, _skillIndex, _monIndex);
				if(_choiceIndex == 5) _pm->getPlayer2()->setSkill(_choiceIndex, _skillIndex, _monIndex);

				_isAtahoSkillFire = false;
			}
			else if (!_isAtahoSkillFire)
			{
				if (_pm->getPlayer()->getMove() == ATTACKEND)
				{
					_pm->getPlayer()->setMove(FIGHTREADY);
				}

				if (_pm->getPlayer()->getMove() == FIGHTREADY)
				{
					setEnemyDead(0);
				}
					
				_isSumsuSkillFire = true;
			}
		break;
		case SUMSU_ATTACK:
			if(_isSumsuSkillFire)
			{
				_pm->getPlayer2()->setSkill(_sChoiceIndex, _sSkillIndex, _sMonIndex);
				if (_sChoiceIndex == 5) _pm->getPlayer()->setSkil(_sChoiceIndex, _sSkillIndex, _sMonIndex);

				_isSumsuSkillFire = false;
			}
			else if(!_isSumsuSkillFire)
			{
				if (_pm->getPlayer2()->getMove() == S_ATTACKEND)
				{
					_pm->getPlayer2()->setMove(S_FIGHTREADY);
				}

				if (_pm->getPlayer2()->getMove() == S_FIGHTREADY)	setEnemyDead(0);					
			}
		break;
		case ENEMY_ATTACK:
			_isAtahoSkillFire = false;
			_isSumsuSkillFire = false;
			if(_em->getAttackEnd() == false)
			{
				_em->hitPlayer();
			}
			else
			{
				_gameTurn = (_pm->getPlayer()->getAttribute().currentHp > 0) ? ATAHO_CHOICE : SUMSU_CHOICE;
				_em->setAttackEnd(false);
			}
		break;

	}

	//if (_isTurn==false&&_isFight == false)
	//{
	//	if (_em->getVEnmey().size() == 0)
	//	{
	//		SCENEMANAGER->changeScene(SCENEMANAGER->getCurrentSceneName());
	//	}
	//}

	
	if(_gameTurn == BATTLE_WIN || _gameTurn == BATTLE_ESCAPE)
	{
		sceneCount++;
		if (sceneCount > 100)
		{
			_pm->getPlayer()->setX(SCENEMANAGER->getPlayerScenePosition().x); _pm->getPlayer()->setY(SCENEMANAGER->getPlayerScenePosition().y);
			_pm->getPlayer2()->setX(SCENEMANAGER->getPlayerScenePosition().x); _pm->getPlayer2()->setY(SCENEMANAGER->getPlayerScenePosition().y);

			_pm->getPlayer()->setSkillFrame(0);

			_vEnemyHpBar.clear();
			while (_em->getVEnmey().size() > 0)
			{
				_em->removeEnemy(0);				
			}
			SOUNDMANAGER->stop("BattleTheMa1");
			SOUNDMANAGER->stop("BattleTheMa2");

			_pm->getPlayer()->setSceneMode(FIELDMODE, LEFT);
			_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_LEFT);

			SCENEMANAGER->changeScene(SCENEMANAGER->getCurrentSceneName());
		}
	}

	for (int i = 0; i < _em->getVEnmey().size(); ++i)
	{
		_vEnemyHpBar[i]->update();
		_vEnemyHpBar[i]->setGauge(_em->getVEnmey()[i]->getTagEnmey().hp, _em->getVEnmey()[i]->getTagEnmey().totalHp);

	}

}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("배틀장면절벽")->render(getMemDC());
	//if (SCENEMANAGER->getCurrentSceneName() == "필드씬1") IMAGEMANAGER->findImage("배틀장면절벽")->render(getMemDC());
	//else if (SCENEMANAGER->getCurrentSceneName() == "필드씬2") IMAGEMANAGER->findImage("배틀장면언덕")->render(getMemDC());
	//else if (SCENEMANAGER->getCurrentSceneName() == "필드씬3") IMAGEMANAGER->findImage("배틀장면대나무")->render(getMemDC());
	
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	_em->render();

	if (_gameTurn==ATAHO_CHOICE||_gameTurn==SUMSU_CHOICE)
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
		if(_gameTurn == ATAHO_CHOICE)
		{
			if (_choiceIndex<3 || _choiceIndex>3)
			{
				IMAGEMANAGER->findImage("스킬1")->frameRender(CAMERA->getCameraDC(), 350, 230);
				if (_choiceIndex == 5) {}
				else
				{
					IMAGEMANAGER->findImage("스킬2")->frameRender(CAMERA->getCameraDC(), 350, 280);
					IMAGEMANAGER->findImage("스킬3")->frameRender(CAMERA->getCameraDC(), 350, 330);
				}
				if (_choiceIndex == 4)
				{
					IMAGEMANAGER->findImage("스킬4")->frameRender(CAMERA->getCameraDC(), 350, 380);
					IMAGEMANAGER->findImage("스킬5")->frameRender(CAMERA->getCameraDC(), 350, 430);
				}
			}
		}
		if(_gameTurn ==SUMSU_CHOICE)
		{
			if (_sChoiceIndex<3 || _sChoiceIndex>3)
			{
				IMAGEMANAGER->findImage("스킬1")->frameRender(CAMERA->getCameraDC(), 350, 230);
				if ((_sChoiceIndex == 0 && _gameTurn == SUMSU_CHOICE) || _sChoiceIndex == 5) {}
				else
				{
					IMAGEMANAGER->findImage("스킬2")->frameRender(CAMERA->getCameraDC(), 350, 280);
					IMAGEMANAGER->findImage("스킬3")->frameRender(CAMERA->getCameraDC(), 350, 330);
				}
				if (_sChoiceIndex == 4)
				{
					IMAGEMANAGER->findImage("스킬4")->frameRender(CAMERA->getCameraDC(), 350, 380);
					IMAGEMANAGER->findImage("스킬5")->frameRender(CAMERA->getCameraDC(), 350, 430);
				}
			}
		}
		
	}
	if (_isSkillCheck)
	{
		IMAGEMANAGER->findImage("MONCHECKBUTTON")->frameRender(CAMERA->getCameraDC(), _monX, _monY);
	}

	for (_viEnemyHpBar = _vEnemyHpBar.begin(); _viEnemyHpBar != _vEnemyHpBar.end(); ++_viEnemyHpBar)
	{
		(*_viEnemyHpBar)->render();
	}

	fontUI();
	//char str[123];
	//sprintf_s(str, "%d", _em->getVEnmey().size());
	//TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
}

void battleScene::addImage(void)
{

	IMAGEMANAGER->addImage("스킬선택창", "image/ui/스킬선택창.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("스킬선택창2", "image/ui/스킬선택창2.bmp", 350, 375, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("기본기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("개인기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("단체기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("도구아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("모드아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("특수기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	

	IMAGEMANAGER->addFrameImage("도구1", "image/ui/아이템.bmp,", 600, 250, 12, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("도구2", "image/ui/아이템.bmp,", 600, 250, 12, 5, true, RGB(255, 0, 255));

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

}

void battleScene::fontUI(void)
{
	HFONT font, ofont;
	char charName[] = "아타호";
	char charName2[] = "스마슈";

	
	char str1[] = "기본기";
	char str2[] = "개인기";
	char str3[] = "단체기";
	char str4[] = "도구";
	char str5[] = "모드";
	char str6[] = "특수기";

	char temp[128];
	char tempHP[128];

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	//sprintf(temp, "%d", _em->getVEnmey().size());
	//TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, temp, strlen(temp));
	if(_gameTurn==ATAHO_CHOICE||_gameTurn==SUMSU_CHOICE)
	{
		if (_gameTurn == ATAHO_CHOICE) TextOut(CAMERA->getCameraDC(), 345, 25, charName, strlen(charName));
		if (_gameTurn == SUMSU_CHOICE) TextOut(CAMERA->getCameraDC(), 345, 25, charName2, strlen(charName2));
		if (_choiceIndex == 0)
		{
			
			if (_gameTurn == ATAHO_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str1, strlen(str1));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "정권", strlen("정권"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "돌려차기", strlen("돌려차기"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "다리후리기", strlen("다리후리기"));
			}
		}
		if(_sChoiceIndex ==0)
		{
			
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str1, strlen(str1));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "베기", strlen("베기"));
			}
		}
			
			
		
		if (_choiceIndex == 1)
		{
			
			if (_gameTurn == ATAHO_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "호격권", strlen("호격권"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "맹호스페셜", strlen("맹호스페셜"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "맹호광파참", strlen("맹호광파참"));
			}
		}
		if(_sChoiceIndex==1)
		{
			
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "대타격", strlen("대타격"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "난도질", strlen("난도질"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "절사어면", strlen("절사어면"));
			}
		}
		if (_choiceIndex == 2)
		{
			
			if (_gameTurn == ATAHO_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "맹호난무", strlen("맹호난무"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "노익장대폭발", strlen("노익장대폭발"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "취호염무", strlen("취호염무"));
			}
		}
		if(_sChoiceIndex==2)
		{
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "백인일섬", strlen("백인일섬"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "분신", strlen("분신"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "용오름", strlen("용오름"));
			}
		}
		if (_choiceIndex == 3||_sChoiceIndex==3) 
		{
			if(_gameTurn==ATAHO_CHOICE)
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str4, strlen(str4));
		}
		if (_choiceIndex == 3 || _sChoiceIndex == 3)
		{
			if (_gameTurn ==SUMSU_CHOICE)
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str4, strlen(str4));
		}

		if (_choiceIndex == 4 || _sChoiceIndex == 4)
		{
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str5, strlen(str5));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "보통", strlen("보통"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "돌격", strlen("돌격"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "방어", strlen("방어"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 390, "선제", strlen("선제"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 440, "반격", strlen("반격"));
			
		} 
		if (_choiceIndex == 5 || _sChoiceIndex == 5)
		{
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str6, strlen(str6));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "도주", strlen("도주"));
		} 
	}

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
//아이콘 변경
void battleScene::iconChange(void)
{
	switch (_choiceIndex)
	{
	case 0:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(11);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(11);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
		}
		

		break;
	case 1:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
		}
		
		break;
	case 2:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(10);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(2);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(14);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(0);
		}
		
		break;
	case 3:

		break;
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
	case 5:
		IMAGEMANAGER->findImage("스킬1")->setFrameX(0);
		IMAGEMANAGER->findImage("스킬1")->setFrameY(2);
		break;
	}
	switch (_sChoiceIndex)
	{
	case 0:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
		}

		break;
	case 1:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(16);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(2);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(16);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(2);
		}
		break;
	case 2:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("스킬1")->setFrameX(13);
			IMAGEMANAGER->findImage("스킬1")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬2")->setFrameX(17);
			IMAGEMANAGER->findImage("스킬2")->setFrameY(0);
			IMAGEMANAGER->findImage("스킬3")->setFrameX(16);
			IMAGEMANAGER->findImage("스킬3")->setFrameY(2);
		}
		break;
	case 3:

		break;
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
	case 5:
		IMAGEMANAGER->findImage("스킬1")->setFrameX(0);
		IMAGEMANAGER->findImage("스킬1")->setFrameY(2);
		break;
	}
}

void battleScene::skillChoice(void)
{
}

void battleScene::atahoSkillCheck()
{
	for (int i = 0; i<6; i++)
	{
		if (_choiceIndex == i)
		{
			_choiceX = 357 + i * 50;
		}
	}
	if (_gameTurn == ATAHO_CHOICE)
	{
		for (int i = 0; i<5; i++)
		{
			if (_skillIndex == i)
			{
				_skillY = 245 + i * 50;
			}
		}
	}
	for (int i = 0; i<_em->getVEnmey().size(); i++)
	{
		if (_monIndex == i)
		{
			_monY = 570 + i * 40;
		}
	}
}

void battleScene::sumsuSkillCheck()
{
	if (_gameTurn == SUMSU_CHOICE)
	{
		for (int i = 0; i<6; i++)
		{
			if (_sChoiceIndex == i)
			{
				_choiceX = 357 + i * 50;
			}
		}
		for (int i = 0; i<5; i++)
		{
			if (_sSkillIndex == i)
			{
				_skillY = 245 + i * 50;
			}
		}
		for (int i = 0; i<_em->getVEnmey().size(); i++)
		{
			if (_sMonIndex == i)
			{
				_monY = 570 + i * 40;
			}
		}

	}
}

void battleScene::setEnemyDead(int index)
{

	//for (int i = 0; i < _em->getVEnmey().size(); i++)
	//{
	//
	//	//에너미 사망
	//	if (_em->getVEnmey()[index]->getTagEnmey().direction != DEAD && _em->getVEnmey()[index]->getTagEnmey().hp <= 0)
	//	{
	//		if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
	//		{
	//			_pm->getPlayer()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
	//			_pm->getPlayer2()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
	//			_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
	//
	//		}
	//		else if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_NOCKDOWN)
	//		{
	//			_pm->getPlayer()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
	//		//	_gold.money += _em->getVEnmey()[index]->getTagEnmey().dropGold;
	//			_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
	//		}
	//		else if (_pm->getPlayer()->getMove() == NOCKDOWN && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
	//		{
	//			_pm->getPlayer2()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
	//			//_gold.money += _em->getVEnmey()[index]->getTagEnmey().dropGold;
	//			_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
	//		}
	//		if (_pm->getPlayer()->getSkillFrame() == 0)_em->getVEnmey()[index]->setEnemyDirection(DEAD);
	//
	//		if (_pm->getPlayer2()->getSkillFrame() == 0) _em->getVEnmey()[index]->setEnemyDirection(DEAD);
	//	}
	//	if (_em->getVEnmey()[index]->getTagEnmey().fadeCount >= 80)
	//	{
	//		_em->removeEnemy(i);
	//		if (_gameTurn == ATAHO_ATTACK)
	//			_gameTurn = SUMSU_ATTACK;
	//		else if (_gameTurn == SUMSU_ATTACK)
	//			_gameTurn = ENEMY_ATTACK;
	//		//return TRUE;
	//		//_playerTurn++;
	//	}
	//	
	//}

	//에너미 사망
	/*if (_em->getVEnmey()[index]->getTagEnmey().direction != DEAD && _em->getVEnmey()[index]->getTagEnmey().hp <= 0)
		{
			//if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
			//{
			//	_pm->getPlayer()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			//	_pm->getPlayer2()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			//	_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
			//
			//}
			//else if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_NOCKDOWN)
			//{
			//	_pm->getPlayer()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			////	_gold.money += _em->getVEnmey()[index]->getTagEnmey().dropGold;
			//	_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
			//}
			//else if (_pm->getPlayer()->getMove() == NOCKDOWN && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
			//{
			//	_pm->getPlayer2()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			//	//_gold.money += _em->getVEnmey()[index]->getTagEnmey().dropGold;
			//	_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);
			//}
			//if (_pm->getPlayer()->getSkillFrame() == 0) _em->getVEnmey()[index]->setEnemyDirection(DEAD);

			//if (_pm->getPlayer2()->getSkillFrame() == 0) _em->getVEnmey()[index]->setEnemyDirection(DEAD);

			_em->getVEnmey()[index]->setEnemyDirection(DEAD);

		}

		//if (_em->getVEnmey()[index]->getTagEnmey().hp == 0)
		//{
		//	_em->getVEnmey()[index]->setEnemyDirection(DEAD);
		//	_em->getVEnmey()[index]->setEnemyDirection(DEAD);
		//}

		if (_em->getVEnmey()[index]->getTagEnmey().fadeCount >= 80)
		{
			_pm->getPlayer()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			_pm->getPlayer2()->setExp(_em->getVEnmey()[index]->getTagEnmey().exp);
			_pm->setMoney((-1) * _em->getVEnmey()[index]->getTagEnmey().dropGold);

			_em->removeEnemy(index);
			if (_gameTurn == ATAHO_ATTACK)
				_gameTurn = SUMSU_ATTACK;
			else if (_gameTurn == SUMSU_ATTACK)
			{
				if (_em->getVEnmey().size() > 0)  _gameTurn = ENEMY_ATTACK;
			}
			//return TRUE;
			//_playerTurn++;
		}*/

	/*for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		//에너미 사망
		if (_em->getVEnmey()[i]->getTagEnmey().direction != DEAD && _em->getVEnmey()[i]->getTagEnmey().hp == 0)
		{
			if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
			{
				_pm->getPlayer()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_pm->getPlayer2()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_pm->setMoney((-1) * _em->getVEnmey()[i]->getTagEnmey().dropGold);

			}
			else if (_pm->getPlayer()->getMove() == FIGHTREADY && _pm->getPlayer2()->getMove() == S_NOCKDOWN)
			{
				_pm->getPlayer()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_pm->setMoney((-1) * _em->getVEnmey()[i]->getTagEnmey().dropGold);
			}
			else if (_pm->getPlayer()->getMove() == NOCKDOWN && _pm->getPlayer2()->getMove() == S_FIGHTREADY)
			{
				_pm->getPlayer2()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_pm->setMoney((-1) * _em->getVEnmey()[i]->getTagEnmey().dropGold);
			}
			if (_pm->getPlayer()->getSkillFrame() == 0)_em->getVEnmey()[i]->setEnemyDirection(DEAD);

			if (_pm->getPlayer2()->getSkillFrame() == 0) _em->getVEnmey()[i]->setEnemyDirection(DEAD);
		}
		if (_em->getVEnmey()[i]->getTagEnmey().fadeCount >= 80)
		{
			_em->removeEnemy(i);
		}
		if (_em->getVEnmey().size() == 0)
		{
			_pm->getPlayer()->setMove(SEREMONI);
			_pm->getPlayer2()->setMove(S_SEREMONI);
		}
	}*/


	for (int i = 0; i < _em->getVEnmey().size(); ++i)
	{
		// 해당 에너미 사망
		if (_em->getVEnmey()[i]->getTagEnmey().direction != DEAD && _em->getVEnmey()[i]->getTagEnmey().direction != DEAD_END 
			&& _em->getVEnmey()[i]->getTagEnmey().hp <= 0)
		{
			_em->getVEnmey()[i]->setEnemyDirection(DEAD);
			_isDeadEnemy = true;
		}
		// 사망 후 80카운트 후에 exp, gold 증가
		if (_em->getVEnmey()[i]->getTagEnmey().direction == DEAD && _em->getVEnmey()[i]->getTagEnmey().fadeCount >= 80)
		{
			if (_pm->getPlayer()->getAttribute().currentHp > 0) _pm->getPlayer()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
			if (_pm->getPlayer2()->getAttribute().currentHp > 0) _pm->getPlayer2()->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
			_pm->setMoney((-1) * _em->getVEnmey()[i]->getTagEnmey().dropGold);
			_isDeadEnemy = false;
			// 에너미 완전 사망
			_em->getVEnmey()[i]->setEnemyDirection(DEAD_END);
		}

	}

	bool _isWin = true;
	for (int i = 0; i < _em->getVEnmey().size(); ++i)
	{
		// 턴넘김
		// 1. 적 중 한마리라도 dead 상태이면, dead상태가 끝난 후(경험치 골드 상승 타임 끝난 후), 턴 넘김
		// 2. 적들이 살아있으면 대기없이 바로 턴 넘김
		if (!_isDeadEnemy)
		{
			if (_gameTurn != BATTLE_WIN || _gameTurn != BATTLE_ESCAPE)
			{
				// 도주 스킬을 썼다면 씬 전환 할 수 있다.
				if (_pm->getPlayer()->getX() < 100 && _pm->getPlayer2()->getX() < 100)
				{
					//_isSceneCount = true;
					_gameTurn = BATTLE_ESCAPE;
					break;
				}

				// 적이 전부 죽은 상태여야만 세레모니를 할 수 있다
				if (_isWin && _em->getVEnmey()[i]->getTagEnmey().direction == DEAD_END)
				{
					if (i == _em->getVEnmey().size() - 1)
					{
						_pm->getPlayer()->setMove(SEREMONI);
						_pm->getPlayer2()->setMove(S_SEREMONI);
						//_isSceneCount = true;
						_gameTurn = BATTLE_WIN;
						break;
					}
				}
				else _isWin = false;
				
				if (i == _em->getVEnmey().size() - 1)
				{
					if (_gameTurn == ATAHO_ATTACK)
					{
						_gameTurn = (_pm->getPlayer2()->getAttribute().currentHp > 0) ? SUMSU_ATTACK : ENEMY_ATTACK;
					}
					else if (_gameTurn == SUMSU_ATTACK)
					{
						_gameTurn = ENEMY_ATTACK;
					}
				}
				
			}
		}
	}

}