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

//����ƽ���� ������ �Ǿ �ʱ�ȭ�� �������� �ʱ�ȭ
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
	IMAGEMANAGER->addImage("����ȯ", "image/ui/ȭ����ȯ.bmp", 3000, 3000, false, RGB(0, 0, 0), true);
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
		IMAGEMANAGER->findImage("����ȯ")->alphaRender(_currentScene->getMemDC(),_alphaValue);
	}
	
}

gameNode * sceneManager::addScene(string sceneName, gameNode* scene)
{
	//���� ���ٸ� NULL���� ��ȯ�ض�
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����� == ���� ����� ����? -> ��ã�Ҵ�
	if (find == _mSceneList.end()) return E_FAIL;

	//�ٲٷ��� ���� ���� ���̸� ���д�
	if (find->second == _currentScene) return S_OK;

	//���������� ���� �ٲ�� init() �Լ��� �����Ѵ�
	if (SUCCEEDED(find->second->init()))
	{
		if (sceneName != "���¾�" && sceneName != "��Ʋ��") { _sceneName = sceneName; }
		//������� � ������ ������ (�̸� � ���� �����Ǿ�������)
		//�ش� ���� ������ ���ְ�
		if (_currentScene) _currentScene->release();
		
		//�ٲٷ��� ���� ���� ������ ��ü�Ѵ�
		_currentScene = find->second;
		_isChange = true;
		//���� �� �� ��ȯ������ �׳��� ������ ���ڸ�
		//�ٲ� ������ �����͸� �޾ƿ� ���� �������� �����ؾ��ϴ� ����
		//���� ����� �ҷ������� ������ ���� ó���� ������Ѵٴ� ��������
		//�ִ�.
		
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
