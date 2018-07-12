#include "stdafx.h"
#include "npc.h"

npc::npc()
{
}


npc::~npc()
{
}

HRESULT npc::init()
{
	IMAGEMANAGER->addFrameImage("NPC", "image/maptool/NPC/NPC.bmp", 288, 192, 6, 3, true, RGB(255, 0, 255));

	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
}

void npc::render()
{
	for (_viTagNPC = _vTagNPC.begin(); _viTagNPC != _vTagNPC.end(); ++_viTagNPC)
	{
		_viTagNPC->img->frameRender(getMemDC(), _viTagNPC->rc.left, _viTagNPC->rc.top, _viTagNPC->frameX, _viTagNPC->frameY);
	}
}

void npc::addNPC(float x, float y, NPCKIND kind, int frameX, int frameY)
{
	tagNPC NPC;
	NPC.kind = kind;
	NPC.img = new image;
	NPC.img = IMAGEMANAGER->findImage("NPC");
	NPC.frameX = frameX;
	NPC.frameY = frameY;

	NPC.x = x;
	NPC.y = y;
	NPC.rc = RectMakeCenter(NPC.x, NPC.y, NPC.img->getFrameWidth(), NPC.img->getFrameHeight());

	_vTagNPC.push_back(NPC);
}
