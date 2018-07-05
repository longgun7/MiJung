#include "stdafx.h"
#include "SumsuSkill.h"

//======= 스마슈 베기 이미지 ========
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
// 스킬 생성 x(해당 적 x좌표, 해당 적 y좌표)
void sumsuCut::addFireSkill(float x, float y)
{
	// 스마슈 베기 이미지 플레이
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}

//======= 스마슈 개인 스킬 2번 : 절사어면 ========
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
// 스킬 생성 x(해당 적 x좌표, 해당 적 y좌표)
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

//======= 스마슈 개인 스킬 3번 : 난도질 ========
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
// 위 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
void sumsuTargetSkill3::cutUpSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutUp", x, y);
}
// 아래 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
void sumsuTargetSkill3::cutDownSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuCutDown", x, y);
}
// 대각선 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
void sumsuTargetSkill3::cutDiagonalSkill(float x, float y)
{
	EFFECTMANAGER->play("SumsuTargetSkill22", x, y);
	EFFECTMANAGER->play("CutEffect", x + 25, y - 25);
}
// 마무리 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
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

//======= 스마슈 단체 스킬 1번 : 백인일섬 ========
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
				// 10 카운트 전까지 매번마다 20씩 증가
				_viTagSumsuSkill->width += 20;
			}
			// 20 초과 41 미만일 때 크기가 줄어들어라 (오른쪽으로 줄어들어라)
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
		// 카운트가 42 이상이면 지워랏
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
// 스킬 생성 (레벨 및 몬스터 수에 따라 변경) x(첫번째 몬스터 x좌표), y(첫버째 몬스터 y좌표), 나타난 몬스터 수
void sumsuAreaSkill1::addAreaSkill(float x, float y, int monsterNum)
{
	tagSumsuSkill areaSkill[4];
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
		ZeroMemory(&areaSkill[i], sizeof(tagSumsuSkill));
		areaSkill[i].img = IMAGEMANAGER->findImage("SumsuAreaSkill1");
		// 1레벨 일때
		if (_level == 1)
		{
			// 몬스터 수 4마리 일때
			if (monsterNum == 4)
			{
				// 0번과 3번 몬스터
				if (i == 0 || i == 3)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 100;
				}
				// 1번과 2번 몬스터
				if (i == 1 || i == 2)
				{
					areaSkill[i].fireX = areaSkill[i].x = x - 150;
				}
			}
			// 몬스터가 4마리가 아닌 나머지 경우
			else
			{
				areaSkill[i].fireX = areaSkill[i].x = x - 100 + i * 50;
			}
		}
		// 2레벨 일때
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
		// 3레벨 일때
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
		// 4레벨 일때
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
		// 최대 거리 제한
		_range = 50.0f;
		// 처음 가로 크기
		areaSkill[i].width = 10;

		areaSkill[i].count = 0;
		areaSkill[i].rc = RectMakeCenter(areaSkill[i].x, areaSkill[i].y, areaSkill[i].img->getFrameWidth(), areaSkill[i].img->getFrameHeight());

		_vTagSumsuSkill.push_back(areaSkill[i]);
	}
}

//======= 스마슈 단체 스킬 2번 : 분신술 ========
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

// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표)
void sumsuAreaSkill2::addAreaSkill(float x, float y)
{
	_currentExp += 40;				// 스킬 경험치 40 증가

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
	if (_level == 1)
	{
		// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표) -> 위에서 매개변수로 인해 자동 처리
		addAreaSkill1(x, y);
	}
	else if (_level == 2)
	{
		// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표) -> 위에서 매개변수로 인해 자동 처리
		addAreaSkill2(x, y);
	}
	else if (_level == 3)
	{
		// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표) -> 위에서 매개변수로 인해 자동 처리
		addAreaSkill3(x, y);
	}
	else if (_level == 4)
	{
		// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표) -> 위에서 매개변수로 인해 자동 처리
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
		// 0번째 분신 각도 = 180 * 0
		// 1번째 분신 각도 = 180 * 1
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
		// 0번째 분신 각도 = (180/2) * 0
		// 1번째 분신 각도 = (180/2) * 1
		// 2번째 분신 각도 = (180/2) * 2
		// 3번째 분신 각도 = (180/2) * 3
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
		// 0번째 분신 각도 = (180/3) * 0
		// 1번째 분신 각도 = (180/3) * 1
		// 2번째 분신 각도 = (180/3) * 2
		// 3번째 분신 각도 = (180/3) * 3
		// 4번째 분신 각도 = (180/3) * 4
		// 5번째 분신 각도 = (180/3) * 5
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
		// 0번째 분신 각도 = (180/5) * 0
		// 1번째 분신 각도 = (180/5) * 1
		// 2번째 분신 각도 = (180/5) * 2
		// 3번째 분신 각도 = (180/5) * 3
		// 4번째 분신 각도 = (180/5) * 4
		// 5번째 분신 각도 = (180/5) * 5
		// 6번째 분신 각도 = (180/5) * 6
		// 7번째 분신 각도 = (180/5) * 7
		// 8번째 분신 각도 = (180/5) * 8
		// 9번째 분신 각도 = (180/5) * 9
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
		// 1 레벨 일때
		if (_level == 1)
		{
			// 카운트가 60미만 일때
			if (_viTagSumsuSkill->count < 60)
			{
				// 알파 색깔 정해주는 카운트
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 60)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// 매번 각도 값 변경
				_viTagSumsuSkill->angle += 0.05f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// 카운트 60이상 90이하 일때 까지는 가만히 있는 설정
			// 카운트가 90초과 일때 
			else if (_viTagSumsuSkill->count > 90)
			{
				// 스피드 값을 다시 조정
				_viTagSumsuSkill->speed = 8.0f;
				// 알파 값 고정
				_alphaColor = 150;
				// 현재 프레임수 카운터에 따라 결정
				if (_viTagSumsuSkill->count % 91 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 3);
				}
				// 분신술이 화면을 나가려고 하면 튕기도록
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
		// 2 레벨 일때
		else if (_level == 2)
		{
			// 카운트 115 미만 일때
			if (_viTagSumsuSkill->count < 115)
			{
				// 알파 색깔 정해주는 카운트
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 115)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// 매번 각도 값 변경
				_viTagSumsuSkill->angle += 0.04f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// 카운트 115이상 143이하 일때 까지는 가만히 있는 설정
			// 카운트가 143초과 일때 
			else if (_viTagSumsuSkill->count > 143)
			{				
				// 스피드 값을 다시 조정
				_viTagSumsuSkill->speed = 8.0f;
				// 알파 값 고정
				_alphaColor = 150;
				// 현재 프레임수 카운터에 따라 결정
				if (_viTagSumsuSkill->count % 36 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 4);
				}
				// 분신술이 화면을 나가려고 하면 튕기도록
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
		// 3 레벨 일때
		else if (_level == 3)
		{
			// 카운트가 105 미만 일때
			if (_viTagSumsuSkill->count < 105)
			{
				// 알파 색깔 정해주는 카운트
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 100)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// 매번 각도 값 변경
				_viTagSumsuSkill->angle += 0.04f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// 카운트 105이상 131이하 일때 까지는 가만히 있는 설정
			// 카운트가 132초과 일때 
			else if (_viTagSumsuSkill->count > 131)
			{
				// 스피드 값을 다시 조정
				_viTagSumsuSkill->speed = 8.0f;
				// 알파 값 고정
				_alphaColor = 150;
				// 현재 프레임수 카운터에 따라 결정
				if (_viTagSumsuSkill->count % 66 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 5);
				}
				// 분신술이 화면을 나가려고 하면 튕기도록
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
		// 4 레벨 일때
		else if (_level == 4)
		{
			// 카운트가 50미만 일때
			if (_viTagSumsuSkill->count < 50)
			{
				// 알파 색깔 정해주는 카운트
				if (_viTagSumsuSkill->count % 8 == 0 || _viTagSumsuSkill->count > 45)
				{
					_alphaColor = 150;
				}
				else if (_viTagSumsuSkill->count % 4 == 0)
				{
					_alphaColor = 0;
				}
				// 매번 각도 값 변경
				_viTagSumsuSkill->angle += 0.07f;
				_viTagSumsuSkill->x += cosf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
				_viTagSumsuSkill->y += -sinf(_viTagSumsuSkill->angle) * _viTagSumsuSkill->speed;
			}
			// 카운트 50이상 75이하 일때 까지는 가만히 있는 설정
			// 카운트가 75초과 일때
			else if (_viTagSumsuSkill->count > 75)
			{
				// 스피드 값을 다시 조정
				_viTagSumsuSkill->speed = 9.0f;
				// 알파 값 고정
				_alphaColor = 150;
				// 현재 프레임수 카운터에 따라 결정
				if (_viTagSumsuSkill->count % 76 == 0)
				{
					_viTagSumsuSkill->currentFrameX = RND->getFromIntTo(1, 6);
				}
				// 분신술이 화면을 나가려고 하면 튕기도록
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
		// 1 레벨 일때
		if (_level == 1)
		{
			// 카운트 넘어가면
			if (_viTagSumsuSkill->count > 350)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 2 레벨 일때
		else if (_level == 2)
		{
			// 카운트 넘어가면
			if (_viTagSumsuSkill->count > 450)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 3 레벨 일때
		else if (_level == 3)
		{
			// 카운트 넘어가면
			if (_viTagSumsuSkill->count > 550)
			{
				_viTagSumsuSkill = _vTagSumsuSkill.erase(_viTagSumsuSkill);
			}
			else
			{
				++_viTagSumsuSkill;
			}
		}
		// 4 레벨 일때
		else if (_level == 4)
		{
			// 카운트 넘어가면
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