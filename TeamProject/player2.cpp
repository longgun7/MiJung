#include "stdafx.h"
#include "player2.h"

HRESULT player2::init(float x , float y)
{

	//������ �̹���
	IMAGEMANAGER->addFrameImage("����������", "image/player/������ ����.bmp", 50, 78, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "image/player/������ ����.bmp", 40, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������޸��", "image/player/������ �޸��.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������̵�", "image/player/������ �����̵�.bmp", 190, 84, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������Ʒ��̵�", "image/player/������ �Ʒ��̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������������̵�", "image/player/������ �������̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������̵�", "image/player/������ �����̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	
	//������ ��ų
	IMAGEMANAGER->addFrameImage("��������Ÿ��", "image/player/������ ��Ÿ��.bmp", 402, 85, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������", "image/player/������ �����.bmp", 2000, 87, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������������ư���", "image/player/������ ���� ���ư���2.bmp", 2675, 120, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������2.bmp", 6570, 140, 45, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 1615, 100, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������н�", "image/player/������ �н�.bmp", 99, 85, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���������", "image/player/������ ���.bmp", 56, 75, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 90, 61, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������ǰ�", "image/player/������ �ǰ�.bmp", 70, 69, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������������", "image/player/������ ��������.bmp", 55, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "image/player/������ �ǰ�.bmp", 70, 69, 1, 1, true, RGB(255, 0, 255));
	//������ ��Ÿ��
	IMAGEMANAGER->addFrameImage("��������Ÿ��", "image/player/������ ��Ÿ��2.bmp", 320, 82, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���������", "image/player/������ ���2.bmp", 320, 82, 4, 1, true, RGB(255, 0, 255));
	//����Ʈ
	IMAGEMANAGER->addFrameImage("������ȸ����", "image/player/������ ȸ����.bmp", 400, 42, 5, 1, true, RGB(255, 0, 255));

	//�ʱ� ���������
	_img = IMAGEMANAGER->findImage("����������");

	//����Ʈ

	_effectImage.img = IMAGEMANAGER->findImage("������ȸ����");
	

	_effectImage.frameImage = 0;
	_effectImage.frame = 0;
	//������ ����
	_x = x - 60;
	_y = y;
	_angle = 0;
	_jumpPower = 5.0f;
	_gravity = 0.2f;
	_imageFrame = 0;
	_frame = 0;
	_skillFrame = 0;
	_moveSpeed = 5;
	_isMotionLive = false;
	_isJumping = false;
	_sceneMode = S_FIELDMODE;
	_attribute.atk = 5;
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
	//������ ��ų
	_soloSkillEffect = new atahoTargetSkill2;
	_soloSkillEffect->init();
	return S_OK;
}

//���� ��_<
//���� �̸��� �ڵ��� ������

void player2::update()
{
	image();		 //�̹���
	
	if (_isMotionLive)
	{
		imageFrame();	 //�̹���������
	}
	move();
	s_event(); //������ �̺�Ʈ
	//��ų
	_soloSkillEffect->update();

	effectImage();
}

void player2::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	char str[125];

	sprintf_s(str, "��ų ������ : %d", _skillFrame);
	TextOut(getMemDC(), 100, 350, str, strlen(str));

	char str2[123];
	sprintf_s(str2, "�̹��������� : %d", _imageFrame);
	TextOut(getMemDC(), 100, 370, str2, strlen(str2));
	//if (_isJumping)
	{
		char str3[123];
		sprintf_s(str3, "���ο��� : %d", _isJumping);
		TextOut(getMemDC(), 100, 390, str3, strlen(str3));
	}
	char str4[234];
	
	//��ų
	_soloSkillEffect->render();
    
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
	
	//����Ʈ
	_effectImage.img->frameRender(getMemDC(), _x-40, _y+10);

}

void player2::release()
{
}

void player2::angleManager(float x , float y)
{

	if (_sceneMode == S_FIELDMODE)
	{
		//��Ÿȣ�� ��ġ�� ���� �ޱ��� �ٲ��.
		_angle = getAngle(_x, _y, x, y);


		//��Ÿȣ�� ���������� �Ÿ�
		if (getDistance(x, y, _x, _y) > 60)
		{
			_x += cosf(_angle)*_moveSpeed;
			_y += -sinf(_angle)*_moveSpeed;

			//�����̴� ���
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_move = S_LEFTMOVE;
				_isMotionLive = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_move = S_RIGHTMOVE;
				_isMotionLive = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_move = S_UPMOVE;
				_isMotionLive = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_move = S_DOWNMOVE;
				_isMotionLive = true;
			}

		}

			//���ڼ�
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				_move = S_DOWN;

			}
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				_move = S_LEFT;

			}
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				_move = S_RIGHT;

			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				_move = S_UP;

			}
		
	}

	if (_sceneMode == S_BATTLEMODE)
	{
		//��ų
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			_move = S_SOLOSKILL1;
			_isMotionLive = true;
			_skillFrame = 0;
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			_move = S_SOLOSKILL2;
			_isMotionLive = true;
			_skillFrame = 0;
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			_move = S_SOLOSKILL3;
			_isMotionLive = true;
			_skillFrame = 0;
		}
		if (KEYMANAGER->isOnceKeyDown('F'))
		{
			_move = S_AREASKILL1;
			_isMotionLive = true;
			_skillFrame = 0;
		}
		if (KEYMANAGER->isOnceKeyDown('G'))
		{
			_move = S_AREASKILL2;
			_isMotionLive = true;
			_skillFrame = 0;
		}
		if (KEYMANAGER->isOnceKeyDown('H'))
		{
			_move = S_AREASKILL3;
			_isMotionLive = true;
			_skillFrame = 0;
		}
	}
}

void player2::image()
{
	//�̹���
	switch (_move)
	{
	case S_RIGHT:
		_img = IMAGEMANAGER->findImage("������������");
		break;
	case S_LEFT:
		_img = IMAGEMANAGER->findImage("����������");
		break;
	case S_DOWN:
		_img = IMAGEMANAGER->findImage("����������");
		break;
	case S_UP:
		_img = IMAGEMANAGER->findImage("�������޸��");
		break;
	case S_LEFTMOVE:
		_img = IMAGEMANAGER->findImage("�����������̵�");
		break;
	case S_RIGHTMOVE:
		_img = IMAGEMANAGER->findImage("�������������̵�");
		break;
	case S_DOWNMOVE:
		_img = IMAGEMANAGER->findImage("�������Ʒ��̵�");
		break;
	case S_UPMOVE:
		_img = IMAGEMANAGER->findImage("�����������̵�");
		break;
	case S_SOLOSKILL1:
		_img = IMAGEMANAGER->findImage("��������Ÿ��");
		break;
	case S_SOLOSKILL2:
		_img = IMAGEMANAGER->findImage("������������");
		break;
	case S_SOLOSKILL3:
		_img = IMAGEMANAGER->findImage("�������������ư���");
		break;
	case S_AREASKILL1:
		_img = IMAGEMANAGER->findImage("�����������");
		break;
	case S_AREASKILL2:
		_img = IMAGEMANAGER->findImage("������������");
		break;
	case S_AREASKILL3:
		_img = IMAGEMANAGER->findImage("�������н�");
		break;
	case S_FIGHTREADY:
		_img = IMAGEMANAGER->findImage("��������������");
		_x = 100;
		_y = 300;
		break;
	case S_ROPEWALKING:
		_img = IMAGEMANAGER->findImage("��������Ÿ��");
		break;
	case S_FALLING:
		_img = IMAGEMANAGER->findImage("����������");
		break;	
	case S_AFRAID:
			_img = IMAGEMANAGER->findImage("���������");
			break;
	default:
		break;
	}
}

void player2::imageFrame()
{
	//�̹���������
	++_frame;

	if (_frame % 7 == 0)
	{
		
		++_imageFrame;

		_img->setFrameX(_imageFrame);
		
		if (_imageFrame >= _img->getMaxFrameX())
		{
			_imageFrame = -1;
			_isMotionLive = false;
		}
		_frame = 0;
	}

}



void player2::move()
{
	
	//��ų �̵�

	//��Ÿ��
	if (_move == S_SOLOSKILL1)
	{
		++_skillFrame;
		if (_x < WINSIZEX - 100)
		{
			_imageFrame = 1;
			_img->setFrameX(1);
			_x += 20;
			_soloSkillEffect->addSkill(_x, _y -  35);
		}

		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_imageFrame = _img->getMaxFrameX();
		}
		if (_skillFrame > 100)
		{
			_move = S_FIGHTREADY;
		}
	}
	//������
	if (_move == S_SOLOSKILL2)
	{
		++_skillFrame;
		if (_img->getFrameX() >= 2 && _x < WINSIZEX - 100)
		{
			_imageFrame = 3;
			_x += 20;
			_img->setFrameX(2);
			_soloSkillEffect->addSkill(_x, _y );
		}
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_imageFrame = _img->getMaxFrameX();
			_imageFrame = 0;
		}
		if (_skillFrame > 150)
		{
			_img->setFrameX(0);
			_move = S_FIGHTREADY;
			
		}
	}
	
	//���� ���ư���
	if(_move == S_SOLOSKILL3)
	{
		if (_img->getFrameX() < 23)
		{
			_x = WINSIZEX - 200;
		}
		if (_img->getFrameX() >= 23 && _x < WINSIZEX )
		{
			_x += 20;
			_img->setFrameX(23);
			_imageFrame = 23;
		}
		if (_x >= WINSIZEX )
		{	
			_img->setFrameX(0);
			_imageFrame = 0;
			_move = S_FIGHTREADY;
			
		}
	}

	//����� 
	if (_move == S_AREASKILL1)
	{
		
		++_skillFrame;
		_x = WINSIZEX - 300;
		_y = WINSIZEY / 2;
		if (_img->getFrameX() >= _img->getMaxFrameX() )
		{
			_imageFrame = 0;
		}
		if (_skillFrame > 200)
		{
			_img->setFrameX(0);
			_skillFrame = 0;
			_move = S_FIGHTREADY;
		}
	}

	//������
	if (_move == S_AREASKILL2)
	{	
		
		_x = WINSIZEX - 200;
		++_skillFrame;
		if (_img->getFrameX() >= 44 && _skillFrame >= 200)
		{
			_imageFrame = 44;
		}
		if (_skillFrame >= 400)
		{	
			_imageFrame = 0;
			_move = S_FIGHTREADY;
		}
	}
	//�н�
	if (_img == IMAGEMANAGER->findImage("�������н�")&& _move== S_AREASKILL3)
	{
		++_skillFrame;

		if (_skillFrame < 50)
		{
			_img->setFrameX(0);
		}
		if (_skillFrame > 50 && _skillFrame < 150)
		{
			_img->setFrameX(1);
		}
		if (_skillFrame > 150 )
		{
			_skillFrame = 0;
			_img->setFrameX(0);
			_move = S_AREASKILL2;
			_isMotionLive = true;
		}
	}

	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

}

void player2::s_event()
{
	//�̺�Ʈ���
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		_sceneMode = S_EVENTMODE;
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 2 - 40;
		_isJumping = false;
	}

	if (!_isJumping)
	{
		_jumpPower = 5.0f;
		_gravity = 0.2f;
	}

	//��Ÿ��
	if (_sceneMode == S_EVENTMODE)
	{
		_move = S_ROPEWALKING;
		
		//������ ��
		if (_isJumping)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
			_x += 3;
			_img = IMAGEMANAGER->findImage("����������");
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isMotionLive = true;
		}

	}
}

//����Ʈ
void player2::effectImage()
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




player2::player2()
{
}


player2::~player2()
{
}
