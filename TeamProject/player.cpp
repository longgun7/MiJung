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
	IMAGEMANAGER->addFrameImage("��Ÿ��-1", "image/player/��Ÿ��-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-2", "image/player/��Ÿ��-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿ��-3", "image/player/��Ÿ��-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+1", "image/player/������Ÿ��+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+2", "image/player/������Ÿ��+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+3", "image/player/������Ÿ��+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��+4", "image/player/������Ÿ��+4.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-1", "image/player/������Ÿ��-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-2", "image/player/������Ÿ��-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-3", "image/player/������Ÿ��-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ÿ��-4", "image/player/������Ÿ��-4.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));

	_img = IMAGEMANAGER->findImage("��Ÿȣ����");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY/2;
	_jumpPower  = 5.0f;
	_gravity    = 0.2f;
	_imageFrame	= 0;
	_frame		= 0;
	_skillFrame = 0;
	_moveSpeed  = 5;
	_isMotionLive = false;
	_isJumping = false;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	return S_OK;
}

void player::update()
{
	image();		 //�̹���
	keyManager();	 //Ű
	if (_isMotionLive )
	{
		imageFrame();	 //�̹���������
	}
	move();			 //������
}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
}

void player::release()
{
}

void player::keyManager()
{
	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

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
		
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_move = AREASKILL1;
		_isMotionLive = true;
		_jumpPower = 5.0f;
		_gravity = 0.2f;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		_move = AREASKILL2;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{	
		_move = AREASKILL3;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_move = DRINK;
		_isMotionLive = true;
	}
	


}

void player::image()
{
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
	case FIGHTMODE:
		_img = IMAGEMANAGER->findImage("��Ÿȣ��������");
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
				if (_img == IMAGEMANAGER->findImage("��Ÿȣ����"))
				{
					_imageFrame = 1;
				}
				else
				{
					_isMotionLive = false;
				}
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
				_move = FIGHTMODE;
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
			_move = FIGHTMODE;
		}
		
	}

	//��ȣ�����
	if (_img == IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����") && _img->getFrameX() >= 25 && _move == SOLOSKILL3)
	{
		_x += 10;
		if (_x >= WINSIZEX)
		{
			_move = FIGHTMODE;
			_x = WINSIZEX / 2;
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
				_move = FIGHTMODE;
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
			_move = FIGHTMODE;
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
}

void player::ropeWalk()
{
}




player::player()
{
}


player::~player()
{
}
