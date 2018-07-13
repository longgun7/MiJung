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
	string talk1 = "절벽 아래로 내다보는 풍경이 아주 아름답구나 ..";
	string talk2 = "린샹과 같이 오면 더 좋았을 텐데..";
	string talk3 = "지금 너의 얼굴을 볼 수 없다는 것이 참으로 슬프구나....";
	string talk4 = "린샹 ... 도대체 어디있는 거니...";
	string talk5 = "형님 지체할 시간이 없습니다. 어서 갑시다!";
	string talk6 = "알겠네";


	string talk7 = "여기 물통이 있군";
	string talk8 = "이게 있으면 줄을 건널 때 좀 더 중심을 잘 잡을 수 있겠어!";
	string talk9 = "아타호는 물통을 주웠다.....!";
	
	string talk12 = "이상한 상상을 했어 ..";






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

