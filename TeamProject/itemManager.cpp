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
	_pItem = new item;
	_pItem->init(16);

	_potion = new item;
	_potion->init(1);
	
	_shopItem = new item;
	_shopItem->init(5);

	_shopPotion = new item;
	_shopPotion->init(20);

	setItem();
	
	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	_potion->update();
}

void itemManager::render()
{
	_pItem->render();
	_potion->render();
	_shopItem->render();
	_shopPotion->render();
}

void itemManager::setItem()
{
	INIDATA->addData("��", "�̸�", "��");
	INIDATA->addData("��", "���ݷ�", "5");
	INIDATA->addData("��", "��", "5");
	INIDATA->addData("��", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("��", "frameX", "1");
	INIDATA->addData("��", "frameY", "0");
	

	INIDATA->addData("Ư����", "�̸�", "Ư����");
	INIDATA->addData("Ư����", "���ݷ�", "10");
	INIDATA->addData("Ư����", "��", "15");
	INIDATA->addData("Ư����", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("Ư����", "frameX", "3");
	INIDATA->addData("Ư����", "frameY", "0");
	INIDATA->addData("Ư����", "���", "600");

	INIDATA->addData("ȭ��", "�̸�", "ȭ��");
	INIDATA->addData("ȭ��", "���ݷ�", "15");
	INIDATA->addData("ȭ��", "��", "20");
	INIDATA->addData("ȭ��", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("ȭ��", "frameX", "4");
	INIDATA->addData("ȭ��", "frameY", "0");
	INIDATA->addData("ȭ��", "���", "2000");

	INIDATA->addData("���� �ͽŻ�", "�̸�", "���� �ͽŻ�");
	INIDATA->addData("���� �ͽŻ�", "���ݷ�", "20");
	INIDATA->addData("���� �ͽŻ�", "��", "25");
	INIDATA->addData("���� �ͽŻ�", "ũ��Ƽ��Ȯ��", "0");
	INIDATA->addData("���� �ͽŻ�", "frameX", "5");
	INIDATA->addData("���� �ͽŻ�", "frameY", "0");
	INIDATA->addData("���� �ͽŻ�", "���", "4000");
	
	INIDATA->addData("�ǹ��� ����", "�̸�", "�ǹ��� ����");
	INIDATA->addData("�ǹ��� ����", "����", "5");
	INIDATA->addData("�ǹ��� ����", "���ǵ�", "7");
	INIDATA->addData("�ǹ��� ����", "frameX", "7");
	INIDATA->addData("�ǹ��� ����", "frameY", "0");
	
	INIDATA->addData("ȣ���� ����", "�̸�", "ȣ���� ����");
	INIDATA->addData("ȣ���� ����", "����", "10");
	INIDATA->addData("ȣ���� ����", "���ǵ�", "12");
	INIDATA->addData("ȣ���� ����", "frameX", "9");
	INIDATA->addData("ȣ���� ����", "frameY", "0");
	INIDATA->addData("ȣ���� ����", "���", "400");

	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "����","15");
	INIDATA->addData("������ ����", "���ǵ�", "14");
	INIDATA->addData("������ ����", "frameX", "10");
	INIDATA->addData("������ ����", "frameY", "0");
	INIDATA->addData("������ ����", "���", "1000");

	INIDATA->addData("��ȣ ����", "�̸�", "��ȣ ����");
	INIDATA->addData("��ȣ ����", "����", "20");
	INIDATA->addData("��ȣ ����", "���ǵ�", "16");
	INIDATA->addData("��ȣ ����", "frameX", "11");
	INIDATA->addData("��ȣ ����", "frameY", "0");
	INIDATA->addData("��ȣ ����", "���", "2000");

	INIDATA->addData("û�浵", "�̸�", "û�浵");
	INIDATA->addData("û�浵", "���ݷ�", "5");
	INIDATA->addData("û�浵", "��", "0");
	INIDATA->addData("û�浵", "ũ��Ƽ��Ȯ��", "12");
	INIDATA->addData("û�浵", "frameX", "1");
	INIDATA->addData("û�浵", "frameY", "2");

	INIDATA->addData("��Ÿ�� ����", "�̸�", "��Ÿ�� ����");
	INIDATA->addData("��Ÿ�� ����", "���ݷ�", "10");
	INIDATA->addData("��Ÿ�� ����", "��", "0");
	INIDATA->addData("��Ÿ�� ����", "ũ��Ƽ��Ȯ��", "16");
	INIDATA->addData("��Ÿ�� ����", "frameX", "2");
	INIDATA->addData("��Ÿ�� ����", "frameY", "2");
	INIDATA->addData("��Ÿ�� ����", "���", "600");

	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "���ݷ�", "15");
	INIDATA->addData("������ ����", "��", "0");
	INIDATA->addData("������ ����", "ũ��Ƽ��Ȯ��", "18");
	INIDATA->addData("������ ����", "frameX", "4");
	INIDATA->addData("������ ����", "frameY", "2");
	INIDATA->addData("������ ����", "���", "2000");

	INIDATA->addData("���ξƼ���", "�̸�", "���ξƼ���");
	INIDATA->addData("���ξƼ���", "���ݷ�", "20");
	INIDATA->addData("���ξƼ���", "��", "0");
	INIDATA->addData("���ξƼ���", "ũ��Ƽ��Ȯ��", "20");
	INIDATA->addData("���ξƼ���", "frameX", "5");
	INIDATA->addData("���ξƼ���", "frameY", "2");
	INIDATA->addData("���ξƼ���", "���", "4000");

	INIDATA->addData("���� ����", "�̸�", "���� ����");
	INIDATA->addData("���� ����", "����", "5");
	INIDATA->addData("���� ����", "���ǵ�", "5");
	INIDATA->addData("���� ����", "frameX", "7");
	INIDATA->addData("���� ����", "frameY", "2");
	
	INIDATA->addData("ö�� ����", "�̸�", "ö�� ����");
	INIDATA->addData("ö�� ����", "����", "10");
	INIDATA->addData("ö�� ����", "���ǵ�", "4");
	INIDATA->addData("ö�� ����", "frameX", "9");
	INIDATA->addData("ö�� ����", "frameY", "2");
	INIDATA->addData("ö�� ����", "���", "400");

	INIDATA->addData("�Ʈ ��Ʈ", "�̸�", "�Ʈ ��Ʈ");
	INIDATA->addData("�Ʈ ��Ʈ", "����", "15");
	INIDATA->addData("�Ʈ ��Ʈ", "���ǵ�", "6");
	INIDATA->addData("�Ʈ ��Ʈ", "frameX", "10");
	INIDATA->addData("�Ʈ ��Ʈ", "frameY", "2");
	INIDATA->addData("�Ʈ ��Ʈ", "���", "1000");

	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "����", "20");
	INIDATA->addData("������ ����", "���ǵ�", "6");
	INIDATA->addData("������ ����", "frameX", "11");
	INIDATA->addData("������ ����", "frameY", "2");
	INIDATA->addData("������ ����", "���", "2000");
	
	INIDATA->addData("����", "�̸�", "����");
	INIDATA->addData("����", "HPȸ��", "50");
	INIDATA->addData("����", "frameX", "0");
	INIDATA->addData("����", "frameY", "3");
	INIDATA->addData("����", "���", "10");

	INIDATA->addData("������ ����", "�̸�", "������ ����");
	INIDATA->addData("������ ����", "MPȸ��", "50");
	INIDATA->addData("������ ����", "frameX", "3");
	INIDATA->addData("������ ����", "frameY", "3");
	INIDATA->addData("������ ����", "���", "200");

	INIDATA->iniSave("item");
}

void itemManager::itemMakeSet(string itemName, float x, float y)
{
	_pItem->makeItem(itemName, x, y);
}

void itemManager::shopItemSet(string itemName, float x, float y)
{
	_shopItem->makeItem(itemName, x, y);
}

void itemManager::potionMakeSet(string potionName, float x, float y)
{
	_potion->makepotion(potionName, x, y);
}

void itemManager::shopPotionSet(string potionName, float x, float y)
{
	_shopPotion->makepotion(potionName, x, y);
}




