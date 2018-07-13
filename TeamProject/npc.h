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

	string strNPC = "���ؾ߸��Ρ������ɡ�����ϰھ�!!";
	string strNPC1 = "�ȳ��Ͻʴϱ�ֿ������Դϴ٢�";
	string strNPC2 = "�Ѥ���? ��פ���? �ơ���ø��䡡����Ŭ��ġŲ���Ծ�ߵǼ�;;";
	string strNPC3 = "�����������������ǡ����ء�����~ ";
	string strNPC4 = "�����롡���������޾��ֽǱ�...?";
	string strNPC5 = "�ݾ���̰��̡��ʿ͡����ǡ��ڵ����̴�. ";
	string strNPC6 = "�����ǡ����ɡ��޴���??";
	string strNPC7 = "�������Ⱑ���������̵����ִµ������̾�~~";
	string strNPC8 = "������������������";
	string strNPC9 = "������������ϰԡ���Ź����Ź";
	string strNPC10 = "��~ ��������������������";
	string strNPC11 = "ȣ���̡��ǹ����������͡��ߴٴ¡�ȣ���̰����ִٴµ�����¥�ϱ�??";

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
