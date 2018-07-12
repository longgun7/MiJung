#include "stdafx.h"
#include "saveLoad.h"
#include "playerManager.h"

HRESULT saveLoad::init()
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	
	
	return S_OK;
}

void saveLoad::save()
{
	char str[3000];
	sprintf_s(str, "%d", _pm->getPlayer()->getX());
	INIDATA->addData("��Ÿȣ", "��ǥx", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getY());
	INIDATA->addData("��Ÿȣ", "��ǥy", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().atk);
	INIDATA->addData("��Ÿȣ", "���ݷ�", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().cri);
	INIDATA->addData("��Ÿȣ", "ũ��Ƽ��", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentExp);
	INIDATA->addData("��Ÿȣ", "�������ġ", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentHp);
	INIDATA->addData("��Ÿȣ", "����ü��", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentMp);
	INIDATA->addData("��Ÿȣ", "���縶��", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().def);
	INIDATA->addData("��Ÿȣ", "�������", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().level);
	INIDATA->addData("��Ÿȣ", "���緹��", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().luck);
	INIDATA->addData("��Ÿȣ", "�����", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxExp);
	INIDATA->addData("��Ÿȣ", "�Ѱ���ġ", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxHp);
	INIDATA->addData("��Ÿȣ", "��ü��", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxMp);
	INIDATA->addData("��Ÿȣ", "�Ѹ���", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().speed);

	for (int i = 0; i < _pm->getVA_WeapInven().size(); ++i)
	{
		sprintf_s(str, "����%d", i);
		INIDATA->addData("��Ÿȣ", str, _pm->getVA_WeapInven()[i].name.c_str());
	}
	for (int i = 0; i < _pm->getVA_ArmorInven().size(); ++i)
	{
		sprintf_s(str, "��%d", i);
		INIDATA->addData("��Ÿȣ", str, _pm->getVA_ArmorInven()[i].name.c_str());
	}

	sprintf_s(str, "%d", _pm->getPlayer2()->getX());
	INIDATA->addData("������", "��ǥx", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getY());
	INIDATA->addData("������", "��ǥy", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().atk);
	INIDATA->addData("������", "���ݷ�", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().cri);
	INIDATA->addData("������", "ũ��Ƽ��", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentExp);
	INIDATA->addData("������", "�������ġ", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentHp);
	INIDATA->addData("������", "����ü��", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentMp);
	INIDATA->addData("������", "���縶��", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().def);
	INIDATA->addData("������", "�������", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().level);
	INIDATA->addData("������", "���緹��", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().luck);
	INIDATA->addData("������", "�����", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxExp);
	INIDATA->addData("������", "�Ѱ���ġ", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxHp);
	INIDATA->addData("������", "��ü��", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxMp);
	INIDATA->addData("������", "�Ѹ���", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().speed);
	INIDATA->addData("������", "�ѽ��ǵ�", str);

	for (int i = 0; i < _pm->getVS_WeapInven().size(); ++i)
	{
		sprintf_s(str, "����%d", i);
		INIDATA->addData("������", str, _pm->getVS_WeapInven()[i].name.c_str());
	}

	for (int i = 0; i < _pm->getVS_ArmorInven().size(); ++i)
	{
		sprintf_s(str, "��%d", i);
		INIDATA->addData("������", str, _pm->getVS_ArmorInven()[i].name.c_str());
	}
	


	INIDATA->iniSave("�÷��̾�����");

}

void saveLoad::loadInt()
{
	_pm->getPlayer()->setAttribute(INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "���ݷ�"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "�������"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "ũ��Ƽ��"),
		INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "���ǵ�"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "����ü��"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "��ü��")
		, INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "���縶��"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "�Ѹ���"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "�������ġ"), INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "�Ѱ���ġ")
		, INIDATA->loadDataInterger("�÷��̾�����", "��Ÿȣ", "���緹��"));
	

	_pm->getPlayer2()->setAttribute(INIDATA->loadDataInterger("�÷��̾�����", "������", "���ݷ�"), INIDATA->loadDataInterger("�÷��̾�����", "������", "�������"), INIDATA->loadDataInterger("�÷��̾�����", "������", "ũ��Ƽ��"),
		INIDATA->loadDataInterger("�÷��̾�����", "������", "���ǵ�"), INIDATA->loadDataInterger("�÷��̾�����", "������", "����ü��"), INIDATA->loadDataInterger("�÷��̾�����", "������", "��ü��")
		, INIDATA->loadDataInterger("�÷��̾�����", "������", "���縶��"), INIDATA->loadDataInterger("�÷��̾�����", "������", "�Ѹ���"), INIDATA->loadDataInterger("�÷��̾�����", "������", "�������ġ"), INIDATA->loadDataInterger("�÷��̾�����", "������", "�Ѱ���ġ")
		, INIDATA->loadDataInterger("�÷��̾�����", "������", "���緹��"));

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "����%d", i);
		if (INIDATA->loadDataString("�÷��̾�����", "��Ÿȣ", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("�÷��̾�����", "��Ÿȣ", str));
	}
	
	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "��%d", i);
		if (INIDATA->loadDataString("�÷��̾�����", "��Ÿȣ", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("�÷��̾�����", "��Ÿȣ", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "����%d", i);
		if (INIDATA->loadDataString("�÷��̾�����", "������", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("�÷��̾�����", "������", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "��%d", i);
		if (INIDATA->loadDataString("�÷��̾�����", "������", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("�÷��̾�����", "������", str));
	}

}


saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}
