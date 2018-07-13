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
	

	bool _isShopCheck;		//������ üũ�Ǿ���?
	bool _isHotelCheck;		//������ üũ�Ǿ���?
	bool _isTalkCheck;
	int _who = 0;
	int _start = 0;
	int _count;
	int _index;
	int _talkIndex;
	int _maxTalkIndex;

	vector<string> vStr;

	string str = "z Z z Z z Z ";
	string str1 = "..Ÿ..��..��!";
	string str2 = "������??";
	string str3 = "��Ÿȣ������!";
	string str4 = "�̡���Ҹ��¡��������ε�. ";
	string str5 = "��Ÿȣ������!!";
	string str6 = "�������ΰ�? ���������ڳ�. ";
	string str7 = "�����̡���ġ�����߾��!!";
	string str8 = "�����?!?!?!";
	string str9 = "�����̡���ġ�����ߴٰ��!!���󸥡����Ϸ�������!";
	string str10 = "�켱���ڸ������̵��ϰ��ڼ���������� ����!";
	string str11 = "�ٽá����ء�����. �����̡���ġ�������ߴٰ�??";
	string str12 = "��! �氡�ٰ����쿬�������������������ٰ������ߴµ����������������׳༮�̡��־����!!";
	string str13 = "�ס��༮??�������������ϴ°հ�??";
	string str14 = "�׳༮�̿�! �׳༮! �����ǡ��������θ��̿����������̿�! ";
	string str15 = "�����?!���ס��ڷΡ��������ס������������ʰڴٰ�����߾��µ������롡�ס��ڰ�������ü����... ";
	string str16 = "�����������¡��𸣰ھ��..�������������̡��־������������Ⱑ���ɻ�ġ�ʾҾ��. �׷������ָ��������Ѻôµ���������������̡��ο������! ����¡������̡��й��ϰ�..���������������������������а��������Ⱦ��. ";
	string str17 = "��?!�����������ʴ¡��֡��������־���? ���������ʰ�! ���������顡�����̡������������ʾ����ٵ�!";
	string str18 = "���࿡�����������й踦���ϸ顡����������û�ҡ����������ϱ��. �׷������ٷΡ���Ÿȣ���������ס��޷��°̴ϴ�! ";
	string str19 = "�׷�. �˰ڴ�. ";
	string str20 = "����! �����������Ϸ�!";

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

