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

	_a_Weapon->makeItem("맨주먹", 100, 100);
	_a_Weapon->makeItem("술", 200, 100);
	_a_Weapon->makeItem("노주", 300, 100);
	_a_Weapon->makeItem("특급주", 400, 100);

	_a_Armor->makeItem("인민복", 100, 150);
	_a_Armor->makeItem("권법가 도복", 200, 150);
	_a_Armor->makeItem("달인의 도복", 300, 150);
	_a_Armor->makeItem("호랑이 도복", 400, 150);

	_s_Weapon->makeItem("닌자도", 100, 200);
	_s_Weapon->makeItem("청룡도", 200, 200);
	_s_Weapon->makeItem("불타는 마검", 300, 200);
	_s_Weapon->makeItem("그레이트소드", 400, 200);

	_s_Armor->makeItem("스마슈타이츠", 100, 250);
	_s_Armor->makeItem("가죽 갑옷", 200, 250);
	_s_Armor->makeItem("흑장속", 300, 250);
	_s_Armor->makeItem("철편 갑옷", 400, 250);
	
	_potion->makepotion("약초", 100, 300);
	_potion->makepotion("마법의 물약", 200, 300);

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
	INIDATA->addData("맨주먹", "이름", "맨주먹");
	INIDATA->addData("맨주먹", "공격력", "0");
	INIDATA->addData("맨주먹", "운", "0");
	INIDATA->addData("맨주먹", "크리티컬확률", "0");
	INIDATA->addData("맨주먹", "frameX", "0");
	INIDATA->addData("맨주먹", "frameY", "0");

	INIDATA->addData("술", "이름", "술");
	INIDATA->addData("술", "공격력", "0");
	INIDATA->addData("술", "운", "5");
	INIDATA->addData("술", "크리티컬확률", "0");
	INIDATA->addData("술", "frameX", "1");
	INIDATA->addData("술", "frameY", "0");

	INIDATA->addData("노주", "이름", "노주");
	INIDATA->addData("노주", "공격력", "0");
	INIDATA->addData("노주", "운", "10");
	INIDATA->addData("노주", "크리티컬확률", "0");
	INIDATA->addData("노주", "frameX", "2");
	INIDATA->addData("노주", "frameY", "0");
	
	INIDATA->addData("특급주", "이름", "특급주");
	INIDATA->addData("특급주", "공격력", "0");
	INIDATA->addData("특급주", "운", "15");
	INIDATA->addData("특급주", "크리티컬확률", "0");
	INIDATA->addData("특급주", "frameX", "3");
	INIDATA->addData("특급주", "frameY", "0");
	
	INIDATA->addData("인민복", "이름", "인민복");
	INIDATA->addData("인민복", "방어력", "10");
	INIDATA->addData("인민복", "스피드", "5");
	INIDATA->addData("인민복", "frameX", "6");
	INIDATA->addData("인민복", "frameY", "0");
	
	INIDATA->addData("권법가 도복", "이름", "권법가 도복");
	INIDATA->addData("권법가 도복", "방어력", "15");
	INIDATA->addData("권법가 도복", "스피드", "7");
	INIDATA->addData("권법가 도복", "frameX", "7");
	INIDATA->addData("권법가 도복", "frameY", "0");
	
	INIDATA->addData("달인의 도복", "이름", "달인의 도복");
	INIDATA->addData("달인의 도복", "방어력", "20");
	INIDATA->addData("달인의 도복", "스피드", "10");
	INIDATA->addData("달인의 도복", "frameX", "8");
	INIDATA->addData("달인의 도복", "frameY", "0");
	
	INIDATA->addData("호랑이 도복", "이름", "호랑이 도복");
	INIDATA->addData("호랑이 도복", "방어력", "25");
	INIDATA->addData("호랑이 도복", "스피드", "12");
	INIDATA->addData("호랑이 도복", "frameX", "9");
	INIDATA->addData("호랑이 도복", "frameY", "0");
	
	INIDATA->addData("닌자도", "이름", "닌자도");
	INIDATA->addData("닌자도", "공격력", "20");
	INIDATA->addData("닌자도", "운", "0");
	INIDATA->addData("닌자도", "크리티컬확률", "10");
	INIDATA->addData("닌자도", "frameX", "0");
	INIDATA->addData("닌자도", "frameY", "2");
	

	INIDATA->addData("청룡도", "이름", "청룡도");
	INIDATA->addData("청룡도", "공격력", "28");
	INIDATA->addData("청룡도", "운", "0");
	INIDATA->addData("청룡도", "크리티컬확률", "12");
	INIDATA->addData("청룡도", "frameX", "1");
	INIDATA->addData("청룡도", "frameY", "2");
	

	INIDATA->addData("불타는 마검", "이름", "불타는 마검");
	INIDATA->addData("불타는 마검", "공격력", "33");
	INIDATA->addData("불타는 마검", "운", "0");
	INIDATA->addData("불타는 마검", "크리티컬확률", "14");
	INIDATA->addData("불타는 마검", "frameX", "2");
	INIDATA->addData("불타는 마검", "frameY", "2");
	

	INIDATA->addData("그레이트소드", "이름", "그레이트소드");
	INIDATA->addData("그레이트소드", "공격력", "41");
	INIDATA->addData("그레이트소드", "운", "0");
	INIDATA->addData("그레이트소드", "크리티컬확률", "16");
	INIDATA->addData("그레이트소드", "frameX", "3");
	INIDATA->addData("그레이트소드", "frameY", "2");
	

	INIDATA->addData("스마슈타이츠", "이름", "스마슈타이츠");
	INIDATA->addData("스마슈타이츠", "방어력", "10");
	INIDATA->addData("스마슈타이츠", "스피드", "10");
	INIDATA->addData("스마슈타이츠", "frameX", "6");
	INIDATA->addData("스마슈타이츠", "frameY", "2");
	

	INIDATA->addData("가죽 갑옷", "이름", "가죽 갑옷");
	INIDATA->addData("가죽 갑옷", "방어력", "18");
	INIDATA->addData("가죽 갑옷", "스피드", "5");
	INIDATA->addData("가죽 갑옷", "frameX", "7");
	INIDATA->addData("가죽 갑옷", "frameY", "2");
	

	INIDATA->addData("흑장속", "이름", "흑장속");
	INIDATA->addData("흑장속", "방어력", "25");
	INIDATA->addData("흑장속", "스피드", "15");
	INIDATA->addData("흑장속", "frameX", "8");
	INIDATA->addData("흑장속", "frameY", "2");
	

	INIDATA->addData("철편 갑옷", "이름", "철편 갑옷");
	INIDATA->addData("철편 갑옷", "방어력", "33");
	INIDATA->addData("철편 갑옷", "스피드", "4");
	INIDATA->addData("철편 갑옷", "frameX", "9");
	INIDATA->addData("철편 갑옷", "frameY", "2");
	

	INIDATA->addData("약초", "이름", "약초");
	INIDATA->addData("약초", "HP회복", "50");
	INIDATA->addData("약초", "frameX", "0");
	INIDATA->addData("약초", "frameY", "3");
	

	INIDATA->addData("마법의 물약", "이름", "마법의 물약");
	INIDATA->addData("마법의 물약", "MP회복", "50");
	INIDATA->addData("마법의 물약", "frameX", "2");
	INIDATA->addData("마법의 물약", "frameY", "3");

	INIDATA->iniSave("item");
}

