#pragma once
#include "gameNode.h"
#include "startScene.h"
#include "endScene.h"
//ȯ������ȣ�� ����
class playGround : public gameNode
{
private:
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void sceneAdd(void);

	playGround();
	~playGround();
};

