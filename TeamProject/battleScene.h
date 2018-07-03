#pragma once
#include"gameNode.h"
class battleScene : public gameNode
{
private: 
	bool _isTurn; //��ų�� �����ΰ�
	int _choiceIndex;

	float _choiceX, _choiceY;	//��� ���� ��ư

public:
	battleScene();
	~battleScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
};

