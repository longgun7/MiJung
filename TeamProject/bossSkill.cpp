#include "stdafx.h"
#include "bossSkill.h"

BossSkill1::BossSkill1() {}

BossSkill1::~BossSkill1() {}

HRESULT BossSkill1::init()
{
	IMAGEMANAGER->addFrameImage("IceFragments", "IceFragments.bmp", 192, 32, 6, 1, true, RGB(255, 0, 255));
	EFFECTMANAGER->addEffect("Ice", "Ice.bmp", 144, 64, 48, 64, 10, 0.01f, 10);

	return S_OK;
}

void BossSkill1::realse() {}

void BossSkill1::update()
{
	moveSkill();
	atkSkill();
	EFFECTMANAGER->update();
}

void BossSkill1::render()
{
	for (_viTagBossSkill = _vTagBossSkill.begin(); _viTagBossSkill != _vTagBossSkill.end(); ++_viTagBossSkill)
	{
		_viTagBossSkill->img->frameRender(getMemDC(), _viTagBossSkill->rc.left, _viTagBossSkill->rc.top,
			_viTagBossSkill->img->getFrameX(), _viTagBossSkill->img->getFrameY());
	}
	EFFECTMANAGER->render();
}


void BossSkill1::addAreaSkill(float x, float y)
{
	_start = false;
	tagBossSkill bossSkill[10];
	for (int i = 0; i < 10; ++i)
	{
		ZeroMemory(&bossSkill[i], sizeof(tagBossSkill));
		bossSkill[i].img = new image;
		bossSkill[i].img = IMAGEMANAGER->findImage("IceFragments");

		bossSkill[i].img->setFrameX(0);

		bossSkill[i].fireX = bossSkill[i].x = x;
		bossSkill[i].fireY = bossSkill[i].y = y - 50;

		_randumAngle = RND->getFloat((PI / 3));
		bossSkill[i].angle = ((PI / 12) * 11) + _randumAngle;

		bossSkill[i].speed = 5.0f;

		bossSkill[i].count = 0;
		bossSkill[i].rc = RectMakeCenter(bossSkill[i].x, bossSkill[i].y, bossSkill[i].img->getFrameWidth(), bossSkill[i].img->getFrameHeight());

		_vTagBossSkill.push_back(bossSkill[i]);
	}
}

void BossSkill1::moveSkill()
{
	if (!_start)
	{
		for (_viTagBossSkill = _vTagBossSkill.begin(); _viTagBossSkill != _vTagBossSkill.end(); ++_viTagBossSkill)
		{
			_viTagBossSkill->y -= 3;
			_count++;
			if (_count % 50 == 0)
			{
				if (_viTagBossSkill->img->getMaxFrameX() <= _viTagBossSkill->img->getFrameX())
				{
					_viTagBossSkill->img->setFrameX(0);
				}
				else _viTagBossSkill->img->setFrameX(_viTagBossSkill->img->getFrameX() + 1);
			}

			if (150 < (_viTagBossSkill->fireY - _viTagBossSkill->y))
			{
				_viTagBossSkill->y = _viTagBossSkill->fireY - 150;
				_viTagBossSkill->img->setFrameX(3);
				_count = 0;
				_start = true;
			}

			_viTagBossSkill->rc = RectMakeCenter(_viTagBossSkill->x, _viTagBossSkill->y,
				_viTagBossSkill->img->getFrameWidth(), _viTagBossSkill->img->getFrameHeight());
		}
	}
}

void BossSkill1::atkSkill()
{
	if (_start)
	{
		for (_viTagBossSkill = _vTagBossSkill.begin(); _viTagBossSkill != _vTagBossSkill.end();)
		{
			_viTagBossSkill->x -= 7;
			_viTagBossSkill->y += -sinf(_viTagBossSkill->angle) * _viTagBossSkill->speed;

			_viTagBossSkill->rc = RectMakeCenter(_viTagBossSkill->x, _viTagBossSkill->y,
				_viTagBossSkill->img->getFrameWidth(), _viTagBossSkill->img->getFrameHeight());

			if (700.0f < getDistance(_viTagBossSkill->fireX, _viTagBossSkill->fireY, _viTagBossSkill->x, _viTagBossSkill->y))
			{
				_x = _viTagBossSkill->x;
				_y = _viTagBossSkill->y;
				EFFECTMANAGER->play("Ice", _x, _y);
				_viTagBossSkill = _vTagBossSkill.erase(_viTagBossSkill);
			}
			else
			{
				++_viTagBossSkill;
			}
		}
	}
}
