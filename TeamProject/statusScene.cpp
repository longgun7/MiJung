#include "stdafx.h"
#include "statusScene.h"


statusScene::statusScene()
{
}

statusScene::~statusScene()
{
}

HRESULT statusScene::init(void)
{
	IMAGEMANAGER->addImage("statusMain", "image/ui/statusMain.bmp", 650, 550, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice", "image/ui/statusChoice.bmp", 350, 150, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice2", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, false, RGB(0, 0, 0));
	
	IMAGEMANAGER->addFrameImage("ĳ�����̹���", "image/ui/ĳ�����̹���.bmp", 1000, 250, 8, 2, false, RGB(0, 0, 0));
	IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(0);

	IMAGEMANAGER->addFrameImage("��ų", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ȯ�漳��", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("��ų")->setFrameX(0);
	IMAGEMANAGER->findImage("����")->setFrameX(1);
	IMAGEMANAGER->findImage("���")->setFrameX(2);
	IMAGEMANAGER->findImage("����")->setFrameX(3);
	IMAGEMANAGER->findImage("���")->setFrameX(8);
	IMAGEMANAGER->findImage("ȯ�漳��")->setFrameX(4);

	IMAGEMANAGER->addFrameImage("������", "image/ui/������.bmp", 600, 250, 12, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ���ͼ���UP", "image/ui/UI��ư.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ĳ���ͼ���DOWN", "image/ui/UI��ư.bmp", 450, 75, 9, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("ĳ���ͼ���UP")->setFrameX(7);
	IMAGEMANAGER->findImage("ĳ���ͼ���DOWN")->setFrameX(8);

	IMAGEMANAGER->addFrameImage("SETTINGBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameX(6);
	IMAGEMANAGER->addFrameImage("INVENBUTTON", "image/ui/UI��ư.bmp",450, 75, 18, 3, true, RGB(255, 0, 255));


	_uiX = WINSIZEX - 314;
	_uiY = 100;

	_setIndex = 0;
	_invenIndex = 0;
	
	_isCheck = false;
	_isItemCheck = false;

	return S_OK;
}

void statusScene::release(void)
{

}

void statusScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if(!_isCheck)
		{
			SCENEMANAGER->changeScene("Ÿ���");
		}
		else
		{
			IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(0);
			_isCheck = false;
		}
		
	}
	//if (KEYMANAGER->isOnceKeyDown(VK_F1))
	//{
	//	SCENEMANAGER->changeScene("�ʵ��");
	//}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if(!_isCheck)
		{
			IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(
				IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() + 1);
			if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX()>1)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(0);
			}
		}
		
	}
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if(!_isCheck)
		{
			IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(
				IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() - 1);
			if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX()<0)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(1);
			}
		}
		
	}

	if(KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if(!_isCheck)
		{
			_setIndex--;
			if (_setIndex < 0)
			{
				_setIndex = 5;
			}
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if(!_isCheck)
		{
			_setIndex++;
			if (_setIndex>5)
			{
				_setIndex = 0;
			}
		}
		
	}
	if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(1);
		_isCheck = true;
	}

	
	for(int i=0;i<6;i++)
	{
		if(_setIndex ==i)
		{
			_uiX = WINSIZEX - 314 +i*50;
		}
	}

}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(CAMERA->getCameraDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(CAMERA->getCameraDC(), 650, 150);
	IMAGEMANAGER->findImage("�⺻status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("ĳ�����̹���")->frameRender(CAMERA->getCameraDC(), 60, 50);

	IMAGEMANAGER->findImage("��ų")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 325, 50);
	IMAGEMANAGER->findImage("����")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 275, 50);
	IMAGEMANAGER->findImage("���")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 225, 50);
	IMAGEMANAGER->findImage("����")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 175, 50);
	IMAGEMANAGER->findImage("���")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 125, 50);
	IMAGEMANAGER->findImage("ȯ�漳��")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 75, 50);

	IMAGEMANAGER->findImage("SETTINGBUTTON")->frameRender(CAMERA->getCameraDC(), _uiX, _uiY);

	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0&&!_isCheck)
	{
		IMAGEMANAGER->findImage("ĳ���ͼ���DOWN")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 527);
		
	}
	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1 && !_isCheck)
	{
		IMAGEMANAGER->findImage("ĳ���ͼ���UP")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 0);
	}
	
	

	fontUI();
}

void statusScene::fontUI(void)
{
	HFONT font, ofont;
	
	
	char strName1[] = "��Ÿȣ";
	char strName2[] = "������";
	
	char str1[] = "����";
	char str2[] = "ü��";
	char str3[] = "���";
	char str4[] = "����";
	char str5[] = "���ݷ�";
	char str6[] = "����";
	char str7[] = "�����";
	char str8[] = "���߷�";
	char str9[] = "��";

	char str10[] = "����";
	char str11[] = "��";

	char str12[] = "���α�";
	char str13[] = "����";
	char str14[] = "����";
	char str15[] = "����";
	char str16[] = "���";
	char str17[] = "ȯ�漳��";

	char str18[] = "����";
	char str19[] = "����";
	char str20[] = "���";
	char str21[] = "����";
	char str22[] = "�ݰ�";
	

	

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0)
	{
		TextOut(CAMERA->getCameraDC(),20, 20, strName1, strlen(strName1));
	}
	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)
	{
		TextOut(CAMERA->getCameraDC(), 20, 20, strName2, strlen(strName2));
	}
	//ĳ���� ����
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 40, str1, strlen(str1));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 80, str2, strlen(str2));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120, str3, strlen(str3));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 160, str4, strlen(str4));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 210, str5, strlen(str5));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 250, str6, strlen(str6));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 290, str7, strlen(str7));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 330, str8, strlen(str8));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 370, str9, strlen(str9));

	//�������
	TextOut(CAMERA->getCameraDC(), 20, WINSIZEY/2-190, str10, strlen(str10));
	TextOut(CAMERA->getCameraDC(), 20, WINSIZEY/2-100, str11, strlen(str11));
	

	//�κ��丮
	if (_setIndex == 0) TextOut(CAMERA->getCameraDC(), WINSIZEX - 212, 160, str12, strlen(str12));
	if (_setIndex == 1) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str13, strlen(str13));
	if (_setIndex == 2) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str14, strlen(str14));
	if (_setIndex == 3) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str15, strlen(str15));
	if (_setIndex == 4) TextOut(CAMERA->getCameraDC(), WINSIZEX - 200, 160, str16, strlen(str16));
	if (_setIndex == 5) TextOut(CAMERA->getCameraDC(), WINSIZEX - 225, 160, str17, strlen(str17));
	
		
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
