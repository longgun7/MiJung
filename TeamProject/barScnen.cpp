#include "stdafx.h"
#include "barScnen.h"


barScnen::barScnen()
{
}


barScnen::~barScnen()
{
}

HRESULT barScnen::init(void)
{
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	
	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
}

void barScnen::render(void)
{
}
