#pragma once
#include "singletonBase.h"

#define BACKGROUNDX 3750
#define BACKGROUNDY 3750

class cameraManager : public singletonBase<cameraManager>
{
private:
	image * _cameraBuffer;

	// 카메라 x, y는 left, top 기준
	float	_cameraX, _cameraY;

	bool _isCursor;
	
public:
	cameraManager();
	~cameraManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void cursor();

	void setPosition(float x, float y);
	POINT getPosition() { return PointMake(_cameraX, _cameraY); }

	image* getCameraBuffer() { return _cameraBuffer; }
	HDC getCameraDC() { return _cameraBuffer->getMemDC(); }
};
