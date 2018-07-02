#include "stdafx.h"
#include "Skill.h"

targetSkill1::targetSkill1(){}

targetSkill1::~targetSkill1(){}

HRESULT targetSkill1::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill1", "TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

	_alphaColor = 0;
	_alphaCount = 0;
	_currentExp = 0;
	_maxExp = 100;
	_level = 1;

	return S_OK;
}

void targetSkill1::realse()
{
}

void targetSkill1::update()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		// 스킬 2레벨 이상부터 시작
		if (_level > 1)
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
		//카운터가 300이 되면 스킬 사라짐
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

void targetSkill1::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		// 알파 프레임 랜더
		_viTagSkill->img->alphaFrameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
			_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(), _alphaColor);

	//	char str[128];
	//	sprintf_s(str, "%d, %d, %d", _viTagSkill->count, _viTagSkill->x, _viTagSkill->x);
	//	TextOut(getMemDC(), 200, 200, str, strlen(str));
	}
}

void targetSkill1::addSkill(float x, float y)
{
	tagSkill targetSkill1;
	ZeroMemory(&targetSkill1, sizeof(tagSkill));

	targetSkill1.img = IMAGEMANAGER->findImage("TargetSkill1");		// 호격권 불러
	targetSkill1.x = x;				// x 좌표
	targetSkill1.y = y;				// y 좌표
	targetSkill1.count = 0;			// 스킬 생성시 카운터 0 초기화
	_currentExp += 40;				// 스킬 생성시 경험치 40 증가

	// 현재 스킬 경험치가 최대치 보다 높으면 레벨업
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}

	// 각 레벨에 따라 알파 최대 카운터 변경
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
