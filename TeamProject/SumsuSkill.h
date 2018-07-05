#pragma once
#include "gameNode.h"
#include <vector>
struct tagSkill
{
	image* img;				// 스킬 이미지
	RECT rc;				// 스킬 상자
	float fireX, fireY;		// 스킬 시작 좌표
	float x, y;				// 스킬 좌표
	bool start;				// 스킬 시작
	int count;				// 스킬 카운트
	float _width;			// 스킬 이미지 가로 크기
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