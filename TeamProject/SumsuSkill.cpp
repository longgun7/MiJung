#include "stdafx.h"
#include "SumsuSkill.h"

//======= ������ ���� �̹��� ========
sumsuCut::sumsuCut() {}

sumsuCut::~sumsuCut() {}

HRESULT sumsuCut::init()
{
	// ����Ʈ �Ŵ��� ������ ���� �÷���
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
// ��ų ���� x(�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuCut::addFireSkill(float x, float y)
{
	// ������ ���� �̹��� �÷���
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}

//======= ������ ���� ��ų 2�� : ������ ========
sumsuTargetSkill2::sumsuTargetSkill2() {}

sumsuTargetSkill2::~sumsuTargetSkill2() {}

HRESULT sumsuTargetSkill2::init()
{
	// ��ų ī��Ʈ �ʱ�ȭ
	_count = 0;
	// ��ų �̹��� ����Ʈ ���� �� �ð�
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
// ��ų ���� x(�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuTargetSkill2::addFireSkill(float x, float y)
{
	// ī��Ʈ ����
	_count++;
	// ī��Ʈ 1�� 6�϶� ����
	if (_count == 1 || _count == 6)
	{
		EFFECTMANAGER->play("SumsuTargetSkill21", x, y);
	}
	// ī��Ʈ 20�� �� ������ ���� ����
	if (_count == 20)
	{
		EFFECTMANAGER->play("SumsuTargetSkill22", x, y);
		EFFECTMANAGER->play("CutEffect", x + 25, y - 25);
	}
}

//======= ������ ���� ��ų 3�� : ������ ========
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
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end(); ++_viTagSumsuSkill)
	{
		_viTagSumsuSkill->img->alphaRender(getMemDC(), _viTagSumsuSkill->rc.left, _viTagSumsuSkill->rc.top, _alphaColor);
	}
}
// �� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuTargetSkill3::cutUpSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutUp", x, y);
}
// �Ʒ� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuTargetSkill3::cutDownSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}
// �밢�� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuTargetSkill3::cutDiagonalSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuTargetSkill22", x, y);
	EFFECTMANAGER->play("CutEffect", x + 25, y - 25);
}
// ������ ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
void sumsuTargetSkill3::cutBigSkill(float x, float y)
{
	tagSumsuSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSumsuSkill));
	targetSkill.img = IMAGEMANAGER->findImage("BigCut");
	targetSkill.fireX = targetSkill.x = x;
	targetSkill.fireY = targetSkill.y = y;
	_range = 100.0f;
	_alphaColor = 255;
	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getWidth(), targetSkill.img->getHeight());

	_vTagSumsuSkill.push_back(targetSkill);
}

void sumsuTargetSkill3::moveSkill()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end();)
	{
		_viTagSumsuSkill->x += 2;
		_viTagSumsuSkill->rc = RectMakeCenter(_viTagSumsuSkill->x, _viTagSumsuSkill->y, _viTagSumsuSkill->img->getWidth(), _viTagSumsuSkill->img->getHeight());

		if (getDistance(_viTagSumsuSkill->x, _viTagSumsuSkill->y, _viTagSumsuSkill->fireX, _viTagSumsuSkill->fireY) > 28)
		{
			_alphaColor -= 5;
		}

		if (_range < getDistance(_viTagSumsuSkill->x, _viTagSumsuSkill->y, _viTagSumsuSkill->fireX, _viTagSumsuSkill->fireY))
		{
			_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
		}
		else
		{
			++_viTagSumsuSkill;
		}
	}
}

//======= ������ ��ü ��ų 1�� : �����ϼ� ========
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
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end(); ++_viTagSumsuSkill)
	{
		_viTagSumsuSkill->count++;
		if (_level == 1)
		{
			if (_viTagSumsuSkill->count < 10)
			{
				// 10 ī��Ʈ ������ �Ź����� 20�� ����
				_viTagSumsuSkill->width += 20;
			}
			// 20 �ʰ� 41 �̸��� �� ũ�Ⱑ �پ���� (���������� �پ����)
			else if (_viTagSumsuSkill->count > 20 && _viTagSumsuSkill->count < 41)
			{
				_viTagSumsuSkill->rc.left += 10;
				_viTagSumsuSkill->width -= 10;
			}
		}
		if (_level == 2)
		{
			if (_viTagSumsuSkill->count < 10)
			{
				_viTagSumsuSkill->width += 40;
			}

			if (_viTagSumsuSkill->count > 20 && _viTagSumsuSkill->count < 41)
			{
				_viTagSumsuSkill->rc.left += 20;
				_viTagSumsuSkill->width -= 20;
			}
		}
		if (_level == 3)
		{
			if (_viTagSumsuSkill->count < 10)
			{
				_viTagSumsuSkill->width += 57;
			}

			if (_viTagSumsuSkill->count > 20 && _viTagSumsuSkill->count < 41)
			{
				_viTagSumsuSkill->rc.left += 28;
				_viTagSumsuSkill->width -= 28;
			}
		}
		if (_level == 4)
		{
			if (_viTagSumsuSkill->count < 10)
			{
				_viTagSumsuSkill->width += 74;
			}

			if (_viTagSumsuSkill->count > 20 && _viTagSumsuSkill->count < 41)
			{
				_viTagSumsuSkill->rc.left += 37;
				_viTagSumsuSkill->width -= 37;
			}
		}
		// ī��Ʈ�� 42 �̻��̸� ������
		if (_viTagSumsuSkill->count >= 42)
		{
			_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			break;
		}
	}
}

void sumsuAreaSkill1::render()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end(); ++_viTagSumsuSkill)
	{
		_viTagSumsuSkill->img->frameRender(getMemDC(), _viTagSumsuSkill->rc.left, _viTagSumsuSkill->rc.top,
			_viTagSumsuSkill->img->getFrameX(), _viTagSumsuSkill->img->getFrameY(),
			_viTagSumsuSkill->width, _viTagSumsuSkill->img->getFrameHeight());
	}
}
// ��ų ���� (���� �� ���� ���� ���� ����) x(ù��° ���� x��ǥ), y(ù��° ���� y��ǥ), ��Ÿ�� ���� ��
void sumsuAreaSkill1::addAreaSkill(float x, float y, int monsterNum)
{
	tagSumsuSkill areaSkill[4];
	_currentExp += 99;									// ��ų ����ġ 40 ����

	// ��ų ���� ����ġ�� �ִ� ����ġ ���� Ŀ���ų� �������� ��ų ������
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
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill1");
		// 1���� �϶�
		if (_level == 1)
		{
			// ���� �� 4���� �϶�
			if (monsterNum == 4)
			{
				// 0���� 3�� ����
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 100;
				}
				// 1���� 2�� ����
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 150;
				}
			}
			// ���Ͱ� 4������ �ƴ� ������ ���
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 100 + i * 50;
			}
		}
		// 2���� �϶�
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
		// 3���� �϶�
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
		// 4���� �϶�
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
		// �ִ� �Ÿ� ����
		_range = 50.0f;
		// ó�� ���� ũ��
		areaSkill[i].width = 10;

		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

//======= ������ ��ü ��ų 2�� : �нż� ========
sumsuAreaSkill2::sumsuAreaSkill2(){}

sumsuAreaSkill2::~sumsuAreaSkill2(){}

HRESULT sumsuAreaSkill2::init()
{
	IMAGEMANAGER->addFrameImage("SumsuAreaSkill2", "image/effect/SumsuAreaSkill2.bmp", 480, 85, 6, 1, true, RGB(255, 0, 255), true);

	_currentExp = 0;
	_maxExp = 100;
	_alphaColor = 150;
	_level = 1;

	return S_OK;
}

void sumsuAreaSkill2::realse() {}

void sumsuAreaSkill2::update()
{
	moveSkill();
}

void sumsuAreaSkill2::render()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end(); ++_viTagSumsuSkill)
	{
		_viTagSumsuSkill->img->alphaFrameRender(getMemDC(), _viTagSumsuSkill->rc.left, _viTagSumsuSkill->rc.top,
			_viTagSumsuSkill->currentFrameX, _viTagSumsuSkill->img->getFrameY(), _alphaColor);
	}
}

// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ)
void sumsuAreaSkill2::addAreaSkill(float x, float y)
{
	_currentExp += 99;				// ��ų ����ġ 40 ����

									// ��ų ���� ����ġ�� �ִ� ����ġ ���� Ŀ���ų� �������� ��ų ������
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}
	if (_level == 1)
	{
		// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ) -> ������ �Ű������� ���� �ڵ� ó��
		addAreaSkill1(x, y);
	}
	else if (_level == 2)
	{
		// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ) -> ������ �Ű������� ���� �ڵ� ó��
		addAreaSkill2(x, y);
	}
	else if (_level == 3)
	{
		// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ) -> ������ �Ű������� ���� �ڵ� ó��
		addAreaSkill3(x, y);
	}
	else if (_level == 4)
	{
		// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ) -> ������ �Ű������� ���� �ڵ� ó��
		addAreaSkill4(x, y);
	}
}

void sumsuAreaSkill2::addAreaSkill1(float x, float y)
{
	tagSumsuSkill areaSkill[2];
	for (int i = 0; i < 2; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill2");

		areaSkill[i].img->setFrameX(0);

		areaSkill[i].fireX = areaSkill[i].x = x;
		areaSkill[i].fireY = areaSkill[i].y = y;
		// 0��° �н� ���� = 180 * 0
		// 1��° �н� ���� = 180 * 1
		areaSkill[i].angle = PI * i;

		areaSkill[i].speed = 2.0f;
		_alphaColor = 150;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

void sumsuAreaSkill2::addAreaSkill2(float x, float y)
{
	tagSumsuSkill areaSkill[4];
	for (int i = 0; i < 4; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill2");
		areaSkill[i].img->setFrameX(0);

		areaSkill[i].fireX = areaSkill[i].x = x;
		areaSkill[i].fireY = areaSkill[i].y = y;
		// 0��° �н� ���� = (180/2) * 0
		// 1��° �н� ���� = (180/2) * 1
		// 2��° �н� ���� = (180/2) * 2
		// 3��° �н� ���� = (180/2) * 3
		areaSkill[i].angle = PI4 * i;

		areaSkill[i].speed = 2.5f;
		_alphaColor = 150;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

void sumsuAreaSkill2::addAreaSkill3(float x, float y)
{
	tagSumsuSkill areaSkill[6];
	for (int i = 0; i < 6; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill2");
		areaSkill[i].img->setFrameX(0);

		areaSkill[i].fireX = areaSkill[i].x = x;
		areaSkill[i].fireY = areaSkill[i].y = y;
		// 0��° �н� ���� = (180/3) * 0
		// 1��° �н� ���� = (180/3) * 1
		// 2��° �н� ���� = (180/3) * 2
		// 3��° �н� ���� = (180/3) * 3
		// 4��° �н� ���� = (180/3) * 4
		// 5��° �н� ���� = (180/3) * 5
		areaSkill[i].angle = PI6 * i;

		areaSkill[i].speed = 3.0f;
		_alphaColor = 150;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

void sumsuAreaSkill2::addAreaSkill4(float x, float y)
{
	tagSumsuSkill areaSkill[10];
	for (int i = 0; i < 10; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill2");
		areaSkill[i].img->setFrameX(0);

		areaSkill[i].fireX = areaSkill[i].x = x;
		areaSkill[i].fireY = areaSkill[i].y = y;
		// 0��° �н� ���� = (180/5) * 0
		// 1��° �н� ���� = (180/5) * 1
		// 2��° �н� ���� = (180/5) * 2
		// 3��° �н� ���� = (180/5) * 3
		// 4��° �н� ���� = (180/5) * 4
		// 5��° �н� ���� = (180/5) * 5
		// 6��° �н� ���� = (180/5) * 6
		// 7��° �н� ���� = (180/5) * 7
		// 8��° �н� ���� = (180/5) * 8
		// 9��° �н� ���� = (180/5) * 9
		areaSkill[i].angle = PI10 * i;

		areaSkill[i].speed = 4.0f;
		_alphaColor = 150;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

void sumsuAreaSkill2::moveSkill()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end();)
	{
		_viTagSumsuSkill->count++;
		// 1 ���� �϶�
		if (_level == 1)
		{
			// ī��Ʈ�� 60�̸� �϶�
			if (_viTagSumsuSkill->count < 60)
			{
				// ���� ���� �����ִ� ī��Ʈ
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 60)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// �Ź� ���� �� ����
				_viTagSumsuSkill->angle += 0.05f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// ī��Ʈ 60�̻� 90���� �϶� ������ ������ �ִ� ����
			// ī��Ʈ�� 90�ʰ� �϶� 
			else if (_viTagSumsuSkill->count > 90)
			{
				// ���ǵ� ���� �ٽ� ����
				_viTagSumsuSkill->speed = 8.0f;
				// ���� �� ����
				_alphaColor = 150;
				// ���� �����Ӽ� ī���Ϳ� ���� ����
				if (_viTagSumsuSkill->count % 91 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 3);
				}
				// �нż��� ȭ���� �������� �ϸ� ƨ�⵵��
				if (_viTagSumsuSkill->x < 50 || _viTagSumsuSkill->x > WINSIZEX-50)
				{
					_viTagSumsuSkill->angle = PI - _viTagSumsuSkill->angle;
				}
				if (_viTagSumsuSkill->y < 75 || _viTagSumsuSkill->y > 450)
				{
					_viTagSumsuSkill->angle = PI2 - _viTagSumsuSkill->angle;
				}
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
		}
		// 2 ���� �϶�
		else if (_level == 2)
		{
			// ī��Ʈ 115 �̸� �϶�
			if (_viTagSumsuSkill->count < 115)
			{
				// ���� ���� �����ִ� ī��Ʈ
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 115)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// �Ź� ���� �� ����
				_viTagSumsuSkill->angle += 0.04f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// ī��Ʈ 115�̻� 143���� �϶� ������ ������ �ִ� ����
			// ī��Ʈ�� 143�ʰ� �϶� 
			else if (_viTagSumsuSkill->count > 143)
			{				
				// ���ǵ� ���� �ٽ� ����
				_viTagSumsuSkill->speed = 8.0f;
				// ���� �� ����
				_alphaColor = 150;
				// ���� �����Ӽ� ī���Ϳ� ���� ����
				if (_viTagSumsuSkill->count % 36 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 4);
				}
				// �нż��� ȭ���� �������� �ϸ� ƨ�⵵��
				if (_viTagSumsuSkill->x < 50 || _viTagSumsuSkill->x > WINSIZEX - 50)
				{
					_viTagSumsuSkill->angle = PI - _viTagSumsuSkill->angle;
				}
				if (_viTagSumsuSkill->y < 75 || _viTagSumsuSkill->y > 450)
				{
					_viTagSumsuSkill->angle = PI2 - _viTagSumsuSkill->angle;
				}
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
		}
		// 3 ���� �϶�
		else if (_level == 3)
		{
			// ī��Ʈ�� 105 �̸� �϶�
			if (_viTagSumsuSkill->count < 105)
			{
				// ���� ���� �����ִ� ī��Ʈ
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 100)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// �Ź� ���� �� ����
				_viTagSumsuSkill->angle += 0.04f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// ī��Ʈ 105�̻� 131���� �϶� ������ ������ �ִ� ����
			// ī��Ʈ�� 132�ʰ� �϶� 
			else if (_viTagSumsuSkill->count > 131)
			{
				// ���ǵ� ���� �ٽ� ����
				_viTagSumsuSkill->speed = 8.0f;
				// ���� �� ����
				_alphaColor = 150;
				// ���� �����Ӽ� ī���Ϳ� ���� ����
				if (_viTagSumsuSkill->count % 66 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 5);
				}
				// �нż��� ȭ���� �������� �ϸ� ƨ�⵵��
				if (_viTagSumsuSkill->x < 50 || _viTagSumsuSkill->x > WINSIZEX - 50)
				{
					_viTagSumsuSkill->angle = PI - _viTagSumsuSkill->angle;
				}
				if (_viTagSumsuSkill->y < 75 || _viTagSumsuSkill->y > 450)
				{
					_viTagSumsuSkill->angle = PI2 - _viTagSumsuSkill->angle;
				}
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
		}
		// 4 ���� �϶�
		else if (_level == 4)
		{
			// ī��Ʈ�� 50�̸� �϶�
			if (_viTagSumsuSkill->count < 50)
			{
				// ���� ���� �����ִ� ī��Ʈ
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 45)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// �Ź� ���� �� ����
				_viTagSumsuSkill->angle += 0.07f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// ī��Ʈ 50�̻� 75���� �϶� ������ ������ �ִ� ����
			// ī��Ʈ�� 75�ʰ� �϶�
			else if (_viTagSumsuSkill->count > 75)
			{
				// ���ǵ� ���� �ٽ� ����
				_viTagSumsuSkill->speed = 9.0f;
				// ���� �� ����
				_alphaColor = 150;
				// ���� �����Ӽ� ī���Ϳ� ���� ����
				if (_viTagSumsuSkill->count % 76 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 6);
				}
				// �нż��� ȭ���� �������� �ϸ� ƨ�⵵��
				if (_viTagSumsuSkill->x < 50 || _viTagSumsuSkill->x > WINSIZEX - 50)
				{
					_viTagSumsuSkill->angle = PI - _viTagSumsuSkill->angle;
				}
				if (_viTagSumsuSkill->y < 75 || _viTagSumsuSkill->y > 450)
				{
					_viTagSumsuSkill->angle = PI2 - _viTagSumsuSkill->angle;
				}
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
		}

		_viTagSumsuSkill->rc = RectMakeCenter(_viTagSumsuSkill->x, _viTagSumsuSkill->y,
			_viTagSumsuSkill->img->getFrameWidth(), _viTagSumsuSkill->img->getFrameHeight());
		// 1 ���� �϶�
		if (_level == 1)
		{
			// ī��Ʈ �Ѿ��
			if (_viTagSumsuSkill->count > 350)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 2 ���� �϶�
		else if (_level == 2)
		{
			// ī��Ʈ �Ѿ��
			if (_viTagSumsuSkill->count > 450)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 3 ���� �϶�
		else if (_level == 3)
		{
			// ī��Ʈ �Ѿ��
			if (_viTagSumsuSkill->count > 550)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 4 ���� �϶�
		else if (_level == 4)
		{
			// ī��Ʈ �Ѿ��
			if (_viTagSumsuSkill->count > 650)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
	}
}

sumsuAreaSkill3::sumsuAreaSkill3() {}

sumsuAreaSkill3::~sumsuAreaSkill3() {}

HRESULT sumsuAreaSkill3::init()
{
	IMAGEMANAGER->addFrameImage("DragonScales", "image/effect/DragonScales.bmp", 96, 48, 3, 1, true, RGB(255, 0, 255));

	_img[0] = IMAGEMANAGER->addFrameImage("DragonHead1", "image/effect/DragonHead.bmp", 1440, 160, 9, 1, true, RGB(255, 0, 255));
	_img[1] = IMAGEMANAGER->addFrameImage("DragonHead2", "image/effect/DragonHead.bmp", 1440, 160, 9, 1, true, RGB(255, 0, 255));

	_currentExp = 0;
	_maxExp = 100;
	_level = 1;

	return S_OK;
}

void sumsuAreaSkill3::realse() {}

void sumsuAreaSkill3::update()
{
	moveSkill();
}

void sumsuAreaSkill3::render()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end(); ++_viTagSumsuSkill)
	{
		_viTagSumsuSkill->img->frameRender(getMemDC(), _viTagSumsuSkill->rc.left, _viTagSumsuSkill->rc.top,
			_viTagSumsuSkill->img->getFrameX(), _viTagSumsuSkill->img->getFrameY());
		if (_level >= 3)
		{
			_img[0]->frameRender(getMemDC(), _img[0]->getX(), _img[0]->getY(), _currentFrameX1, _img[0]->getFrameY());
			_img[1]->frameRender(getMemDC(), _img[1]->getX(), _img[1]->getY(), _currentFrameX2, _img[1]->getFrameY());
		}
	}
}

// ������ x(���� ��ǥ), y(���� ��ǥ)
void sumsuAreaSkill3::addAreaSkill(float x, float y)
{
	_expCount++;
	if (_expCount == 1)
	{
		_currentExp += 99;				// ��ų ����ġ 40 ����
	}
	// ��ų ���� ����ġ�� �ִ� ����ġ ���� Ŀ���ų� �������� ��ų ������
	if (_currentExp >= _maxExp)
	{
		_currentExp = 0;
		_level++;
		if (_level > 4)
		{
			_level = 4;
		}
	}
	_range = 550.0f;

	if (_level == 1)
	{
		addAreaSkill1(x, y);
	}
	else if (_level == 2)
	{
		addAreaSkill2(x, y);
	}
	else if (_level == 3)
	{
		addAreaSkill3(x, y);
	}
	else if (_level == 4)
	{
		addAreaSkill4(x, y);
	}
}
// ������ x(���� ��ǥ), y(���� ��ǥ)
void sumsuAreaSkill3::addAreaSkill1(float x, float y)
{
	tagSumsuSkill areaSkill[2];
	for (int i = 0; i < 2; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("DragonScales");
		// ���� �� ������ x ��ȣ
		areaSkill[i].img->setFrameX(0);

		// ����� ��� ��ġ�� ������ġ
		areaSkill[i].fireX = areaSkill[i].x = x + 200 - i * 400;
		areaSkill[i].fireY = areaSkill[i].y = y + 100;

		// ����� ����
		areaSkill[i].angle = PI / 2;
		areaSkill[i].angle1 = PI / 2;

		// ����� ���ǵ�
		areaSkill[i].speed = 0.5f;
		areaSkill[i].speedx = 25.0f;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}
// ������ x(���� ��ǥ), y(���� ��ǥ)
void sumsuAreaSkill3::addAreaSkill2(float x, float y)
{
	tagSumsuSkill areaSkill[6];
	for (int i = 0; i < 6; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("DragonScales");
		// ���� �� ������ x ��ȣ
		areaSkill[i].img->setFrameX(0);
		
		// ����� ��� ��ġ�� ������ġ
		// ������
		if (i % 2 == 0)
		{
			areaSkill[i].fireX = areaSkill[i].x = x + 200 + (i / 2) * 12;
		}
		// ����
		else if (i % 2 == 1)
		{
			areaSkill[i].fireX = areaSkill[i].x = x - 200 - (i / 2) * 12;
		}
		areaSkill[i].fireY = areaSkill[i].y = y + 100;
		
		// ����� ����
		areaSkill[i].angle = PI / 2;
		areaSkill[i].angle1 = PI / 2;
		
		// ����� ���ǵ�
		areaSkill[i].speed = 0.5f;
		areaSkill[i].speedx = 25.0f;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}
// ������ x(���� ��ǥ), y(���� ��ǥ)
void sumsuAreaSkill3::addAreaSkill3(float x, float y)
{
	tagSumsuSkill areaSkill[6];
	for (int i = 0; i < 6; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("DragonScales");
		// ���� �� ������ x ��ȣ
		areaSkill[i].img->setFrameX(1);
		// ����� ��� ��ġ�� ������ġ
		// ������
		if (i % 2 == 0)
		{
			areaSkill[i].fireX = areaSkill[i].x = x + 200 + (i / 2) * 16;
		}
		// ����
		else if (i % 2 == 1)
		{
			areaSkill[i].fireX = areaSkill[i].x = x - 200 - (i / 2) * 16;
		}
		areaSkill[i].fireY = areaSkill[i].y = y + 100;
		// ����� ����
		areaSkill[i].angle = PI / 2;
		areaSkill[i].angle1 = PI / 2;
		// ����� ���ǵ�
		areaSkill[i].speed = 0.5f;
		areaSkill[i].speedx = 25.0f;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
	//�� �Ӹ� ������ x ��ȣ
	_currentFrameX1 = 8;			// ������
	_currentFrameX2 = 0;			// ����
}
// ������ x(���� ��ǥ), y(���� ��ǥ)
void sumsuAreaSkill3::addAreaSkill4(float x, float y)
{
	tagSumsuSkill areaSkill[8];
	for (int i = 0; i < 8; ++i)
	{
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = new image;
		areaSkill[i].img = IMAGEMANAGER->findImage("DragonScales");
		// ���� �� ������ x ��ȣ
		areaSkill[i].img->setFrameX(2);
		// ����� ��� ��ġ�� ������ġ
		// ������
		if (i % 2 == 0)
		{
			areaSkill[i].fireX = areaSkill[i].x = x + 200 + (i / 2) * 25;
		}
		// ����
		else if (i % 2 == 1)
		{
			areaSkill[i].fireX = areaSkill[i].x = x - 200 - (i / 2) * 25;
		}
		areaSkill[i].fireY = areaSkill[i].y = y + 100;
		// ����� ����
		areaSkill[i].angle = PI / 2;
		areaSkill[i].angle1 = PI / 2;
		// ����� ���ǵ�
		areaSkill[i].speed = 0.5f;
		areaSkill[i].speedx = 25.0f;
		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
	//�� �Ӹ� ������ x ��ȣ
	_currentFrameX1 = 8;				// ������
	_currentFrameX2 = 0;				// ����
}
// ��ų ������
void sumsuAreaSkill3::moveSkill()
{
	for (_viTagSumsuSkill = _vTagSumsuSkill.begin(); _viTagSumsuSkill != _vTagSumsuSkill.end();)
	{
		// ���� ī���� ����
		_viTagSumsuSkill->count++;
		// �Ź� ī���� ����
		_count++;

		// y ����
		_viTagSumsuSkill->angle -= 0.12f;
		// x ���ǵ�
		_viTagSumsuSkill->speedx -= 0.05f;
		// x ���� �� ���� ���° ȸ������
		if (_viTagSumsuSkill->angle1 <= -(PI2 - (PI / 2)) && _count % 2 == 0)
		{
			_viTagSumsuSkill->number++;
			if (_viTagSumsuSkill->number > 1)
			{
				_currentFrameX1 = 0;
				_viTagSumsuSkill->angle1 = (PI / 2);
			}
		}
		if (_viTagSumsuSkill->angle1 >= (PI2 + (PI / 2)) && _count % 2 == 1)
		{
			_viTagSumsuSkill->number++;
			if (_viTagSumsuSkill->number > 1)
			{
				_currentFrameX2 = 8;
				_viTagSumsuSkill->angle1 = PI / 2;
			}
		}
		// x ��ǥ ����
		_viTagSumsuSkill->angle1 += 0.12f * ((_count % 2 == 0) ? -1 : 1);

		_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle1) * _viTagSumsuSkill->speedx;
		_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
		// 3���� ������ �� ������ ��õ
		if (_level < 4)
		{
			_viTagSumsuSkill->y -= 3.0f;
		}
		// 4������ ������ ��õ
		else
		{
			_viTagSumsuSkill->y -= 6.0f;
		}

		_viTagSumsuSkill->rc = RectMakeCenter(_viTagSumsuSkill->x, _viTagSumsuSkill->y,
			_viTagSumsuSkill->img->getFrameWidth(), _viTagSumsuSkill->img->getFrameHeight());
		//���� �Ÿ� �Ѿ�� �������� �׸��� ����ġ ī��Ʈ �ʱ�ȭ
		if (_range < getDistance(_viTagSumsuSkill->x, _viTagSumsuSkill->y, _viTagSumsuSkill->fireX, _viTagSumsuSkill->fireY))
		{
			_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			_expCount = 0;
		}
		else
		{
			++_viTagSumsuSkill;
		}
	}
	// ���Ͱ� �����Ѵٸ�
	if (_vTagSumsuSkill.size())
	{
		// ���� 3�̸� �� �Ӹ��� ��ǥ
		if (_level == 3)
		{
			_img[0]->setCenter(_vTagSumsuSkill[2].x, _vTagSumsuSkill[2].y - 30);
			_img[1]->setCenter(_vTagSumsuSkill[5].x, _vTagSumsuSkill[3].y - 40);
		}
		// ���� 4�̸� �� �Ӹ��� ��ǥ
		else if (_level == 4)
		{
			_img[0]->setCenter(_vTagSumsuSkill[2].x, _vTagSumsuSkill[2].y - 55);
			_img[1]->setCenter(_vTagSumsuSkill[5].x, _vTagSumsuSkill[2].y - 65);
		}
		// 0���� ���� ���ǵ�� �� �Ӹ��� ������ ��ȣ ����
		if (_vTagSumsuSkill[0].angle < 0)
		{
			_vTagSumsuSkill[0].angle = PI2;
		}
		if (_vTagSumsuSkill[0].angle > 0 && _vTagSumsuSkill[0].angle < (PI8))
		{
			_currentFrameX1 = 7;
			_currentFrameX2 = 1;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 7) && _vTagSumsuSkill[0].angle < PI2)
		{
			_currentFrameX1 = 6;
			_currentFrameX2 = 2;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 6) && _vTagSumsuSkill[0].angle < (PI8 * 7))
		{
			_currentFrameX1 = 5;
			_currentFrameX2 = 3;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 5) && _vTagSumsuSkill[0].angle < (PI8 * 6))
		{
			_currentFrameX1 = 4;
			_currentFrameX2 = 4;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 4) && _vTagSumsuSkill[0].angle < (PI8 * 5))
		{
			_currentFrameX1 = 3;
			_currentFrameX2 = 5;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 3) && _vTagSumsuSkill[0].angle < (PI8 * 4))
		{
			_currentFrameX1 = 2;
			_currentFrameX2 = 6;
		}
		else if (_vTagSumsuSkill[0].angle >(PI8 * 2) && _vTagSumsuSkill[0].angle < (PI8 * 3))
		{
			_currentFrameX1 = 1;
			_currentFrameX2 = 7;
		}
	}	
}