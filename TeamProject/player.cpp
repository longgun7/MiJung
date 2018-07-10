#include "stdafx.h"
#include "player.h"
#include "enemyManager.h"
#include "playMap.h"

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
	
	IMAGEMANAGER->addFrameImage("아타호정권찌르기", "image/player/아타호 정권찌르기.bmp", 704, 172, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호돌려차기", "image/player/아타호 돌려차기.bmp", 704, 172, 4, 1, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->addFrameImage("아타호피격", "image/player/아타호 피격.bmp", 50, 77, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호세레모니", "image/player/아타호 세레모니3.bmp", 870, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호코골이", "image/player/아타호 코골이.bmp", 1145, 50, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호쓰러짐", "image/player/아타호 쓰러짐.bmp", 246, 63, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호방어","image/player/아타호 방어.bmp", 45, 64, 1, 1, true, RGB(255, 0, 255));
	//줄타기
	IMAGEMANAGER->addFrameImage("올라타기", "image/player/올라타기.bmp", 100, 120, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기", "image/player/줄타기.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+1", "image/player/줄타기+1.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+2", "image/player/줄타기+2.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+3", "image/player/줄타기+3.bmp", 300, 120, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("줄타기+4", "image/player/줄타기+4.bmp", 65, 94, 1, 1, true, RGB(255, 0, 255));
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
	
	//이펙트
	IMAGEMANAGER->addFrameImage("스마슈회오리", "image/player/스마슈 회오리.bmp", 400, 42, 5, 1, true, RGB(255, 0, 255));

	//이펙트
	_effectImage.img = IMAGEMANAGER->findImage("스마슈회오리");
	_effectImage.frameImage = 0;
	_effectImage.frame = 0;

	_img = IMAGEMANAGER->findImage("아타호정면");
	
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

	//아타호 타겟 스킬 
	
	//호격권
	_soloSkillEffect1 = new atahoTargetSkill1;
	_soloSkillEffect1->init();
	//맹호스페셜
	_soloSkillEffect2 = new atahoTargetSkill2;
	_soloSkillEffect2->init();
	//에너지파
	_soloSkillEffect3 = new atahoTargetSkill3;
	_soloSkillEffect3->init();
	//광역스킬2
	_areaSkillEffect2 = new atahoAreaSkill2;
	_areaSkillEffect2->init();
	//광역스킬3
	_areaSkillEffect3 = new atahoAreaSkill3;
	_areaSkillEffect3->init();
	//게임 이펙트
	_gameEffect = new gameEffect;
	_gameEffect->init();

	_zOrderRC = RectMake(_rc.left, _rc.bottom - 25, _img->getFrameWidth(), 25);
	
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

	//스킬 이펙트 업데이트
	_soloSkillEffect1->update(); //호격권 스킬이펙트 업데이트
	_soloSkillEffect2->update(); //맹호스페셜 스킬 이펙트 업데이트
	_soloSkillEffect3->update(); //에너지파 스킬 이펙트 업데이트
	_areaSkillEffect2->update(); //화둔 호화구시수시술! 
	_areaSkillEffect3->update(); //노익장 대폭발!
	_gameEffect->update();//게임 이펙트
	effectImage();

}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	char str2[124];
	sprintf_s(str2, "아타호 이미지프레임: %d", _imageFrame);
	TextOut(getMemDC(), 100, 440, str2, strlen(str2));
	//기울기 프레임
	char str[125];
	if (KEYMANAGER->isToggleKey('Z'))
	{
		sprintf_s(str, "에너미 hp : %d", _em->getVEnmey()[0]->getTagEnmey().hp);
		TextOut(getMemDC(), 100, 410, str, strlen(str));
	}//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
	//스킬 이펙트 렌더
	_soloSkillEffect1->render(); 
	_soloSkillEffect2->render();
	_soloSkillEffect3->render();
	_areaSkillEffect2->render();
	_areaSkillEffect3->render();
	_gameEffect->render();
	if (_isWeaponMounting)
	{//이펙트
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

	//배틀장면일 때
	if (_sceneMode == BATTLEMODE)
	{	
		if (_attribute.currentHp > 0 && _em->getVEnmey().size() != 0)
		{
			//스킬
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
	case BASICSKILL1:
		_img = IMAGEMANAGER->findImage("아타호정권찌르기");
		break;
	case BASICSKILL2:
		_img = IMAGEMANAGER->findImage("아타호돌려차기");
		break;
	case BASICSKILL3:
		_img = IMAGEMANAGER->findImage("아타호노익장대폭발");
		break;
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
		_y = 200;
		break;
	case DAMAGE:
		_img = IMAGEMANAGER->findImage("아타호피격");
		break;
	case DEFENCE:
		_img = IMAGEMANAGER->findImage("아타호방어");
		break;
	case SEREMONI:
		_img = IMAGEMANAGER->findImage("아타호세레모니");
		break;
	case NOCKDOWN:
		_img = IMAGEMANAGER->findImage("아타호쓰러짐");
		break;
	case HPUP:
		_img = IMAGEMANAGER->findImage("아타호노익장대폭발");
		break;
	case MPUP:
		_img = IMAGEMANAGER->findImage("아타호노익장대폭발");
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
	tileMove();

	////////////////////////////////////////////////////////
	//
	//                     스킬 움직임
	//
	////////////////////////////////////////////////////////


	////////////////////////////////////
	//
	//             기본기
    //
	////////////////////////////////////

	//정권찌르기
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
	
	//돌려차기
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

	//다리후리기
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
	//              개인기
    //
	////////////////////////////////////

	//호격권
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

	
	//광파참
	if ( _move == SOLOSKILL2)
	{
		_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 250;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		++_skillFrame;
		
		//기모으는 중~
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

		//때릴 때~~~
		if (_skillFrame > 120 && _skillFrame < 122)
		{
			//스킬
			_soloSkillEffect3->fireAddSkill(_x + 50, _y);
		}
		if(_skillFrame > 122 && _skillFrame < 300)
		{
			_img->setFrameX(2);	
			//데미지
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

	//맹호스페셜
	if (_move == SOLOSKILL3)
	{
		++_skillFrame;
		//데미지 넣기~
		if ((_skillFrame% 7 ==0 && _imageFrame == 1) || (_skillFrame % 7 == 0 && _imageFrame == 5) ||
			(_skillFrame % 7 == 0 && _imageFrame == 8) || (_skillFrame % 7 == 0 && _imageFrame == 13) ||
			(_skillFrame % 7 == 0 && _imageFrame == 18) || (_skillFrame % 7 == 0 && _imageFrame == 23) 
			)
		{
			randEffect();
			setSoloDamage(6);
			_skillFrame = 0;
		}
		//날라까기~
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
	//                단체기
    //
	////////////////////////////////////////////

	//맹호난무
	if (_move == AREASKILL1);
	{
		
		if (_isJumping)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
			
		}
		//데미지 넣기
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
	//화둔
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
			//스킬 이펙트 나오기~
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
			//데미지 넣기~
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
	//노익장 대폭발
	if (_move == AREASKILL3)
	{
		++_skillFrame;
		//스킬 이펙트 나오기~
		if (_skillFrame % 7 == 0 && _skillFrame < 150)
		{
			_areaSkillEffect3->addFireSkill(_x, _y);
		}
		
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_img->setFrameX(_img->getMaxFrameX());
		}
		//데미지 넣기
		if (_skillFrame% 100 == 0)
		{
			randEffect();
			setAreaDamage(20); //데미지 넣기~
		}
		if (_skillFrame >= 300)
		{
			
			_move = FIGHTREADY;
			_skillFrame = 0;
		}
	}
	//술마시기
	if (_img == IMAGEMANAGER->findImage("아타호술마시기"))
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

	//피격당했을 때
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
	//hp회복 
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
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	//스킬렉트
	for (int i = 0; i < 9; i++)
	{
		_skillRC[i] = RectMakeCenter(400 + i * 40, 450, 30, 30);
	}
}

//레벨업 
void player::levelCheck()
{
	if (_sceneMode == BATTLEMODE)
	{
		//레벨업
		if (_attribute.currentExp >= _attribute.maxExp)
		{
			
			_attribute.isLevelUp = true;
		}

		//레벨업 했을 때
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

//에너미가 데미지 넣을 것
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

//에너미에게 공격을 넣는 함수를 간단하게 만든 함수
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

//스텟 넣기
void player::setStat(int atk, int def, int luck, int cri, int speed)
{
	
	_attribute.atk += atk;
	_attribute.cri += cri;
	_attribute.def += def;
	_attribute.luck += luck;
	_attribute.speed += speed;
}

//포션먹기
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
	{// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitLUDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x-10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y-20);
	}
	if (randNum == 1)
	{// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitLDDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x- 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 2)
	{// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitRUDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 3)
	{// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitRDDiagonal(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 4)
	{// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitLUDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 5)
	{// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitLDDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 10, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
	if (randNum == 6)
	{// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitRUDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y - 20);
	}
	if (randNum == 7)
	{// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
		_gameEffect->hitRDDiagonal2(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x + 30, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y + 30);
	}
}

void player::randAreaEffect()
{
	int randNum = RND->getInt(8);
	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		if (randNum == 0)
		{// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 1)
		{// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 2)
		{// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 3)
		{// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 4)
		{// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 5)
		{// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLDDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randNum == 6)
		{// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randNum == 7)
		{// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
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

	int tileIndex[2];	//이동 방향에 따른 타일속성을 검출하기위한 타일 인덱스 값 계산용 배열
	int tileX, tileY;	//탱크 이동 방향에 따라 '검출'하기 위한 인덱스 계산용 변수

	rcCollision = _zOrderRC;

	switch (_move)
	{
	case LEFTMOVE:	_angle = PI; (_x > TILESIZE * 3) ? _x += cosf(_angle)*_moveSpeed : _x = TILESIZE * 3;	break;
	case RIGHTMOVE: _angle = 0; (_x < CAMERA->getMaxPositon().x - TILESIZE * 3) ? _x += cosf(_angle)*_moveSpeed : _x = CAMERA->getMaxPositon().x - TILESIZE * 3;	break;
	case DOWNMOVE:	_angle = 2 * PI - PI / 2; (_y > TILESIZE) ? _y += -sinf(_angle)*_moveSpeed : _y = TILESIZE;	break;
	case UPMOVE:	_angle = PI / 2; (_y < CAMERA->getMaxPositon().y - TILESIZE) ? _y += -sinf(_angle)*_moveSpeed : _y = CAMERA->getMaxPositon().y - TILESIZE;	break;
	}

	rcCollision = RectMakeCenter(_x, _y + 27, _img->getFrameWidth(), 25);

	//임의의 충돌렉트 사이즈 줄이기
	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILESIZE;
	tileY = rcCollision.top / TILESIZE;

	//방향에 따른 타일 검출
	//타일 검출을 통해서 내 진행 방향(좌표)에 있는 타일의 속성을 검출
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

	// 혹시 모를 예외처리(tileIndex가 쓰레기 값이 나올 경우)
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
