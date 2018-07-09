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
	INIDATA->addData("술", "이름", "술");
	INIDATA->addData("술", "공격력", "5");
	INIDATA->addData("술", "운", "5");
	INIDATA->addData("술", "크리티컬확률", "0");
	INIDATA->addData("술", "frameX", "1");
	INIDATA->addData("술", "frameY", "0");
	

	INIDATA->addData("특급주", "이름", "특급주");
	INIDATA->addData("특급주", "공격력", "10");
	INIDATA->addData("특급주", "운", "15");
	INIDATA->addData("특급주", "크리티컬확률", "0");
	INIDATA->addData("특급주", "frameX", "3");
	INIDATA->addData("특급주", "frameY", "0");
	INIDATA->addData("특급주", "비용", "600");

	INIDATA->addData("화주", "이름", "화주");
	INIDATA->addData("화주", "공격력", "15");
	INIDATA->addData("화주", "운", "20");
	INIDATA->addData("화주", "크리티컬확률", "0");
	INIDATA->addData("화주", "frameX", "4");
	INIDATA->addData("화주", "frameY", "0");
	INIDATA->addData("화주", "비용", "2000");

	INIDATA->addData("명주 귀신살", "이름", "명주 귀신살");
	INIDATA->addData("명주 귀신살", "공격력", "20");
	INIDATA->addData("명주 귀신살", "운", "25");
	INIDATA->addData("명주 귀신살", "크리티컬확률", "0");
	INIDATA->addData("명주 귀신살", "frameX", "5");
	INIDATA->addData("명주 귀신살", "frameY", "0");
	INIDATA->addData("명주 귀신살", "비용", "4000");
	
	INIDATA->addData("권법가 도복", "이름", "권법가 도복");
	INIDATA->addData("권법가 도복", "방어력", "5");
	INIDATA->addData("권법가 도복", "스피드", "7");
	INIDATA->addData("권법가 도복", "frameX", "7");
	INIDATA->addData("권법가 도복", "frameY", "0");
	
	INIDATA->addData("호랑이 도복", "이름", "호랑이 도복");
	INIDATA->addData("호랑이 도복", "방어력", "10");
	INIDATA->addData("호랑이 도복", "스피드", "12");
	INIDATA->addData("호랑이 도복", "frameX", "9");
	INIDATA->addData("호랑이 도복", "frameY", "0");
	INIDATA->addData("호랑이 도복", "비용", "400");

	INIDATA->addData("나찰의 도복", "이름", "나찰의 도복");
	INIDATA->addData("나찰의 도복", "방어력","15");
	INIDATA->addData("나찰의 도복", "스피드", "14");
	INIDATA->addData("나찰의 도복", "frameX", "10");
	INIDATA->addData("나찰의 도복", "frameY", "0");
	INIDATA->addData("나찰의 도복", "비용", "1000");

	INIDATA->addData("백호 도복", "이름", "백호 도복");
	INIDATA->addData("백호 도복", "방어력", "20");
	INIDATA->addData("백호 도복", "스피드", "16");
	INIDATA->addData("백호 도복", "frameX", "11");
	INIDATA->addData("백호 도복", "frameY", "0");
	INIDATA->addData("백호 도복", "비용", "2000");

	INIDATA->addData("청룡도", "이름", "청룡도");
	INIDATA->addData("청룡도", "공격력", "5");
	INIDATA->addData("청룡도", "운", "0");
	INIDATA->addData("청룡도", "크리티컬확률", "12");
	INIDATA->addData("청룡도", "frameX", "1");
	INIDATA->addData("청룡도", "frameY", "2");

	INIDATA->addData("불타는 마검", "이름", "불타는 마검");
	INIDATA->addData("불타는 마검", "공격력", "10");
	INIDATA->addData("불타는 마검", "운", "0");
	INIDATA->addData("불타는 마검", "크리티컬확률", "16");
	INIDATA->addData("불타는 마검", "frameX", "2");
	INIDATA->addData("불타는 마검", "frameY", "2");
	INIDATA->addData("불타는 마검", "비용", "600");

	INIDATA->addData("나찰의 흉인", "이름", "나찰의 흉인");
	INIDATA->addData("나찰의 흉인", "공격력", "15");
	INIDATA->addData("나찰의 흉인", "운", "0");
	INIDATA->addData("나찰의 흉인", "크리티컬확률", "18");
	INIDATA->addData("나찰의 흉인", "frameX", "4");
	INIDATA->addData("나찰의 흉인", "frameY", "2");
	INIDATA->addData("나찰의 흉인", "비용", "2000");

	INIDATA->addData("마인아수라", "이름", "마인아수라");
	INIDATA->addData("마인아수라", "공격력", "20");
	INIDATA->addData("마인아수라", "운", "0");
	INIDATA->addData("마인아수라", "크리티컬확률", "20");
	INIDATA->addData("마인아수라", "frameX", "5");
	INIDATA->addData("마인아수라", "frameY", "2");
	INIDATA->addData("마인아수라", "비용", "4000");

	INIDATA->addData("가죽 갑옷", "이름", "가죽 갑옷");
	INIDATA->addData("가죽 갑옷", "방어력", "5");
	INIDATA->addData("가죽 갑옷", "스피드", "5");
	INIDATA->addData("가죽 갑옷", "frameX", "7");
	INIDATA->addData("가죽 갑옷", "frameY", "2");
	
	INIDATA->addData("철편 갑옷", "이름", "철편 갑옷");
	INIDATA->addData("철편 갑옷", "방어력", "10");
	INIDATA->addData("철편 갑옷", "스피드", "4");
	INIDATA->addData("철편 갑옷", "frameX", "9");
	INIDATA->addData("철편 갑옷", "frameY", "2");
	INIDATA->addData("철편 갑옷", "비용", "400");

	INIDATA->addData("어설트 슈트", "이름", "어설트 슈트");
	INIDATA->addData("어설트 슈트", "방어력", "15");
	INIDATA->addData("어설트 슈트", "스피드", "6");
	INIDATA->addData("어설트 슈트", "frameX", "10");
	INIDATA->addData("어설트 슈트", "frameY", "2");
	INIDATA->addData("어설트 슈트", "비용", "1000");

	INIDATA->addData("투신의 갑옷", "이름", "투신의 갑옷");
	INIDATA->addData("투신의 갑옷", "방어력", "20");
	INIDATA->addData("투신의 갑옷", "스피드", "6");
	INIDATA->addData("투신의 갑옷", "frameX", "11");
	INIDATA->addData("투신의 갑옷", "frameY", "2");
	INIDATA->addData("투신의 갑옷", "비용", "2000");
	
	INIDATA->addData("약초", "이름", "약초");
	INIDATA->addData("약초", "HP회복", "50");
	INIDATA->addData("약초", "frameX", "0");
	INIDATA->addData("약초", "frameY", "3");
	INIDATA->addData("약초", "비용", "10");

	INIDATA->addData("마법의 물약", "이름", "마법의 물약");
	INIDATA->addData("마법의 물약", "MP회복", "50");
	INIDATA->addData("마법의 물약", "frameX", "3");
	INIDATA->addData("마법의 물약", "frameY", "3");
	INIDATA->addData("마법의 물약", "비용", "200");

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




