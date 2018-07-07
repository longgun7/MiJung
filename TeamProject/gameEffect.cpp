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

// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal", x, y);
}

// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal", x, y);
}

// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("CutEffect", x, y);
}

// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal", x, y);
}

// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal2", x, y);
}

// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal2", x, y);
}

// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRUDiagonal2", x, y);
}

// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal2", x, y);
}

// 왼쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonLCloud(float x, float y)
{
	EFFECTMANAGER->play("LCloud", x, y);
}

// 오른쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonRCloud(float x, float y)
{
	EFFECTMANAGER->play("RCloud", x, y);
}

// 왼쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonLSpeed(float x, float y)
{
	EFFECTMANAGER->play("LSpeed", x, y);
}

// 오른쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonRSpeed(float x, float y)
{
	EFFECTMANAGER->play("RSpeed", x, y);
}

// 돈 떨어지는 이미지 생성 x(적 중점 좌표), y(적 중점 좌표)
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
		// 각 카운터 증가
		_viTagEffect->count++;
		// 카운트 20 미만이면
		if (_viTagEffect->count < 20)
		{
			// y좌표 증가
			_viTagEffect->y += 1;
		}
		else if (_viTagEffect->count < 30)
		{
			// y좌표 감소
			_viTagEffect->y -= 1;
		}
		else if (_viTagEffect->count < 40)
		{
			// y좌표 증가
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
				// 이미지 프레임 번호 증가
				_viTagEffect->img->setFrameX(_viTagEffect->img->getFrameX() + 1);
				// 번호가 3번 넘어가면 0번으로 초기화
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