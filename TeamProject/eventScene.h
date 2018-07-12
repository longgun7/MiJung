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

	vector<string> _vTalk;
	int _talkIndex;
	string talk1 = "���� �Ʒ��� ���ٺ��� ǳ���� ���� �Ƹ��䱸�� ..";
	string talk2 = "������ ���� ���� �� ������ �ٵ�..";
	string talk3 = "���� ���� ���� �� �� ���ٴ� ���� ������ ��������....";
	string talk4 = "���� ... ����ü ����ִ� �Ŵ�...";
	string talk5 = "���� ��ü�� �ð��� �����ϴ�. � ���ô�!";
	string talk6 = "�˰ڳ�";
public:
	eventScene();
	~eventScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	void talk();
	void sceneChange(void);
};

