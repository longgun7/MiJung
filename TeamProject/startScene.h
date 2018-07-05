#pragma once
#include"gameNode.h"



class startScene: public gameNode
{
private:
	float _uiX, _uiY;
	float _loadX, _loadY;

	int _index, _loadIndex;
	bool _isLoadCheck;
	
	bool _isCount;		//카운트 돌리늬?
	int _frameCount;	
	bool _isPlay;	//게임이 시작됐늬?
public:
	startScene();
	~startScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	bool getIsPlay() { return _isPlay; }

	void fontUI();//폰트 배치
};

