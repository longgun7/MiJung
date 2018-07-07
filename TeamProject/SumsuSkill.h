#pragma once
#include "gameNode.h"
#include <vector>

struct tagSumsuSkill
{
	image* img;				// 스킬 이미지
	RECT rc;				// 스킬 상자
	float fireX, fireY;		// 스킬 시작 좌표
	float x, y;				// 스킬 좌표
	bool start;				// 스킬 시작
	int count;				// 스킬 카운트
	float width;			// 스킬 이미지 가로 크기
	int currentFrameX;		// 현재 프레임 번호
	float angle;			// 스킬 각도
	float angle1;			// 스마슈 3단계 전체기 용 각도 추가
	float speed;			// 스킬 스피드
	float speedx;			// 스마슈 3단계 전체기 용 스피드 추가
	int number;				// 스마슈 3단계 전체기 용 바퀴 회전 수
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

	// 스킬 생성 x(해당 적 x좌표, 해당 적 y좌표)
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

	// 스킬 생성 x(해당 적 x좌표, 해당 적 y좌표)
	void addFireSkill(float x, float y);		// 스킬 생성

	int setCount(int count) { return _count = count; }
};
//======= 스마슈 개인 스킬 3번 : 난도질 ========
class sumsuTargetSkill3 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

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

	// 위 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
	void cutUpSkill(float x, float y);
	// 아래 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
	void cutDownSkill(float x, float y);
	// 대각선 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
	void cutDiagonalSkill(float x, float y);
	// 마무리 베기 스킬 생성 (해당 적 x좌표, 해당 적 y좌표)
	void cutBigSkill(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }
};
//======= 스마슈 단체 스킬 1번 : 백인일섬 ========
class sumsuAreaSkill1 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

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

	// 스킬 생성 (레벨 및 몬스터 수에 따라 변경) x(첫번째 몬스터 x좌표), y(첫번째 몬스터 y좌표), 나타난 몬스터 수
	void addAreaSkill(float x, float y, int monsterNum);

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};
//======= 스마슈 단체 스킬 2번 : 분신술 ========
class sumsuAreaSkill2 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;

	int _alphaColor;	// 알파 색

public:
	sumsuAreaSkill2();
	~sumsuAreaSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	// 분신 캐릭터 설정 x(캐릭터 x좌표), y(캐릭터 y좌표)
	void addAreaSkill(float x, float y);
	void addAreaSkill1(float x, float y);
	void addAreaSkill2(float x, float y);
	void addAreaSkill3(float x, float y);
	void addAreaSkill4(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};

class sumsuAreaSkill3 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

	image* _img[2];
	RECT _rc[2];

	float _range;

	int _currentExp;	// 스킬 현재 경험치
	int _maxExp;		// 스킬 최대 경험치
	int _level;

	int _currentFrameX1;
	int _currentFrameX2;

	int _count;
	int _expCount;
public:
	sumsuAreaSkill3();
	~sumsuAreaSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	// 스마슈 x(중점 좌표), y(중점 좌표)
	void addAreaSkill(float x, float y);
	void addAreaSkill1(float x, float y);
	void addAreaSkill2(float x, float y);
	void addAreaSkill3(float x, float y);
	void addAreaSkill4(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};