#include "stdafx.h"
#include "statusScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"


statusScene::statusScene()
{
}

statusScene::~statusScene()
{
}

HRESULT statusScene::init(void)
{
	addImage();
	

	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	_uiX = WINSIZEX - 314;
	_uiY = 100;

	_invenX = WINSIZEX - 340;
	_invenY = 210;

	_setIndex = 0;
	_invenIndex = 0;
	_invenTypeIndex = 0;
	
	_isCheck = false;
	_isItemCheck = false;

	_isState = false;

	return S_OK;
}

void statusScene::release(void)
{

}

void statusScene::update(void)
{
	iconChange();
	if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if(!_isCheck)
		{
			SCENEMANAGER->changeScene("Ÿ���");		//�����ִ������� ���ư��� �ٲ����
		}
		else
		{
			IMAGEMANAGER->findImage("SETTINGBUTTON")->setFrameY(0);
			_invenIndex = 0;
			_isCheck = false;
		}
		
	}
	
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
		else if(_isCheck)
		{
			_invenIndex++;
			if (_setIndex == 0) { if (_invenIndex > 2)_invenIndex = 0; }
			if (_setIndex == 1) 
			{ 
				if (_invenIndex > _pm->getV_PoInven().size())_invenIndex = 0; 
			}
			if (_setIndex == 2)
			{
				if (_invenIndex > _pm->getVA_WeapInven().size())_invenIndex = 0;
			}
			if (_setIndex == 3) { if (_invenIndex > 1)_invenIndex = 0; }
			if (_setIndex == 4) { if (_invenIndex > 4)_invenIndex = 0; }
			if (_setIndex == 5) { if (_invenIndex > 4)_invenIndex = 0; }

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
		else if (_isCheck)
		{
			_invenIndex--;
			if (_setIndex == 0) { if (_invenIndex < 0)_invenIndex = 2; }
			if (_setIndex == 1)
			{
				if (_invenIndex <0)_invenIndex = _pm->getV_PoInven().size();
			}
			if (_setIndex == 2)
			{
				if (_invenIndex < 0)_invenIndex = _pm->getVA_WeapInven().size();
			}
			if (_setIndex == 3) { if (_invenIndex < 0)_invenIndex = 1; }
			if (_setIndex == 4) { if (_invenIndex < 0)_invenIndex = 4; }
			if (_setIndex == 5) { if (_invenIndex < 0)_invenIndex = 4; }
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
	for(int i=0;i<5;i++)
	{
		if(_invenIndex==i)
		{
			_invenY = 210 + i * 50;
		}
	}
}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(CAMERA->getCameraDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(CAMERA->getCameraDC(), 650, 150);
	IMAGEMANAGER->findImage("ĳ�����̹���")->frameRender(CAMERA->getCameraDC(), 60, 50);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);
	IMAGEMANAGER->findImage("��ų")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 325, 50);
	IMAGEMANAGER->findImage("����")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 275, 50);
	IMAGEMANAGER->findImage("���")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 225, 50);
	IMAGEMANAGER->findImage("����")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 175, 50);
	IMAGEMANAGER->findImage("���")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 125, 50);
	IMAGEMANAGER->findImage("ȯ�漳��")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 75, 50);

	if(_isCheck)
	IMAGEMANAGER->findImage("INVENBUTTON")->frameRender(CAMERA->getCameraDC(), _invenX, _invenY);

	IMAGEMANAGER->findImage("SETTINGBUTTON")->frameRender(CAMERA->getCameraDC(), _uiX, _uiY);

	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0&&!_isCheck)
	{
		IMAGEMANAGER->findImage("ĳ���ͼ���DOWN")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 527);
		
	}
	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1 && !_isCheck)
	{
		IMAGEMANAGER->findImage("ĳ���ͼ���UP")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 0);
	}
	char str123[128];
	if (_setIndex==0 || _setIndex>3)
	{
		IMAGEMANAGER->findImage("��ų1")->frameRender(CAMERA->getCameraDC(), WINSIZEX-315, 200);
		IMAGEMANAGER->findImage("��ų2")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 250);
		IMAGEMANAGER->findImage("��ų3")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 300);
		
		if (_setIndex == 4)
		{
			IMAGEMANAGER->findImage("��ų4")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 350);
			IMAGEMANAGER->findImage("��ų5")->frameRender(CAMERA->getCameraDC(), WINSIZEX - 315, 400);
		}
	}
	
	fontUI();
	
}

void statusScene::addImage(void)
{
	IMAGEMANAGER->addImage("statusMain", "image/ui/statusMain.bmp", 650, 550, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice", "image/ui/statusChoice.bmp", 350, 150, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice2", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));

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
	IMAGEMANAGER->addFrameImage("INVENBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("INVENBUTTON")->setFrameX(7);
}

void statusScene::iconChange(void)
{
	switch (_setIndex)
	{
	case 0:
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX()==0)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(11);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(11);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
		}

		break;
	case 1:
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(2);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(2);
		}
		break;
	case 2:
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(10);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(2);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(14);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(0);
		}
		if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)
		{
			IMAGEMANAGER->findImage("��ų1")->setFrameX(13);
			IMAGEMANAGER->findImage("��ų1")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų2")->setFrameX(17);
			IMAGEMANAGER->findImage("��ų2")->setFrameY(0);
			IMAGEMANAGER->findImage("��ų3")->setFrameX(16);
			IMAGEMANAGER->findImage("��ų3")->setFrameY(2);
		}
		break;
	case 3:

		break;
	case 4:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų2")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų2")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų3")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų3")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų4")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų4")->setFrameY(1);
		IMAGEMANAGER->findImage("��ų5")->setFrameX(8);
		IMAGEMANAGER->findImage("��ų5")->setFrameY(1);
		break;
	case 5:
		IMAGEMANAGER->findImage("��ų1")->setFrameX(10);
		IMAGEMANAGER->findImage("��ų1")->setFrameY(3);
		break;
	}
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
	
	char currentHP1[128];	//��Ÿȣ ����ü�� / �ִ�ü��
	sprintf_s(currentHP1, "%d / %d", _pm->getPlayer()->getAttribute().currentHp,_pm->getPlayer()->getAttribute().maxHp);
	char currentHP2[128];	//������ ����ü�� / �ִ�ü��
	sprintf_s(currentHP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentHp, _pm->getPlayer2()->getAttribute().maxHp);

	char currentMP1[128];	//��Ÿȣ ���縶�� / �ִ븶��
	sprintf_s(currentMP1, "%d / %d", _pm->getPlayer()->getAttribute().currentMp, _pm->getPlayer()->getAttribute().maxMp);
	char currentMP2[128];	//������ ���縶�� / �ִ븶��
	sprintf_s(currentMP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentMp, _pm->getPlayer2()->getAttribute().maxMp);
	
	char currentEXP1[128];	//��Ÿȣ �������ġ / �ִ����ġ
	sprintf_s(currentEXP1, "%d / %d", _pm->getPlayer()->getAttribute().currentExp, _pm->getPlayer()->getAttribute().maxExp);
	char currentEXP2[128];	//������ �������ġ / �ִ����ġ
	sprintf_s(currentEXP2, "%d / %d", _pm->getPlayer2()->getAttribute().currentExp, _pm->getPlayer2()->getAttribute().maxExp);

	//�÷��̾� 1,2 �ɷ�ġ
	char level1[128];	sprintf(level1, "%d", _pm->getPlayer()->getAttribute().level);
	char atk1[128];		sprintf_s(atk1,"%d", _pm->getPlayer()->getAttribute().atk);
	char def1[128];		sprintf_s(def1, "%d", _pm->getPlayer()->getAttribute().def);
	char speed1[128];	sprintf_s(speed1, "%d", _pm->getPlayer()->getAttribute().speed);
	char luck1[128];	sprintf_s(luck1, "%d", _pm->getPlayer()->getAttribute().luck);

	char level2[128];	sprintf(level2, "%d", _pm->getPlayer2()->getAttribute().level);
	char atk2[128];		sprintf_s(atk2, "%d", _pm->getPlayer2()->getAttribute().atk);
	char def2[128];		sprintf_s(def2, "%d", _pm->getPlayer2()->getAttribute().def);
	char speed2[128];	sprintf_s(speed2, "%d", _pm->getPlayer2()->getAttribute().speed);
	char luck2[128];	sprintf_s(luck2, "%d", _pm->getPlayer2()->getAttribute().luck);

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 0)//��Ÿȣ �ɷ�ġ
	{
		TextOut(CAMERA->getCameraDC(),20, 20, strName1, strlen(strName1));
		TextOut(CAMERA->getCameraDC(), 410, 40, level1, strlen(level1));
		TextOut(CAMERA->getCameraDC(), 410, 80, currentHP1, strlen(currentHP1));
		TextOut(CAMERA->getCameraDC(), 410, 120, currentMP1, strlen(currentMP1));
		TextOut(CAMERA->getCameraDC(), 410, 160, currentEXP1, strlen(currentEXP1));
		TextOut(CAMERA->getCameraDC(), 410, 210, atk1, strlen(atk1));
		TextOut(CAMERA->getCameraDC(), 410, 250, def1, strlen(def1));
		TextOut(CAMERA->getCameraDC(), 410, 290, speed1, strlen(speed1));
		TextOut(CAMERA->getCameraDC(), 410, 330, luck1, strlen(luck1));
		
	}
	if (IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() == 1)//������ �ɷ�ġ
	{
		TextOut(CAMERA->getCameraDC(), 20, 20, strName2, strlen(strName2));
		TextOut(CAMERA->getCameraDC(), 410, 40, level2, strlen(level2));
		TextOut(CAMERA->getCameraDC(), 410, 80, currentHP2, strlen(currentHP2));
		TextOut(CAMERA->getCameraDC(), 410, 120, currentMP2, strlen(currentMP2));
		TextOut(CAMERA->getCameraDC(), 410, 160, currentEXP2, strlen(currentEXP2));
		TextOut(CAMERA->getCameraDC(), 410, 210, atk2, strlen(atk2));
		TextOut(CAMERA->getCameraDC(), 410, 250, def2, strlen(def2));
		TextOut(CAMERA->getCameraDC(), 410, 290, speed2, strlen(speed2));
		TextOut(CAMERA->getCameraDC(), 410, 330, luck2, strlen(luck2));
	}
	//ĳ���� ����
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 40, str1, strlen(str1));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 80, str2, strlen(str2));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120, str3, strlen(str3));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 160, str4, strlen(str4));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 210, str5, strlen(str5));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 250, str6, strlen(str6));
	//TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 290, str7, strlen(str7)); //����� ����
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 290, str8, strlen(str8));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 330, str9, strlen(str9));

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
