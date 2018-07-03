#include "stdafx.h"
#include "Skill.h"

//======= ��Ÿȣ ���� ��ų 1�� : ȣ�ݱ� ========
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
		// ��ų 200 ī��Ʈ ������
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
		//��ų ���� ����
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
	//��ų �̹���
	targetSkill1.img = IMAGEMANAGER->findImage("TargetSkill1");
	targetSkill1.x = x;			// ��ų x��ǥ
	targetSkill1.y = y;			// ��ų y��ǥ
	targetSkill1.count = 0;		// ��ų ������ ī��Ʈ �ʱ�ȭ
	_currentExp += 40;			// ��ų ����ġ 40 ����

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
	// ��ų ������ �ִ� ī��Ʈ ����
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

//======= ��Ÿȣ ���� ��ų 2�� : ��ȣ����� ========
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

void atahoTargetSkill2::realse()
{
}

void atahoTargetSkill2::update()
{
	moveSkill();

	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;
		// ī��Ʈ 4���� ������ ����
		if (_viTagSkill->count % 4 == 0)
		{
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// ������ x �ִ�ġ ���޽� �� ������ ����
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
		// ��ų ���� 4�̻� ���� �׸��� �׷�����
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
// ��ų ����
void atahoTargetSkill2::addSkill(float x, float y)
{

	tagSkill targetSkill2;
	ZeroMemory(&targetSkill2, sizeof(tagSkill));
	
	//��ų �̹���
	targetSkill2.img = new image;
	targetSkill2.img = IMAGEMANAGER->findImage("TargetSkill2");
	targetSkill2.fireX = targetSkill2.x = x;			// ��ų x��ǥ, ���� x��ǥ
	targetSkill2.fireY = targetSkill2.y = y;			// ��ų y��ǥ, ���� y��ǥ
	targetSkill2.count = 0;								// ��ų ������ ī��Ʈ �ʱ�ȭ
	targetSkill2.angle = RND->getFromFloatTo((3.0f / 4.0f) * PI, (5.0f / 4.0f) * PI);		// ��ų ������ ��ǥ ����
	targetSkill2.img->setFrameX(0);						// ��ų ������ ������x��ǥ �ʱ�ȭ
	targetSkill2.speed = 1.0f;							// ��ų ���ư� �ӵ�
	_range = 50.0f;										// ��ų ���ư� �ִ� ����
	_currentExp += 40;									// ��ų ����ġ 40 ����

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
	targetSkill2.rc = RectMakeCenter(targetSkill2.x, targetSkill2.y, targetSkill2.img->getFrameWidth(), targetSkill2.img->getFrameHeight());

	_vTagSkill.push_back(targetSkill2);
}

//��ų ������
void atahoTargetSkill2::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// x, y ��ǥ ���ư� ��ǥ �̵�
		_viTagSkill->x += cosf(_viTagSkill->angle) * _viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle) * _viTagSkill->speed;

		// ��ų ���� ����
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// �ִ� ���̸� ����� ��ų�� �������
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
		}
		else ++_viTagSkill;
	}
}
// ============== ��Ÿȣ ���� ��ų 3�� : ��� - ��ȣ������ ===============
atahoTargetSkill3::atahoTargetSkill3() {}

atahoTargetSkill3::~atahoTargetSkill3() {}

HRESULT atahoTargetSkill3::init()
{
	IMAGEMANAGER->addFrameImage("TargetSkill3Charging", "image/effect/TargetSkill3Charging.bmp", 96, 16, 6, 1, true, RGB(255, 0, 255));

	_currentExp = 0;
	_maxExp = 100;
	_level = 1;
	_width = 16;
	return S_OK;
}

void atahoTargetSkill3::realse()
{
}

void atahoTargetSkill3::update()
{
	if (!_start)
	{
		for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
		{
			_viTagSkill->count++;
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
			if (_viTagSkill->count % 2 == 0)
			{
				_width += 16;
				if (_width >= 500)
				{
					_width = 500;
				}
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
			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
		}
		if (_start)
		{
			// ù��° �׸� ����
			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
			// �ι�° �׸� ���� (�̹��� ���� �ø���)
			_viTagSkill->img1->frameRender(getMemDC(), _viTagSkill->rc1.left, _viTagSkill->rc1.top,
				_viTagSkill->img1->getFrameX(), _viTagSkill->img1->getFrameY(), _width, _viTagSkill->img1->getFrameHeight());
			// ����° �׸� ����
			_viTagSkill->img2->frameRender(getMemDC(), _viTagSkill->rc2.left + (_width - _viTagSkill->img2->getFrameWidth()), _viTagSkill->rc2.top,
				_viTagSkill->img2->getFrameX(), _viTagSkill->img2->getFrameY());
		}
		char str[128];
		sprintf_s(str, "%d, %d, %d", _viTagSkill->count, _currentExp, _level);
		TextOut(getMemDC(), 200, 200, str, strlen(str));

		char str1[128];
		sprintf_s(str1, "%d, %d, %d", _viTagSkill->rc.left, _viTagSkill->rc1.left, _viTagSkill->rc2.left);
		TextOut(getMemDC(), 200, 150, str1, strlen(str1));
	}
}
// ��ų ���� ������� ����
void atahoTargetSkill3::addSkill(float x, float y)
{
	_start = false;
	_currentExp += 40;									// ��ų ����ġ 40 ����
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

	// ��ų ������ ��¡ ����
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

//��ų ������
void atahoTargetSkill3::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		switch (_level)
		{
		case 1:
		case 2:
			_viTagSkill->speed = 1.0f;							// ��ų ���ư� �ӵ�
			_viTagSkill->angle -= 0.04f;
			_range = 50.0f;										// ��ų ���ư� �ִ� ����
			break;
		case 3:
			_viTagSkill->speed = 1.0f;							// ��ų ���ư� �ӵ�
			_viTagSkill->angle -= 0.045f;
			_range = 44.4f;										// ��ų ���ư� �ִ� ����
			break;
		case 4:
			_viTagSkill->speed = 1.0f;							// ��ų ���ư� �ӵ�
			_viTagSkill->angle -= 0.045f;
			_range = 44.4f;										// ��ų ���ư� �ִ� ����
			break;
		}
		// x, y ��ǥ ���ư� ��ǥ �̵�
		_viTagSkill->x += cosf(_viTagSkill->angle) * _viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle) * _viTagSkill->speed;

		// ��ų ���� ����
		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y,
			_viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// �ִ� ���̸� ����� ��ų�� �������
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
		}
		else ++_viTagSkill;
	}
}
// ��¡ 1,2�ܰ� ��ġ �� ����
void atahoTargetSkill3::chargingSkill12(float x, float y)
{
	tagSkill targetSkill3[4];
	for (int i = 0; i < 4; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		// ��ų �̹���
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// ������
		if (i % 4 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ����
		else if (i % 4 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 50;						// ��ų y��ǥ, ���� y��ǥ
		}
		// ����
		else if (i % 4 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// �Ʒ���
		else if (i % 4 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 50;						// ��ų y��ǥ, ���� y��ǥ
		}

		targetSkill3[i].count = 0;							// ��ų ������ ī��Ʈ �ʱ�ȭ
		targetSkill3[i].img->setFrameX(0);					// ��ų ������ ������x��ǥ �ʱ�ȭ
		targetSkill3[i].speed = 1.0f;						// ��ų ���ư� �ӵ�
		targetSkill3[i].angle = PI * 3 / 2 + (PI * i) / 2;

		_range = 50.0f;										// ��ų ���ư� �ִ� ����

		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());
		_vTagSkill.push_back(targetSkill3[i]);
	}
}
// ��¡ 3�ܰ� ��ġ �� ����
void atahoTargetSkill3::chargingSkill3(float x, float y)
{
	tagSkill targetSkill3[6];
	for (int i = 0; i < 6; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		//��ų �̹���
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// ������
		if (i % 6 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ������ �밢�� ��
		else if (i % 6 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 40;						// ��ų y��ǥ, ���� y��ǥ
		}
		// ���� �밢�� ��
		else if (i % 6 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 40;						// ��ų y��ǥ, ���� y��ǥ
		}
		// ����
		else if (i % 6 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ���� �밢�� �Ʒ�
		else if (i % 6 == 4)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 40;						// ��ų y��ǥ, ���� y��ǥ
		}
		// ������ �밢�� �Ʒ�
		else if (i % 6 == 5)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 40;						// ��ų y��ǥ, ���� y��ǥ
		}

		targetSkill3[i].count = 0;							// ��ų ������ ī��Ʈ �ʱ�ȭ
		targetSkill3[i].img->setFrameX(0);					// ��ų ������ ������x��ǥ �ʱ�ȭ
		targetSkill3[i].angle = PI / 2 + PI + (PI6 * i);				// ��ų ������ ������ ����


		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());

		_vTagSkill.push_back(targetSkill3[i]);
	}
}
// ��¡ 4�ܰ� ��ġ �� ����
void atahoTargetSkill3::chargingSkill4(float x, float y)
{
	tagSkill targetSkill3[8];
	for (int i = 0; i < 8; ++i)
	{
		ZeroMemory(&targetSkill3[i], sizeof(tagSkill));
		//��ų �̹���
		targetSkill3[i].img = new image;
		targetSkill3[i].img = IMAGEMANAGER->findImage("TargetSkill3Charging");
		// ������
		if (i % 8 == 0)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 50;						// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ������ �밢�� ����
		else if (i % 8 == 1)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;							// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 25;								// ��ų y��ǥ, ���� y��ǥ
		}
		// ����
		else if (i % 8 == 2)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;							// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 50;								// ��ų y��ǥ, ���� y��ǥ
		}
		// ���� �밢�� ����
		else if (i % 8 == 3)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;								// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y - 25;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ����
		else if (i % 8 == 4)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 50;								// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ���� �밢�� �Ʒ�
		else if (i % 8 == 5)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x - 25;								// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 25;							// ��ų y��ǥ, ���� y��ǥ
		}
		// �Ʒ���
		else if (i % 8 == 6)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x;								// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 50;							// ��ų y��ǥ, ���� y��ǥ
		}
		// ������ �밢�� �Ʒ�
		else if (i % 8 == 7)
		{
			targetSkill3[i].x = targetSkill3[i].fireX = x + 25;								// ��ų x��ǥ, ���� x��ǥ
			targetSkill3[i].y = targetSkill3[i].fireY = y + 25;							// ��ų y��ǥ, ���� y��ǥ
		}

		targetSkill3[i].count = 0;							// ��ų ������ ī��Ʈ �ʱ�ȭ
		targetSkill3[i].img->setFrameX(0);					// ��ų ������ ������x��ǥ �ʱ�ȭ
		targetSkill3[i].angle = PI / 2 + PI + (PI8 * i);				// ��ų ������ ������ ����


		targetSkill3[i].rc = RectMakeCenter(targetSkill3[i].x, targetSkill3[i].y, targetSkill3[i].img->getFrameWidth(), targetSkill3[i].img->getFrameHeight());

		_vTagSkill.push_back(targetSkill3[i]);
	}
}

void atahoTargetSkill3::fireAddSkill(float x, float y)
{
	_start = true;
	_width = 0;
	// ��ų ������ ������ ����
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
	//��ų �̹���
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����

	targetSkill.fireX = targetSkill.x = x;		// fire, x ��ǥ ���� - �������� ��Ÿȣ�� rc.right������
	targetSkill.fireY = targetSkill.y = y;		// fire, y ��ǥ ����

	targetSkill.img->setFrameX(0);				// ù��° �׸� ��Ÿȣ �� �� �׸�
	targetSkill.img1->setFrameX(1);				// �ι�° �׸� ������ �þ�� �ϴ� �׸�
	targetSkill.img2->setFrameX(2);				// ����° �׸� ������ ���� �׸�

	targetSkill.count = 0;						// ī���� ���۽� �ʱ�ȭ

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill2(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//��ų �̹���
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));			// �� �̹��� ����

	targetSkill.fireX = targetSkill.x = x;			// fire, x ��ǥ ���� - �������� ��Ÿȣ�� rc.right������
	targetSkill.fireY = targetSkill.y = y;			// fire, y ��ǥ ����

	targetSkill.img->setFrameX(3);					// ù��° �׸� ��Ÿȣ �� �� �׸�
	targetSkill.img1->setFrameX(4);					// �ι�° �׸� ������ �þ�� �ϴ� �׸�
	targetSkill.img2->setFrameX(5);					// ����° �׸� ������ ���� �׸�

	targetSkill.count = 0;							// ī���� ���۽� �ʱ�ȭ

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill3(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//��ų �̹���
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));

	targetSkill.fireX = targetSkill.x = x;			// fire, x ��ǥ ���� - �������� ��Ÿȣ�� rc.right������
	targetSkill.fireY = targetSkill.y = y;			// fire, y ��ǥ ����

	targetSkill.img->setFrameX(9);					// ù��° �׸� ��Ÿȣ �� �� �׸�
	targetSkill.img1->setFrameX(10);				// �ι�° �׸� ������ �þ�� �ϴ� �׸�
	targetSkill.img2->setFrameX(11);				// ����° �׸� ������ ���� �׸�

	targetSkill.count = 0;							// ī���� ���۽� �ʱ�ȭ

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}

void atahoTargetSkill3::fireSkill4(float x, float y)
{
	tagSkill targetSkill;
	ZeroMemory(&targetSkill, sizeof(tagSkill));
	//��ų �̹���
	targetSkill.img = new image;
	targetSkill.img1 = new image;
	targetSkill.img2 = new image;

	targetSkill.img->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img1->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));
	targetSkill.img2->init("image/effect/TargetSkill3Fire.bmp", 288, 32, 18, 1, true, RGB(255, 0, 255));

	targetSkill.fireX = targetSkill.x = x;			// fire, x ��ǥ ���� - �������� ��Ÿȣ�� rc.right������
	targetSkill.fireY = targetSkill.y = y;			// fire, y ��ǥ ����

	targetSkill.img->setFrameX(15);					// ù��° �׸� ��Ÿȣ �� �� �׸�
	targetSkill.img1->setFrameX(16);				// �ι�° �׸� ������ �þ�� �ϴ� �׸�
	targetSkill.img2->setFrameX(17);				// ����° �׸� ������ ���� �׸�

	targetSkill.count = 0;							// ī���� ���۽� �ʱ�ȭ

	targetSkill.rc = RectMakeCenter(targetSkill.x, targetSkill.y, targetSkill.img->getFrameWidth(), targetSkill.img->getFrameHeight());
	targetSkill.rc1 = RectMakeCenter(targetSkill.x + targetSkill.img1->getFrameWidth(), targetSkill.y, targetSkill.img1->getFrameWidth(), targetSkill.img1->getFrameHeight());
	targetSkill.rc2 = RectMakeCenter(targetSkill.x + (targetSkill.img2->getFrameWidth() * 2), targetSkill.y, targetSkill.img2->getFrameWidth(), targetSkill.img2->getFrameHeight());

	_vTagSkill.push_back(targetSkill);
}