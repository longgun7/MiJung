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
	
	
	IMAGEMANAGER->addImage("����â", "image/ui/����â.bmp", 450, 360, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â������", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â���Լ�", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â����", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));

	_isShopCheck = false;
	_isHotelCheck = false;

	_im = new itemManager;
	_im->init();

	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
	//���� üũ
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isShopCheck)
		{
			_isShopCheck = true;
			setItem();
			
		}
		else if (_isShopCheck) _isShopCheck = false;
	}
	if (!_isShopCheck)
	{
		for (int i = 0; i < _im->getShopItem()->getVItem().size(); ++i)
		{
			_im->getShopItem()->reMoveItem(i);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("���¾�");
	}
}

void barScnen::render(void)
{
	

	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	
	if(_isShopCheck)
	{	
		

		IMAGEMANAGER->findImage("����â")->render(CAMERA->getCameraDC(), 175, 95);
		IMAGEMANAGER->findImage("����â������")->render(CAMERA->getCameraDC(), 625, 95);
		IMAGEMANAGER->findImage("����â���Լ�")->render(CAMERA->getCameraDC(), 625, 215);
		IMAGEMANAGER->findImage("����â����")->render(CAMERA->getCameraDC(), 625, 335);

		_im->render();
	}
	
	fontUI();



}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "������";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
	if (_isShopCheck)
	{
		for (int i = 0; i < _im->getShopItem()->getVItem().size(); ++i)
		{
			//ar str[] = 		
			string str1 = _im->getShopItem()->getVItem()[i].name;
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);
		}

		for (int i = 0; i < _im->getShopItem()->getVItem().size(); ++i)
		{
			char str2[128];
			sprintf_s(str2, "%d", _im->getShopItem()->getVItem()[i].cost);
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2+50, 120 + i * 50, str2, strlen(str2));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);
		}
	}
}

void barScnen::setItem()
{
	_im->shopItemSet("���ξƼ���", WINSIZEX/2-260, 130);
	_im->shopItemSet("��Ÿ�� ����", WINSIZEX / 2 - 260, 180);
	_im->shopItemSet("���� �ͽŻ�", WINSIZEX / 2 - 260, 230);
	_im->shopItemSet("ȣ���� ����", WINSIZEX / 2 - 260, 280);
}
