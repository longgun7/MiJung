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
	INIDATA->addData("아타호", "좌표x", str);
	char str1[128];
	sprintf_s(str1, "%d", (int)_pm->getPlayer()->getY());
	INIDATA->addData("아타호", "좌표y", str1);
	char str2[128];
	sprintf_s(str2, "%d", _pm->getPlayer()->getAttribute().atk);
	INIDATA->addData("아타호", "공격력", str2);
	char str3[128];
	sprintf_s(str3, "%d", _pm->getPlayer()->getAttribute().cri);
	INIDATA->addData("아타호", "크리티컬", str3);
	char str4[128];
	sprintf_s(str4, "%d", _pm->getPlayer()->getAttribute().currentExp);
	INIDATA->addData("아타호", "현재경험치", str4);
	char str5[128];
	sprintf_s(str5, "%d", _pm->getPlayer()->getAttribute().currentHp);
	INIDATA->addData("아타호", "현재체력", str5);
	char str6[128];
	sprintf_s(str6, "%d", _pm->getPlayer()->getAttribute().currentMp);
	INIDATA->addData("아타호", "현재마나", str6);
	char str7[128];
	sprintf_s(str7, "%d", _pm->getPlayer()->getAttribute().def);
	INIDATA->addData("아타호", "현재방어력", str7);
	char str8[128];
	sprintf_s(str8, "%d", _pm->getPlayer()->getAttribute().level);
	INIDATA->addData("아타호", "현재레벨", str8);
	char str9[128];
	sprintf_s(str9, "%d", _pm->getPlayer()->getAttribute().luck);
	INIDATA->addData("아타호", "현재운", str9);
	char str10[128];
	sprintf_s(str10, "%d", _pm->getPlayer()->getAttribute().maxExp);
	INIDATA->addData("아타호", "총경험치", str10);
	char str11[128];
	sprintf_s(str11, "%d", _pm->getPlayer()->getAttribute().maxHp);
	INIDATA->addData("아타호", "총체력", str11);
	char str12[128];
	sprintf_s(str12, "%d", _pm->getPlayer()->getAttribute().maxMp);
	INIDATA->addData("아타호", "총마나", str12);
	char str13[128];
	sprintf_s(str13, "%d", _pm->getPlayer()->getAttribute().speed);
	INIDATA->addData("아타호", "총스피드", str13);

	string temp1 = _pm->getA_WeapItemName();
	INIDATA->addData("아타호", "장착무기", temp1.c_str());

	string temp2 = _pm->getA_ArmorItemName();
	INIDATA->addData("아타호", "장착방어구", temp2.c_str());
	
	string temp3[4];
	for (int i = 0; i < _pm->getVA_WeapInven().size(); ++i)
	{
		char str14[128];
		sprintf_s(str14, "무기%d", i);
		temp3[i] = _pm->getVA_WeapInven()[i].name;
		INIDATA->addData("아타호", str14 , temp3[i].c_str());
	}

	string temp4[4];
	for (int i = 0; i < _pm->getVA_ArmorInven().size(); ++i)
	{
		char str15[128];
		sprintf_s(str15, "방어구%d", i);
		temp4[i] = _pm->getVA_ArmorInven()[i].name;
		INIDATA->addData("아타호", str15, temp4[i].c_str());
	}

	char str16[128];
	sprintf_s(str16, "%d", (int)_pm->getPlayer2()->getX());
	INIDATA->addData("스마슈", "좌표x", str16);
	char str17[128];
	sprintf_s(str17, "%d", (int)_pm->getPlayer2()->getY());
	INIDATA->addData("스마슈", "좌표y", str17);
	char str18[128];
	sprintf_s(str18, "%d", _pm->getPlayer2()->getAttribute().atk);
	INIDATA->addData("스마슈", "공격력", str18);
	char str19[128];
	sprintf_s(str19, "%d", _pm->getPlayer2()->getAttribute().cri);
	INIDATA->addData("스마슈", "크리티컬", str19);
	char str20[128];
	sprintf_s(str20, "%d", _pm->getPlayer2()->getAttribute().currentExp);
	INIDATA->addData("스마슈", "현재경험치", str20);
	char str21[128];
	sprintf_s(str21, "%d", _pm->getPlayer2()->getAttribute().currentHp);
	INIDATA->addData("스마슈", "현재체력", str21);
	char str22[128];
	sprintf_s(str22, "%d", _pm->getPlayer2()->getAttribute().currentMp);
	INIDATA->addData("스마슈", "현재마나", str22);
	char str23[128];
	sprintf_s(str23, "%d", _pm->getPlayer2()->getAttribute().def);
	INIDATA->addData("스마슈", "현재방어력", str23);
	char str24[128];
	sprintf_s(str24, "%d", _pm->getPlayer2()->getAttribute().level);
	INIDATA->addData("스마슈", "현재레벨", str24);
	char str25[128];
	sprintf_s(str25, "%d", _pm->getPlayer2()->getAttribute().luck);
	INIDATA->addData("스마슈", "현재운", str25);
	char str26[128];
	sprintf_s(str26, "%d", _pm->getPlayer2()->getAttribute().maxExp);
	INIDATA->addData("스마슈", "총경험치", str26);
	char str27[128];
	sprintf_s(str27, "%d", _pm->getPlayer2()->getAttribute().maxHp);
	INIDATA->addData("스마슈", "총체력", str27);
	char str28[128];
	sprintf_s(str28 ,"%d", _pm->getPlayer2()->getAttribute().maxMp);
	INIDATA->addData("스마슈", "총마나", str28);
	char str29[128];
	sprintf_s(str29, "%d", _pm->getPlayer2()->getAttribute().speed);
	INIDATA->addData("스마슈", "총스피드", str29);

	string temp5 = _pm->getS_WeapItemName();
	INIDATA->addData("스마슈", "장착무기", temp5.c_str());
	string temp6 = _pm->getS_ArmorItemName();
	INIDATA->addData("스마슈", "장착방어구", temp6.c_str());
	
	string temp7[4];
	temp7[0] = _pm->getVS_WeapInven()[0].name;
	INIDATA->addData("스마슈", "무기0", temp7[0].c_str());
	if (_pm->getVS_WeapInven().size() > 1) 
	{
		temp7[1] = _pm->getVS_WeapInven()[1].name;
		INIDATA->addData("스마슈", "무기1", temp7[1].c_str());
	}
	if (_pm->getVS_WeapInven().size() > 2)
	{
		temp7[2] = _pm->getVS_WeapInven()[2].name;
		INIDATA->addData("스마슈", "무기2", temp7[2].c_str());
	}
	
	if (_pm->getVS_WeapInven().size() > 3)
	{
		temp7[3] = _pm->getVS_WeapInven()[3].name;
		INIDATA->addData("스마슈", "무기2", temp7[3].c_str());
	}

	string temp8[4];
	for (int i = 0; i < _pm->getVS_ArmorInven().size(); ++i)
	{
		char str31[128];
		temp8[i] = _pm->getVS_ArmorInven()[i].name;
		sprintf_s(str31, "방어구%d", i);
		INIDATA->addData("스마슈", str31, temp8[i].c_str());  
	}

	
	string temp9[4];
	if (_pm->getV_PoInven().size() > 0)
	{
		temp9[0] = _pm->getV_PoInven()[0].name;
		INIDATA->addData("포션", "포션0", temp9[0].c_str());
	}

	if (_pm->getV_PoInven().size() > 1)
	{
		temp9[1] = _pm->getV_PoInven()[0].name;
		INIDATA->addData("포션", "포션1", temp9[1].c_str());
	}
	
	
	char str33[128];
	sprintf_s(str33, "%d",_pm->getHpPoIndex());
	INIDATA->addData("포션", "hp포션수", str33);
	
	char str34[128];
	sprintf_s(str34, "%d", _pm->getMpPoIndex());
	INIDATA->addData("포션", "mp포션수", str34);

	char str35[128]; 
	sprintf_s(str35, "%d", _pm->getTagMoney().money);
	INIDATA->addData("골드", "총골드", str35);

	INIDATA->addData("세이브", "세이브여부", "1");

	INIDATA->addData("세이브", "장소세이브", "여관");

	char str36[128];
	sprintf_s(str36, "플레이어정보%d", index);
	INIDATA->iniSave(str36);

}

void saveLoad::loadInt(int index)
{
	char str10[128];
	sprintf_s(str10, "플레이어정보%d", index);

	_pm->getPlayer()->setX(INIDATA->loadDataInterger(str10, "아타호", "좌표x"));
	_pm->getPlayer()->setY(INIDATA->loadDataInterger(str10, "아타호", "좌표y"));
	_pm->getPlayer2()->setX(INIDATA->loadDataInterger(str10, "스마슈", "좌표x"));
	_pm->getPlayer2()->setY(INIDATA->loadDataInterger(str10, "스마슈", "좌표y"));

	_pm->getPlayer()->setAttribute(INIDATA->loadDataInterger(str10, "아타호", "공격력"), INIDATA->loadDataInterger(str10, "아타호", "현재방어력"), INIDATA->loadDataInterger(str10, "아타호", "크리티컬"),
		INIDATA->loadDataInterger(str10, "아타호", "스피드"), INIDATA->loadDataInterger(str10, "아타호", "현재체력"), INIDATA->loadDataInterger(str10, "아타호", "총체력")
		, INIDATA->loadDataInterger(str10, "아타호", "현재마나"), INIDATA->loadDataInterger(str10, "아타호", "총마나"), INIDATA->loadDataInterger(str10, "아타호", "현재경험치"), INIDATA->loadDataInterger(str10, "아타호", "총경험치")
		, INIDATA->loadDataInterger(str10, "아타호", "현재레벨"));
	

	_pm->getPlayer2()->setAttribute(INIDATA->loadDataInterger(str10, "스마슈", "공격력"), INIDATA->loadDataInterger(str10, "스마슈", "현재방어력"), INIDATA->loadDataInterger(str10, "스마슈", "크리티컬"),
		INIDATA->loadDataInterger(str10, "스마슈", "스피드"), INIDATA->loadDataInterger(str10, "스마슈", "현재체력"), INIDATA->loadDataInterger(str10, "스마슈", "총체력")
		, INIDATA->loadDataInterger(str10, "스마슈", "현재마나"), INIDATA->loadDataInterger(str10, "스마슈", "총마나"), INIDATA->loadDataInterger(str10, "스마슈", "현재경험치"), INIDATA->loadDataInterger(str10, "스마슈", "총경험치")
		, INIDATA->loadDataInterger(str10, "스마슈", "현재레벨"));

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "무기%d", i);
		if (INIDATA->loadDataString(str10, "야타호", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "야타호", str));
	}
	
	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "방어구%d", i);
		if (INIDATA->loadDataString(str10, "야타호", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "야타호", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "무기%d", i);
		if (INIDATA->loadDataString(str10, "스마슈", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "스마슈", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "방어구%d", i);
		if (INIDATA->loadDataString(str10, "스마슈", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString(str10, "스마슈", str));
	}

	for (int i = 0; i < 4; ++i)
	{
		char str[128];
		sprintf_s(str, "포션%d", i);
		if (INIDATA->loadDataString(str10, "포션", str) == "") break;
		_pm->getItemValue(INIDATA->loadDataString("str10", "포션", str));
	}

	_pm->setHpPoindex(INIDATA->loadDataInterger(str10,"포션", "hp포션수"));
	_pm->setMpPoindex(INIDATA->loadDataInterger(str10,"포션", "mp포션수"));

	_pm->setA_WeapItemName((INIDATA->loadDataString(str10, "야타호", "장착무기")));
	_pm->setA_ArmorItemName((INIDATA->loadDataString(str10, "야타호", "장착방어구")));

	_pm->setS_WeapItemName((INIDATA->loadDataString(str10, "스마슈", "장착무기")));
	_pm->setS_ArmorItemName((INIDATA->loadDataString(str10, "스마슈", "장착방어구")));

	_pm->setGold(INIDATA->loadDataInterger(str10, "골드", "총골드"));
	
}


saveLoad::saveLoad()
{
}


saveLoad::~saveLoad()
{
}
