#include "stdafx.h"
#include "player2.h"
#include "enemyManager.h"
HRESULT player2::init(float x , float y)
{

	//스마슈 이미지
	IMAGEMANAGER->addFrameImage("스마슈정면", "image/player/스마슈 정면.bmp", 50, 78, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈왼쪽", "image/player/스마슈 왼쪽.bmp", 40, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈오른쪽", "image/player/스마슈 오른쪽.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈뒷모습", "image/player/스마슈 뒷모습.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈위로이동", "image/player/스마슈 위로이동.bmp", 190, 84, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈아래이동", "image/player/스마슈 아래이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈오른쪽이동", "image/player/스마슈 오른쪽이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈왼쪽이동", "image/player/스마슈 왼쪽이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	
	//스마슈 스킬
	IMAGEMANAGER->addFrameImage("스마슈베기", "image/player/스마슈 베기.bmp", 438, 140, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈대타격", "image/player/스마슈 대타격.bmp", 402, 85, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈용오름", "image/player/스마슈 용오름.bmp", 2000, 87, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈베고날아가기", "image/player/스마슈 베고 날아가기2.bmp", 2675, 120, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈난도질", "image/player/스마슈 난도질2.bmp", 6570, 140, 45, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈절사어면", "image/player/스마슈 절사어면.bmp", 1615, 100, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈분신", "image/player/스마슈 분신.bmp", 99, 85, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈방어", "image/player/스마슈 방어.bmp", 56, 75, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈쓰러짐", "image/player/스마슈 쓰러짐.bmp", 90, 61, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈피격", "image/player/스마슈 피격.bmp", 70, 69, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈전투상태", "image/player/스마슈 전투상태.bmp", 55, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈낙사", "image/player/스마슈 피격.bmp", 70, 69, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈쓰러짐2", "image/player/스마슈 쓰러짐2.bmp", 246, 51, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈세레모니", "image/player/스마슈 세레모니.bmp", 330, 86, 4, 1, true, RGB(255, 0, 255));
	//스마슈 줄타기
	IMAGEMANAGER->addFrameImage("스마슈줄타기", "image/player/스마슈 줄타기2.bmp", 320, 82, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈놀람", "image/player/스마슈 놀람2.bmp", 320, 82, 4, 1, true, RGB(255, 0, 255));
	

	//초기 스마슈모습
	_img = IMAGEMANAGER->findImage("스마슈정면");

	//스마슈 정보
	
	_x2[0] = x - 60;
	_y2[0] = y;
	_angle2[0] = 0;

	_x = _x2[4] - 60;
	_y = _y2[4] - 60;
	_angle = 0;
	
	_jumpPower = 5.0f;
	_gravity = 0.2f;
	_imageFrame = 0;
	_frame = 0;
	_skillFrame = 0;
	_moveSpeed = 5;
	_isMotionLive = false;
	_isJumping = false;
	_isSwordMounting = false;
	_sceneMode = S_FIELDMODE;
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
	_attribute.isLevelUp = false;
	//스마슈 이펙트로 쓸것
	_soloSkillEffect = new atahoTargetSkill2;
	_soloSkillEffect->init();
	//스마슈 고유스킬
	_soloSkill2 = new sumsuTargetSkill2;
	_soloSkill2->init();
	_soloSkill3 = new sumsuTargetSkill3;
	_soloSkill3->init();
	_areaSkill1 = new sumsuAreaSkill1;
	_areaSkill1->init();
	_areaSkill2 = new sumsuAreaSkill2;
	_areaSkill2->init();
	_areaSkill3 = new sumsuAreaSkill3;
	_areaSkill3->init();
	_gameEffect = new gameEffect;
	_gameEffect->init();
	
	return S_OK;
}

//데헷 ㅇ_<
//내가 이맛에 코딩을 못끊지

void player2::update()
{
	playerImage();		 //이미지	
	if (_isMotionLive)
	{
		imageFrame();	 //이미지프레임
	}
	move();
	s_event(); //스마슈 이벤트
	battleKeyManager(); //배틀모드일 때
	levelCheck(); //레벨체크
		//스킬
	_soloSkillEffect->update();
	_soloSkill2->update();
	_soloSkill3->update();
	_areaSkill1->update();
	_areaSkill2->update();
	_areaSkill3->update();
	_gameEffect->update();

}

void player2::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);

	char str[125];

	sprintf_s(str, "스킬 프레임 : %d", _skillFrame);
	TextOut(getMemDC(), 100, 350, str, strlen(str));

	char str2[123];
	sprintf_s(str2, "이미지프레임 : %d", _imageFrame);
	TextOut(getMemDC(), 100, 370, str2, strlen(str2));
	//if (_isJumping)
	{
		char str3[123];
		sprintf_s(str3, "점핑여부 : %d", _isJumping);
		TextOut(getMemDC(), 100, 390, str3, strlen(str3));
	}
	char str4[234];
	
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
	strongestSwordEffect();
	_soloSkill2->render();
	_soloSkill3->render();
	_areaSkill1->render();
	_areaSkill2->render();
	_areaSkill3->render();
	_gameEffect->render();

	for (int i = 0; i < 7; i++)
	{
		Rectangle(getMemDC(), _skillRC[i].left, _skillRC[i].top, _skillRC[i].right, _skillRC[i].bottom);
	}
	for (int i = 0; i < 5; i++)
	{
		//Rectangle(getMemDC(), _rc2[i].left, _rc2[i].top, _rc2[i].right, _rc2[i].bottom);
	}
	
}

void player2::release()
{
	SAFE_DELETE(_soloSkill2);
	SAFE_DELETE(_soloSkill3);
	SAFE_DELETE(_areaSkill1);
	SAFE_DELETE(_areaSkill2);
	SAFE_DELETE(_areaSkill3);
	SAFE_DELETE(_gameEffect);
}

void player2::fieldKeyManager(float x , float y,float angle)
{

	if (_sceneMode == S_FIELDMODE)
	{
		if (_attribute.currentHp == 0)
		{
			_attribute.currentHp += 1;
		}

		++_skillFrame;
		if (_skillFrame % 7 == 0)
		{
			_soloSkillEffect->addSkill(_x, _y - 10);
			_skillFrame = 0;
		}
		//아타호의 위치에 따라 앵글이 바뀐다.
		//_angle = getAngle(_x, _y, x, y);




		
		if (getDistance(x, y, _x2[0], _y2[0]) > 15.0f)
		{

			_angle2[0] = angle;
			
			_x2[0] = x - cosf(_angle2[0]) * 10.0f;
			_y2[0] = y - -sinf(_angle2[0]) * 10.0f;
		}
		for (int i = 1; i < 5; i++)
		{
			if (getDistance(_x2[i-1], _y2[i-1], _x2[i], _y2[i]) > 15.0f)
			{

				_angle2[i] = _angle2[i-1];

				_x2[i] = _x2[i-1] - cosf(_angle2[i]) * 10.0f;
				_y2[i] = _y2[i-1] - -sinf(_angle2[i]) * 10.0f;
			}
		}

		if (getDistance(_x2[4], _y2[4], _x, _y) > 15.0f)
		{

			_angle = _angle2[4];

			_x = _x2[4] - cosf(_angle) * 10.0f;
			_y = _y2[4] - -sinf(_angle) * 10.0f;
		}
	
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			
			for (int i = 0; i < 5; i++)
			{
				_x2[i] += cosf(_angle2[i])* _moveSpeed;
				_y2[i] += -sinf(_angle2[i])*_moveSpeed;
			}
				
				_x += cosf(_angle)* _moveSpeed;
				_y += -sinf(_angle)*_moveSpeed;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			
			
			for (int i = 0; i < 5; i++)
			{
				_x2[i] += cosf(_angle2[i])* _moveSpeed;
				_y2[i] += -sinf(_angle2[i])*_moveSpeed;
			}
				_x += cosf(_angle)* _moveSpeed;
				_y += -sinf(_angle)*_moveSpeed;
		}
	
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
		
			for (int i = 0; i < 5; i++)
			{
				_x2[i] += cosf(_angle2[i])* _moveSpeed;
				_y2[i] += -sinf(_angle2[i])*_moveSpeed;
			}
			_x += cosf(_angle)* _moveSpeed;
			_y += -sinf(_angle)*_moveSpeed;
		}
		

		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{

			
			for (int i = 0; i < 5; i++)
			{
				_x2[i] += cosf(_angle2[i])* _moveSpeed;
				_y2[i] += -sinf(_angle2[i])*_moveSpeed;
			}
			_x += cosf(_angle)* _moveSpeed;
			_y += -sinf(_angle)*_moveSpeed;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN) || KEYMANAGER->isStayKeyDown(VK_UP) || KEYMANAGER->isStayKeyDown(VK_RIGHT) || KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			if (_angle == PI / 2)
			{
				_move = S_UPMOVE;
				_isMotionLive = true;
			}
			if (_angle == 2 * PI - PI / 2)
			{
				_move = S_DOWNMOVE;
				_isMotionLive = true;
			}
			if (_angle == 0)
			{
				_move = S_RIGHTMOVE;
				_isMotionLive = true;
			}
			if (_angle == PI)
			{
				_move = S_LEFTMOVE;
				_isMotionLive = true;
			}
		}
		//정자세
		if (KEYMANAGER->isOnceKeyUp(VK_DOWN) || KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			if (_angle == 2 * PI - PI / 2)
			{
				_move = S_DOWN;
			}
			if (_angle == PI)
			{
				_move = S_LEFT;
			}
			if (_angle == 0)
			{
				_move = S_RIGHT;
			}
			if (_angle ==PI / 2 )
			{
				_move = S_UP;
			}
		}
		
		
	}
}

//배틀모드
void player2::battleKeyManager()
{
	if (_attribute.currentHp > 0)
	{
		if (_sceneMode == S_BATTLEMODE && _em->getVEnmey().size() != 0)
		{
			
			//스킬
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (PtInRect(&_skillRC[0], _ptMouse))
				{
					_move = S_BASICSKILL1;
					_isMotionLive = true;
					_skillFrame = 0;
					_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 50;
					_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
					setSoloDamage(6);

				}
				if (PtInRect(&_skillRC[1], _ptMouse))
				{
					_move = S_SOLOSKILL1;
					_isMotionLive = true;
					_skillFrame = 0;
					_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[2], _ptMouse))
				{
					_move = S_SOLOSKILL2;
					_isMotionLive = true;
					_skillFrame = 0;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[3], _ptMouse))
				{
					_move = S_AREASKILL1;
					_isMotionLive = true;
					_skillFrame = 0;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[4], _ptMouse))
				{
					_move = S_AREASKILL3;
					_isMotionLive = true;
					_skillFrame = 0;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[5], _ptMouse))
				{
					_move = S_SOLOSKILL3;
					_isMotionLive = true;
					_skillFrame = 0;
					_attribute.currentMp -= 3;
				}
				if (PtInRect(&_skillRC[6], _ptMouse))
				{
					_x = WINSIZEX / 2;
					_y = WINSIZEY / 3;
					_move = S_AREASKILL2;
					_isMotionLive = true;
					_skillFrame = 0;
					_attribute.currentMp -= 3;
				}
				if (KEYMANAGER->isOnceKeyDown('J'))
				{
					_move = S_ESCAPE;
					_isMotionLive = true;
				}
				if (KEYMANAGER->isOnceKeyDown('V'))
				{
					setPlayerDamage(11);
				}
			}
		}
	}
	else
	{
		_move = S_NOCKDOWN;
		_isMotionLive = true;
	}
}

void player2::playerImage()
{
	//이미지
	switch (_move)
	{
	case S_RIGHT:
		_img = IMAGEMANAGER->findImage("스마슈오른쪽");
		break;
	case S_LEFT:
		_img = IMAGEMANAGER->findImage("스마슈왼쪽");
		break;
	case S_DOWN:
		_img = IMAGEMANAGER->findImage("스마슈정면");
		break;
	case S_UP:
		_img = IMAGEMANAGER->findImage("스마슈뒷모습");
		break;
	case S_LEFTMOVE:
		_img = IMAGEMANAGER->findImage("스마슈왼쪽이동");
		break;
	case S_RIGHTMOVE:
		_img = IMAGEMANAGER->findImage("스마슈오른쪽이동");
		break;
	case S_DOWNMOVE:
		_img = IMAGEMANAGER->findImage("스마슈아래이동");
		break;
	case S_UPMOVE:
		_img = IMAGEMANAGER->findImage("스마슈위로이동");
		break;
	case S_BASICSKILL1:
		_img = IMAGEMANAGER->findImage("스마슈베기");
		break;
	case S_SOLOSKILL1:
		_img = IMAGEMANAGER->findImage("스마슈대타격");
		break;
	case S_SOLOSKILL3:
		_img = IMAGEMANAGER->findImage("스마슈난도질");
		break;
	case S_AREASKILL1:
		_img = IMAGEMANAGER->findImage("스마슈베기");
		break;
	case S_AREASKILL3:
		_img = IMAGEMANAGER->findImage("스마슈용오름");
		break;
	case S_SOLOSKILL2:
		_img = IMAGEMANAGER->findImage("스마슈절사어면");
		break;
	case S_AREASKILL2:
		_img = IMAGEMANAGER->findImage("스마슈분신");
		break;
	case S_FIGHTREADY:
		_img = IMAGEMANAGER->findImage("스마슈전투상태");
		_x = 100;
		_y = 400;
		break;
	case S_ROPEWALKING:
		_img = IMAGEMANAGER->findImage("스마슈줄타기");
		break;
	case S_DANGER:
		_img = IMAGEMANAGER->findImage("스마슈낙사");
		break;	
	case S_AFRAID:
			_img = IMAGEMANAGER->findImage("스마슈놀람");
			break;
	case S_DEFENCE:
		_img = IMAGEMANAGER->findImage("스마슈방어");
		break;
	case S_NOCKDOWN:
		_img = IMAGEMANAGER->findImage("스마슈쓰러짐2");
		break;
	case S_ESCAPE:
		_img = IMAGEMANAGER->findImage("스마슈방어");
		break;
	case S_SEREMONI:
		_img = IMAGEMANAGER->findImage("스마슈세레모니");
		break;
	default:
		break;
	}
}

void player2::imageFrame()
{
	//이미지프레임
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
	
	//스킬 이동
	if (_move == S_BASICSKILL1)
	{
		++_skillFrame;
		if (_skillFrame == 50)
		{
			_soloSkillEffect->addSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
		}
		if (_skillFrame > 80)
		{
			_move = S_FIGHTREADY;
		}
	}
	//대타격
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
		if (_img->getFrameX() >= _img->getMaxFrameX() && _skillFrame%20==0 )
		{
               setSoloDamage(6);
		}
		if (_img->getFrameX() >= _img->getMaxFrameX())
		{
			_soloSkill2->addFireSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
			_imageFrame = _img->getMaxFrameX();
		}
		if (_skillFrame > 100)
		{
			_move = S_FIGHTREADY;
		}
	}
	
	//절사어면
	if (_move == S_SOLOSKILL2)
	{
		++_skillFrame;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		if (_img->getFrameX() >= 2 && _x < WINSIZEX - 100)
		{
			_imageFrame = 3;
			_x += 20;
			
			_img->setFrameX(2);
			_soloSkillEffect->addSkill(_x, _y);
		}
		if (_skillFrame == 50)
		{
			setAreaDamage(6);
			_areaSkill1->addAreaSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y, _enemyIndex + 1);
		}
		//스킬 넣기
		if ((_skillFrame % 5 == 0 && _imageFrame == 5) || (_skillFrame % 5 == 0 && _imageFrame == 9))
		{
			setAreaDamage(6);
			randEffect();
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

	//난도질
	if (_move == S_SOLOSKILL3)
	{

		_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 80;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		++_skillFrame;
		if (_skillFrame % 30 == 0 && _img->getFrameX() < 40)
		{
			setSoloDamage(6);
			randEffect();
		}
		if (_img->getFrameX() == 43)
		{
			if (!SOUNDMANAGER->isPlaySound("Cut4"))
			{
				SOUNDMANAGER->play("Cut4", 1.0f);
			}
			_soloSkill3->cutBigSkill(_x + 30, _y);
		}
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

	//백인일섬
	if(_move == S_AREASKILL1)
	{
		++_skillFrame;
		if (_skillFrame == 30)
		{
			for (int i = 0; i < _em->getVEnmey().size(); i++)
			{
				_areaSkill1->addAreaSkill(_em->getVEnmey()[i]->getTagEnmey().x, _em->getVEnmey()[i]->getTagEnmey().y, _em->getVEnmey().size());
				setAreaDamage(10);
			}
		}
		if (_skillFrame > 100)
		{	
			_img->setFrameX(0);
			_imageFrame = 0;
			_move = S_FIGHTREADY;
			
		}
	}

	//분신
	if (_img == IMAGEMANAGER->findImage("스마슈분신") && _move == S_AREASKILL2)
	{
		if (!SOUNDMANAGER->isPlaySound("Clone1"))
		{
			SOUNDMANAGER->play("Clone1", 0.5f);
		}
		++_skillFrame;
		if (_skillFrame == 50)
		{
			_areaSkill2->addAreaSkill(_x, _y);
		}
		if (_skillFrame < 50)
		{
			_img->setFrameX(0);
		}
		if (_skillFrame > 50 && _skillFrame < 150)
		{
			_img->setFrameX(1);
		}
		if (_skillFrame > 150 && _skillFrame % 30 == 0)
		{
			SOUNDMANAGER->stop("Clone1");
			setAreaDamage(6);
			randAreaEffect();
		}
		if (_skillFrame > 400)
		{
			_skillFrame = 0;
			_img->setFrameX(0);
			_move = S_FIGHTREADY;
			_isMotionLive = true;
		}
	}

	//용오름 
	if (_move == S_AREASKILL3)
	{
		if (!SOUNDMANAGER->isPlaySound("DragronUp"))
		{
			SOUNDMANAGER->play("DragronUp", 0.5f);
		}
		++_skillFrame;
		_x = 200;
		_y = WINSIZEY / 2;
		if (_img->getFrameX() >= _img->getMaxFrameX() )
		{
			_imageFrame = 0;
		}
		if (_skillFrame < 30)
		{
			_areaSkill3->addAreaSkill(WINSIZEX -250, WINSIZEY/3);
		}
		
		
		if (_skillFrame % 30 == 0)
		{
			
			setAreaDamage(6);
			randAreaEffect();
		}
		if (_skillFrame > 200)
		{
			_img->setFrameX(0);
			_skillFrame = 0;
			_move = S_FIGHTREADY;
		}
	}

	
	

	//피격당했을 때
	if (_move == S_DANGER)
	{
		if (!SOUNDMANAGER->isPlaySound("Clone1"))
		{
			SOUNDMANAGER->play("Hit", 0.5f);
		}
		++_skillFrame;

		if (_skillFrame < 20)
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
			_move = S_FIGHTREADY;
		}
	}
	
	if (_move == S_ESCAPE)
	{
		++_skillFrame;
		_x -= 2;
		if (_skillFrame % 10 == 0)
		{
			_gameEffect->summonLCloud(_x+ 20, _y+ 30);
			_gameEffect->summonRCloud(_x + 20, _y + 30);
		}
	}
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	
	for (int i = 0; i < 5; i++)
	{
		_rc2[i] = RectMakeCenter(_x2[i], _y2[i], 50, 50);
	}
	
	for (int i = 0; i < 7; i++)
	{
		_skillRC[i] = RectMakeCenter(500 + i * 40, 500, 30, 30);
	}
}

void player2::randEffect()
{
	int randCut = RND->getInt(3);
	
	if (randCut == 0)
	{
		_soloSkill3->cutDiagonalSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
		if (!SOUNDMANAGER->isPlaySound("Cut1"))
		{
			SOUNDMANAGER->play("Cut1", 0.5f);
		}
	}
	if (randCut == 1)
	{
		_soloSkill3->cutDownSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
		if (!SOUNDMANAGER->isPlaySound("Cut2"))
		{
			SOUNDMANAGER->play("Cut2", 0.5f);
		}
	}
	if (randCut == 2)
	{
		_soloSkill3->cutUpSkill(_em->getVEnmey()[_enemyIndex]->getTagEnmey().x, _em->getVEnmey()[_enemyIndex]->getTagEnmey().y);
		if (!SOUNDMANAGER->isPlaySound("Cut3"))
		{
			SOUNDMANAGER->play("Cut3", 0.5f);
		}
	}
}

void player2::randAreaEffect()
{
	int randEffect = RND->getInt(8);

	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		if (randEffect == 0)
		{// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randEffect == 1)
		{// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randEffect == 2)
		{// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRUDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randEffect == 3)
		{// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRDDiagonal(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randEffect == 4)
		{// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randEffect == 5)
		{// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitLDDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x - 10, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
		if (randEffect == 6)
		{// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRUDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y - 20);
		}
		if (randEffect == 7)
		{// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
			_gameEffect->hitRDDiagonal2(_em->getVEnmey()[i]->getTagEnmey().x + 30, _em->getVEnmey()[i]->getTagEnmey().y + 30);
		}
	}
}

void player2::s_event()
{
	//이벤트모드
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

	//줄타기
	if (_sceneMode == S_EVENTMODE)
	{
		
		_move = S_ROPEWALKING;
		//낙사할 때
		if (_isJumping && _x > WINSIZEX/2 -150 &&_x < WINSIZEX/2 +150)
		{
			_y -= _jumpPower;
			_jumpPower -= _gravity;
			_x += 3;	
		}
		if (_isJumping)
		{
			_img = IMAGEMANAGER->findImage("스마슈낙사");
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isMotionLive = true;
		}

	}
}

void player2::levelCheck()
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
			_move = S_SEREMONI;
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

		if (_move == S_SEREMONI)
		{
			_x = 95;
			_y = 300;
			++_skillFrame;
			if (_skillFrame > 75)
			{
				_move = S_FIGHTREADY;
			}
		}
		if (_isExpSet == true)
		{
			if (_exp - _compareExp > 100)
			{
				_attribute.currentExp += 1;
				_compareExp += 1;
			}
			if (_exp - _compareExp > 50)
			{
				_attribute.currentExp += 2;
				_compareExp += 2;
			}
			if (_exp - _compareExp > 0)
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
}

void player2::strongestSwordEffect()
{
	if (_isSwordMounting)
	{//이펙트
		if (_move == S_RIGHT || _move == S_UP || _move == S_RIGHTMOVE || _move == S_UPMOVE)
		{
			//image
			_img->frameRender(getMemDC(), _rc.left, _rc.top);
			//스킬
			_soloSkillEffect->render();
		}
		else
		{
			//스킬
			_soloSkillEffect->render();
			//image
			_img->frameRender(getMemDC(), _rc.left, _rc.top);
		}
	}
}

void player2::setSoloDamage(int plusDamage)
{
	_em->hitEnemy(_enemyIndex, _attribute.atk + plusDamage);
}

void player2::setAreaDamage(int plusDamage)
{
	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		_em->hitEnemy(i, _attribute.atk + plusDamage);
	}
}
void player2::setExp(int exp)
{
	_exp += exp;
	_isExpSet = true;
}
//스텟 넣기
void player2::setStat(int atk, int def, int luck, int cri, int speed)
{
	_attribute.atk += atk;
	_attribute.cri += cri;
	_attribute.def += def;
	_attribute.luck += luck;
	_attribute.speed += speed;
}

//포션넣기
void player2::setPortion(int hp, int mp)
{
	if (_attribute.currentMp <= _attribute.maxMp || _attribute.currentHp <= _attribute.maxHp)
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

void player2::setSkillMove(SMOVE move)
{
	if (move == S_BASICSKILL1)
	{
		_move = S_BASICSKILL1;
		_isMotionLive = true;
		_skillFrame = 0;
		_x = _em->getVEnmey()[_enemyIndex]->getTagEnmey().x - 50;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		setSoloDamage(6);
	}
	if (move == S_SOLOSKILL1 && _attribute.currentMp >= 3)
	{
		_move = S_SOLOSKILL1;
		_isMotionLive = true;
		_skillFrame = 0;
		_y = _em->getVEnmey()[_enemyIndex]->getTagEnmey().y;
		_attribute.currentMp -= 3;
	}
	if (move == S_SOLOSKILL2 && _attribute.currentMp >= 3)
	{
		_move = S_SOLOSKILL2;
		_isMotionLive = true;
		_skillFrame = 0;
		_attribute.currentMp -= 3;
	}
	if (move == S_AREASKILL1)
	{
		_move = S_AREASKILL1;
		_isMotionLive = true;
		_skillFrame = 0;
		_attribute.currentMp -= 3;
	}
	if (move == S_AREASKILL3)
	{
		_move = S_AREASKILL3;
		_isMotionLive = true;
		_skillFrame = 0;
		_attribute.currentMp -= 3;
	}
	if (move == S_SOLOSKILL3)
	{
		_move = S_SOLOSKILL3;
		_isMotionLive = true;
		_skillFrame = 0;
		_attribute.currentMp -= 3;
	}
	if (move == S_AREASKILL2)
	{
		_x = WINSIZEX / 2;
		_y = WINSIZEY / 3;
		_move = S_AREASKILL2;
		_isMotionLive = true;
		_skillFrame = 0;
		_attribute.currentMp -= 3;
	}

	
}


void player2::setPlayerDamage(int damage)
{
	
	if (_sceneMode == S_BATTLEMODE)
	{
		if (damage > _attribute.def)
		{
			damage -= _attribute.def;
			_move = S_DANGER;
		}
		else
		{
			damage = 0;
			_move = S_DEFENCE;
			_isMotionLive = true;
		}

		_attribute.currentHp -= damage;

		if (_attribute.currentHp <= 0)
		{
			_attribute.currentHp = 0;
		}
	}
}

void player2::setEventMode(S_SCENEMODE mode)
{
	_sceneMode = S_EVENTMODE;
	_x = WINSIZEX / 2+20;
	_y = WINSIZEY / 2 - 40;
	_isJumping = false;
}

player2::player2()
{
}


player2::~player2()
{
}
