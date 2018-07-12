#include "stdafx.h"
#include "npc.h"
#include "bossSkill.h"

npc::npc()
{
}


npc::~npc()
{
}

HRESULT npc::init()
{
	IMAGEMANAGER->addFrameImage("NPC", "image/maptool/NPC/NPC.bmp", 432, 288, 6, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("대화창", "image/ui/대화창.bmp", 600, 125, false, RGB(0, 0, 0));

	_talkNPC = false;
	_count = 0;
	talkNPCSave();
	talkNPCLoad();
	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	
	if (_talkNPC)
	{
		_count++;
		if (_count % 8 == 0)
		{
			_talkIndex++;
			if (_maxTalkIndex <= (_talkIndex * 2))
			{
				_talkIndex = (_maxTalkIndex / 2);
			}
		}

		if (_talkIndex == (_maxTalkIndex / 2))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				_talkNPC = false;
				_count = 0;
				_talkIndex = 0;
				_maxTalkIndex = 0;
			}
		}

		else if (_talkIndex < (_maxTalkIndex / 2));
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				_talkIndex = (_maxTalkIndex / 2);
			}
		}

	}
}

void npc::render()
{
	for (_viTagNPC = _vTagNPC.begin(); _viTagNPC != _vTagNPC.end(); ++_viTagNPC)
	{
		_viTagNPC->img->frameRender(getMemDC(), _viTagNPC->rc.left, _viTagNPC->rc.top, _viTagNPC->frameX, _viTagNPC->frameY);

		if (_talkNPC)
		{
			IMAGEMANAGER->findImage("대화창")->render(CAMERA->getCameraDC(), 272, 400);
			SetTextColor(getMemDC(), RGB(255, 255, 255));

			for (int i = 0; i < 12; ++i)
			{
				if (_index == i)
				{
					_maxTalkIndex = strlen(vStrNPC[i].c_str());

					if ((_talkIndex * 2) < 100)
					{
						TextOut(CAMERA->getCameraDC(), 300, 450, vStrNPC[i].c_str(), (_talkIndex * 2));
					}
					//else if ((_talkIndex * 2) >= 100 && (_talkIndex * 2) < 200)
					//{
					//	string text = "";
					//
					//	text = vStrNPC[i].substr(0, 100);
					//	TextOut(CAMERA->getCameraDC(), 100, 450, text.c_str(), text.size());
					//
					//	text = vStrNPC[i].substr(100, _maxTalkIndex);
					//	TextOut(CAMERA->getCameraDC(), 100, 470, text.c_str(), (_talkIndex * 2) - 100);
					//}
					//else
					//{
					//	string text = "";
					//
					//	text = vStrNPC[i].substr(0, 100);
					//	TextOut(CAMERA->getCameraDC(), 100, 450, text.c_str(), text.size());
					//
					//	text = vStrNPC[i].substr(101, 200);
					//	TextOut(CAMERA->getCameraDC(), 100, 470, text.c_str(), text.size());
					//
					//	text = vStrNPC[i].substr(200, _maxTalkIndex);
					//	TextOut(CAMERA->getCameraDC(), 100, 490, text.c_str(), (_talkIndex * 2) - 200);
					//}
					break;
				}
			}
		}
	}
}

void npc::addNPC(float x, float y, NPCKIND kind, int frameX, int frameY, int tileX, int tileY)
{
	tagNPC NPC;
	NPC.kind = kind;
	NPC.img = new image;
	NPC.img = IMAGEMANAGER->findImage("NPC");
	NPC.frameX = frameX;
	NPC.frameY = frameY;
	NPC.tileX = tileX;
	NPC.tileY = tileY;
	NPC.x = x;
	NPC.y = y;
	NPC.rc = RectMakeCenter(NPC.x, NPC.y, NPC.img->getFrameWidth(), NPC.img->getFrameHeight());

	_vTagNPC.push_back(NPC);
}

void npc::talkNPC(int frameX, int frameY)
{
	for (_viTagNPC = _vTagNPC.begin(); _viTagNPC != _vTagNPC.end(); ++_viTagNPC)
	{
		if (_viTagNPC->frameX == frameX && _viTagNPC->frameY == frameY)
		{
			_talkNPC = true;
			_index = frameX + (frameY * 6);
		}
	}
}

void npc::talkNPCSave()
{
	vStrNPC.push_back(strNPC);
	vStrNPC.push_back(strNPC1);
	vStrNPC.push_back(strNPC2);
	vStrNPC.push_back(strNPC3);
	vStrNPC.push_back(strNPC4);
	vStrNPC.push_back(strNPC5);
	vStrNPC.push_back(strNPC6);
	vStrNPC.push_back(strNPC7);
	vStrNPC.push_back(strNPC8);
	vStrNPC.push_back(strNPC9);
	vStrNPC.push_back(strNPC10);
	vStrNPC.push_back(strNPC11);

	TXTDATA->txtSave("NPC대사.txt", vStrNPC);
}

void npc::talkNPCLoad()
{
	vStrNPC = TXTDATA->txtLoad("NPC대사.txt");
}
