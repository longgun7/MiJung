#pragma once
#include "gameNode.h"
#include "playMap.h"
#include <vector>
class playerManager;
class eventScene : public gameNode
{
private:
	//eventMode * _event;
	playMap * _map;
	playerManager*	_pm;

	int _soundFrame;
	int _alphaNum;
	bool _isEventMode;

	bool _isBottleCol;

	vector<string> _vTalk;
	vector<string> _vTalk2;
	int _talkIndex;
	int _talkIndex2;
	string talk1 = "���� �Ʒ��� ���ٺ��� ǳ���� ���� �Ƹ��䱸�� ..";
	string talk2 = "������ ���� ���� �� ������ �ٵ�..";
	string talk3 = "���� ���� ���� �� �� ���ٴ� ���� ������ ��������....";
	string talk4 = "���� ... ����ü ����ִ� �Ŵ�...";
	string talk5 = "���� ��ü�� �ð��� �����ϴ�. � ���ô�!";
	string talk6 = "�˰ڳ�";


	string talk7 = "���� ������ �ֱ�";
	string talk8 = "�̰� ������ ���� �ǳ� �� �� �� �߽��� �� ���� �� �ְھ�!";
	string talk9 = "��Ÿȣ�� ������ �ֿ���.....!";
	
	string talk12 = "�̻��� ����� �߾� ..";






public:
	eventScene();
	~eventScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void talk();
	void sceneChange(void);

	void collision();

};

