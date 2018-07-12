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
	string talk1 = "절벽 아래로 내다보는 풍경이 아주 아름답구나 ..";
	string talk2 = "린샹과 같이 오면 더 좋았을 텐데..";
	string talk3 = "지금 너의 얼굴을 볼 수 없다는 것이 참으로 슬프구나....";
	string talk4 = "린샹 ... 도대체 어디있는 거니...";
	string talk5 = "형님 지체할 시간이 없습니다. 어서 갑시다!";
	string talk6 = "알겠네";
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

