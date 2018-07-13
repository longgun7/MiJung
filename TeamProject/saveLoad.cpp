#include "stdafx.h"
#include "saveLoad.h"
#include "playerManager.h"

HRESULT saveLoad::init()
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	
	return S_OK;
}

void saveLoad::save(int index)
{
	char str[128];
	sprintf_s(str, "%d", (int)_pm->getPlayer()->getX());
	INIDATA->addData("��Ÿȣ", "��ǥx", str);
	char str1[128];
	sprintf_s(str1, "%d", (int)_pm->getPlayer()->getY());
	INIDATA->addData("��Ÿȣ", "��ǥy", str1);
	char str2[128];
	sprintf_s(str2, "%d", _pm->getPlayer()->getAttribute().atk);
	INIDATA->addData("��Ÿȣ", "���ݷ�", str2);
	char str3[128];
	sprintf_s(str3, "%d", _pm->getPlayer()->getAttribute().cri);
	INIDATA->addData("��Ÿȣ", "ũ��Ƽ��", str3);
	char str4[128];
	sprintf_s(str4, "%d", _pm->getPlayer()->getAttribute().currentExp);
	INIDATA->addData("��Ÿȣ", "�������ġ", str4);
	char str5[128];
	sprintf_s(str5, "%d", _pm->getPlayer()->getAttribute().currentHp);
	INIDATA->addData("��Ÿȣ", "����ü��", str5);
	char str6[128];
	sprintf_s(str6, "%d", _pm->getPlayer()->getAttribute().currentMp);
	INIDATA->addData("��Ÿȣ", "���縶��", str6);
	char str7[128];
	sprintf_s(str7, "%d", _pm->getPlayer()->getAttribute().def);
	INIDATA->addData("��Ÿȣ", "�������", str7);
	char str8[128];
	sprintf_s(str8, "%d", _pm->getPlayer()->getAttribute().level);
	INIDATA->addData("��Ÿȣ", "���緹��", str8);
	char str9[128];
	sprintf_s(str9, "%d", _pm->getPlayer()->getAttribute().luck);
	INIDATA->addData("��Ÿȣ", "�����", str9);
	char str10[128];
	sprintf_s(str10, "%d", _pm->getPlayer()->getAttribute().maxExp);
	INIDATA->addData("��Ÿȣ", "�Ѱ���ġ", str10);
	char str11[128];
	sprintf_s(str11, "%d", _pm->getPlayer()->getAttribute().maxHp);
	INIDATA->addData("��Ÿȣ", "��ü��", str11);
	char str12[128];
	sprintf_s(str12, "%d", _pm->getPlayer()->getAttribute().maxMp);
	INIDATA->addData("��Ÿȣ", "�Ѹ���", str12);
	char str13[128];
	sprintf_s(str13, "%d", _pm->getPlayer()->getAttribute().speed);
	INIDATA->addData("��Ÿȣ", "�ѽ��ǵ�", str13);

	string temp1 = _pm->getA_WeapItemName();
	INIDATA->addData("��Ÿȣ", "��������", temp1.c_str());

	string temp2 = _pm->getA_ArmorItemName();
	INIDATA->addData("��Ÿȣ", "������", temp2.c_str());
	
	string temp3[4];
	for (int i = 0; i < _pm->getVA_WeapInven().size(); ++i)
	{
		char str14[128];
		sprintf_s(str14, "����%d", i);
		temp3[i] = _pm->getVA_WeapInven()[i].name;
		INIDATA->addData("��Ÿȣ", str14 , temp3[i].c_str());
	}

	string temp4[4];
	for (int i = 0; i < _pm->getVA_ArmorInven().size(); ++i)
	{
		char str15[128];
		sprintf_s(str15, "��%d", i);
		temp4[i] = _pm->getVA_ArmorInven()[i].name;
		INIDATA->addData("��Ÿȣ", str15, temp4[i].c_str());
	}

	char str16[128];
	sprintf_s(str16, "%d", (int)_pm->getPlayer2()->getX());
	INIDATA->addData("������", "��ǥx", str16);
	char str17[128];
	sprintf_s(str17, "%d", (int)_pm->getPlayer2()->getY());
	INIDATA->addData("������", "��ǥy", str17);
	char str18[128];
	sprintf_s(str18, "%d", _pm->getPlayer2()->getAttribute().atk);
	INIDATA->addData("������", "���ݷ�", str18);
	char str19[128];
	sprintf_s(str19, "%d", _pm->getPlayer2()->getAttribute().cri);
	INIDATA->addData("������", "ũ��Ƽ��", str19);
	char str20[128];
	sprintf_s(str20, "%d", _pm->getPlayer2()->getAttribute().currentExp);
	INIDATA->addData("������", "�������ġ", str20);
	char str21[128];
	sprintf_s(str21, "%d", _pm->getPlayer2()->getAttribute().currentHp);
	INIDATA->addData("������", "����ü��", str21);
	char str22[128];
	sprintf_s(str22, "%d", _pm->getPlayer2()->getAttribute().currentMp);
	INIDATA->addData("������", "���縶��", str22);
	char str23[128];
	sprintf_s(str23, "%d", _pm->getPlayer2()->getAttribute().def);
	INIDATA->addData("������", "�������", str23);
	char str24[128];
	sprintf_s(str24, "%d", _pm->getPlayer2()->getAttribute().level);
	INIDATA->addData("������", "���緹��", str24);
	char str25[128];
	sprintf_s(str25, "%d", _pm->getPlayer2()->getAttribute().luck);
	INIDATA->addData("������", "�����", str25);
	char str26[128];
	sprintf_s(str26, "%d", _pm->getPlayer2()->getAttribute().maxExp);
	INIDATA->addData("������", "�Ѱ���ġ", str26);
	char str27[128];
	sprintf_s(str27, "%d", _pm->getPlayer2()->getAttribute().maxHp);
	INIDATA->addData("������", "��ü��", str27);
	char str28[128];
	sprintf_s(str28 ,"%d", _pm->getPlayer2()->getAttribute().maxMp);
	INIDATA->addData("������", "�Ѹ���", str28);
	char str29[128];
	sprintf_s(str29, "%d", _pm->getPlayer2()->getAttribute().speed);
	INIDATA->addData("������", "�ѽ��ǵ�", str29);

	string temp5 = _pm->getS_WeapItemName();
	INIDATA->addData("������", "��������", temp5.c_str());
	string temp6 = _pm->getS_ArmorItemName();
	INIDATA->addData("������", "������", temp6.c_str());
	
	string temp7[4];
	temp7[0] = _pm->getVS_WeapInven()[0].name;
	INIDATA->addData("������", "����0", temp7[0].c_str());
	if (_pm->getVS_WeapInven().size() > 1) 
	{
		temp7[1] = _pm->getVS_WeapInven()[1].name;
		INIDATA->addData("������", "����1", temp7[1].c_str());
	}
	if (_pm->getVS_WeapInven().size() > 2)
	{
		temp7[2] = _pm->getVS_WeapInven()[2].name;
		INIDATA->addData("������", "����2", temp7[2].c_str());
	}
	
	if (_pm->getVS_WeapInven().size() > 3)
	{
		temp7[3] = _pm->getVS_WeapInven()[3].name;
		INIDATA->addData("������", "����2", temp7[3].c_str());
	}

	string temp8[4];
	for (int i = 0; i < _pm->getVS_ArmorInven().size(); ++i)
	{
		char str31[128];
		temp8[i] = _pm->getVS_ArmorInven()[i].name;
		sprintf_s(str31, "��%d", i);
		INIDATA->addData("������", str31, temp8[i].c_str());  
	}

	
	string temp9[4];
	if (_pm->getV_PoInven().size() > 0)
	{
		temp9[0] = _pm->getV_PoInven()[0].name;
		INIDATA->addData("����", "����0", temp9[0].c_str());
	}

	if (_pm->getV_PoInven().size() > 1)
	{
		temp9[1] = _pm->getV_PoInven()[0].name;
		INIDATA->addData("����", "����1", temp9[1].c_str());
	}
	
	
	char str33[128];
	sprintf_s(str33, "%d",_pm->getHpPoIndex());
	INIDATA->addData("����", "hp���Ǽ�", str33);
	
	char str34[128];
	sprintf_s(str34, "%d", _pm->getMpPoIndex());
	INIDATA->addData("����", "mp���Ǽ�", str34);

	char str35[128]; 
	sprintf_s(str35, "%d", _pm->getTagMoney().money);
	INIDATA->addData("���", "�Ѱ��", str35);

	INIDATA->addData("���̺�", "���̺꿩��", "1");

	INIDATA->addData("���̺�", "��Ҽ��̺�", "����");

	char str36[128];
	sprintf_s(str36, "�÷��̾�����%d", index);
	INIDATA->iniSave(str36);

}

void saveLoad::loadInt(int index)
{
	char str10[128];
	sprintf_s(str10, "�÷��̾�����%d", index);

	_pm->getPlayer()->setX(INIDATA->loadDataInterger(str10, "��Ÿȣ", "��ǥx"));
	_pm->getPlayer()->setY(INIDATA->loadDataInterger(str10, "��Ÿȣ", "��ǥy"));
	_pm->getPlayer2()->setX(INIDATA->loadDataInterger(str10, "������", "��ǥx"));
	_pm->getPlayer2()->setY(INIDATA->loadDataInterger(str10, "������", "��ǥy"));

	_pm->getPlayer()->setAttribute(INIDATA->loadDataInterger(str10, "��Ÿȣ", "���ݷ�"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "�������"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "ũ��Ƽ��"),
		INIDATA->loadDataInterger(str10, "��Ÿȣ", "���ǵ�"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "����ü��"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "��ü��")
		, INIDATA->loadDataInterger(str10, "��Ÿȣ", "���縶��"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "�Ѹ���"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "�������ġ"), INIDATA->loadDataInterger(str10, "��Ÿȣ", "�Ѱ���ġ")
		, INIDATA->loadDataInterger(str10, "��Ÿȣ", "���緹��"));
	

	_pm->getPlayer2()->setAttribute(INIDATA->loadDataInterger(str10, "������", "���ݷ�"), INIDATA->loadDataInterger(str10, "������", "�������"), INIDATA->loadDataInterger(str10, "������", "ũ��Ƽ��"),
		INIDATA->loadDataInterger(str10, "������", "���ǵ�"), INIDATA->loadDataInterger(str10, "������", "����ü��"), INIDATA->loadDataInterger(str10, "������", "��ü��")
		, INIDATA->loadDataInterger(str10, "������", "���縶��"), INIDATA->loadDataInterger(str10, "������", "�Ѹ���"), INIDATA->loadDataInterger(str10, "������", "�������ġ"), INIDATA->loadDataInterger(str10, "������", "�Ѱ���ġ")
		, INIDATA->loadDataInterger(str10, "������", "���緹��"));

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "����%d", i);
		if (INIDATA->loadDataString(str10, "��Ÿȣ", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "��Ÿȣ", str));
	}
	
	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "��%d", i);
		if (INIDATA->loadDataString(str10, "��Ÿȣ", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "��Ÿȣ", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "����%d", i);
		if (INIDATA->loadDataString(str10, "������", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "������", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "��%d", i);
		if (INIDATA->loadDataString(str10, "������", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "������", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "����%d", i);
		if (INIDATA->loadDataString(str10, "����", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("str10", "����", str));
	}

	_pm->setHpPoindex(INIDATA->loadDataInterger(str10,"����", "hp���Ǽ�"));
	_pm->setMpPoindex(INIDATA->loadDataInterger(str10,"����", "mp���Ǽ�"));

	_pm->setA_WeapItemName((INIDATA->loadDataString(str10, "��Ÿȣ", "��������")));
	_pm->setA_ArmorItemName((INIDATA->loadDataString(str10, "��Ÿȣ", "������")));

	_pm->setS_WeapItemName((INIDATA->loadDataString(str10, "������", "��������")));
	_pm->setS_ArmorItemName((INIDATA->loadDataString(str10, "������", "������")));

	_pm->setGold(INIDATA->loadDataInterger(str10, "���", "�Ѱ��"));
	
}


saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}
