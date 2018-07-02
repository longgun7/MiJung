#include "stdafx.h"
#include "Skill.h"

atahoTargetSkill1::atahoTargetSkill1() {}

atahoTargetSkill1::~atahoTargetSkill1() {}

HRESULT atahoTargetSkill1::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill1", "TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

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
		//스킬 레벨 2 이상 부터
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
