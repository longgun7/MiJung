#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_a_Weapon = new item;
	_a_Weapon->init(3);

	_a_Armor = new item;
	_a_Armor->init(3);

	_potion = new item;
	_potion->init(1);

	_s_Weapon = new item;
	_s_Weapon->init(3);

	_s_Armor = new item;
	_s_Armor->init(3);
	

	setItem();

	_a_Weapon->makeItem("���ָ�", 100, 100);
	_a_Weapon->makeItem("��", 200, 100);
	_a_Weapon->makeItem("����", 300, 100);
	_a_Weapon->makeItem("Ư����", 400, 100);

	_a_Armor->makeItem("�ικ�", 100, 150);
	_a_Armor->makeItem("�ǹ��� ����", 200, 150);
	_a_Armor->makeItem("������ ����", 300, 150);
	_a_Armor->makeItem("ȣ���� ����", 400, 150);

	_s_Weapon->makeItem("���ڵ�", 100, 200);
	_s_Weapon->makeItem("û�浵", 200, 200);
	_s_Weapon->makeItem("��Ÿ�� ����", 300, 200);
	_s_Weapon->makeItem("�׷���Ʈ�ҵ�", 400, 200);

	_s_Armor->makeItem("������Ÿ����", 100, 250);
	_s_Armor->makeItem("���� ����", 200, 250);
	_s_Armor->makeItem("�����", 300, 250);
	_s_Armor->makeItem("ö�� ����", 400, 250);
	
	_potion->makepotion("����", 100, 300);
	_potion->makepotion("������ ����", 200, 300);

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	_a_Weapon->update();
	_a_Armor->update();
	_s_Weapon->update();
	_s_Armor->update();
	_potion->update();
}

void itemManager::render()
{
	_a_Weapon->render();
	_a_Armor->render();
	_s_Weapon->render();
	_s_Armor->render();
	_potion->render();

	for (int i = 0; i < 1; ++i)
	{
		char str[128];
		sprintf_s(str, "%d", _a_Weapon->getVItem()[i].luck);
		TextOut(getMemDC(), 100 + 100 * i, 150, str, strlen(str));
	}

	char str[128];
	sprintf_s(str, "%d", _potion->getVPotion()[0].hp);
	TextOut(getMemDC(), 100, 250, str, strlen(str));
}

void itemManager::setItem()
{
	INIDATA->addData("���ָ�", "�̸�", "���ָ�");
	INIDATA->addData("���ָ�", "���ݷ�", "0");
	INIDATA->addData("���ָ�", "��", "0");
	INIDATA->addData("���ָ�", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("���ָ�", "frameX", "0");
	INIDATA->addData("���ָ�", "frameY", "0");

	INIDATA->addData("��", "�̸�", "��");
	INIDATA->addData("��", "���ݷ�", "0");
	INIDATA->addData("��", "��", "5");
	INIDATA->addData("��", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("��", "frameX", "1");
	INIDATA->addData("��", "frameY", "0");

	INIDATA->addData("����", "�̸�", "����");
	INIDATA->addData("����", "���ݷ�", "0");
	INIDATA->addData("����", "��", "10");
	INIDATA->addData("����", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("����", "frameX", "2");
	INIDATA->addData("����", "frameY", "0");
	
	INIDATA->addData("Ư����", "�̸�", "Ư����");
	INIDATA->addData("Ư����", "���ݷ�", "0");
	INIDATA->addData("Ư����", "��", "15");
	INIDATA->addData("Ư����", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("Ư����", "frameX", "3");
	INIDATA->addData("Ư����", "frameY", "0");
	
	INIDATA->addData("�ικ�", "�̸�", "�ικ�");
	INIDATA->addData("�ικ�", "����", "10");
	INIDATA->addData("�ικ�", "���ǵ�", "5");
	INIDATA->addData("�ικ�", "frameX", "6");
	INIDATA->addData("�ικ�", "frameY", "0");
	
	INIDATA->addData("�ǹ��� ����", "�̸�", "�ǹ��� ����");
	INIDATA->addData("�ǹ��� ����", "����", "15");
	INIDATA->addData("�ǹ��� ����", "���ǵ�", "7");
	INIDATA->addData("�ǹ��� ����", "frameX", "7");
	INIDATA->addData("�ǹ��� ����", "frameY", "0");
	
	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "����", "20");
	INIDATA->addData("������ ����", "���ǵ�", "10");
	INIDATA->addData("������ ����", "frameX", "8");
	INIDATA->addData("������ ����", "frameY", "0");
	
	INIDATA->addData("ȣ���� ����", "�̸�", "ȣ���� ����");
	INIDATA->addData("ȣ���� ����", "����", "25");
	INIDATA->addData("ȣ���� ����", "���ǵ�", "12");
	INIDATA->addData("ȣ���� ����", "frameX", "9");
	INIDATA->addData("ȣ���� ����", "frameY", "0");
	
	INIDATA->addData("���ڵ�", "�̸�", "���ڵ�");
	INIDATA->addData("���ڵ�", "���ݷ�", "20");
	INIDATA->addData("���ڵ�", "��", "0");
	INIDATA->addData("���ڵ�", "ũ��Ƽ��Ȯ��", "10");
	INIDATA->addData("���ڵ�", "frameX", "0");
	INIDATA->addData("���ڵ�", "frameY", "2");
	

	INIDATA->addData("û�浵", "�̸�", "û�浵");
	INIDATA->addData("û�浵", "���ݷ�", "28");
	INIDATA->addData("û�浵", "��", "0");
	INIDATA->addData("û�浵", "ũ��Ƽ��Ȯ��", "12");
	INIDATA->addData("û�浵", "frameX", "1");
	INIDATA->addData("û�浵", "frameY", "2");
	

	INIDATA->addData("��Ÿ�� ����", "�̸�", "��Ÿ�� ����");
	INIDATA->addData("��Ÿ�� ����", "���ݷ�", "33");
	INIDATA->addData("��Ÿ�� ����", "��", "0");
	INIDATA->addData("��Ÿ�� ����", "ũ��Ƽ��Ȯ��", "14");
	INIDATA->addData("��Ÿ�� ����", "frameX", "2");
	INIDATA->addData("��Ÿ�� ����", "frameY", "2");
	

	INIDATA->addData("�׷���Ʈ�ҵ�", "�̸�", "�׷���Ʈ�ҵ�");
	INIDATA->addData("�׷���Ʈ�ҵ�", "���ݷ�", "41");
	INIDATA->addData("�׷���Ʈ�ҵ�", "��", "0");
	INIDATA->addData("�׷���Ʈ�ҵ�", "ũ��Ƽ��Ȯ��", "16");
	INIDATA->addData("�׷���Ʈ�ҵ�", "frameX", "3");
	INIDATA->addData("�׷���Ʈ�ҵ�", "frameY", "2");
	

	INIDATA->addData("������Ÿ����", "�̸�", "������Ÿ����");
	INIDATA->addData("������Ÿ����", "����", "10");
	INIDATA->addData("������Ÿ����", "���ǵ�", "10");
	INIDATA->addData("������Ÿ����", "frameX", "6");
	INIDATA->addData("������Ÿ����", "frameY", "2");
	

	INIDATA->addData("���� ����", "�̸�", "���� ����");
	INIDATA->addData("���� ����", "����", "18");
	INIDATA->addData("���� ����", "���ǵ�", "5");
	INIDATA->addData("���� ����", "frameX", "7");
	INIDATA->addData("���� ����", "frameY", "2");
	

	INIDATA->addData("�����", "�̸�", "�����");
	INIDATA->addData("�����", "����", "25");
	INIDATA->addData("�����", "���ǵ�", "15");
	INIDATA->addData("�����", "frameX", "8");
	INIDATA->addData("�����", "frameY", "2");
	

	INIDATA->addData("ö�� ����", "�̸�", "ö�� ����");
	INIDATA->addData("ö�� ����", "����", "33");
	INIDATA->addData("ö�� ����", "���ǵ�", "4");
	INIDATA->addData("ö�� ����", "frameX", "9");
	INIDATA->addData("ö�� ����", "frameY", "2");
	

	INIDATA->addData("����", "�̸�", "����");
	INIDATA->addData("����", "HPȸ��", "50");
	INIDATA->addData("����", "frameX", "0");
	INIDATA->addData("����", "frameY", "3");
	

	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "MPȸ��", "50");
	INIDATA->addData("������ ����", "frameX", "2");
	INIDATA->addData("������ ����", "frameY", "3");

	INIDATA->iniSave("item");
}

