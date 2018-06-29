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

	_image = IMAGEMANAGER->findImage("��Ÿȣ����");
	
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
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
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
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}

void player::release()
{
}

void player::keyManager()
{
	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

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
		_move = FRONT;

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
		_move = BACK;
		
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
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{	
		_move = AREASKILL3;
		_isMotionLive = true;
	}



}

void player::image()
{
	switch (_move)
	{
	case LEFT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case RIGHT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ������");
		break;
	case FRONT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case BACK:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�޸��");
		break;
	case LEFTMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	case RIGHTMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�������̵�");
		break;
	case DOWNMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�Ʒ��̵�");
		break;
	case UPMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	case SOLOSKILL1:
		_image = IMAGEMANAGER->findImage("��Ÿȣȣ�ݱ�");
		break;
	case SOLOSKILL2:
		 _image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ������");
		break;
	case SOLOSKILL3:
		_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����");
		break;
	case AREASKILL1:
		_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ����");
		break;
	case AREASKILL2:
		//_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ����");
		break;
	case AREASKILL3:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����������");
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

			_image->setFrameX(_imageFrame);

			if (_imageFrame >= _image->getMaxFrameX())
			{
				if (_image == IMAGEMANAGER->findImage("��Ÿȣ����"))
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
	case FRONT:
		break;
	case BACK:
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
	if (_image == IMAGEMANAGER->findImage("��Ÿȣȣ�ݱ�"))
	{
		if (_image->getFrameX() >= 9)
		{
			++_skillFrame;
			if (_skillFrame >= 50)
			{
				_image->setFrameX(0);
				_move = RIGHT;
				_skillFrame = 0;
			}
		}
	}

	//������
	if (_image == IMAGEMANAGER->findImage("��Ÿȣ��ȣ������"))
	{
		
		++_skillFrame;

		if (_skillFrame < 50)
		{
			_image->setFrameX(0);
		}
		if (_skillFrame > 50 &&_skillFrame < 100)
		{
			_image->setFrameX(1);
		}
		if(_skillFrame > 100 && _skillFrame < 200)
		{
			_image->setFrameX(2);
		}
		if (_skillFrame > 200)
		{	
			_image->setFrameX(0);
			_skillFrame = 0;
			_move = RIGHT;
		}
		
	}

	//��ȣ�����
	if (_image == IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����") && _image->getFrameX() >= 25 && _move == SOLOSKILL3)
	{
		_x += 10;
		if (_x >= WINSIZEX)
		{
			_move = RIGHT;
			_x = WINSIZEX / 2;
			_image->setFrameX(0);
		}
	}

	//��ȣ����
	if (_image == IMAGEMANAGER->findImage("��Ÿȣ��ȣ����"));
	{
		if (_isJumping)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;

		}


		if (_image->getFrameX() >= 12 && _move == AREASKILL1)
		{
			_isJumping = true;
			++_skillFrame;
			if (_skillFrame >= 50)
			{
				_move = RIGHT;
				_jumpPower = 0;
				_gravity = 0;
				_isJumping = false;
				_image->setFrameX(0);
				_skillFrame = 0;
				_y = WINSIZEY / 2;
			}
		}

	}
}




player::player()
{
}


player::~player()
{
}
