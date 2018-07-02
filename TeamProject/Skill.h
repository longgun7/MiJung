#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;			// 스킬 이펙트 이미지
	RECT rc;			// 스킬 상자
	float x, y;			// 스킬 좌표
	bool start;			// 스킬 시작
	int count;			// 스킬 카운트
};

class targetSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;			// 스킬 레벨

	int _alphaColor;	// 스킬 알파 색
	int _alphaCount;	// 스킬 알파 카운트
	int _alphaMaxCount;	// 스킬 알파 최대 카운트

public:
	targetSkill1();
	~targetSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y, int dmage);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

class targetSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;			// 스킬 레벨

	int _alphaColor;	// 스킬 알파 색
	int _alphaCount;	// 스킬 알파 카운트
	int _alphaMaxCount;	// 스킬 알파 최대 카운트

public:
	targetSkill2();
	~targetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};
