#include "stdafx.h"
#include "player.h"


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
	IMAGEMANAGER->addFrameImage("��Ÿȣ�ǰ�", "image/player/��Ÿȣ �ǰ�.bmp", 41, 63, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�������", "image/player/��Ÿȣ �������.bmp", 287, 67, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�ڰ���", "image/player/��Ÿȣ �ڰ���.bmp", 1145, 50, 12, 1, true, RGB(255, 0, 255));
	
	//��Ÿ��
	IMAGEMANAGER->addFrameImage("�ö�Ÿ��", "image/player/�ö�Ÿ��.bmp", 100, 120, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��", "image/player/��Ÿ��.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+1", "image/player/��Ÿ��+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+2", "image/player/��Ÿ��+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+3", "image/player/��Ÿ��+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��+4", "image/player/��Ÿ��+4.bmp", 65, 90, 1, 1, true, RGB(255, 0, 255));
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

	_img = IMAGEMANAGER->findImage("��Ÿȣ����");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY/2;
	_jumpPower  = 5.0f;
	_gravity    = 0.2f;
	_imageFrame	= 0;
	_frame		= 0;
	_skillFrame = 0;
	_slopeFrame = 0;
	_moveSpeed  = 5;
	_isMotionLive = false;
	_isJumping = false;
	_atk = 5;
	_def = 10;
	_luck = 10;
	_cri = 5;
	_speed = 10;
	_currentHp = 20;
	_maxHp = 20;
	_currentMp = 20;
	_maxMp = 20;
	_currentExp = 0;
	_maxExp = 100;
	_level = 1;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
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
}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);

	//���� ������
	char str[125];
	sprintf_s(str, "���� ������ : %d", _slopeFrame);
	TextOut(getMemDC(), 100, 500, str, strlen(str));
}

void player::release()
{
}

void player::fieldKeyManager()
{
	//�ʵ���
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_sceneMode = FIELDMODE;
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 2;
		_move = RIGHT;
	}

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
	//��Ʋ���
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_sceneMode = BATTLEMODE;
		_x = 100;
		_y = 400;
		_move = FIGHTREADY;
	}

	//��Ʋ����� ��
	if (_sceneMode == BATTLEMODE)
	{
		//��ų
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			_move = SOLOSKILL1;
			_isMotionLive = true;

		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			_move = SOLOSKILL2;
			_isMotionLive = true;

		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			_move = SOLOSKILL3;
			_isMotionLive = true;
			_x = WINSIZEX - 200;

		}
		if (KEYMANAGER->isOnceKeyDown('F'))
		{
			_move = AREASKILL1;
			_isMotionLive = true;
			_x = WINSIZEX - 200;
			_jumpPower = 5.0f;
			_gravity = 0.2f;
		}
		if (KEYMANAGER->isOnceKeyDown('G'))
		{
			_move = AREASKILL2;
			_isMotionLive = true;
			_x = WINSIZEX - 200;
		}
		if (KEYMANAGER->isOnceKeyDown('H'))
		{
			_move = AREASKILL3;
			_isMotionLive = true;
			_x = WINSIZEX / 2;
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_move = DRINK;
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
		_y = 400;
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
	switch (_move)
	{
	case LEFT:
		break;
	case RIGHT:
		break;
	case DOWN:
		break;
	case UP:
		break;
	case LEFTMOVE:
		_x -= _moveSpeed;
		break;
	case RIGHTMOVE:
		_x += _moveSpeed;
		break;
	case DOWNMOVE:
		_y += _moveSpeed;
		break;
	case UPMOVE:
		_y -= _moveSpeed;
		break;
	case FIGHTREADY:
		break;
	default:
		break;
	}

	//��ų ������

	//ȣ�ݱ�
	if (_img == IMAGEMANAGER->findImage("��Ÿȣȣ�ݱ�"))
	{
		if (_img->getFrameX() >= 9)
		{
			++_skillFrame;
			if (_skillFrame >= 50 )
			{
				_img->setFrameX(0);
				_move = FIGHTREADY;
				_skillFrame = 0;
			}
		}
	}

	//������
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ��ȣ������"))
	{
		
		++_skillFrame;

		if (_skillFrame < 50)
		{
			_img->setFrameX(0);
		}
		if (_skillFrame > 50 &&_skillFrame < 100)
		{
			_img->setFrameX(1);
		}
		if(_skillFrame > 100 && _skillFrame < 200)
		{
			_img->setFrameX(2);
		}
		if (_skillFrame > 200)
		{	
			_img->setFrameX(0);
			_skillFrame = 0;
			_move = FIGHTREADY;
		}
		
	}

	//��ȣ�����
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����") && _img->getFrameX() >= 25 && _move == SOLOSKILL3)
	{
		_x += 10;
		if (_x >= WINSIZEX)
		{
			_move = FIGHTREADY;
			_img->setFrameX(0);
		}
	}

	//��ȣ����
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ��ȣ����"));
	{
		if (_isJumping)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;

		}

		if (_img->getFrameX() >= 12 && _move == AREASKILL1)
		{
			_isJumping = true;
			++_skillFrame;
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
	if (_img == IMAGEMANAGER->findImage("��Ÿȣȭ��"))
	{
		++_skillFrame;

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
		if (_skillFrame > 60 && _skillFrame < 100)
		{
			_imageFrame = 2;
		}
		if (_skillFrame > 100)
		{	
			_skillFrame = 0;
			_img->setFrameX(0);
			_move = FIGHTREADY;
		}
	}

	//�����ñ�
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ�����ñ�"))
	{
		++_skillFrame;
		if (_skillFrame > 100)
		{
			_img->setFrameX(0);
			_move = DRUNKEN;
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



	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
}

void player::ropeWalk()
{
}

void player::levelCheck()
{
	//������
	if (_currentExp >= _maxExp)
	{
		_isLevelUp = true;
	}

	//������ ���� ��
	if (_isLevelUp) 
	{
		_atk += 5;          
		_def += 5;			
		_luck += 5;			
		_cri  += 5;			
		_speed += 5;		
							
		_maxHp += 10;		
		_currentHp = _maxHp;
							
		_maxMp += 10;		
		_currentMp = _maxMp;
							
		_currentExp = 0;	
		_maxExp += 100;	

		_level += 1;
							
		_isLevelUp = false;	
	}

}




player::player()
{
}


player::~player()
{
}
