#pragma once
#include"gameNode.h"
class battleScene : public gameNode
{
private: 
	bool _isTurn; //��ų�� �����ΰ�

public:
	battleScene();
	~battleScene();

	

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

