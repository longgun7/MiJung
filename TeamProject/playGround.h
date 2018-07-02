#pragma once
#include "gameNode.h"
#include "startScene.h"
#include "endScene.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"

//ȯ������ȣ�� ����
class playGround : public gameNode
{
private:

	//�÷��̾� �Ŵ���
	playerManager * _PM;
	itemManager* _im;
	enemyManager* _em;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void sceneAdd(void);

	playGround();
	~playGround();
};

