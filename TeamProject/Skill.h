#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;
	RECT rc;
	float x, y;
	int currentExp = 0;
	int maxExp;
	bool start;
	int level = 1;
	int count;
};

class Skill : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _alphaColor;
	int _alphaCount;
	int _alphaMaxCount;
	 
public:
	Skill();
	~Skill();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);
};

