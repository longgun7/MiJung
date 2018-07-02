#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init(void)
{
	IMAGEMANAGER->addImage("background", "image/ui/½ºÅ¸Æ®¾À.bmp", 1000, 750, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("startChoice", "image/ui/startUI.bmp", 300, 100, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("loadChoice", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("UIBUTTON", "image/ui/UI¹öÆ°.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LOADBUTTON", "image/ui/UI¹öÆ°.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	SCENEMANAGER->addScene("¸ÊÅø¾À", new mapToolScene);
	SCENEMANAGER->addScene("ÇÃ·¹ÀÌ¾À", new playScene);

	IMAGEMANAGER->findImage("UIBUTTON")->setFrameX(7);
	IMAGEMANAGER->findImage("UIBUTTON")->setFrameY(0);
	IMAGEMANAGER->findImage("LOADBUTTON")->setFrameX(7);
	IMAGEMANAGER->findImage("LOADBUTTON")->setFrameY(0);
	_uiX = WINSIZEX/2-130;
	_uiY = WINSIZEY/2+80;

	_loadX = WINSIZEX - 320;
	_loadY = WINSIZEY / 2-100;

	
	_isLoadCheck = false;
	_index = 0;
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("¸ÊÅø¾À");
	}
	
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if(!_isLoadCheck) //ÀÌ¾îÇÏ±â ¹öÆ° ¾È´­·¶À»¶§
		{
			if (_index == 1)	  _index = 0;
			else if (_index == 0) _index = 1;
		}
		else//´­·¶À»¶§
		{
			_loadIndex--;
			if (_loadIndex < 0)
			{
				_loadIndex = 4;
			}
		}
		
	}
	if(KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (!_isLoadCheck)
		{
			if (_index == 1)	  _index = 0;
			else if (_index == 0) _index = 1;
		}
		else
		{
			_loadIndex++;
			if (_loadIndex > 4)
			{
				_loadIndex = 0;
			}
		}
	}	
	if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_isLoadCheck)
		{
			IMAGEMANAGER->findImage("LOADBUTTON")->setFrameY(1);
		}
		IMAGEMANAGER->findImage("UIBUTTON")->setFrameY(1);
		if(_index==0)
		{
			//SCENEMANAGER->changeScene("ÇÃ·¹ÀÌ¾À");
			playScene* _playScene;
			_playScene = new playScene;
			_playScene->init();
		}
		if(_index ==1)
		{
			_isLoadCheck = true;
		}
	}
	if(KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if (_isLoadCheck)
		{
			IMAGEMANAGER->findImage("LOADBUTTON")->setFrameY(0);
		}
		IMAGEMANAGER->findImage("UIBUTTON")->setFrameY(0);
		if(_index ==1)
		{
			_isLoadCheck = false;
		}
		
	}

	if(_index ==0)
	{
		_uiX = WINSIZEX / 2 - 130;
		_uiY = WINSIZEY / 2 + 80;
	}
	if(_index ==1)
	{
		_uiX = WINSIZEX / 2 - 130;
		_uiY = WINSIZEY / 2 + 110;
	}

	for(int i=0;i<5;i++)
	{
		if(_loadIndex == i)
		{
			_loadX = WINSIZEX - 320;
			_loadY = WINSIZEY / 2 - 100+i*50;
		}
	}
}

void startScene::render(void)
{
	IMAGEMANAGER->findImage("background")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("startChoice")->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 60);
	IMAGEMANAGER->findImage("UIBUTTON")->frameRender(getMemDC(), _uiX, _uiY);
	if(_isLoadCheck)
	{
		IMAGEMANAGER->findImage("loadChoice")->render(getMemDC(), WINSIZEX / 2 + 150, WINSIZEY / 2 - 150);
		IMAGEMANAGER->findImage("LOADBUTTON")->frameRender(getMemDC(), _loadX, _loadY);
	}
	
	fontUI();
}

void startScene::fontUI()
{
	HFONT font, ofont;
	char str[] = "Ã³À½ÇÏ±â";
	char str2[] = "ÀÌ¾îÇÏ±â";
	
	font = CreateFont(25,0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "»õ±¼¸²");
	ofont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), WINSIZEX / 2 - 100, WINSIZEY / 2+80, str, strlen(str));
	TextOut(getMemDC(), WINSIZEX / 2 - 100, WINSIZEY / 2 + 115, str2, strlen(str2));
	SelectObject(getMemDC(), ofont);
	DeleteObject(font);

}
