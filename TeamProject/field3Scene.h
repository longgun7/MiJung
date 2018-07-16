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

	// ���� ������
	string strBoss1 = "....��������߳�. ";
	string strBoss2 = "����! ������ ��ġ�ϴٴ�! ���� �Ӽ��̳�! ";
	string strBoss3 = "���������ٽá��ѹ����ο���ʹ�. ";
	string strBoss4 = "?!?!?!";
	string strBoss5 = "�׷��顡��������??";
	string strBoss6 = "���񸦡�������̱⡡���ؼ����ϻ�..����ġ�����ʾҴ�. ";
	string strBoss7 = "�������Ρ�����������û�Ѵ�! �����ǡ����п͡�������̡������������������Բ����������̴�. ";
	string strBoss8 = "����̡��߸��Ǿ��������ס��������޾Ƶ�����. ";
	string strBoss9 = "��Ÿȣ�������̡��׷��ԡ������ϼ����顡�����ס��������������ڽ��ϴ�. ";
	string strBoss10 = "�º�!!";

	// �¸���
	string strBoss11 = "�������ºο���... �����������濡���ִ�. ";
	string strBoss12 = "�������������������޾��ְڴ�. �������������δ¡��̷����ǡ�������������ʰ��������Ρ���û�����顡���ڱ�";
	string strBoss13 = "�˰ڴ�. �������ʹ¡��������Ρ�����������û�ϰڴ�. ";
	string strBoss14 = "Hey �����ס���û�ص����ȴٰ�~~";
	string strBoss15 = "��....";
	string strBoss16 = "�׷���������������������! ";
	string strBoss17 = "������������";

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

