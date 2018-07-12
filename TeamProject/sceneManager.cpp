#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"
#include "playMap.h"

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

//스태틱으로 선언이 되어서 초기화는 전역으로 초기화
gameNode* sceneManager::_currentScene = NULL;

HRESULT sceneManager::init()
{
	_pm = new playerManager;
	_im = new itemManager;
	_em = new enemyManager;
	_map = new playMap;

	_pm->setEnemyManagerAdressLink(_em);
	_pm->setItemManagerAdressLink(_im);
	_em->setAdressLinkPlayerManager(_pm);
	IMAGEMANAGER->addImage("씬전환", "image/ui/화면전환.bmp", 3000, 3000, false, RGB(0, 0, 0), true);
	_pm->init();
	_im->init();
	_em->init();

	_currentScene = NULL;
	_isShop = false;
	_isChange = false;
	_frameCount = 0;
	_alphaValue = 255;

	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();
	if(_isChange)
	{
		_frameCount++;
		if (_frameCount % 1 == 0)
		{
			if (_alphaValue>0)
			{
				_alphaValue-=20;
				if (_alphaValue < 0) _alphaValue = 0;
			}
			_frameCount = 0;
		}
	
	}
	if (_alphaValue == 0)
	{
		_isChange = false;
		_alphaValue = 255;
	}
}

void sceneManager::render()
{
	
	if (_currentScene) _currentScene->render();
	if (_isChange)
	{
		IMAGEMANAGER->findImage("씬전환")->alphaRender(_currentScene->getMemDC(),_alphaValue);
	}
	
}

gameNode * sceneManager::addScene(string sceneName, gameNode* scene)
{
	//씬이 없다면 NULL값을 반환해라
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	
	mapSceneIter find = _mSceneList.find(sceneName);

	//이터레이터 == 맵의 엔드와 같다? -> 못찾았다
	if (find == _mSceneList.end()) return E_FAIL;

	//바꾸려는 씬이 현재 씬이면 냅둔다
	if (find->second == _currentScene) return S_OK;

	//성공적으로 씬이 바뀌면 init() 함수를 실행한다
	if (SUCCEEDED(find->second->init()))
	{
		if (sceneName != "상태씬" && sceneName != "배틀씬") { _sceneName = sceneName; }
		//현재씬에 어떤 정보가 있으면 (미리 어떤 씬이 배정되어있으면)
		//해당 씬을 릴리즈 해주고
		if (_currentScene) _currentScene->release();
		
		//바꾸려는 씬을 현재 씬으로 교체한다
		_currentScene = find->second;
		_isChange = true;
		//지금 이 씬 변환구조의 그나마 단점을 꽂자면
		//바뀐 씬에서 데이터를 받아온 다음 이전씬을 해제해야하는 경우는
		//먼저 릴리즈가 불러와지기 때문에 따로 처리를 해줘야한다는 불편함이
		//있다.
		
		return S_OK;
	}

	return E_FAIL;
}

string sceneManager::getSceneName()
{
	for (mapSceneIter miSceneList = _mSceneList.begin(); miSceneList != _mSceneList.end(); ++miSceneList)
	{
		if (miSceneList->second == _currentScene)
		{
			return miSceneList->first;
		}
	}

	return NULL;
}
