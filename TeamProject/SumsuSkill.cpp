#include "stdafx.h"
#include "SumsuSkill.h"


sumsuCut::sumsuCut() {}

sumsuCut::~sumsuCut() {}

HRESULT sumsuCut::init()
{
	// 이펙트 매니저 스마슈 베기 플레이
	EFFECTMANAGER->addEffect("SumsuCutDown", "image/effect/SumsuCutDown.bmp", 192, 48, 64, 48, 1.0f, 0.15f, 1);
	return S_OK;
}

void sumsuCut::realse() {}

void sumsuCut::update()
{
	EFFECTMANAGER->update();
}

void sumsuCut::render()
{
	EFFECTMANAGER->render();
}

void sumsuCut::addFireSkill(float x, float y)
{
	// 스마슈 베기 이미지 플레이
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}

sumsuTargetSkill2::sumsuTargetSkill2() {}

sumsuTargetSkill2::~sumsuTargetSkill2() {}

HRESULT sumsuTargetSkill2::init()
{
	// 스킬 카운트 초기화
	_count = 0;
	// 스킬 이미지 이펙트 생성 및 시간
	EFFECTMANAGER->addEffect("SumsuTargetSkill21", "image/effect/SumsuTargetSkill21.bmp", 240, 64, 80, 64, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("SumsuTargetSkill22", "image/effect/SumsuTargetSkill22.bmp", 192, 64, 64, 64, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("CutEffect", "image/effect/CutEffect.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);

	return S_OK;
}

void sumsuTargetSkill2::realse() {}

void sumsuTargetSkill2::update()
{
	EFFECTMANAGER->update();
}

void sumsuTargetSkill2::render()
{
	EFFECTMANAGER->render();
}

void sumsuTargetSkill2::addFireSkill(float x, float y)
{
	// 카운트 증가
	_count++;
	// 카운트 1과 6일때 실행
	if (_count == 1 || _count == 6)
	{
		EFFECTMANAGER->play("SumsuTargetSkill21", x, y);
	}
	// 카운트 20일 때 마무리 베기 실행
	if (_count == 20)
	{
		EFFECTMANAGER->play("SumsuTargetSkill22", x, y);
		EFFECTMANAGER->play("CutEffect", x + 25, y - 25);
	}
}
sumsuTargetSkill3::sumsuTargetSkill3() {}

sumsuTargetSkill3::~sumsuTargetSkill3() {}

HRESULT sumsuTargetSkill3::init()
{
	EFFECTMANAGER->addEffect("SumsuCutDown", "image/effect/SumsuCutDown.bmp", 192, 48, 64, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("SumsuCutUp", "image/effect/SumsuCutUp.bmp", 192, 48, 64, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("SumsuTargetSkill22", "image/effect/SumsuTargetSkill22.bmp", 192, 64, 64, 64, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("CutEffect", "image/effect/CutEffect.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	IMAGEMANAGER->addImage("BigCut", "image/effect/BigCut.bmp", 48, 64, true, RGB(255, 0, 255), true);
	return S_OK;
}

void sumsuTargetSkill3::realse() {}

void sumsuTargetSkill3::update()
{
	EFFECTMANAGER->update();
	moveSkill();
}

void sumsuTargetSkill3::render()
{
	EFFECTMANAGER->render();
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->img->alphaRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top, _alphaColor);
	}
}

void sumsuTargetSkill3::cutUpSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutUp", x, y);
}

void sumsuTargetSkill3::cutDownSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}

void sumsuTargetSkill3::cutDiagonalSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuTargetSkill22", x, y);
	EFFECTMANAGER->play("CutEffect", x + 25, y - 25);
}

void sumsuTargetSkill3::cutBigSkill(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	targetSkill.img = IMAGEMANAGER->findImage("BigCut");
	targetSkill.fireX = targetSkill.x = x;
	targetSkill.fireY = targetSkill.y = y;
	_range = 100.0f;
	_alphaColor = 255;
	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getWidth(), targetSkill.img->getHeight());

	_vTagSkill.push_back(targetSkill);
}

void sumsuTargetSkill3::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		_viTagSkill->x += 2;
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y, _viTagSkill->img->getWidth(), _viTagSkill->img->getHeight());

		if (getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY) > 28)
		{
			_alphaColor -= 5;
		}

		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
		}
		else
		{
			++_viTagSkill;
		}
	}
}

sumsuAreaSkill1::sumsuAreaSkill1() {}

sumsuAreaSkill1::~sumsuAreaSkill1() {}

HRESULT sumsuAreaSkill1::init()
{
	IMAGEMANAGER->addFrameImage("SumsuAreaSkill1", "image/effect/SumsuAreaSkill1.bmp", 4, 2, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SumsuTargetSkill21", "image/effect/SumsuTargetSkill21.bmp", 240, 64, 3, 1, true, RGB(255, 0, 255));

	_currentExp = 0;
	_maxExp = 100;
	_level = 1;
	return S_OK;
}

void sumsuAreaSkill1::realse() {}

void sumsuAreaSkill1::update()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		if (_level == 1)
		{
			if (_viTagSkill->count < 10)
			{
				_viTagSkill->_width += 20;
			}
			else if (_viTagSkill->count > 20 && _viTagSkill->count < 41)
			{
				_viTagSkill->rc.left += 10;
				_viTagSkill->_width -= 10;
			}
		}
		if (_level == 2)
		{
			if (_viTagSkill->count < 10)
			{
				_viTagSkill->_width += 40;
			}

			if (_viTagSkill->count > 20 && _viTagSkill->count < 41)
			{
				_viTagSkill->rc.left += 20;
				_viTagSkill->_width -= 20;
			}
		}
		if (_level == 3)
		{
			if (_viTagSkill->count < 10)
			{
				_viTagSkill->_width += 57;
			}

			if (_viTagSkill->count > 20 && _viTagSkill->count < 41)
			{
				_viTagSkill->rc.left += 28;
				_viTagSkill->_width -= 28;
			}
		}
		if (_level == 4)
		{
			if (_viTagSkill->count < 10)
			{
				_viTagSkill->_width += 74;
			}

			if (_viTagSkill->count > 20 && _viTagSkill->count < 41)
			{
				_viTagSkill->rc.left += 37;
				_viTagSkill->_width -= 37;
			}
		}
		if (_viTagSkill->count >= 42)
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
			break;
		}
	}
}

void sumsuAreaSkill1::render()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
			_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY(),
			_viTagSkill->_width, _viTagSkill->img->getFrameHeight());
	}
}


void sumsuAreaSkill1::addAreaSkill(float x, float y, int monsterNum)
{
	tagSkill areaSkill[4];
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
	for (int i = 0; i < monsterNum; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSkill));
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill1");
		if (_level == 1)
		{
			if (monsterNum == 4)
			{
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 100;
				}
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 150;
				}
			}
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 100 + i * 50;
			}
		}
		else if (_level == 2)
		{
			if (monsterNum == 4)
			{
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 200;
				}
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 250;
				}
			}
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 200 + i * 50;
			}
		}
		else if (_level == 3)
		{
			if (monsterNum == 4)
			{
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 350;
				}
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 400;
				}
			}
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 350 + i * 50;
			}
		}
		else if (_level == 4)
		{
			if (monsterNum == 4)
			{
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 500;
				}
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 550;
				}
			}
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 500 + i * 50;
			}
		}
		areaSkill[i].fireY = areaSkill[i].y = y * (i + 1);

		_range = 50.0f;
		areaSkill[i]._width = 10;

		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSkill.push_back(areaSkill[i]);
	}
}