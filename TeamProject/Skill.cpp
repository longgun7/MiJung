#include "stdafx.h"
#include "Skill.h"

//======= ��Ÿȣ ���� ��ų 1�� : ȣ�ݱ� ========
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

		// ��ų 200 ī��Ʈ ������
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
			//��ų ���� ����
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
	//��ų �̹���	
	targetSkill1.img = new image;
	targetSkill1.img->init("image/effect/TargetSkill1.bmp", 100, 85, 1, 1, true, RGB(255, 0, 255), true);

	targetSkill1.x = x;			// ��ų x��ǥ
	targetSkill1.y = y;			// ��ų y��ǥ
	targetSkill1.count = 0;		// ��ų ������ ī��Ʈ �ʱ�ȭ
	_width = 0;
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

void atahoTargetSkill2::realse(){}

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
			// ù��° �׸� ����
			_viTagSkill->img->frameRender(getMemDC(), _viTagSkill->rc.left, _viTagSkill->rc.top,
				_viTagSkill->img->getFrameX(), _viTagSkill->img->getFrameY());
			// �ι��� �׸� ���� (
			_viTagSkill->img1->frameRender(getMemDC(), _viTagSkill->rc1.left, _viTagSkill->rc1.top,
				_viTagSkill->img1->getFrameX(), _viTagSkill->img1->getFrameY(), _width, _viTagSkill->img1->getFrameHeight());
			_viTagSkill->img2->frameRender(getMemDC(), _viTagSkill->rc2.left + (_width - _viTagSkill->img2->getFrameWidth()), _viTagSkill->rc2.top,
				_viTagSkill->img2->getFrameX(), _viTagSkill->img2->getFrameY());
		}
	}
}
// ��ų ���� ������� ����
void atahoTargetSkill3::addSkill(float x, float y)
{
	_start = false;
	_expCount++;
	if (_expCount == 1)
	{
		_currentExp += 40;									// ��ų ����ġ 40 ����
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

	_img = IMAGEMANAGER->findImage("TargetSkill3Chakra");
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

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
//======= ��Ÿȣ ��ü ��ų 2�� : ȭ��! ========
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
		// ī��Ʈ 10 ����
		if (_viTagSkill->count % 10 == 0)
		{
			// �ִ� �������� �ȴٸ�
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// 5��° ���������� �׷��ش�
				_viTagSkill->img->setFrameX(5);
				break;
			}
			else
			{
				// �Ѱ��� �÷��ش�
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
	//��ų �̹���
	areaSkill.img = new image;
	areaSkill.img->init("image/effect/AreaSkill2.bmp", 96, 16, 6, 1, true, RGB(255, 0, 255));
	areaSkill.fireX = areaSkill.x = x;				// ��ų x��ǥ, ���� x��ǥ
	areaSkill.fireY = areaSkill.y = y;				// ��ų y��ǥ, ���� y��ǥ
	areaSkill.count = 0;								// ��ų ������ ī��Ʈ �ʱ�

	if (_angle > (PI / 6))								// ��ų ������ 30���� �Ѿ�� 
	{
		_start = false;									// false
	}
	else if (_angle < 0)								// ��ų ������ 0�� ���� �۾�����
	{		
		_start = true;									// true
	}
	if (_start)
	{
		_angle += 0.05f;								// true �� ������ �þ�� (������)
	}
	else
	{
		_angle -= 0.05f;								// false �� ������ �پ��� (����)
	}

	areaSkill.angle = PI / 12;						// ��ų ������ �߻� ��ǥ ����
	areaSkill.angle -= _angle;						// ��ų ���� ����
	areaSkill.img->setFrameX(0);						// ��ų ������ ������x��ǥ �ʱ�ȭ
	areaSkill.speed = 2.0f;							// ��ų ���ư� �ӵ�
	_range = 150.0f;									// ��ų ���ư� �ִ� ����
	
	areaSkill.rc = RectMakeCenter(areaSkill.x, areaSkill.y, areaSkill.img->getFrameWidth(), areaSkill.img->getFrameHeight());

	_vTagSkill.push_back(areaSkill);
}

void atahoAreaSkill2::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// ��ų �̵� ��ǥ
		_viTagSkill->x += cosf(_viTagSkill->angle)*_viTagSkill->speed;
		_viTagSkill->y += -sinf(_viTagSkill->angle)*_viTagSkill->speed;

		_viTagSkill->rc = RectMakeCenter(_viTagSkill->x, _viTagSkill->y, _viTagSkill->img->getFrameWidth(), _viTagSkill->img->getFrameHeight());
		// ��ų�� �ִ� ���̸� �Ѿ��
		if (_range < getDistance(_viTagSkill->x, _viTagSkill->y, _viTagSkill->fireX, _viTagSkill->fireY))
		{
			// ��ų�� ��������
			_viTagSkill = _vTagSkill.erase(_viTagSkill);

		}
		else
		{
			++_viTagSkill;
		}
	}
}
//======= ��Ÿȣ ���� ��ų 3�� : ������ ������ ========
atahoAreaSkill3::atahoAreaSkill3(){}

atahoAreaSkill3::~atahoAreaSkill3(){}

HRESULT atahoAreaSkill3::init()
{
	IMAGEMANAGER->addImage("NULL", 0, 0);		// �� �̹��� ����
	return S_OK;
}

void atahoAreaSkill3::realse(){}

void atahoAreaSkill3::update()
{
	moveSkill();
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end(); ++_viTagSkill)
	{
		_viTagSkill->count++;

		// ī��Ʈ 5���� ���� ������
		if (_viTagSkill->count % 5 == 0)
		{
			if (_viTagSkill->img->getMaxFrameX() <= _viTagSkill->img->getFrameX())
			{
				// �ִ� ������ ���� �� �̹����� �ٲ۴�
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
	// �� ���� ī��Ʈ
	if (_stoneCount < 4)
	{
		areaSkill.img1 = new image;
		areaSkill.img1->init("image/effect/AreaSkillStone3.bmp", 64, 48, 2, 1, true, RGB(255, 0, 255));
		_stoneCount++;
	}
	// �� 4�� ��� ���� ������ �� �̹����� ���Ͷ�
	else
	{
		areaSkill.img1 = new image;
		areaSkill.img1 = IMAGEMANAGER->findImage("NULL");
	}
	// �� ��ǥ ��Ÿȣ �������� -100 ~ +100
	_randnumFireX = RND->getFromFloatTo(x - 100, x + 100);
	// �� ��ǥ�� ��Ÿȣ �������� -50 ~ +50 �̶��
	if (_randnumFireX > x - 50 && _randnumFireX < x + 50)
	{
		// y ��ǥ�� �� �Ʒ� �� ����
		_randnumFireY = RND->getInt(2);
		if (_randnumFireY == 0)
		{
			// ��
			_randnumFireY = y - 50;
		}
		else if (_randnumFireY == 1)
		{
			// �Ʒ�
			_randnumFireY = y + 50;
		}
	}
	// ��Ÿȣ �ֺ��� �ƴ϶��
	else
	{
		_randnumFireY = y;
	}

	areaSkill.x = _randnumFireX;
	areaSkill.y = _randnumFireY;
	// �� ��ǥ ��Ÿȣ �������� -100 ~ +100
	_randnumStoneX = RND->getFromFloatTo(x - 100, x + 100);
	// �� ��ǥ�� ��Ÿȣ �������� -50 ~ +50 �̶��
	if (_randnumStoneX > x - 50 && _randnumStoneX < x + 50)
	{
		// y ��ǥ�� �� �Ʒ� �� ����
		_randnumStoneY = RND->getInt(2);
		if (_randnumStoneY == 0)
		{
			// ��
			_randnumStoneY = y - 50;
		}
		else if(_randnumStoneY == 1)
		{
			// �Ʒ�
			_randnumStoneY = y + 50;
		}
	}
	// ��Ÿȣ �ֺ��� �ƴ϶��
	else
	{
		_randnumStoneY = y;
	}
	// �� ������ 0 or 1 �� ����
	_randStone = RND->getInt(2);
	areaSkill.img->setFrameX(_randStone);

	areaSkill.stoneX = _randnumStoneX;
	areaSkill.stoneY = _randnumStoneY;
	areaSkill.count = 0;					// ī��Ʈ �ʱ�ȭ

	areaSkill.rc = RectMakeCenter(areaSkill.x, areaSkill.y, areaSkill.img->getFrameWidth(), areaSkill.img->getFrameHeight());
	areaSkill.rc1 = RectMakeCenter(areaSkill.stoneX, areaSkill.stoneY, areaSkill.img1->getFrameWidth(), areaSkill.img1->getFrameHeight());

	_vTagSkill.push_back(areaSkill);
}

void atahoAreaSkill3::moveSkill()
{
	for (_viTagSkill = _vTagSkill.begin(); _viTagSkill != _vTagSkill.end();)
	{
		// ī��Ʈ�� 5 �Ʒ� �Ǵ� 50 ����
		if (_viTagSkill->count < 5 || _viTagSkill->count > 50)
		{
			// ���� �ö󰡶�
			_viTagSkill->stoneY -= 7;
		}

		_viTagSkill->rc1 = RectMakeCenter(_viTagSkill->stoneX, _viTagSkill->stoneY,
			_viTagSkill->img1->getFrameWidth(), _viTagSkill->img1->getFrameHeight());

		// ���� �� �ö󰬴ٸ�
		if (_viTagSkill->stoneY < 0)
		{
			// ������
			_viTagSkill = _vTagSkill.erase(_viTagSkill);
			// ������ ����� �� �������� ���� ������ 0���� �ʱ�ȭ �ñ�ĭ��
			if (_vTagSkill.size() <= 0) _stoneCount = 0;
		}
		else
		{
			++_viTagSkill;
		}
	}
}