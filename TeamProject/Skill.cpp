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
