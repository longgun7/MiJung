#pragma once
#include "gameNode.h"
#include <vector>

enum NPCKIND
{
	NORMAL,
	SHOP,
	MOTEL
};
struct tagNPC
{
	NPCKIND kind;
	image* img;
	RECT rc;
	float x, y;
	int frameX, frameY;
};
class npc : public gameNode
{
	vector<tagNPC>				_vTagNPC;
	vector<tagNPC>::iterator	_viTagNPC;

public:
	npc();
	~npc();

	HRESULT init();
	void release();
	void update();
	void render();

	void addNPC(float x, float y, NPCKIND kind, int frameX, int frameY);

	vector<tagNPC>				getVTagNPC() { return _vTagNPC; }
	vector<tagNPC>::iterator	getVITagNPC() { return _viTagNPC; }
};
