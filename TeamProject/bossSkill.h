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