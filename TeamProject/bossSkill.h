#pragma once
#include "gameNode.h"
#include <vector>

struct tagBossSkill
{
	image* img;
	RECT rc;
	float fireX, fireY;
	float x, y;
	bool start;
	int count;
	float speed;
	float angle;
	int height;
};

class BossSkill1 : public gameNode
{
private:
	vector<tagBossSkill>			_vTagBossSkill;
	vector<tagBossSkill>::iterator	_viTagBossSkill;

	image* _img;
	RECT _rc;
	float _x, _y;

	int _count;
	bool _start;
	float _randumAngle;

public:
	BossSkill1();
	~BossSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addAreaSkill(float x, float y);
	void moveSkill();
	void atkSkill();

	vector<tagBossSkill>getVTagSkill() { return _vTagBossSkill; }
	vector<tagBossSkill>::iterator getVITagSkill() { return _viTagBossSkill; }
};

class BossSkill2 : public gameNode
{
private:
	vector<tagBossSkill>			_vTagBossSkill;
	vector<tagBossSkill>::iterator	_viTagBossSkill;

	int _count;
	int _randumHeight;
	int _randumX;
	int _randumY;

public:
	BossSkill2();
	~BossSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addAreaSkill();
	void moveSkill();

	vector<tagBossSkill>getVTagSkill() { return _vTagBossSkill; }
	vector<tagBossSkill>::iterator getVITagSkill() { return _viTagBossSkill; }
};