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

	IMAGEMANAGER->addImage("��Ʋ���볪��","image/battleScene/��Ʋ��� �볪��.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʋ�����", "image/battleScene/��Ʋ��� ���.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʋ�������", "image/battleScene/��Ʋ��� ����.bmp", 1000, 550, true, RGB(255, 0, 255));

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
				if (_sMonIndex < _em->getVEnmey().size() - 1)_sMonIndex = 0;
			}

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
				_gameTurn = SUMSU_CHOICE;
			}
			else if(_choiceIndex>1)
			{
				_isSkillCheck = false;
				_gameTurn = SUMSU_CHOICE;
							
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
				_gameTurn = ATAHO_ATTACK;
			}
			else if (_sChoiceIndex>1)
			{
				_isSkillCheck = false;
				_gameTurn = ATAHO_ATTACK;
				
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
				_isAtahoSkillFire = false;
			}
			else if (!_isAtahoSkillFire && _pm->getPlayer()->getMove() == ATTACKEND)
			{
				_pm->getPlayer()->setMove(FIGHTREADY);
				_gameTurn = SUMSU_ATTACK;
				_isSumsuSkillFire = true;
			}
		break;
		case SUMSU_ATTACK:
			if(_isSumsuSkillFire)
			{
				_isAtahoSkillFire = false;
				_pm->getPlayer2()->setSkill(_sChoiceIndex, _sSkillIndex, _sMonIndex);
				if (_pm->getPlayer2()->getImage()->getFrameX() == _pm->getPlayer2()->getImage()->getMaxFrameX());
				_gameTurn = ENEMY_ATTACK;
			}
			
		break;
		case ENEMY_ATTACK:
			_isAtahoSkillFire = false;
			_em->hitPlayer();
			_gameTurn = ATAHO_CHOICE;
			
		break;

	}

	if (_isTurn==false&&_isFight == false)
	{
		if (_em->getVEnmey().size() == 0)
		{
			SCENEMANAGER->changeScene(SCENEMANAGER->getCurrentSceneName());
		}
	}
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("��Ʋ�������")->render(getMemDC());
	//if (SCENEMANAGER->getCurrentSceneName() == "�ʵ��1") IMAGEMANAGER->findImage("��Ʋ�������")->render(getMemDC());
	//else if (SCENEMANAGER->getCurrentSceneName() == "�ʵ��2") IMAGEMANAGER->findImage("��Ʋ�����")->render(getMemDC());
	//else if (SCENEMANAGER->getCurrentSceneName() == "�ʵ��3") IMAGEMANAGER->findImage("��Ʋ���볪��")->render(getMemDC());
	
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_gameTurn==ATAHO_CHOICE||_gameTurn==SUMSU_CHOICE)
	{
		IMAGEMANAGER->findImage("��ų����â")->render(CAMERA->getCameraDC(), 320, 0);
		IMAGEMANAGER->findImage("��ų����â2")->render(CAMERA->getCameraDC(), 320, 175);
		IMAGEMANAGER->findImage("�⺻�������")->frameRender(CAMERA->getCameraDC(), 345, 75);
		IMAGEMANAGER->findImage("���α������")->frameRender(CAMERA->getCameraDC(), 395, 75);
		IMAGEMANAGER->findImage("��ü�������")->frameRender(CAMERA->getCameraDC(), 445, 75);
		IMAGEMANAGER->findImage("����������")->frameRender(CAMERA->getCameraDC(), 495, 75);
		IMAGEMANAGER->findImage("��������")->frameRender(CAMERA->getCameraDC(), 545, 75);
		IMAGEMANAGER->findImage("Ư���������")->frameRender(CAMERA->getCameraDC(), 595, 75);
		
		IMAGEMANAGER->findImage("SKILLBUTTON")->frameRender(CAMERA->getCameraDC(), _choiceX, _choiceY);
		IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->frameRender(CAMERA->getCameraDC(), _skillX, _skillY);
		if(_gameTurn == ATAHO_CHOICE)
		{
			if (_choiceIndex<3 || _choiceIndex>3)
			{
				IMAGEMANAGER->findImage("��ų1")->frameRender(CAMERA->getCameraDC(), 350, 230);
				if (_choiceIndex == 5) {}
				else
				{
					IMAGEMANAGER->findImage("��ų2")->frameRender(CAMERA->getCameraDC(), 350, 280);
					IMAGEMANAGER->findImage("��ų3")->frameRender(CAMERA->getCameraDC(), 350, 330);
				}
				if (_choiceIndex == 4)
				{
					IMAGEMANAGER->findImage("��ų4")->frameRender(CAMERA->getCameraDC(), 350, 380);
					IMAGEMANAGER->findImage("��ų5")->frameRender(CAMERA->getCameraDC(), 350, 430);
				}
			}
		}
		if(_gameTurn ==SUMSU_CHOICE)
		{
			if (_sChoiceIndex<3 || _sChoiceIndex>3)
			{
				IMAGEMANAGER->findImage("��ų1")->frameRender(CAMERA->getCameraDC(), 350, 230);
				if ((_sChoiceIndex == 0 && _gameTurn == SUMSU_CHOICE) || _sChoiceIndex == 5) {}
				else
				{
					IMAGEMANAGER->findImage("��ų2")->frameRender(CAMERA->getCameraDC(), 350, 280);
					IMAGEMANAGER->findImage("��ų3")->frameRender(CAMERA->getCameraDC(), 350, 330);
				}
				if (_sChoiceIndex == 4)
				{
					IMAGEMANAGER->findImage("��ų4")->frameRender(CAMERA->getCameraDC(), 350, 380);
					IMAGEMANAGER->findImage("��ų5")->frameRender(CAMERA->getCameraDC(), 350, 430);
				}
			}
		}
		
	}
	if (_isSkillCheck)
	{
		IMAGEMANAGER->findImage("MONCHECKBUTTON")->frameRender(CAMERA->getCameraDC(), _monX, _monY);
	}
	fontUI();
}

void battleScene::addImage(void)
{

	IMAGEMANAGER->addImage("��ų����â", "image/ui/��ų����â.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ų����â2", "image/ui/��ų����â2.bmp", 350, 375, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("�⺻�������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���α������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ü�������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ư���������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	

	IMAGEMANAGER->addFrameImage("����1", "image/ui/������.bmp,", 600, 250, 12, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����2", "image/ui/������.bmp,", 600, 250, 12, 5, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("�⺻�������")->setFrameX(5);
	IMAGEMANAGER->findImage("���α������")->setFrameX(6);
	IMAGEMANAGER->findImage("��ü�������")->setFrameX(7);
	IMAGEMANAGER->findImage("����������")->setFrameX(1);
	IMAGEMANAGER->findImage("��������")->setFrameX(8);
	IMAGEMANAGER->findImage("Ư���������")->setFrameX(9);

	IMAGEMANAGER->addFrameImage("SKILLBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameX(6);
	IMAGEMANAGER->addFrameImage("SKILLCHOICEBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SKILLCHOICEBUTTON")->setFrameX(7);
	IMAGEMANAGER->addFrameImage("MONCHECKBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("MONCHECKBUTTON")->setFrameX(7);

}

void battleScene::fontUI(void)
{
	HFONT font, ofont;
	char charName[] = "��Ÿȣ";
	char charName2[] = "������";

	
	char str1[] = "�⺻��";
	char str2[] = "���α�";
	char str3[] = "��ü��";
	char str4[] = "����";
	char str5[] = "���";
	char str6[] = "Ư����";

	char temp[128];
	char tempHP[128];

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
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
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "����", strlen("����"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "��������", strlen("��������"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "�ٸ��ĸ���", strlen("�ٸ��ĸ���"));
			}
		}
		if(_sChoiceIndex ==0)
		{
			
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str1, strlen(str1));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "����", strlen("����"));
			}
		}
			
			
		
		if (_choiceIndex == 1)
		{
			
			if (_gameTurn == ATAHO_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "ȣ�ݱ�", strlen("ȣ�ݱ�"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "��ȣ�����", strlen("��ȣ�����"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "��ȣ������", strlen("��ȣ������"));
			}
		}
		if(_sChoiceIndex==1)
		{
			
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "��Ÿ��", strlen("��Ÿ��"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "������", strlen("������"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "������", strlen("������"));
			}
		}
		if (_choiceIndex == 2)
		{
			
			if (_gameTurn == ATAHO_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "��ȣ����", strlen("��ȣ����"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "�����������", strlen("�����������"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "��ȣ����", strlen("��ȣ����"));
			}
		}
		if(_sChoiceIndex==2)
		{
			if (_gameTurn == SUMSU_CHOICE)
			{
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "�����ϼ�", strlen("�����ϼ�"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "�н�", strlen("�н�"));
				TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "�����", strlen("�����"));
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
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "����", strlen("����"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 290, "����", strlen("����"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 340, "���", strlen("���"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 390, "����", strlen("����"));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 440, "�ݰ�", strlen("�ݰ�"));
			
		} 
		if (_choiceIndex == 5 || _sChoiceIndex == 5)
		{
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str6, strlen(str6));
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 80, 240, "����", strlen("����"));
		} 
	}

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
//������ ����
void battleScene::iconChange(void)
{
	switch (_choiceIndex)
	{
	case 0:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(11);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(11);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		

		break;
	case 1:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		
		break;
	case 2:
		if (_gameTurn == ATAHO_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(2);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(14);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		
		break;
	case 3:

		break;
	case 4:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų2")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų2")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų3")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų3")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų4")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų4")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų5")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų5")->setFrameY(1);
		break;
	case 5:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(0);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(2);
		break;
	}
	switch (_sChoiceIndex)
	{
	case 0:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
		}

		break;
	case 1:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(2);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(2);
		}
		break;
	case 2:
		
		if (_gameTurn == SUMSU_CHOICE)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(17);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(2);
		}
		break;
	case 3:

		break;
	case 4:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų2")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų2")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų3")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų3")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų4")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų4")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų5")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų5")->setFrameY(1);
		break;
	case 5:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(0);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(2);
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
