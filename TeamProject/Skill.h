#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;				// 스킬 이미지
	image* img1;			// 아타호 3단계 개인기 레이저 이미지 추가
	image* img2;			// 아타호 3단계 개인기 레이저 이미지 추가
	RECT rc;				// 스킬 상자
	RECT rc1;				// 아타호 3단계 개인기 레이저 상자 추가
	RECT rc2;				// 아타호 3단계 개인기 레이저 상자 추가
	float fireX, fireY;		// 스킬 시작 좌표
	float x, y;				// 스킬 좌표
	float stoneX, stoneY;	// 아타호 3단계 전체기 돌 좌표
	bool start;				// 스킬 시작
	int count;				// 스킬 카운트
	float speed;			// 스킬 속도
	float angle;			// 스킬 각도
	float _width;			// 스킬 이미지 가로 크기
};
//======= 아타호 개인 스킬 1번 : 호격권 ========
class atahoTargetSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;			// 스킬 레벨
	int _width;

	int _alphaColor;	// 알파 색
	int _alphaCount;	// 알파 카운트
	int _alphaMaxCount;	// 알차 최대 카운트

public:
	atahoTargetSkill1();
	~atahoTargetSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);				// 스킬 생성

	vector<tagSkill> getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};

//======= 아타호 개인 스킬 2번 : 맹호스페셜 ========
class atahoTargetSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;			// 스킬 레벨

public:
	atahoTargetSkill2();
	~atahoTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);			// 스킬 생성
	void moveSkill();							// 스킬 움직임

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};

//======= 아타호 개인 스킬 3번 : 비기 - 맹호광파참 ========
class atahoTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	image * _img;			// 모으기 이미지
	RECT _rc;				// 모으기 상자
	float _x, _y;			// 모으기 x, y 좌표

	float _range;			// 최대 길이

	int _count;				// 카운트
	int _expCount;			// 경험치 카운트
	int _currentExp;		// 현재 경험치
	int _maxExp;			// 최대 경험치
	int _level;				// 현재 레벨
	int _width;				// 늘어날 가로 크기
	bool _start;			// 기모으기인지 레이저인지 확인

public:
	atahoTargetSkill3();
	~atahoTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);		// 기모으기 시작
	void moveSkill();						// 기모으기 움직임

	void chargingSkill12(float x, float y);	// 차징 1,2단계 위치 및 각도
	void chargingSkill3(float x, float y);	// 차징 3단계 위치 및 각도
	void chargingSkill4(float x, float y);	// 차징 4단계 위치 및 각도

	void fireAddSkill(float x, float y);	// 기 발사 시작
	void fireSkill1(float x, float y);		// 기 발사 1단계 위치 및 초기 값
	void fireSkill2(float x, float y);		// 기 발사 2단계 위치 및 초기 값
	void fireSkill3(float x, float y);		// 기 발사 3단계 위치 및 초기 값
	void fireSkill4(float x, float y);		// 기 발사 4단계 위치 및 초기 값

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};
//======= 아타호 단체 스킬 2번 : 화둔! ========
class atahoAreaSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;				// 스킬 최대 길이 제한

	float _angle;				// 스킬 각도
	bool _start;				// 스킬 각도 제한

public:
	atahoAreaSkill2();
	~atahoAreaSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);		// 스킬 생성
	void moveSkill();						// 스킬 움직임

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};
//======= 아타호 개인 스킬 3번 : 노익장 대폭발 ========
class atahoAreaSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _randnumFireX;					// 불 x 좌표 랜덤
	float _randnumFireY;					// 불 y 좌표 랜덤
	float _randnumStoneX;					// 돌 x 좌표 랜덤
	float _randnumStoneY;					// 돌 y 좌표 랜덤

	int _randStone;							// 돌 프레임 0 or 1 랜덤
	int _stoneCount;						// 돌 4개만 생성 되게 해주는 카운트

public:
	atahoAreaSkill3();
	~atahoAreaSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);	// 스킬 생성
	void moveSkill();						// 스킬 움직임

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};
//======= 스마슈 베기 이미지 ========
class sumsuCut : public gameNode
{
private:

public:
	sumsuCut();
	~sumsuCut();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);		// 스킬 생성
};
//======= 스마슈 개인 스킬 2번 : 절사어면 ========
class sumsuTargetSkill2 : public gameNode
{
private:

	int _count;					// 스킬 카운트

public:
	sumsuTargetSkill2();
	~sumsuTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);		// 스킬 생성

	int setCount(int count) { return _count = count; }
};
//======= 스마슈 개인 스킬 3번 : 난도질 ========
class sumsuTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _alphaColor;	// 알파 색
	int _alphaCount;	// 알파 카운트
	int _alphaMaxCount;	// 알차 최대 카운트

public:
	sumsuTargetSkill3();
	~sumsuTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void cutUpSkill(float x, float y);			// 위 베기 스킬 생성
	void cutDownSkill(float x, float y);		// 아래 베기 스킬 생성
	void cutDiagonalSkill(float x, float y);	// 대각선 베기 스킬 생성
	void cutBigSkill(float x, float y);			// 마무리 베기 스킬 생성
	void moveSkill();
	
	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

class sumsuAreaSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;

	float _range;

public:
	sumsuAreaSkill1();
	~sumsuAreaSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addAreaSkill(float x, float y, int monsterNum);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};