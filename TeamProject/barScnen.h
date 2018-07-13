#pragma once
#include "shop.h"
#include "saveLoad.h"
#include "gameNode.h"
#include "playMap.h"
#include "npc.h"

class playerManager;

class barScnen : public gameNode
{
private:
	
	npc*				_npc;
	playMap*			_map;
	shop *				_shop;
	playerManager * _pm;
	
	saveLoad* _sl;
	

	bool _isShopCheck;		//상점이 체크되었늬?
	bool _isHotelCheck;		//여관이 체크되었늬?
	bool _isTalkCheck;
	int _who = 0;
	int _start = 0;
	int _count;
	int _index;
	int _talkIndex;
	int _maxTalkIndex;

	vector<string> vStr;

	string str = "z Z z Z z Z ";
	string str1 = "..타..　..님!";
	string str2 = "누구지??";
	string str3 = "아타호　형님!";
	string str4 = "이　목소리는　스마슈인데. ";
	string str5 = "아타호　형님!!";
	string str6 = "무슨일인가? 스마슈　자네. ";
	string str7 = "린샹이　납치　당했어요!!";
	string str8 = "뭐라고?!?!?!";
	string str9 = "린샹이　납치　당했다고요!!　얼른　구하러　가요!";
	string str10 = "우선　자리를　이동하고　자세히　얘기해 보게!";
	string str11 = "다시　말해　보게. 린샹이　납치를　당했다고??";
	string str12 = "네! 길가다가　우연히　린샹을　봐서　다가가려했는데　린샹　옆에　그녀석이　있었어요!!";
	string str13 = "그　녀석??　누구를　말하는겐가??";
	string str14 = "그녀석이요! 그녀석! 린샹의　예전　두목이였던　총통이요! ";
	string str15 = "뭐라고?!　그　뒤로　린샹한테　접근하지　않겠다고　약속했었는데　총통　그　자가　도대체　왜... ";
	string str16 = "저도　이유는　모르겠어요..　하지만　같이　있었을때　분위기가　심상치않았어요. 그래서　멀리서　지켜봤는데　총통과　린샹이　싸우더라고요! 결과는　린샹이　패배하고..　총통은　린샹을　데리고　어디론가　가버렸어요. ";
	string str17 = "뭐?!　스마슈　너는　왜　보고만　있었나? 도와주지않고! 도와줬으면　린샹이　끌려가지　않았을텐데!";
	string str18 = "만약에　저까지　패배를　하면　도움을　요청할　수　없으니까요. 그래서　바로　아타호　형님한테　달려온겁니다! ";
	string str19 = "그래. 알겠다. ";
	string str20 = "가자! 린샹을　구하러!";

public:
	barScnen();
	~barScnen();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void npcTileSetting();
	void npcCollision();
	
	void fontUI(void);
	void sceneChange(void);

	void talkSave();

	void talkLoad();

	int setTalkSaveLoad(int start) { return _start = start; }
};

