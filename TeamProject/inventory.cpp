#include "stdafx.h"
#include "inventory.h"


HRESULT inventory::init()
{
	return E_NOTIMPL;
}

void inventory::update()
{
}

void inventory::render()
{
}

void inventory::release()
{
}

void inventory::setWeapon(int att,int luck , int cri)
{
	_att = att;
	_luck = luck;
	_cri = cri;

}

inventory::inventory()
{
}


inventory::~inventory()
{
}
