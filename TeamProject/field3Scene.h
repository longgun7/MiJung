#pragma once
#include "gameNode.h"
#include "playMap.h"
#include "fildSkeleton.h"
#include "npc.h"
#include <vector>

class playerManager;
class enemyManager;
class itemManager;

class field3Scene : public gameNode
{
private:
	vector<fildSkeleton>			_vSkeleton;
	vector<fildSkeleton>::iterator	_viSkeleton;

	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;
	playMap* _map;
	npc* _npc;

	int _count;
	int _who = 0;
	int _start;
	int _index;
	int _talkIndex;
	int _maxTalkIndex;
	bool _bossTalk;
	bool _bossAppear;
	bool _end;
	vector<string>				vStrBoss;

	// 보스 만나면
	string strBoss1 = "....드디어　도착했나. ";
	string strBoss2 = "총통! 린샹을 납치하다니! 무슨 속셈이냐! ";
	string strBoss3 = "너희들과　다시　한번　싸우고　싶다. ";
	string strBoss4 = "?!?!?!";
	string strBoss5 = "그러면　린샹양은??";
	string strBoss6 = "너희를　끌어들이기　위해서　일뿐..　해치진　않았다. ";
	string strBoss7 = "정식으로　결투를　신청한다! 결투의　승패와　상관없이　린샹은　너희들과　함께　보낼것이다. ";
	string strBoss8 = "방법이　잘못되었지만　그　결투　받아들이지. ";
	string strBoss9 = "아타호　형님이　그렇게　결정하셨으면　전　그　결정을　따르겠습니다. ";
	string strBoss10 = "승부!!";

	// 승리시
	string strBoss11 = "좋은　승부였다... 린샹은　옆방에　있다. ";
	string strBoss12 = "도전은　언제든지　받아주겠다. 하지만　앞으로는　이런식의　방법을　쓰지않고　정식으로　요청했으면　좋겠군";
	string strBoss13 = "알겠다. 다음부터는　정식으로　결투를　신청하겠다. ";
	string strBoss14 = "Hey 나한테　신청해도　된다고~~";
	string strBoss15 = "훗....";
	string strBoss16 = "그럼　다음에　봅세　총통! ";
	string strBoss17 = "다음에　보자";

public:
	field3Scene();
	~field3Scene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
	void fieldSettingEnemy(void);

	void sceneChange(void);
	void talkSave();
	void talkLoad();
};

