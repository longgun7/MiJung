#include "stdafx.h"
#include "Skill.h"

Skill::Skill(){}

Skill::~Skill(){}

HRESULT Skill::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill1", "TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

	return S_OK;
}

void Skill::realse()
{
}

void Skill::update()
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

		if (_viTagSkill->count % 300 == 0)
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

void Skill::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->img->alphaFrameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
			_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(), _alphaColor);
	}

}

void Skill::addSkill(float x, float y)
{
	tagSkill targetSkill1;
	ZeroMemory(&targetSkill1, sizeof(tagSkill));

	targetSkill1.img = IMAGEMANAGER->findImage("TargetSkill1");
	targetSkill1.x = x;
	targetSkill1.y = y;
	targetSkill1.count = 0;
	targetSkill1.currentExp += 40;
	targetSkill1.maxExp = 100;

	if (targetSkill1.currentExp >= targetSkill1.maxExp)
	{
		targetSkill1.currentExp = 0;
		targetSkill1.level++;
		if (targetSkill1.level > 4)
		{
			targetSkill1.level = 4;
		}
	}

	if (targetSkill1.level == 1)
	{
		_alphaMaxCount = 2;
	}
	else if (targetSkill1.level == 2)
	{
		_alphaMaxCount = 2;
	}
	else if (targetSkill1.level == 3)
	{
		_alphaMaxCount = 2;
	}
	else if (targetSkill1.level == 4)
	{
		_alphaMaxCount = 2;
	}
	targetSkill1.rc = RectMakeCenter(targetSkill1.x, targetSkill1.y, targetSkill1.img->getFrameWidth(), targetSkill1.img->getFrameHeight());

	_vTagSkill.push_back(targetSkill1);
}
