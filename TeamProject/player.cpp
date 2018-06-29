#include "stdafx.h"
#include "player.h"


HRESULT player::init()
{
	
	//아타호 이미지
	IMAGEMANAGER->addFrameImage("아타호정면", "image/player/아타호 정면.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽", "image/player/아타호 왼쪽.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호오른쪽", "image/player/아타호 오른쪽.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호뒷모습", "image/player/아타호 뒷모습.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호위로이동", "image/player/아타호 위로이동.bmp", 180, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호아래이동", "image/player/아타호 아래이동.bmp", 190, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호오른쪽이동", "image/player/아타호 오른쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽이동", "image/player/아타호 왼쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("아타호노익장대폭발", "image/player/아타호 노익장대폭발.bmp", 220, 80, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호광파참", "image/player/아타호 맹호광파참.bmp", 244, 85, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호난무", "image/player/아타호 맹호난무.bmp", 1912, 110, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호스페셜", "image/player/아타호 맹호스페셜2.bmp", 4576, 172, 26, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호호격권", "image/player/아타호 호격권.bmp", 1100, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽이동", "image/player/아타호 왼쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호만취", "image/player/아타호 만취.bmp", 502, 85, 8, 1, true, RGB(255, 0, 255));

	_image = IMAGEMANAGER->findImage("아타호정면");
	
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
	image();		 //이미지
	keyManager();	 //키
	if (_isMotionLive )
	{
		imageFrame();	 //이미지프레임
	}
	move();			 //움직임
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
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//움직이는 모션
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

	//정자세
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

	//스킬
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
		_image = IMAGEMANAGER->findImage("아타호왼쪽");
		break;
	case RIGHT:
		_image = IMAGEMANAGER->findImage("아타호오른쪽");
		break;
	case FRONT:
		_image = IMAGEMANAGER->findImage("아타호정면");
		break;
	case BACK:
		_image = IMAGEMANAGER->findImage("아타호뒷모습");
		break;
	case LEFTMOVE:
		_image = IMAGEMANAGER->findImage("아타호왼쪽이동");
		break;
	case RIGHTMOVE:
		_image = IMAGEMANAGER->findImage("아타호오른쪽이동");
		break;
	case DOWNMOVE:
		_image = IMAGEMANAGER->findImage("아타호아래이동");
		break;
	case UPMOVE:
		_image = IMAGEMANAGER->findImage("아타호위로이동");
		break;
	case SOLOSKILL1:
		_image = IMAGEMANAGER->findImage("아타호호격권");
		break;
	case SOLOSKILL2:
		 _image = IMAGEMANAGER->findImage("아타호맹호광파참");
		break;
	case SOLOSKILL3:
		_image = IMAGEMANAGER->findImage("아타호맹호스페셜");
		break;
	case AREASKILL1:
		_image = IMAGEMANAGER->findImage("아타호맹호난무");
		break;
	case AREASKILL2:
		//_image = IMAGEMANAGER->findImage("아타호맹호난무");
		break;
	case AREASKILL3:
		_image = IMAGEMANAGER->findImage("아타호노익장대폭발");
		break;
	default:
		break;
	}
}

void player::imageFrame()
{
	//프레임 이미지
	++_frame;
	
		if (_frame % 8 == 0)
		{
			++_imageFrame;

			_image->setFrameX(_imageFrame);

			if (_imageFrame >= _image->getMaxFrameX())
			{
				if (_image == IMAGEMANAGER->findImage("아타호만취"))
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
	//이동
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

	//스킬 움직임

	//호격권
	if (_image == IMAGEMANAGER->findImage("아타호호격권"))
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

	//광파참
	if (_image == IMAGEMANAGER->findImage("아타호맹호광파참"))
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

	//맹호스페셜
	if (_image == IMAGEMANAGER->findImage("아타호맹호스페셜") && _image->getFrameX() >= 25 && _move == SOLOSKILL3)
	{
		_x += 10;
		if (_x >= WINSIZEX)
		{
			_move = RIGHT;
			_x = WINSIZEX / 2;
			_image->setFrameX(0);
		}
	}

	//맹호난무
	if (_image == IMAGEMANAGER->findImage("아타호맹호난무"));
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
