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
	int tileX, tileY;
};
class npc : public gameNode
{
	vector<tagNPC>				_vTagNPC;
	vector<tagNPC>::iterator	_viTagNPC;

	int _index;
	int _talkIndex;
	int _maxTalkIndex;

	vector<string>				vStrNPC;

	string strNPC = "올해야말로　슈스케　우승하겠어!!";
	string strNPC1 = "안녕하십니까↗오랜만입니다↗";
	string strNPC2 = "롤ㄱㄱ? 배그ㄱㄱ? 아　잠시만요　프링클　치킨　먹어야되서;;";
	string strNPC3 = "무조건이지　무조건　말해　뭐해~ ";
	string strNPC4 = "언제쯤　질문을　받아주실까...?";
	string strNPC5 = "꿇어라　이것이　너와　나의　코딩높이다. ";
	string strNPC6 = "오늘의　점심　메뉴는??";
	string strNPC7 = "내가　기가막힌　아이디어가　있는데　말이야~~";
	string strNPC8 = "가능하지　가능하지";
	string strNPC9 = "불편　불편　편안하게　부탁　부탁";
	string strNPC10 = "여~ 오늘은　날씨가　좋다";
	string strNPC11 = "호랑이　권법을　마스터　했다는　호랑이가　있다는데　진짜일까??";

	bool _talkNPC;
	int _count;

public:
	npc();
	~npc();

	HRESULT init();
	void release();
	void update();
	void render();

	void addNPC(float x, float y, NPCKIND kind, int frameX, int frameY, int tileX, int tileY);
	void talkNPC(int frameX, int frameY);
	void talkNPCSave();

	void talkNPCLoad();

	void setIsTalk(bool isTalk) { _talkNPC = isTalk; }
	BOOL getIsTalk() { return _talkNPC; }

	vector<tagNPC>				getVTagNPC() { return _vTagNPC; }
	vector<tagNPC>::iterator	getVITagNPC() { return _viTagNPC; }
};
