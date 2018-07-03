#pragma once
#include"gameNode.h"
class battleScene : public gameNode
{
private: 
	bool _isTurn; //스킬쓸 차례인가
	int _choiceIndex;

	float _choiceX, _choiceY;	//모드 선택 버튼

public:
	battleScene();
	~battleScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
};

