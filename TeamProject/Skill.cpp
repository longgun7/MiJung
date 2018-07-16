#include "stdafx.h"
#include "Skill.h"

//======= 아타호 개인 스킬 1번 : 호격권 ========
atahoTargetSkill1::atahoTargetSkill1() {}

atahoTargetSkill1::~atahoTargetSkill1() {}

HRESULT atahoTargetSkill1::init()
{
	_alphaColor = 0;
	_alphaCount = 0;
	_currentExp = 0;
	_maxExp = 100;
	_level = 1;	
	_width = 0;
	return S_OK;
}

void atahoTargetSkill1::realse(){}

void atahoTargetSkill1::update()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		if (_level > 1 && _viTagSkill->count / 200 <= 0)
		{
			if (_alphaMaxCount <= _alphaCount)
			{
				_alphaColor = 255;
			}
			else if ((_viTagSkill->count % 30 == 0) || (_viTagSkill->count < 15))
			{
				_alphaColor = 255;
			}
			else if (_viTagSkill->count % 15 == 0)
			{
				_alphaColor = 0;
				_alphaCount++;
			}
		}
		if (_viTagSkill->count / 200 > 0)
		{
			_alphaColor -= 15;
			_width += 1;
			_viTagSkill->rc.left -= 2;
			_viTagSkill->rc.top -= 2;
			_viTagSkill->rc.right += 4;
			_viTagSkill->rc.bottom += 4;
		}

		// 스킬 200 카운트 까지만
		if (_viTagSkill->count % 217 == 0)
		{
			_viTagSkill->count = 0;
			_alphaCount = 0;
			SAFE_RELEASE(_viTagSkill->img);
			SAFE_DELETE(_viTagSkill->img);
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
			break;
		}
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->rc.right - _viTagSkill->rc.left, _viTagSkill->rc.bottom - _viTagSkill->rc.top);
	}
}

void atahoTargetSkill1::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		if (_viTagSkill->count / 200 <= 0)
		{
			//스킬 알파 렌더
			_viTagSkill->img->alphaFrameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(), _alphaColor);
		}
		else
		{
			_viTagSkill->img->alphaFrameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(),
				_viTagSkill->rc.right - _viTagSkill->rc.left, _viTagSkill->rc.bottom - _viTagSkill->rc.top,
				_alphaColor);
		}
	}
}

void atahoTargetSkill1::addSkill(float x, float y)
{
	tagSkill targetSkill1;
	ZeroMemory(&targetSkill1, sizeof(tagSkill));
	//스킬 이미지	
	targetSkill1.img = new image;
	targetSkill1.img->init("image/effect/TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

	targetSkill1.x = x;			// 스킬 x좌표
	targetSkill1.y = y;			// 스킬 y좌표
	targetSkill1.count = 0;		// 스킬 생성시 카운트 초기화
	_width = 0;
	_currentExp += 40;			// 스킬 경험치 40 증가

	// 스킬 현재 경험치가 최대 경험치 보다 커지거나 같아지면 스킬 레벨업
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}
	// 스킬 레벨당 최대 카운트 조절
	if (_level == 1)
	{
		_alphaMaxCount = 2;
	}
	else if (_level == 2)
	{
		_alphaMaxCount = 3;
	}
	else if (_level == 3)
	{
		_alphaMaxCount = 5;
	}
	else if (_level == 4)
	{
		_alphaMaxCount = 7;
	}
	targetSkill1.rc = RectMakeCenter(targetSkill1.x, targetSkill1.y, targetSkill1.img->getFrameWidth(), targetSkill1.img->getFrameHeight());

	_vTagSkill.push_back(targetSkill1);
}

//======= 아타호 개인 스킬 2번 : 맹호스페셜 ========
atahoTargetSkill2::atahoTargetSkill2()
{
}

atahoTargetSkill2::~atahoTargetSkill2()
{
}

HRESULT atahoTargetSkill2::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill2", "image/effect/TargetSkill2.bmp", 128, 16, 8, 1, true, RGB(255, 0, 255));

	_currentExp = 0;
	_maxExp = 100;
	_level = 1;

	return S_OK;
}

void atahoTargetSkill2::realse(){}

void atahoTargetSkill2::update()
{
	moveSkill();

	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		// 카운트 4마다 프레임 돌림
		if (_viTagSkill->count % 4 == 0)
		{
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// 프레임 x 최대치 도달시 그 프레임 유지
				_viTagSkill->count = 0;
				_viTagSkill->img->setFrameX(_viTagSkill->img->getMaxFrameX());
				break;
			}
			else
			{
				_viTagSkill->img->setFrameX(_viTagSkill->img->getFrameX() + 1);
			}
		}
	}
}

void atahoTargetSkill2::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		// 스킬 레벨 4이상 부터 그림이 그려진다
		if (_level >= 4)
		{
			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
		}
		//char str[128];
		//sprintf_s(str, "%d, %f, %f, %d, %d, %f", _viTagSkill->count, _viTagSkill->x, _viTagSkill->y, _viTagSkill->img->getFrameX(), _currentExp, _viTagSkill->angle);
		//TextOut(getMemDC(), 200, 200, str, strlen(str));
	}
}
// 스킬 생성
void atahoTargetSkill2::addSkill(float x, float y)
{
	tagSkill targetSkill2;
	ZeroMemory(&targetSkill2, sizeof(tagSkill));
	//스킬 이미지
	targetSkill2.img = new image;
	targetSkill2.img = IMAGEMANAGER->findImage("TargetSkill2");
	targetSkill2.fireX = targetSkill2.x = x;			// 스킬 x좌표, 날라갈 x좌표
	targetSkill2.fireY = targetSkill2.y = y;			// 스킬 y좌표, 날라갈 y좌표
	targetSkill2.count = 0;								// 스킬 생성시 카운트 초기화
	targetSkill2.angle = RND->getFromFloatTo((3.0f / 4.0f) * PI, (5.0f / 4.0f) * PI);		// 스킬 생성시 좌표 랜덤
	targetSkill2.img->setFrameX(0);						// 스킬 생성시 프레임x좌표 초기화
	targetSkill2.speed = 1.0f;							// 스킬 날아갈 속도
	_range = 50.0f;										// 스킬 날아갈 최대 길이
	_currentExp += 40;									// 스킬 경험치 40 증가

														// 스킬 현재 경험치가 최대 경험치 보다 커지거나 같아지면 스킬 레벨업
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}
	targetSkill2.rc = RectMakeCenter(targetSkill2.x, targetSkill2.y, targetSkill2.img->getFrameWidth(), targetSkill2.img->getFrameHeight());

	_vTagSkill.push_back(targetSkill2);
}

//스킬 움직임
void atahoTargetSkill2::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// x, y 좌표 날아갈 좌표 이동
		_viTagSkill->x += cosf(_viTagSkill->angle) * _viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle) * _viTagSkill->speed;

		
		// 스킬 상자 갱신
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// 최대 길이를 벗어나면 스킬이 사라진다
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
		}
		else ++_viTagSkill;
	}
}
// ============== 아타호 개인 스킬 3번 : 비기 - 맹호광파참 ===============
atahoTargetSkill3::atahoTargetSkill3() {}

atahoTargetSkill3::~atahoTargetSkill3() {}

HRESULT atahoTargetSkill3::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill3Charging", "image/effect/TargetSkill3Charging.bmp", 96, 16, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("TargetSkill3Chakra", "image/effect/TargetSkill3Chakra.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));

	_currentExp = 0;
	_maxExp = 100;
	_level = 1;
	_width = 16;
	return S_OK;
}

void atahoTargetSkill3::realse(){}

void atahoTargetSkill3::update()
{
	if (!_start)
	{
		for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
		{
			_viTagSkill->count++;
			if (_viTagSkill->count % 10 == 0)
			{
				if (_img->getMaxFrameX() <= _img->getFrameX())
				{
					_img->setFrameX(0);
				}
				else
				{
					_img->setFrameX(_img->getFrameX() + 1);
				}
			}
			if (_viTagSkill->count % 30 == 0)
			{
				if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
				{
					_viTagSkill->count = 0;
					_viTagSkill->img->setFrameX(_viTagSkill->img->getMaxFrameX());
					break;
				}
				else
				{
					_viTagSkill->img->setFrameX(_viTagSkill->img->getFrameX() + 1);
				}
			}
		}
		moveSkill();
	}

	else if (_start)
	{
		for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
		{
			_viTagSkill->count++;
			_width += 30;
			if (_width >= 500)
			{
				_width = 500;
			}

			if (_viTagSkill->count / 150 > 0)
			{
				if (_viTagSkill->count % 5 == 0)
				{
					_viTagSkill->img->setFrameX(_viTagSkill->img->getFrameX() - 3);
					_viTagSkill->img1->setFrameX(_viTagSkill->img1->getFrameX() - 3);
					_viTagSkill->img2->setFrameX(_viTagSkill->img2->getFrameX() - 3);
					if (_viTagSkill->img->getFrameX() <= 0)
					{
						_expCount = 0;
						_vTagSkill.clear();
						break;
					}
				}
			}
		}
	}
}

void atahoTargetSkill3::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		if (!_start)
		{
			_img->frameRender(getMemDC(), _rc.left, _rc.top, _img->getFrameX(), _img->getFrameY());

			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
		}
		if (_start)
		{
			// 첫번째 그림 랜더
			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
			// 두번꺠 그림 랜더 (
			_viTagSkill->img1->frameRender(getMemDC(), _viTagSkill->rc1.left, _viTagSkill->rc1.top,
				_viTagSkill->img1->getFrameX(), _viTagSkill->img1->getFrameY(), _width, _viTagSkill->img1->getFrameHeight());
			_viTagSkill->img2->frameRender(getMemDC(), _viTagSkill->rc2.left + (_width - _viTagSkill->img2->getFrameWidth()), _viTagSkill->rc2.top,
				_viTagSkill->img2->getFrameX(), _viTagSkill->img2->getFrameY());
		}
	}
}
// 스킬 생성 기모으기 시작
void atahoTargetSkill3::addSkill(float x, float y)
{
	_start = false;
	_expCount++;
	if (_expCount == 1)
	{
		_currentExp += 40;									// 스킬 경험치 40 증가
	}
	// 스킬 현재 경험치가 최대 경험치 보다 커지거나 같아지면 스킬 레벨업
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}

	_img = IMAGEMANAGER->findImage("TargetSkill3Chakra");
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	// 스킬 레벨당 차징 개수
	if (_level <= 2)
	{
		chargingSkill12(x, y);
	}
	else if (_level == 3)
	{
		chargingSkill3(x, y);
	}
	else if (_level == 4)
	{
		chargingSkill4(x, y);
	}
}

//스킬 움직임
void atahoTargetSkill3::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		switch (_level)
		{
		case 1:
		case 2:
			_viTagSkill->speed = 1.0f;							// 스킬 날아갈 속도
			_viTagSkill->angle -= 0.04f;
			_range = 50.0f;										// 스킬 날아갈 최대 길이
			break;
		case 3:
			_viTagSkill->speed = 1.0f;							// 스킬 날아갈 속도
			_viTagSkill->angle -= 0.045f;
			_range = 44.4f;										// 스킬 날아갈 최대 길이
			break;
		case 4:
			_viTagSkill->speed = 1.0f;							// 스킬 날아갈 속도
			_viTagSkill->angle -= 0.045f;
			_range = 44.4f;										// 스킬 날아갈 최대 길이
			break;
		}
		// x, y 좌표 날아갈 좌표 이동
		_viTagSkill->x += cosf(_viTagSkill->angle) * _viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle) * _viTagSkill->speed;

		// 스킬 상자 갱신
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// 최대 길이를 벗어나면 스킬이 사라진다
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
		}
		else ++_viTagSkill;
	}
}
// 차징 1,2단계 위치 및 각도
void atahoTargetSkill3::chargingSkill12(float x, float y)
{
	tagSkill targetSkill3[4];
	for (int i = 0; i < 4; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		// 스킬 이미지
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// 오른쪽
		if (i % 4 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 위쪽
		else if (i % 4 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 50;						// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽
		else if (i % 4 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 아래쪽
		else if (i % 4 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 50;						// 스킬 y좌표, 날라갈 y좌표
		}

		targetSkill3[i].count = 0;							// 스킬 생성시 카운트 초기화
		targetSkill3[i].img->setFrameX(0);					// 스킬 생성시 프레임x좌표 초기화
		targetSkill3[i].speed = 1.0f;						// 스킬 날아갈 속도
		targetSkill3[i].angle = PI * 3 / 2 + (PI * i) / 2;

		_range = 50.0f;										// 스킬 날아갈 최대 길이

		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());
		_vTagSkill.push_back(targetSkill3[i]);
	}
}
// 차징 3단계 위치 및 각도
void atahoTargetSkill3::chargingSkill3(float x, float y)
{
	tagSkill targetSkill3[6];
	for (int i = 0; i < 6; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		//스킬 이미지
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// 오른쪽
		if (i % 6 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 오른쪽 대각선 위
		else if (i % 6 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 40;						// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽 대각선 위
		else if (i % 6 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 40;						// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽
		else if (i % 6 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽 대각선 아래
		else if (i % 6 == 4)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 40;						// 스킬 y좌표, 날라갈 y좌표
		}
		// 오른쪽 대각선 아래
		else if (i % 6 == 5)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 40;						// 스킬 y좌표, 날라갈 y좌표
		}

		targetSkill3[i].count = 0;							// 스킬 생성시 카운트 초기화
		targetSkill3[i].img->setFrameX(0);					// 스킬 생성시 프레임x좌표 초기화
		targetSkill3[i].angle = PI / 2 + PI + (PI6 * i);				// 스킬 생성시 움직임 각도


		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());

		_vTagSkill.push_back(targetSkill3[i]);
	}
}
// 차징 4단계 위치 및 각도
void atahoTargetSkill3::chargingSkill4(float x, float y)
{
	tagSkill targetSkill3[8];
	for (int i = 0; i < 8; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		//스킬 이미지
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// 오른쪽
		if (i % 8 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 오른쪽 대각선 위쪽
		else if (i % 8 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;							// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 25;								// 스킬 y좌표, 날라갈 y좌표
		}
		// 위쪽
		else if (i % 8 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 50;								// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽 대각선 위쪽
		else if (i % 8 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;								// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y - 25;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽
		else if (i % 8 == 4)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;								// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 왼쪽 대각선 아래
		else if (i % 8 == 5)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;								// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 25;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 아래쪽
		else if (i % 8 == 6)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;								// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 50;							// 스킬 y좌표, 날라갈 y좌표
		}
		// 오른쪽 대각선 아래
		else if (i % 8 == 7)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;								// 스킬 x좌표, 날라갈 x좌표
			targetSkill3[i].y = targetSkill3[i].fireY = y + 25;							// 스킬 y좌표, 날라갈 y좌표
		}

		targetSkill3[i].count = 0;							// 스킬 생성시 카운트 초기화
		targetSkill3[i].img->setFrameX(0);					// 스킬 생성시 프레임x좌표 초기화
		targetSkill3[i].angle = PI / 2 + PI + (PI8 * i);				// 스킬 생성시 움직임 각도


		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());

		_vTagSkill.push_back(targetSkill3[i]);
	}
}

void atahoTargetSkill3::fireAddSkill(float x, float y)
{
	_start = true;
	_width = 0;
	// 스킬 레벨당 레이저 결정
	if (_level == 1)
	{
		fireSkill1(x, y);
	}
	else if (_level == 2)
	{
		fireSkill2(x, y);
	}
	else if (_level == 3)
	{
		fireSkill3(x, y);
	}
	else if (_level == 4)
	{
		fireSkill4(x, y);
	}
}

void atahoTargetSkill3::fireSkill1(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//스킬 이미지
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성

	targetSkill.fireX = targetSkill.x = x;		// fire, x 좌표 결정 - 레이저는 아타호의 rc.right값으로
	targetSkill.fireY = targetSkill.y = y;		// fire, y 좌표 결정

	targetSkill.img->setFrameX(0);				// 첫번째 그림 아타호 손 앞 그림
	targetSkill.img1->setFrameX(1);				// 두번째 그림 레이저 늘어나야 하는 그림
	targetSkill.img2->setFrameX(2);				// 세번째 그림 레이저 끝의 그림

	targetSkill.count = 0;						// 카운터 시작시 초기화

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill2(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//스킬 이미지
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// 각 이미지 생성

	targetSkill.fireX = targetSkill.x = x;			// fire, x 좌표 결정 - 레이저는 아타호의 rc.right값으로
	targetSkill.fireY = targetSkill.y = y;			// fire, y 좌표 결정

	targetSkill.img->setFrameX(3);					// 첫번째 그림 아타호 손 앞 그림
	targetSkill.img1->setFrameX(4);					// 두번째 그림 레이저 늘어나야 하는 그림
	targetSkill.img2->setFrameX(5);					// 세번째 그림 레이저 끝의 그림

	targetSkill.count = 0;							// 카운터 시작시 초기화

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill3(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//스킬 이미지
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));

	targetSkill.fireX = targetSkill.x = x;			// fire, x 좌표 결정 - 레이저는 아타호의 rc.right값으로
	targetSkill.fireY = targetSkill.y = y;			// fire, y 좌표 결정

	targetSkill.img->setFrameX(9);					// 첫번째 그림 아타호 손 앞 그림
	targetSkill.img1->setFrameX(10);				// 두번째 그림 레이저 늘어나야 하는 그림
	targetSkill.img2->setFrameX(11);				// 세번째 그림 레이저 끝의 그림

	targetSkill.count = 0;							// 카운터 시작시 초기화

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill4(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//스킬 이미지
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));

	targetSkill.fireX = targetSkill.x = x;			// fire, x 좌표 결정 - 레이저는 아타호의 rc.right값으로
	targetSkill.fireY = targetSkill.y = y;			// fire, y 좌표 결정

	targetSkill.img->setFrameX(15);					// 첫번째 그림 아타호 손 앞 그림
	targetSkill.img1->setFrameX(16);				// 두번째 그림 레이저 늘어나야 하는 그림
	targetSkill.img2->setFrameX(17);				// 세번째 그림 레이저 끝의 그림

	targetSkill.count = 0;							// 카운터 시작시 초기화

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}
//======= 아타호 단체 스킬 2번 : 화둔! ========
atahoAreaSkill2::atahoAreaSkill2(){}

atahoAreaSkill2::~atahoAreaSkill2(){}

HRESULT atahoAreaSkill2::init()
{
	_angle = 0.03f;
	_start = true;
	return S_OK;
}

void atahoAreaSkill2::realse(){}

void atahoAreaSkill2::update()
{
	moveSkill();
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		// 카운트 10 마다
		if (_viTagSkill->count % 10 == 0)
		{
			// 최대 프레임이 된다면
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// 5번째 프레임으로 그려준다
				_viTagSkill->img->setFrameX(5);
				break;
			}
			else
			{
				// 한개씩 늘려준다
				_viTagSkill->img->setFrameX(_viTagSkill->img->getFrameX() + 1);
			}
		}
	}
}

void atahoAreaSkill2::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top, _viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
	}
}

void atahoAreaSkill2::addSkill(float x, float y)
{
	tagSkill areaSkill;
	ZeroMemory(&areaSkill, sizeof(tagSkill));
	//스킬 이미지
	areaSkill.img = new image;
	areaSkill.img->init("image/effect/AreaSkill2.bmp", 96, 16, 6, 1, true, RGB(255, 0, 255));
	areaSkill.fireX = areaSkill.x = x;				// 스킬 x좌표, 날라갈 x좌표
	areaSkill.fireY = areaSkill.y = y;				// 스킬 y좌표, 날라갈 y좌표
	areaSkill.count = 0;								// 스킬 생성시 카운트 초기

	if (_angle > (PI / 6))								// 스킬 각도가 30도가 넘어가면 
	{
		_start = false;									// false
	}
	else if (_angle < 0)								// 스킬 각도가 0도 보다 작아지면
	{		
		_start = true;									// true
	}
	if (_start)
	{
		_angle += 0.05f;								// true 면 각도가 늘어난다 (밑으로)
	}
	else
	{
		_angle -= 0.05f;								// false 면 각도가 줄어든다 (위로)
	}

	areaSkill.angle = PI / 12;						// 스킬 생성시 발사 좌표 지정
	areaSkill.angle -= _angle;						// 스킬 각도 조정
	areaSkill.img->setFrameX(0);						// 스킬 생성시 프레임x좌표 초기화
	areaSkill.speed = 2.0f;							// 스킬 날아갈 속도
	_range = 150.0f;									// 스킬 날아갈 최대 길이
	
	areaSkill.rc = RectMakeCenter(areaSkill.x, areaSkill.y, areaSkill.img->getFrameWidth(), areaSkill.img->getFrameHeight());

	_vTagSkill.push_back(areaSkill);
}

void atahoAreaSkill2::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// 스킬 이동 좌표
		_viTagSkill->x += cosf(_viTagSkill->angle)*_viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle)*_viTagSkill->speed;

		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y, _viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// 스킬이 최대 길이를 넘어가면
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			// 스킬이 없어진다
			_viTagSkill = _vTagSkill.erase(_viTagSkill);

		}
		else
		{
			++_viTagSkill;
		}
	}
}
//======= 아타호 개인 스킬 3번 : 노익장 대폭발 ========
atahoAreaSkill3::atahoAreaSkill3(){}

atahoAreaSkill3::~atahoAreaSkill3(){}

HRESULT atahoAreaSkill3::init()
{
	IMAGEMANAGER->addImage("NULL", 0, 0);		// 빈 이미지 생성
	return S_OK;
}

void atahoAreaSkill3::realse(){}

void atahoAreaSkill3::update()
{
	moveSkill();
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;

		// 카운트 5마다 다음 프레임
		if (_viTagSkill->count % 5 == 0)
		{
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// 최대 프레임 가면 빈 이미지로 바꾼다
				_viTagSkill->img = IMAGEMANAGER->findImage("NULL");
				break;
			}
			else
			{
				_viTagSkill->img->setFrameX(_viTagSkill->img->getFrameX() + 1);
			}
		}
	}
}

void atahoAreaSkill3::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
			_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());

		if (_viTagSkill->img1 != NULL)
		{
			_viTagSkill->img1->frameRender(getMemDC(), _viTagSkill->rc1.left, _viTagSkill->rc1.top,
				_viTagSkill->img1->getFrameX(), _viTagSkill->img1->getFrameY());
		}
	}
}

void atahoAreaSkill3::addFireSkill(float x, float y)
{
	tagSkill areaSkill;
	ZeroMemory(&areaSkill, sizeof(tagSkill));	
	areaSkill.img = new image;	
	areaSkill.img->init("image/effect/AreaSkillFire3.bmp", 192, 48, 4, 1, true, RGB(255, 0, 255));
	// 돌 개수 카운트
	if (_stoneCount < 4)
	{
		areaSkill.img1 = new image;
		areaSkill.img1->init("image/effect/AreaSkillStone3.bmp", 64, 48, 2, 1, true, RGB(255, 0, 255));
		_stoneCount++;
	}
	// 돌 4개 모두 생성 됫으면 빈 이미지로 나와라
	else
	{
		areaSkill.img1 = new image;
		areaSkill.img1 = IMAGEMANAGER->findImage("NULL");
	}
	// 불 좌표 아타호 중점으로 -100 ~ +100
	_randnumFireX = RND->getFromFloatTo(x - 100, x + 100);
	// 불 좌표가 아타호 중점으로 -50 ~ +50 이라면
	if (_randnumFireX > x - 50 && _randnumFireX < x + 50)
	{
		// y 좌표를 위 아래 중 랜덤
		_randnumFireY = RND->getInt(2);
		if (_randnumFireY == 0)
		{
			// 위
			_randnumFireY = y - 50;
		}
		else if (_randnumFireY == 1)
		{
			// 아래
			_randnumFireY = y + 50;
		}
	}
	// 아타호 주변이 아니라면
	else
	{
		_randnumFireY = y;
	}

	areaSkill.x = _randnumFireX;
	areaSkill.y = _randnumFireY;
	// 돌 좌표 아타호 중점으로 -100 ~ +100
	_randnumStoneX = RND->getFromFloatTo(x - 100, x + 100);
	// 돌 좌표가 아타호 중점으로 -50 ~ +50 이라면
	if (_randnumStoneX > x - 50 && _randnumStoneX < x + 50)
	{
		// y 좌표를 위 아래 중 랜덤
		_randnumStoneY = RND->getInt(2);
		if (_randnumStoneY == 0)
		{
			// 위
			_randnumStoneY = y - 50;
		}
		else if(_randnumStoneY == 1)
		{
			// 아래
			_randnumStoneY = y + 50;
		}
	}
	// 아타호 주변이 아니라면
	else
	{
		_randnumStoneY = y;
	}
	// 돌 프레임 0 or 1 중 랜덤
	_randStone = RND->getInt(2);
	areaSkill.img->setFrameX(_randStone);

	areaSkill.stoneX = _randnumStoneX;
	areaSkill.stoneY = _randnumStoneY;
	areaSkill.count = 0;					// 카운트 초기화

	areaSkill.rc = RectMakeCenter(areaSkill.x, areaSkill.y, areaSkill.img->getFrameWidth(), areaSkill.img->getFrameHeight());
	areaSkill.rc1 = RectMakeCenter(areaSkill.stoneX, areaSkill.stoneY, areaSkill.img1->getFrameWidth(), areaSkill.img1->getFrameHeight());

	_vTagSkill.push_back(areaSkill);
}

void atahoAreaSkill3::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// 카운트가 5 아래 또는 50 위면
		if (_viTagSkill->count < 5 || _viTagSkill->count > 50)
		{
			// 돌아 올라가라
			_viTagSkill->stoneY -= 7;
		}

		_viTagSkill->rc1 = RectMakeCenter(_viTagSkill->stoneX, _viTagSkill->stoneY,
			_viTagSkill->img1->getFrameWidth(), _viTagSkill->img1->getFrameHeight());

		// 돌이 다 올라갔다면
		if (_viTagSkill->stoneY < 0)
		{
			// 지워랏
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
			// 벡터의 사이즈가 다 없어지면 돌의 개수를 0으로 초기화 시기칸다
			if (_vTagSkill.size() <= 0) _stoneCount = 0;
		}
		else
		{
			++_viTagSkill;
		}
	}
}