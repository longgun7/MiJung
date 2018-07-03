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
	bool start;				// 스킬 시작
	int count;				// 스킬 카운트
	float speed;			// 스킬 속도
	float angle;			// 스킬 각도
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