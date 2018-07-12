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
	INIDATA->addData("아타호", "좌표x", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getY());
	INIDATA->addData("아타호", "좌표y", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().atk);
	INIDATA->addData("아타호", "공격력", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().cri);
	INIDATA->addData("아타호", "크리티컬", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentExp);
	INIDATA->addData("아타호", "현재경험치", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentHp);
	INIDATA->addData("아타호", "현재체력", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().currentMp);
	INIDATA->addData("아타호", "현재마나", str);	
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().def);
	INIDATA->addData("아타호", "현재방어력", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().level);
	INIDATA->addData("아타호", "현재레벨", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().luck);
	INIDATA->addData("아타호", "현재운", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxExp);
	INIDATA->addData("아타호", "총경험치", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxHp);
	INIDATA->addData("아타호", "총체력", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().maxMp);
	INIDATA->addData("아타호", "총마나", str);
	sprintf_s(str, "%d", _pm->getPlayer()->getAttribute().speed);

	for (int i = 0; i < _pm->getVA_WeapInven().size(); ++i)
	{
		sprintf_s(str, "무기%d", i);
		INIDATA->addData("아타호", str, _pm->getVA_WeapInven()[i].name.c_str());
	}
	for (int i = 0; i < _pm->getVA_ArmorInven().size(); ++i)
	{
		sprintf_s(str, "방어구%d", i);
		INIDATA->addData("아타호", str, _pm->getVA_ArmorInven()[i].name.c_str());
	}

	sprintf_s(str, "%d", _pm->getPlayer2()->getX());
	INIDATA->addData("스마슈", "좌표x", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getY());
	INIDATA->addData("스마슈", "좌표y", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().atk);
	INIDATA->addData("스마슈", "공격력", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().cri);
	INIDATA->addData("스마슈", "크리티컬", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentExp);
	INIDATA->addData("스마슈", "현재경험치", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentHp);
	INIDATA->addData("스마슈", "현재체력", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().currentMp);
	INIDATA->addData("스마슈", "현재마나", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().def);
	INIDATA->addData("스마슈", "현재방어력", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().level);
	INIDATA->addData("스마슈", "현재레벨", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().luck);
	INIDATA->addData("스마슈", "현재운", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxExp);
	INIDATA->addData("스마슈", "총경험치", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxHp);
	INIDATA->addData("스마슈", "총체력", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().maxMp);
	INIDATA->addData("스마슈", "총마나", str);
	sprintf_s(str, "%d", _pm->getPlayer2()->getAttribute().speed);
	INIDATA->addData("스마슈", "총스피드", str);

	for (int i = 0; i < _pm->getVS_WeapInven().size(); ++i)
	{
		sprintf_s(str, "무기%d", i);
		INIDATA->addData("스마슈", str, _pm->getVS_WeapInven()[i].name.c_str());
	}

	for (int i = 0; i < _pm->getVS_ArmorInven().size(); ++i)
	{
		sprintf_s(str, "방어구%d", i);
		INIDATA->addData("스마슈", str, _pm->getVS_ArmorInven()[i].name.c_str());
	}
	


	INIDATA->iniSave("플레이어정보");

}

void saveLoad::loadInt()
{
	_pm->getPlayer()->setAttribute(INIDATA->loadDataInterger("플레이어정보", "아타호", "공격력"), INIDATA->loadDataInterger("플레이어정보", "아타호", "현재방어력"), INIDATA->loadDataInterger("플레이어정보", "아타호", "크리티컬"),
		INIDATA->loadDataInterger("플레이어정보", "아타호", "스피드"), INIDATA->loadDataInterger("플레이어정보", "아타호", "현재체력"), INIDATA->loadDataInterger("플레이어정보", "아타호", "총체력")
		, INIDATA->loadDataInterger("플레이어정보", "아타호", "현재마나"), INIDATA->loadDataInterger("플레이어정보", "아타호", "총마나"), INIDATA->loadDataInterger("플레이어정보", "아타호", "현재경험치"), INIDATA->loadDataInterger("플레이어정보", "아타호", "총경험치")
		, INIDATA->loadDataInterger("플레이어정보", "아타호", "현재레벨"));
	

	_pm->getPlayer2()->setAttribute(INIDATA->loadDataInterger("플레이어정보", "스마슈", "공격력"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "현재방어력"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "크리티컬"),
		INIDATA->loadDataInterger("플레이어정보", "스마슈", "스피드"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "현재체력"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "총체력")
		, INIDATA->loadDataInterger("플레이어정보", "스마슈", "현재마나"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "총마나"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "현재경험치"), INIDATA->loadDataInterger("플레이어정보", "스마슈", "총경험치")
		, INIDATA->loadDataInterger("플레이어정보", "스마슈", "현재레벨"));

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "무기%d", i);
		if (INIDATA->loadDataString("플레이어정보", "야타호", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("플레이어정보", "야타호", str));
	}
	
	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "방어구%d", i);
		if (INIDATA->loadDataString("플레이어정보", "야타호", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("플레이어정보", "야타호", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "무기%d", i);
		if (INIDATA->loadDataString("플레이어정보", "스마슈", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("플레이어정보", "스마슈", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "방어구%d", i);
		if (INIDATA->loadDataString("플레이어정보", "스마슈", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("플레이어정보", "스마슈", str));
	}

}


saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}
