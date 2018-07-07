#include "stdafx.h"
#include "gameEffect.h"


gameEffect::gameEffect()
{
}


gameEffect::~gameEffect()
{
}

HRESULT gameEffect::init()
{
	EFFECTMANAGER->addEffect("HitLUDiagonal", "image/effect/HitLUDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitLDDiagonal", "image/effect/HitLDDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("CutEffect", "image/effect/CutEffect.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRDDiagonal", "image/effect/HitRDDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);

	EFFECTMANAGER->addEffect("HitLUDiagonal2", "image/effect/HitLUDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitLDDiagonal2", "image/effect/HitLDDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRUDiagonal2", "image/effect/HitRUDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRDDiagonal2", "image/effect/HitRDDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);

	EFFECTMANAGER->addEffect("LCloud", "image/effect/LCloud.bmp", 160, 32, 32, 32, 1.0f, 0.5f, 3);
	EFFECTMANAGER->addEffect("RCloud", "image/effect/RCloud.bmp", 160, 32, 32, 32, 1.0f, 0.5f, 3);

	EFFECTMANAGER->addEffect("LSpeed", "image/effect/LSpeed.bmp", 256, 48, 64, 48, 1.0f, 0.5f, 3);
	EFFECTMANAGER->addEffect("RSpeed", "image/effect/RSpeed.bmp", 256, 48, 64, 48, 1.0f, 0.5f, 3);

	IMAGEMANAGER->addFrameImage("Money", "image/effect/Money.bmp", 112, 16, 7, 1, true, RGB(255, 0, 255));
	return S_OK;
}

void gameEffect::realse()
{
}

void gameEffect::update()
{
	moveMoney();
	EFFECTMANAGER->update();
}

void gameEffect::render()
{
	for (_viTagEffect = _vTagEffect.begin(); _viTagEffect != _vTagEffect.end(); ++_viTagEffect)
	{
		_viTagEffect->img->frameRender(getMemDC(), _viTagEffect->rc.left, _viTagEffect->rc.top,
			_viTagEffect->img->getFrameX(), _viTagEffect->img->getFrameY());
	}

	EFFECTMANAGER->render();
}

// ���� ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal", x, y);
}

// ���� �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal", x, y);
}

// ������ ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("CutEffect", x, y);
}

// ������ �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal", x, y);
}

// ���� ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal2", x, y);
}

// ���� �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal2", x, y);
}

// ������ ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRUDiagonal2", x, y);
}

// ������ �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal2", x, y);
}

// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonLCloud(float x, float y)
{
	EFFECTMANAGER->play("LCloud", x, y);
}

// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonRCloud(float x, float y)
{
	EFFECTMANAGER->play("RCloud", x, y);
}

// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonLSpeed(float x, float y)
{
	EFFECTMANAGER->play("LSpeed", x, y);
}

// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonRSpeed(float x, float y)
{
	EFFECTMANAGER->play("RSpeed", x, y);
}

// �� �������� �̹��� ���� x(�� ���� ��ǥ), y(�� ���� ��ǥ)
void gameEffect::addMoney(float x, float y)
{
	tagEffect effect;
	ZeroMemory(&effect, sizeof(tagEffect));
	effect.img = IMAGEMANAGER->findImage("Money");
	effect.x = x;
	effect.y = y;
	effect.count = 0;

	effect.rc = RectMakeCenter(effect.x, effect.y, effect.img->getFrameWidth(), effect.img->getFrameHeight());

	_vTagEffect.push_back(effect);
}
void gameEffect::moveMoney()
{
	for (_viTagEffect = _vTagEffect.begin(); _viTagEffect != _vTagEffect.end();)
	{
		// �� ī���� ����
		_viTagEffect->count++;
		// ī��Ʈ 20 �̸��̸�
		if (_viTagEffect->count < 20)
		{
			// y��ǥ ����
			_viTagEffect->y += 1;
		}
		else if (_viTagEffect->count < 30)
		{
			// y��ǥ ����
			_viTagEffect->y -= 1;
		}
		else if (_viTagEffect->count < 40)
		{
			// y��ǥ ����
			_viTagEffect->y += 1;
		}
		else if (_viTagEffect->count < 70)
		{
			if (_viTagEffect->count % 6 == 0)
			{
				_viTagEffect->img->setFrameX(_viTagEffect->img->getFrameX() + 1);
				if (6 < _viTagEffect->img->getFrameX()) _viTagEffect->img->setFrameX(4);
			}
		}
		else if (_viTagEffect->count < 75)
		{
			_viTagEffect->img->setFrameX(6);
		}

		if (_viTagEffect->count < 40)
		{
			if (_viTagEffect->count % 4 == 0)
			{
				// �̹��� ������ ��ȣ ����
				_viTagEffect->img->setFrameX(_viTagEffect->img->getFrameX() + 1);
				// ��ȣ�� 3�� �Ѿ�� 0������ �ʱ�ȭ
				if (3 < _viTagEffect->img->getFrameX()) _viTagEffect->img->setFrameX(0);
			}
		}

		_viTagEffect->rc = RectMakeCenter(_viTagEffect->x, _viTagEffect->y,
			_viTagEffect->img->getFrameX(), _viTagEffect->img->getFrameY());

		if (_viTagEffect->count > 85)
		{
			_viTagEffect = _vTagEffect.erase(_viTagEffect);
		}
		else
		{
			++_viTagEffect;
		}
	}
}