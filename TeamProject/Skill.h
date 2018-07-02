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
	float speed;			// 스킬 속도
	float angle;			// 스킬 각도
	int level;
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

	void addSkill(float x, float y);

	vector<tagSkill> getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
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

	int _alphaColor;	// 알파 색
	int _alphaCount;	// 알파 카운트
	int _alphaMaxCount;	// 알차 최대 카운트

public:
	atahoTargetSkill2();
	~atahoTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);
	void moveSkill();

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

//======= 아타호 개인 스킬 3번 : 비기 - 맹호광파참 ========
class atahoTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _currentExp;
	int _maxExp;
	int _level;

	int _alphaColor;
	int _alphaCount;
	int _alphaMaxCount;

public:
	atahoTargetSkill3();
	~atahoTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);
	void moveSkill();

	void chargingSkill12(float x, float y);
	void chargingSkill3(float x, float y);
	void chargingSkill4(float x, float y);

};