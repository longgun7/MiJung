#include "stdafx.h"
#include "Skill.h"

//======= 아타호 개인 스킬 1번 : 호격권 ========
atahoTargetSkill1::atahoTargetSkill1() {}

atahoTargetSkill1::~atahoTargetSkill1() {}

HRESULT atahoTargetSkill1::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill1", "image/effect/TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

	_alphaColor = 0;
	_alphaCount = 0;
	_currentExp = 0;
	_maxExp = 100;
	_level = 1;
	return S_OK;
}

void atahoTargetSkill1::realse()
{
}

void atahoTargetSkill1::update()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill) 
	{
		_viTagSkill->count++; 
		if (_viTagSkill->level > 1)
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
		// 스킬 200 카운트 까지만
		if (_viTagSkill->count % 200 == 0)
		{
			_viTagSkill->count = 0;
			_alphaCount = 0;
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
			break;
		}
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
	}
}

void atahoTargetSkill1::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		//스킬 알파 렌더
		_viTagSkill->img->alphaFrameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
			_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(), _alphaColor);

		//char str[128];
		//sprintf_s(str, "%d, %d, %d", _viTagSkill->count, _viTagSkill->x, _viTagSkill->x);
		//TextOut(getMemDC(), 200, 200, str, strlen(str));
	}
}

void atahoTargetSkill1::addSkill(float x, float y)
{
	tagSkill targetSkill1;
	ZeroMemory(&targetSkill1, sizeof(tagSkill));
	//스킬 이미지
	targetSkill1.img = IMAGEMANAGER->findImage("TargetSkill1");
	targetSkill1.x = x;			// 스킬 x좌표
	targetSkill1.y = y;			// 스킬 y좌표
	targetSkill1.count = 0;		// 스킬 생성시 카운트 초기화
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
	IMAGEMANAGER->addFrameImage("TargetSkill2", "TargetSkill2.bmp", 128, 16, 8, 1, true, RGB(255, 0, 255));

	_alphaColor = 0;
	_alphaCount = 0;
	_currentExp = 0;
	_maxExp = 100;
	_level = 1;

	return S_OK;
}

void atahoTargetSkill2::realse()
{
}

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
