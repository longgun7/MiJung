#pragma once
#include "gameNode.h"
//ȯ������ȣ�� ����
class playGround : public gameNode
{
private:
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	playGround();
	~playGround();
};

