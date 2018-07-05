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
	IMAGEMANAGER->addImage("background", "image/ui/스타트씬.bmp", 1000, 750, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("startChoice", "image/ui/startUI.bmp", 300, 100, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("loadChoice", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("UIBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LOADBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("화면전환", "image/ui/화면전환.bmp", 1000, 750, false, RGB(0, 0, 0),true);

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

	_frameCount = 0;
	_isCount = false;
	_isPlay = false;
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	if(_isCount)
	{
		_frameCount+=5;
		if (_frameCount >= 255) _frameCount = 255;
	}

	
	
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if(!_isLoadCheck) //이어하기 버튼 안눌렀을때
		{
			if (_index == 1)	  _index = 0;
			else if (_index == 0) _index = 1;
		}
		else//눌렀을때
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
			_isCount = true;
			
			
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
	if (_frameCount >= 255)
	{
		SCENEMANAGER->changeScene("타운씬");
		_isPlay = true;
	}
}

void startScene::render(void)
{
	IMAGEMANAGER->findImage("background")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("startChoice")->render(CAMERA->getCameraDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 60);
	IMAGEMANAGER->findImage("UIBUTTON")->frameRender(CAMERA->getCameraDC(), _uiX, _uiY);
	if(_isLoadCheck)
	{
		IMAGEMANAGER->findImage("loadChoice")->render(CAMERA->getCameraDC(), WINSIZEX / 2 + 150, WINSIZEY / 2 - 150);
		IMAGEMANAGER->findImage("LOADBUTTON")->frameRender(CAMERA->getCameraDC(), _loadX, _loadY);
	}
	IMAGEMANAGER->findImage("화면전환")->alphaRender(CAMERA->getCameraDC(), 0, 0,_frameCount);
	fontUI();
}

void startScene::fontUI()
{
	HFONT font, ofont;
	char str[] = "처음하기";
	char str2[] = "이어하기";
	
	font = CreateFont(25,0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255-_frameCount, 255-_frameCount, 255-_frameCount));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 100, WINSIZEY / 2+80, str, strlen(str));
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 100, WINSIZEY / 2 + 115, str2, strlen(str2));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

}
