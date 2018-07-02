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
	IMAGEMANAGER->addFrameImage("아타호화둔", "image/player/아타호 화둔.bmp", 290, 90, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호술마시기", "image/player/아타호 술마시기.bmp", 655, 95, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호전투상태", "image/player/아타호 전투상태.bmp", 55, 86, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호피격", "image/player/아타호 피격.bmp", 41, 63, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호세레모니", "image/player/아타호 세레모니.bmp", 287, 67, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호코골이", "image/player/아타호 코골이.bmp", 1145, 50, 12, 1, true, RGB(255, 0, 255));
	
	//줄타기
	IMAGEMANAGER->addFrameImage("올라타기", "image/player/올라타기.bmp", 100, 120, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기", "image/player/줄타기.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+1", "image/player/줄타기+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+2", "image/player/줄타기+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+3", "image/player/줄타기+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+4", "image/player/줄타기+4.bmp", 65, 90, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기-1", "image/player/줄타기-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기-2", "image/player/줄타기-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기-3", "image/player/줄타기-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기-4", "image/player/줄타기-4.bmp", 80, 100, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기", "image/player/물통줄타기.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기+1", "image/player/물통줄타기+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기+2", "image/player/물통줄타기+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기+3", "image/player/물통줄타기+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기+4", "image/player/물통줄타기+4.bmp", 66, 114, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기-1", "image/player/물통줄타기-1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기-2", "image/player/물통줄타기-2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기-3", "image/player/물통줄타기-3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("물통줄타기-4", "image/player/물통줄타기-4.bmp", 81, 112, 1, 1, true, RGB(255, 0, 255));

	_img = IMAGEMANAGER->findImage("아타호정면");
	
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
	playerImage();		  //이미지
	fieldKeyManager();	  //필드모드 키매니저
	battleKeyManager();   //배틀모드 키매니저
	slopeNumImage();      //기울기넘버에 따라 변하는 이미지
	eventKeyManager();    //이벤트모드 키매니저
	
	if (_isMotionLive )
	{
		imageFrame();	  //이미지프레임
	}
	move();			      //움직임
	levelCheck();	      //레벨업 여부
}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);

	//기울기 프레임
	char str[125];
	sprintf_s(str, "기울기 프레임 : %d", _slopeFrame);
	TextOut(getMemDC(), 100, 500, str, strlen(str));
}

void player::release()
{
}

void player::fieldKeyManager()
{
	//필드모드
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_sceneMode = FIELDMODE;
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 2;
		_move = RIGHT;
	}

	//필드에 있을 때
	if (_sceneMode == FIELDMODE)
	{
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
	//배틀모드
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_sceneMode = BATTLEMODE;
		_x = 100;
		_y = 400;
		_move = FIGHTREADY;
	}

	//배틀장면일 때
	if (_sceneMode == BATTLEMODE)
	{
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
	//이벤트모드
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

	//아래키 누르면 움직인다
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
	//기울기 적용
	if (_sceneMode == EVENTMODE)
	{
		++_slopeFrame;

		if (_slopeFrame % 30 == 0)
		{
			//좌우 랜덤적용
			_rndDirection = RND->getInt(2);

			if (_rndDirection == 0)
			{
				_slopeNum -= 1;

			}
			if (_rndDirection == 1)
			{
				_slopeNum += 1;
	
			}
	
			//기울기 프레임 초기화
			_slopeFrame = 0;
		}

		//물통을 들고 있지 않을 때
		if (!_isWoodDrop)
		{
			//기울기 번호에 따른 이미지 적용
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

		//물통을 들고 있을 때
		if (_isWoodDrop)
		{
			//기울기 번호에 따른 이미지 적용
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
	//상하좌우 움직임
	switch (_move)
	{
	case LEFT:
		_img = IMAGEMANAGER->findImage("아타호왼쪽");
		break;
	case RIGHT:
		_img = IMAGEMANAGER->findImage("아타호오른쪽");
		break;
	case DOWN:
		_img = IMAGEMANAGER->findImage("아타호정면");
		break;
	case UP:
		_img = IMAGEMANAGER->findImage("아타호뒷모습");
		break;
	case LEFTMOVE:
		_img = IMAGEMANAGER->findImage("아타호왼쪽이동");
		break;
	case RIGHTMOVE:
		_img = IMAGEMANAGER->findImage("아타호오른쪽이동");
		break;
	case DOWNMOVE:
		_img = IMAGEMANAGER->findImage("아타호아래이동");
		break;
	case UPMOVE:
		_img = IMAGEMANAGER->findImage("아타호위로이동");
		break;
	default:
		break;
	}

	//스킬 움직임
	switch (_move)
	{
	case SOLOSKILL1:
		_img = IMAGEMANAGER->findImage("아타호호격권");
		break;
	case SOLOSKILL2:
		_img = IMAGEMANAGER->findImage("아타호맹호광파참");
		break;
	case SOLOSKILL3:
		_img = IMAGEMANAGER->findImage("아타호맹호스페셜");
		break;
	case AREASKILL1:
		_img = IMAGEMANAGER->findImage("아타호맹호난무");
		break;
	case AREASKILL2:
		_img = IMAGEMANAGER->findImage("아타호화둔");
		break;
	case AREASKILL3:
		_img = IMAGEMANAGER->findImage("아타호노익장대폭발");
		break;
	case DRINK:
		_img = IMAGEMANAGER->findImage("아타호술마시기");
		break;
	case DRUNKEN:
		_img = IMAGEMANAGER->findImage("아타호만취");
		break;
	case FIGHTREADY:
		_img = IMAGEMANAGER->findImage("아타호전투상태");
		_x = 100;
		_y = 400;
		break;
	default:
		break;
	}

	//이벤트 움직임
	switch (_move)
	{
	case FRONT:
		_img = IMAGEMANAGER->findImage("줄타기");
		break;
	case LEFT1:
		_img = IMAGEMANAGER->findImage("줄타기-1");
		break;
	case LEFT2:
		_img = IMAGEMANAGER->findImage("줄타기-2");
		break;
	case LEFT3:
		_img = IMAGEMANAGER->findImage("줄타기-3");
		break;
	case LEFT4:
		_img = IMAGEMANAGER->findImage("줄타기-4");
		break;
	case RIGHT1:
		_img = IMAGEMANAGER->findImage("줄타기+1");
		break;
	case RIGHT2:
		_img = IMAGEMANAGER->findImage("줄타기+2");
		break;
	case RIGHT3:
		_img = IMAGEMANAGER->findImage("줄타기+3");
		break;
	case RIGHT4:
		_img = IMAGEMANAGER->findImage("줄타기+4");
		break;
	case WOODFRONT:
		_img = IMAGEMANAGER->findImage("물통줄타기");  
		break;
	case WOODLEFT1:
		_img = IMAGEMANAGER->findImage("물통줄타기-1");
		break;
	case WOODLEFT2:
		_img = IMAGEMANAGER->findImage("물통줄타기-2");
		break;
	case WOODLEFT3:
		_img = IMAGEMANAGER->findImage("물통줄타기-3");
		break;
	case WOODLEFT4:
		_img = IMAGEMANAGER->findImage("물통줄타기-4");
		break;
	case WOODRIGHT1:
		_img = IMAGEMANAGER->findImage("물통줄타기+1");
		break;
	case WOODRIGHT2:
		_img = IMAGEMANAGER->findImage("물통줄타기+2");
		break;
	case WOODRIGHT3:
		_img = IMAGEMANAGER->findImage("물통줄타기+3");
		break;
	case WOODRIGHT4:
		_img = IMAGEMANAGER->findImage("물통줄타기+4");
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
	//이동
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

	//스킬 움직임

	//호격권
	if (_img == IMAGEMANAGER->findImage("아타호호격권"))
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

	//광파참
	if (_img == IMAGEMANAGER->findImage("아타호맹호광파참"))
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

	//맹호스페셜
	if (_img == IMAGEMANAGER->findImage("아타호맹호스페셜") && _img->getFrameX() >= 25 && _move == SOLOSKILL3)
	{
		_x += 10;
		if (_x >= WINSIZEX)
		{
			_move = FIGHTREADY;
			_img->setFrameX(0);
		}
	}

	//맹호난무
	if (_img == IMAGEMANAGER->findImage("아타호맹호난무"));
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
	//화둔
	if (_img == IMAGEMANAGER->findImage("아타호화둔"))
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

	//술마시기
	if (_img == IMAGEMANAGER->findImage("아타호술마시기"))
	{
		++_skillFrame;
		if (_skillFrame > 100)
		{
			_img->setFrameX(0);
			_move = DRUNKEN;
			_skillFrame = 0;
		}
	}

	//만취
	if (_img == IMAGEMANAGER->findImage("아타호만취"))
	{
		_isMotionLive = true;
	}

	//EVENT 떨어질 때
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



	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
}

void player::ropeWalk()
{
}

void player::levelCheck()
{
	//레벨업
	if (_currentExp >= _maxExp)
	{
		_isLevelUp = true;
	}

	//레벨업 했을 때
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
