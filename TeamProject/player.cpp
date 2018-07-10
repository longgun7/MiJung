#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"
#include "playMap.h"

HRESULT player::init()
{
	
	//��Ÿȣ �̹���
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ������", "image/player/��Ÿȣ ������.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�޸��", "image/player/��Ÿȣ �޸��.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 180, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�Ʒ��̵�", "image/player/��Ÿȣ �Ʒ��̵�.bmp", 190, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�������̵�", "image/player/��Ÿȣ �������̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("��Ÿȣ�������", "image/player/��Ÿȣ �������.bmp", 704, 172, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��������", "image/player/��Ÿȣ ��������.bmp", 704, 172, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����������", "image/player/��Ÿȣ �����������.bmp", 220, 80, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ������", "image/player/��Ÿȣ ��ȣ������.bmp", 244, 85, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ����", "image/player/��Ÿȣ ��ȣ����.bmp", 1912, 110, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ�����", "image/player/��Ÿȣ ��ȣ�����2.bmp", 4576, 172, 26, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣȣ�ݱ�", "image/player/��Ÿȣ ȣ�ݱ�.bmp", 1100, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 502, 85, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣȭ��", "image/player/��Ÿȣ ȭ��.bmp", 290, 90, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����ñ�", "image/player/��Ÿȣ �����ñ�.bmp", 655, 95, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��������", "image/player/��Ÿȣ ��������.bmp", 55, 86, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�ǰ�", "image/player/��Ÿȣ �ǰ�.bmp", 50, 77, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�������", "image/player/��Ÿȣ �������3.bmp", 870, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�ڰ���", "image/player/��Ÿȣ �ڰ���.bmp", 1145, 50, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ������", "image/player/��Ÿȣ ������.bmp", 246, 63, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ���","image/player/��Ÿȣ ���.bmp", 45, 64, 1, 1, true, RGB(255, 0, 255));
	//��Ÿ��
	IMAGEMANAGER->addFrameImage("�ö�Ÿ��", "image/player/�ö�Ÿ��.bmp", 100, 120, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��", "image/player/��Ÿ��.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+1", "image/player/��Ÿ��+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+2", "image/player/��Ÿ��+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+3", "image/player/��Ÿ��+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+4", "image/player/��Ÿ��+4.bmp", 65, 94, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-1", "image/player/��Ÿ��-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-2", "image/player/��Ÿ��-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-3", "image/player/��Ÿ��-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-4", "image/player/��Ÿ��-4.bmp", 80, 100, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��", "image/player/������Ÿ��.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+1", "image/player/������Ÿ��+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+2", "image/player/������Ÿ��+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+3", "image/player/������Ÿ��+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+4", "image/player/������Ÿ��+4.bmp", 66, 114, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-1", "image/player/������Ÿ��-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-2", "image/player/������Ÿ��-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-3", "image/player/������Ÿ��-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-4", "image/player/������Ÿ��-4.bmp", 81, 112, 1, 1, true, RGB(255, 0, 255));
	
	//����Ʈ
	IMAGEMANAGER->addFrameImage("������ȸ����", "image/player/������ ȸ����.bmp", 400, 42, 5, 1, true, RGB(255, 0, 255));

	//����Ʈ
	_effectImage.img = IMAGEMANAGER->findImage("������ȸ����");
	_effectImage.frameImage = 0;
	_effectImage.frame = 0;

	_img = IMAGEMANAGER->findImage("��Ÿȣ����");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY/2;
	_jumpPower  = 5.0f;
	_gravity    = 0.2f;
	_imageFrame	= 0;
	_frame		= 0;
	_skillFrame = 0;
	_slopeFrame = 0;
	_moveSpeed  = 5.0f;
	_isMotionLive = false;
	_isJumping = false;
	_isWeaponMounting = false;
	_attribute.isLevelUp = false;
	_attribute.atk = 10;
	_attribute.def = 10;
	_attribute.luck = 10;
	_attribute.cri = 5;
	_attribute.speed = 10;
	_attribute.currentHp = 20;
	_attribute.maxHp = 20;
	_attribute.currentMp = 20;
	_attribute.maxMp = 20;
	_attribute.currentExp = 0;
	_attribute.maxExp = 100;
	_attribute.level = 1;
	_enemyIndex = 0;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	//��Ÿȣ Ÿ�� ��ų 
	
	//ȣ�ݱ�
	_soloSkillEffect1 = new atahoTargetSkill1;
	_soloSkillEffect1->init();
	//��ȣ�����
	_soloSkillEffect2 = new atahoTargetSkill2;
	_soloSkillEffect2->init();
	//��������
	_soloSkillEffect3 = new atahoTargetSkill3;
	_soloSkillEffect3->init();
	//������ų2
	_areaSkillEffect2 = new atahoAreaSkill2;
	_areaSkillEffect2->init();
	//������ų3
	_areaSkillEffect3 = new atahoAreaSkill3;
	_areaSkillEffect3->init();
	//���� ����Ʈ
	_gameEffect = new gameEffect;
	_gameEffect->init();

	_zOrderRC = RectMake(_rc.left, _rc.bottom - 25, _img->getFrameWidth(), 25);
	
	return S_OK;
}

void player::update()
{
	playerImage();		  //�̹���
	fieldKeyManager();	  //�ʵ��� Ű�Ŵ���
	battleKeyManager();   //��Ʋ��� Ű�Ŵ���
	slopeNumImage();      //����ѹ��� ���� ���ϴ� �̹���
	eventKeyManager();    //�̺�Ʈ��� Ű�Ŵ���
	
	if (_isMotionLive )
	{
		imageFrame();	  //�̹���������
	}
	move();			      //������
	levelCheck();	      //������ ����

	//��ų ����Ʈ ������Ʈ
	_soloSkillEffect1->update(); //ȣ�ݱ� ��ų����Ʈ ������Ʈ
	_soloSkillEffect2->update(); //��ȣ����� ��ų ����Ʈ ������Ʈ
	_soloSkillEffect3->update(); //�������� ��ų ����Ʈ ������Ʈ
	_areaSkillEffect2->update(); //ȭ�� ȣȭ���ü��ü�! 
	_areaSkillEffect3->update(); //������ ������!
	_gameEffect->update();//���� ����Ʈ
	effectImage();

}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	char str2[124];
	sprintf_s(str2, "��Ÿȣ �̹���������: %d", _imageFrame);
	TextOut(getMemDC(), 100, 440, str2, strlen(str2));
	//���� ������
	char str[125];
	if (KEYMANAGER->isToggleKey('Z'))
	{
		sprintf_s(str, "���ʹ� hp : %d", _em->getVEnmey()[0]->getTagEnmey().hp);
		TextOut(getMemDC(), 100, 410, str, strlen(str));
	}//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
	//��ų ����Ʈ ����
	_soloSkillEffect1->render(); 
	_soloSkillEffect2->render();
	_soloSkillEffect3->render();
	_areaSkillEffect2->render();
	_areaSkillEffect3->render();
	_gameEffect->render();
	if (_isWeaponMounting)
	{//����Ʈ
		if (_move != AREASKILL1)
		{
			_effectImage.img->frameRender(getMemDC(), _x - 40, _y + 5);
		}
		if (_move == AREASKILL1)
		{
			_effectImage.img->frameRender(getMemDC(), _x - 30 , _y + 5);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		Rectangle(getMemDC(), _skillRC[i].left, _skillRC[i].top, _skillRC[i].right, _skillRC[i].bottom);
	}
}

void player::release()
{
	SAFE_DELETE(_soloSkillEffect1);
	SAFE_DELETE(_soloSkillEffect2);
	SAFE_DELETE(_soloSkillEffect3);
	SAFE_DELETE(_areaSkillEffect2);
	SAFE_DELETE(_areaSkillEffect3);
	SAFE_DELETE(_gameEffect);
}

void player::fieldKeyManager()
{
	
	//�ʵ忡 ���� ��
	if (_sceneMode == FIELDMODE)
	{
		//�����̴� ���
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			
			_move = LEFTMOVE;
			_isMotionLive = true;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			
			_move = RIGHTMOVE;
			_isMotionLive = true;
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			
			_move = UPMOVE;
			_isMotionLive = true;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			
			_move = DOWNMOVE;
			_isMotionLive = true;
		}

		//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		//{
		//	//_x += cosf(_angle)*_moveSpeed;
		//}
		//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		//{
		//	//_x += cosf(_angle)*_moveSpeed;
		//}
		//if (KEYMANAGER->isStayKeyDown(VK_UP))
		//{
		//	//_y += -sinf(_angle)*_moveSpeed;
		//}
		//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		//{
		//	//_y += -sinf(_angle)*_moveSpeed;
		//	
		//}

		//���ڼ�
		if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_move = DOWN;
			
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_move = LEFT;
			
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_move = RIGHT;
			
		}
		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_move = UP;
			
		}
	}
}

void player::battleKeyManager()
{

	//��Ʋ����� ��
	if (_sceneMode == BATTLEMODE)
	{	
		if (_attribute.currentHp > 0 && _em->getVEnmey().size() != 0)
		{
			//��ų
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (PtInRect(&_skillRC[0],_ptMouse) && _attribute.currentMp >= 3)
				{
					_move = SOLOSKILL1;
					_isMotionLive = true;
					_attribute.currentMp -= 3;

				}
				if (PtInRect(&_skillRC[1], _ptMouse) && _attribute.currentMp >= 3)
				{
					_move = SOLOSKILL2;
					_isMotionLive = true;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[2], _ptMouse) && _attribute.currentMp >= 3)
				{
					_move = SOLOSKILL3;
					_isMotionLive = true;
					_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 80;
					_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[3], _ptMouse) && _attribute.currentMp >= 3)
				{
					_move = AREASKILL1;
					_isMotionLive = true;
					_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 100;
					_y = WINSIZEY / 3;
					_jumpPower = 5.0f;
					_gravity = 0.2f;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[4], _ptMouse) && _attribute.currentMp >= 3)
				{
					_move = DRINK;
					_isMotionLive = true;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[5], _ptMouse) && _attribute.currentMp >= 3)
				{
					_move = AREASKILL3;
					_isMotionLive = true;
					_x = WINSIZEX / 2;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[6], _ptMouse))
				{
					_move = BASICSKILL1;
					_isMotionLive = true;
					_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 80;
					_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;

				}
				if (PtInRect(&_skillRC[7], _ptMouse))
				{
					_move = BASICSKILL2;
					_isMotionLive = true;

				}
				if (PtInRect(&_skillRC[8], _ptMouse))
				{
					_move = BASICSKILL3;
					_isMotionLive = true;

				}
			}
			if (KEYMANAGER->isOnceKeyDown('V'))
			{
				setPlayerDamage(11);
			}
			if (KEYMANAGER->isOnceKeyDown('B'))
			{
				_move = HPUP;
			}
			if (KEYMANAGER->isOnceKeyDown('J'))
			{
				_move = ESCAPE;
			}
		}
		if(_attribute.currentHp ==0)
		{
			_move = NOCKDOWN;
			_isMotionLive = true;
		}
	}
}

void player::eventKeyManager()
{
	//�̺�Ʈ���
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		_sceneMode = EVENTMODE;
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 2;
		_jumpPower = 5.0f;
		_gravity = 0.2f;
		_move = FRONT;
		_slopeNum = 4;
		_isWoodDrop = false;
	}

	//�Ʒ�Ű ������ �����δ�
	if (_sceneMode == EVENTMODE)
	{ 
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isMotionLive = true;
		}	
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_slopeNum -= 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_slopeNum += 1;
	}
	
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		_isWoodDrop = true;
	}
		
}



void player::slopeNumImage()
{
	//���� ����
	if (_sceneMode == EVENTMODE)
	{
		++_slopeFrame;

		if (_slopeFrame % 30 == 0)
		{
			//�¿� ��������
			_rndDirection = RND->getInt(2);

			if (_rndDirection == 0)
			{
				_slopeNum -= 1;

			}
			if (_rndDirection == 1)
			{
				_slopeNum += 1;
	
			}
	
			//���� ������ �ʱ�ȭ
			_slopeFrame = 0;
		}

		//������ ��� ���� ���� ��
		if (!_isWoodDrop)
		{
			//���� ��ȣ�� ���� �̹��� ����
			if (_slopeNum <= 0)
			{
				_move = LEFT4;
			}
			if (_slopeNum == 1)
			{
				_move = LEFT3;
			}
			if (_slopeNum == 2)
			{
				_move = LEFT2;
			}
			if (_slopeNum == 3)
			{
				_move = LEFT1;
			}
			if (_slopeNum == 4)
			{
				_move = FRONT;
			}
			if (_slopeNum == 5)
			{
				_move = RIGHT1;
			}
			if (_slopeNum == 6)
			{
				_move = RIGHT2;
			}
			if (_slopeNum == 7)
			{
				_move = RIGHT3;
			}
			if (_slopeNum >= 8)
			{
				_move = RIGHT4;
			}
		}

		//������ ��� ���� ��
		if (_isWoodDrop)
		{
			//���� ��ȣ�� ���� �̹��� ����
			if (_slopeNum <= 0)
			{
				_move = WOODLEFT4;
			}
			if (_slopeNum == 1)
			{
				_move = WOODLEFT3;
			}
			if (_slopeNum == 2)
			{
				_move = WOODLEFT2;
			}
			if (_slopeNum == 3)
			{
				_move = WOODLEFT1;
			}
			if (_slopeNum == 4)
			{
				_move = WOODFRONT;
			}
			if (_slopeNum == 5)
			{
				_move = WOODRIGHT1;
			}
			if (_slopeNum == 6)
			{
				_move = WOODRIGHT2;
			}
			if (_slopeNum == 7)
			{
				_move = WOODRIGHT3;
			}
			if (_slopeNum >= 8)
			{
				_move = WOODRIGHT4;
			}
		}
	}
}

void player::playerImage()
{
	//�����¿� ������
	switch (_move)
	{
	case LEFT:
		_img = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case RIGHT:
		_img = IMAGEMANAGER->findImage("��Ÿȣ������");
		break;
	case DOWN:
		_img = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case UP:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�޸��");
		break;
	case LEFTMOVE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	case RIGHTMOVE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�������̵�");
		break;
	case DOWNMOVE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�Ʒ��̵�");
		break;
	case UPMOVE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	default:
		break;
	}

	//��ų ������
	switch (_move)
	{
	case BASICSKILL1:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�������");
		break;
	case BASICSKILL2:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��������");
		break;
	case BASICSKILL3:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����������");
		break;
	case SOLOSKILL1:
		_img = IMAGEMANAGER->findImage("��Ÿȣȣ�ݱ�");
		break;
	case SOLOSKILL2:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��ȣ������");
		break;
	case SOLOSKILL3:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����");
		break;
	case AREASKILL1:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��ȣ����");
		break;
	case AREASKILL2:
		_img = IMAGEMANAGER->findImage("��Ÿȣȭ��");
		break;
	case AREASKILL3:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����������");
		break;
	case DRINK:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����ñ�");
		break;
	case DRUNKEN:
		_img = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case FIGHTREADY:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��������");
		_x = 100;
		_y = 200;
		break;
	case DAMAGE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�ǰ�");
		break;
	case DEFENCE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ���");
		break;
	case SEREMONI:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�������");
		break;
	case NOCKDOWN:
		_img = IMAGEMANAGER->findImage("��Ÿȣ������");
		break;
	case HPUP:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����������");
		break;
	case MPUP:
		_img = IMAGEMANAGER->findImage("��Ÿȣ�����������");
		break;
	default:
		break;
	}

	//�̺�Ʈ ������
	switch (_move)
	{
	case FRONT:
		_img = IMAGEMANAGER->findImage("��Ÿ��");
		break;
	case LEFT1:
		_img = IMAGEMANAGER->findImage("��Ÿ��-1");
		break;
	case LEFT2:
		_img = IMAGEMANAGER->findImage("��Ÿ��-2");
		break;
	case LEFT3:
		_img = IMAGEMANAGER->findImage("��Ÿ��-3");
		break;
	case LEFT4:
		_img = IMAGEMANAGER->findImage("��Ÿ��-4");
		break;
	case RIGHT1:
		_img = IMAGEMANAGER->findImage("��Ÿ��+1");
		break;
	case RIGHT2:
		_img = IMAGEMANAGER->findImage("��Ÿ��+2");
		break;
	case RIGHT3:
		_img = IMAGEMANAGER->findImage("��Ÿ��+3");
		break;
	case RIGHT4:
		_img = IMAGEMANAGER->findImage("��Ÿ��+4");
		break;
	case WOODFRONT:
		_img = IMAGEMANAGER->findImage("������Ÿ��");  
		break;
	case WOODLEFT1:
		_img = IMAGEMANAGER->findImage("������Ÿ��-1");
		break;
	case WOODLEFT2:
		_img = IMAGEMANAGER->findImage("������Ÿ��-2");
		break;
	case WOODLEFT3:
		_img = IMAGEMANAGER->findImage("������Ÿ��-3");
		break;
	case WOODLEFT4:
		_img = IMAGEMANAGER->findImage("������Ÿ��-4");
		break;
	case WOODRIGHT1:
		_img = IMAGEMANAGER->findImage("������Ÿ��+1");
		break;
	case WOODRIGHT2:
		_img = IMAGEMANAGER->findImage("������Ÿ��+2");
		break;
	case WOODRIGHT3:
		_img = IMAGEMANAGER->findImage("������Ÿ��+3");
		break;
	case WOODRIGHT4:
		_img = IMAGEMANAGER->findImage("������Ÿ��+4");
		break;

	default:
		break;
	}	
}
void player::imageFrame()
{
	//������ �̹���
	++_frame;
	
		if (_frame % 8 == 0)
		{
			++_imageFrame;

			_img->setFrameX(_imageFrame);
			
			if (_imageFrame >= _img->getMaxFrameX())
			{
			
				_isMotionLive = false;
				
				_imageFrame = -1;
			}
			_frame = 0;
		}
		
}

void player::move()
{
	//�̵�
	tileMove();

	////////////////////////////////////////////////////////
	//
	//                     ��ų ������
	//
	////////////////////////////////////////////////////////


	////////////////////////////////////
	//
	//             �⺻��
    //
	////////////////////////////////////

	//�������
	if (_move == BASICSKILL1)
	{
		
		++_skillFrame;
		if (_skillFrame == 30)
		{
			randEffect();
			setSoloDamage(0);
		}

		if (_skillFrame > 100)
		{
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
	}
	
	//��������
	if (_move == BASICSKILL2)
	{
		++_skillFrame;
		if (_skillFrame == 30)
		{
			randEffect();
			setSoloDamage(0);
		}
		
		if (_skillFrame > 100)
		{
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
	}

	//�ٸ��ĸ���
	if ( _move == BASICSKILL3)
	{
		++_skillFrame;
		if (_skillFrame == 30)
		{
			randEffect();
			setSoloDamage(0);
		}
		
		if (_skillFrame > 100)
		{
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
	}
	////////////////////////////////////
	//
	//              ���α�
    //
	////////////////////////////////////

	//ȣ�ݱ�
	if ( _move == SOLOSKILL1)
	{
		if (_img->getFrameX() >= 9)
		{
			++_skillFrame;

			
			if (_skillFrame < 2)
			{	
				randEffect();
				setSoloDamage(10);
				_soloSkillEffect1->addSkill(WINSIZEX - 450, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
			}
			if (_skillFrame >= 200 )
			{
				_img->setFrameX(0);
				_move = FIGHTREADY;
				_skillFrame = 0;
			}
		}
	}

	
	//������
	if ( _move == SOLOSKILL2)
	{
		_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 250;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		++_skillFrame;
		
		//������� ��~
		if (_skillFrame < 50)
		{
			_img->setFrameX(0);
			if (_skillFrame % 10 == 0)
			{
				_soloSkillEffect3->addSkill(_x-20, _y+5);
			}
		}
		if (_skillFrame > 50 &&_skillFrame < 150)
		{
			_img->setFrameX(1);
		}

		//���� ��~~~
		if (_skillFrame > 120 && _skillFrame < 122)
		{
			//��ų
			_soloSkillEffect3->fireAddSkill(_x + 50, _y);
		}
		if(_skillFrame > 122 && _skillFrame < 300)
		{
			_img->setFrameX(2);	
			//������
			if (_skillFrame % 30 == 0)
			{
				randEffect();
				setSoloDamage(10);
			}		
		}
		if (_skillFrame > 300)
		{	
			_img->setFrameX(0);
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
		
	}

	//��ȣ�����
	if (_move == SOLOSKILL3)
	{
		++_skillFrame;
		//������ �ֱ�~
		if ((_skillFrame% 7 ==0 && _imageFrame == 1) || (_skillFrame % 7 == 0 && _imageFrame == 5) ||
			(_skillFrame % 7 == 0 && _imageFrame == 8) || (_skillFrame % 7 == 0 && _imageFrame == 13) ||
			(_skillFrame % 7 == 0 && _imageFrame == 18) || (_skillFrame % 7 == 0 && _imageFrame == 23) 
			)
		{
			randEffect();
			setSoloDamage(6);
			_skillFrame = 0;
		}
		//������~
		if (_img->getFrameX() >= 25)
		{
			_x += 10;
			_soloSkillEffect2->addSkill(_x, _y + 10);
		}
		if (_x >= WINSIZEX)
		{
			setSoloDamage(6);
			_move = FIGHTREADY;
			_img->setFrameX(0);
		}

	}
	////////////////////////////////////////////
	// 
	//                ��ü��
    //
	////////////////////////////////////////////

	//��ȣ����
	if (_move == AREASKILL1);
	{
		
		if (_isJumping)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
			
		}
		//������ �ֱ�
		if (_skillFrame % 10 == 0 && _imageFrame == 12 && _move == AREASKILL1)
		{
			randAreaEffect();
			setAreaDamage(10);
		}

		if (_img->getFrameX() >= 12 && _move == AREASKILL1)
		{
			_isJumping = true;
			++_skillFrame;
			_soloSkillEffect2->addSkill(_x+60, _y-29);
			
			if (_skillFrame >= 50)
			{
				_move = FIGHTREADY;
				_jumpPower = 0;
				_gravity = 0;
				_isJumping = false;
				_img->setFrameX(0);
				_skillFrame = 0;
				_y = WINSIZEY / 2;
			}
		}

	}
	//ȭ��
	if (_move == AREASKILL2)
	{
		++_skillFrame;
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 2;
		if (_skillFrame < 20)
		{
			_imageFrame = -1;
		}
		if (_skillFrame > 20 && _skillFrame < 40)
		{
			_imageFrame = 0;
		}
		if (_skillFrame > 40 && _skillFrame < 60 )
		{
			_imageFrame = 1;
		}
		if (_skillFrame > 60 && _skillFrame < 200)
		{
			_imageFrame = 2;
			//��ų ����Ʈ ������~
			if (_skillFrame % 5 == 0)
			{
				_areaSkillEffect2->addSkill(_x + 40, _y-2);
			}
			if (_skillFrame % 5 == 0)
			{
				_areaSkillEffect2->addSkill(_x + 60, _y+5 );
			}
			if (_skillFrame % 5 == 0)
			{
				_areaSkillEffect2->addSkill(_x + 60, _y - 5);
			}
			//������ �ֱ�~
			if (_skillFrame % 20 == 0)
			{
				randAreaEffect();
				setAreaDamage(10);
			}
		}
		if (_skillFrame > 200)
		{	
			_skillFrame = 0;
			_img->setFrameX(0);
			_move = FIGHTREADY;
		}
	}
	//������ ������
	if (_move == AREASKILL3)
	{
		++_skillFrame;
		//��ų ����Ʈ ������~
		if (_skillFrame % 7 == 0 && _skillFrame < 150)
		{
			_areaSkillEffect3->addFireSkill(_x, _y);
		}
		
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_img->setFrameX(_img->getMaxFrameX());
		}
		//������ �ֱ�
		if (_skillFrame% 100 == 0)
		{
			randEffect();
			setAreaDamage(20); //������ �ֱ�~
		}
		if (_skillFrame >= 300)
		{
			
			_move = FIGHTREADY;
			_skillFrame = 0;
		}
	}
	//�����ñ�
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ�����ñ�"))
	{
		++_skillFrame;
		if (_skillFrame > 100)
		{
			_img->setFrameX(0);
			_move = AREASKILL2;
			_isMotionLive = true;
			_skillFrame = 0;
		}
	}

	//����
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ����"))
	{
		_isMotionLive = true;
	}

	//EVENT ������ ��
	if (_sceneMode == EVENTMODE)
	{
		if (_slopeNum >= 8)
		{
			_slopeNum = 8;
			_slopeNum += 1;
			_x += 5;
			_isJumping = true;
		}
		if (_slopeNum <= 0)
		{
			_slopeNum = 0;
			_slopeNum -= 1;
			_x -= 5;
			_isJumping = true;
		}
		if (_y >= WINSIZEY +100)
		{
			_isJumping = false;
			_jumpPower = 5.0;
			_gravity = 0.2f;
		}
	}

	//�ǰݴ����� ��
	if (_move == DAMAGE)
	{
		++_skillFrame;
		
		if (_skillFrame < 20 )
		{
			int randMove = RND->getInt(2);

			if (randMove == 0)
			{
				_x -= 3;
			}
			if (randMove == 1)
			{
				_x += 3;
			}
		}
		if (_skillFrame > 20)
		{
			_x = 100;
		}
		if (_skillFrame > 50)
		{
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
	}
	//hpȸ�� 
	if (_move == HPUP|| _move == MPUP)
	{
		_isMotionLive = true;
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_imageFrame = 3;
		}
		++_skillFrame;
		_soloSkillEffect2->addSkill(_x, _y - 20);
		if (_skillFrame > 100)
		{
			_imageFrame = 0;
			_move = FIGHTREADY;
			_skillFrame = 0;
		}

	}
	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	//��ų��Ʈ
	for (int i = 0; i < 9; i++)
	{
		_skillRC[i] = RectMakeCenter(400 + i * 40, 450, 30, 30);
	}
}

//������ 
void player::levelCheck()
{
	if (_sceneMode == BATTLEMODE)
	{
		//������
		if (_attribute.currentExp >= _attribute.maxExp)
		{
			
			_attribute.isLevelUp = true;
		}

		//������ ���� ��
		if (_attribute.isLevelUp)
		{
			_x += 20;
			_y -= 10;
			_imageFrame = 0;
			_move = SEREMONI;
			_isMotionLive = true;
			_skillFrame = 0;
			_attribute.atk += 5;
			_attribute.def += 0;
			_attribute.luck += 5;
			_attribute.cri += 5;
			_attribute.speed += 5;

			_attribute.maxHp += 10;
			_attribute.currentHp = _attribute.maxHp;

			_attribute.maxMp += 10;
			_attribute.currentMp = _attribute.maxMp;

			_attribute.currentExp = 0;
			_attribute.maxExp += 100;

			_attribute.level += 1;
			_attribute.isLevelUp = false;
		
		}

		if (_move == SEREMONI)
		{
			++_skillFrame;
			if (_skillFrame > 75 )
			{
				_move = FIGHTREADY;
			}
		}
	}

	if (_isExpSet == true)
	{
		if (_exp-_compareExp > 100)
		{
			_attribute.currentExp += 1;
			_compareExp += 1;
		}
		if (_exp-_compareExp > 50)
		{
			_attribute.currentExp += 2;
			_compareExp += 2;
		}
		if (_exp-_compareExp > 0)
		{
			_attribute.currentExp += 1;
			_compareExp += 1;
		}
		if (_compareExp >= _exp)
		{
			_isExpSet = false;
			_exp = 0;
			_compareExp = 0;
		}
	}
}

//���ʹ̰� ������ ���� ��
void player::setPlayerDamage(int damage)
{
	
	if (damage > _attribute.def)
	{
		_move = DAMAGE;
		_isMotionLive = true;
		damage -= _attribute.def;
		_attribute.currentHp -= damage;
	}
	else
	{
		_move = DEFENCE;
		_isMotionLive = true;
		_attribute.currentHp -= 0;
	}

	if (_attribute.currentHp <= 0)
	{
		_attribute.currentHp = 0;
	}
}

//���ʹ̿��� ������ �ִ� �Լ��� �����ϰ� ���� �Լ�
void player::setSoloDamage(int plusDamage)
{
	_em->hitEnemy(_enemyIndex, _attribute.atk+ plusDamage);
}

void player::setAreaDamage(int plusDamage)
{
	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		_em->hitEnemy(i, _attribute.atk + plusDamage);
	}
}

void player::setExp(int exp)
{
	_exp += exp;
	_isExpSet = true;

}

//���� �ֱ�
void player::setStat(int atk, int def, int luck, int cri, int speed)
{
	
	_attribute.atk += atk;
	_attribute.cri += cri;
	_attribute.def += def;
	_attribute.luck += luck;
	_attribute.speed += speed;
}

//���ǸԱ�
void player::setPortion(int hp, int mp)
{

	if (_attribute.currentMp <= _attribute.maxMp|| _attribute.currentHp <= _attribute.maxHp)
	{
		_attribute.currentHp += hp;
		_attribute.currentMp += mp;
		if (_attribute.currentMp >= _attribute.maxMp)
		{
			_attribute.currentMp = _attribute.maxMp;
		}
		if (_attribute.currentHp >= _attribute.maxHp)
		{
			_attribute.currentHp = _attribute.maxHp;
		}
	}	
	
	
}

void player::randEffect()
{
	int randNum = RND->getInt(8);

	if (randNum == 0)
	{// ���� ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitLUDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x-10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y-20);
	}
	if (randNum == 1)
	{// ���� �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitLDDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x- 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 2)
	{// ������ ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitRUDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 3)
	{// ������ �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitRDDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 4)
	{// ���� ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitLUDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 5)
	{// ���� �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitLDDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 6)
	{// ������ ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitRUDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 7)
	{// ������ �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
		_gameEffect->hitRDDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
}

void player::randAreaEffect()
{
	int randNum = RND->getInt(8);
	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		if (randNum == 0)
		{// ���� ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitLUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 1)
		{// ���� �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitLDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 2)
		{// ������ ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitRUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 3)
		{// ������ �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitRDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 4)
		{// ���� ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitLUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 5)
		{// ���� �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitLDDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 6)
		{// ������ ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitRUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 7)
		{// ������ �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
			_gameEffect->hitRDDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
	}
}



void player::effectImage()
{
	++_effectImage.frame;

	if (_effectImage.frame % 5 == 0)
	{
		++_effectImage.frameImage;

		_effectImage.img->setFrameX(_effectImage.frameImage);

		if (_effectImage.img->getFrameX() >= _effectImage.img->getMaxFrameX())
		{
			_effectImage.frameImage = 0;
		}
		_effectImage.frame = 0;
	}
}



void player::setMove(MOVE move)
{
	if (_sceneMode == BATTLEMODE)
	{
		if (_attribute.currentHp > 0)
		{
			if (move == SOLOSKILL1 && _attribute.currentMp >= 3)
			{
				_move = SOLOSKILL1;
				_isMotionLive = true;
				_attribute.currentMp -= 3;
			}
			if (move == SOLOSKILL2 && _attribute.currentMp >= 3)
			{
				_move = SOLOSKILL2;
				_isMotionLive = true;
				_attribute.currentMp -= 3;
			}
			if (move == SOLOSKILL3 && _attribute.currentMp >= 3)
			{
				_move = SOLOSKILL3;
				_isMotionLive = true;
				_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 80;
				_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
				_attribute.currentMp -= 3;
			}
			if (move == AREASKILL1 && _attribute.currentMp >= 3)
			{
				_move = AREASKILL1;
				_isMotionLive = true;
				_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 100;
				_y = WINSIZEY / 3;
				_jumpPower = 5.0f;
				_gravity = 0.2f;
				_attribute.currentMp -= 3;
			}
			if (move == DRINK && _attribute.currentMp >= 3)
			{
				_move = DRINK;
				_isMotionLive = true;
				_attribute.currentMp -= 3;
			}
			if (move == AREASKILL3 && _attribute.currentMp >= 3)
			{
				_move = AREASKILL3;
				_isMotionLive = true;
				_x = WINSIZEX / 2;
				_attribute.currentMp -= 3;
			}
			if (move == BASICSKILL1)
			{
				_move = BASICSKILL1;
				_isMotionLive = true;
				_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 80;
				_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
			}
			if (move == BASICSKILL2)
			{
				_move = BASICSKILL2;
				_isMotionLive = true;
			}
			if (move == BASICSKILL3)
			{
				_move = BASICSKILL3;
				_isMotionLive = true;
			}
		}
	}
}


void player::tileMove(void)
{
	RECT rcCollision;

	int tileIndex[2];	//�̵� ���⿡ ���� Ÿ�ϼӼ��� �����ϱ����� Ÿ�� �ε��� �� ���� �迭
	int tileX, tileY;	//��ũ �̵� ���⿡ ���� '����'�ϱ� ���� �ε��� ���� ����

	rcCollision = _zOrderRC;

	switch (_move)
	{
	case LEFTMOVE:	_angle = PI; (_x > TILESIZE * 3) ? _x += cosf(_angle)*_moveSpeed : _x = TILESIZE * 3;	break;
	case RIGHTMOVE: _angle = 0; (_x < CAMERA->getMaxPositon().x - TILESIZE * 3) ? _x += cosf(_angle)*_moveSpeed : _x = CAMERA->getMaxPositon().x - TILESIZE * 3;	break;
	case DOWNMOVE:	_angle = 2 * PI - PI / 2; (_y > TILESIZE) ? _y += -sinf(_angle)*_moveSpeed : _y = TILESIZE;	break;
	case UPMOVE:	_angle = PI / 2; (_y < CAMERA->getMaxPositon().y - TILESIZE) ? _y += -sinf(_angle)*_moveSpeed : _y = CAMERA->getMaxPositon().y - TILESIZE;	break;
	}

	rcCollision = RectMakeCenter(_x, _y + 27, _img->getFrameWidth(), 25);

	//������ �浹��Ʈ ������ ���̱�
	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILESIZE;
	tileY = rcCollision.top / TILESIZE;

	//���⿡ ���� Ÿ�� ����
	//Ÿ�� ������ ���ؼ� �� ���� ����(��ǥ)�� �ִ� Ÿ���� �Ӽ��� ����
	switch (_move)
	{
	case LEFTMOVE:
		tileIndex[0] = tileX + tileY * TILEX;
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case UPMOVE:
		tileIndex[0] = tileX + tileY * TILEX;
		tileIndex[1] = tileX + 1 + tileY * TILEX;
		break;
	case RIGHTMOVE:
		tileIndex[0] = (tileX + tileY * TILEX) + 2;
		tileIndex[1] = (tileX + (1 + tileY) * TILEX) + 2;
		break;
	case DOWNMOVE:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	default: return;
	}

	// Ȥ�� �� ����ó��(tileIndex�� ������ ���� ���� ���)
	//if (tileIndex[0] >= 0 || tileIndex[1] >= 0) return;

	for (int i = 0; i < 2; i++)
	{
		RECT rc;
		if ((_map->getTiles()[tileIndex[i]].terrain == TR_UNMOVE) &&
			IntersectRect(&rc, &_map->getTiles()[tileIndex[i]].rc, &rcCollision))
		{
			switch (_move)
			{
			case LEFTMOVE:
				_x -= cosf(_angle)*_moveSpeed;
				//(RND->getInt(2)) ? _y += _moveSpeed, _move = DOWNMOVE : _y -= _moveSpeed, _move = UPMOVE;				 
				break;
			case UPMOVE:
				_y -= -sinf(_angle)*_moveSpeed;
				//(RND->getInt(2)) ? _x += _moveSpeed, _move = RIGHTMOVE : _x -= _moveSpeed, _move = LEFTMOVE;
				break;
			case RIGHTMOVE:
				_x -= cosf(_angle)*_moveSpeed;
				//(RND->getInt(2)) ? _y += _moveSpeed, _move = DOWNMOVE : _y -= _moveSpeed, _move = UPMOVE;
				break;
			case DOWNMOVE:
				_y -= -sinf(_angle)*_moveSpeed;
				//(RND->getInt(2)) ? _x += _moveSpeed, _move = RIGHTMOVE : _x -= _moveSpeed, _move = LEFTMOVE;
				break;
			}
			return;
		}
	}

	rcCollision = RectMakeCenter(_x, _y + 27, _img->getFrameWidth(), 25);
	_zOrderRC = rcCollision;

}


player::player()
{
}


player::~player()
{
}
