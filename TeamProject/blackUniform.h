#pragma once
#include "boss.h"

class blackUniform : public boss
{
private:



public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	blackUniform();
	~blackUniform();
};

