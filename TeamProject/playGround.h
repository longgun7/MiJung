#pragma once
#include "gameNode.h"
#include "playSceneManager.h"

//ȯ������ȣ�� ����
class playGround : public gameNode
{
private:
	playSceneManager * _psm;
	
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	

	playGround();
	~playGround();
};

