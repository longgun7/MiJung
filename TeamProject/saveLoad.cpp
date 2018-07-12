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
	INIDATA->addData("��Ÿȣ", "��ǥ x", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getY());
	INIDATA->addData("��Ÿȣ", "��ǥ y", str);
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
	INIDATA->addData("��Ÿȣ", "�ѽ��ǵ�", str);
	
	sprintf_s(str, "%d", _pm->getPlayer2()->getX());
	INIDATA->addData("������", "��ǥ x", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getY());
	INIDATA->addData("������", "��ǥ y", str);
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

	INIDATA->iniSave("�÷��̾�����");

}

void saveLoad::load(string name)
{
	//_pm->getPlayer()->getAttribute().atk
}

saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}
