#pragma once
#include "enemy.h"

class skeletonWizard : public enemy
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	skeletonWizard();
	~skeletonWizard();
};

