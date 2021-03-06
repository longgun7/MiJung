


#include "stdafx.h"
#include "iniDataManager.h"


iniDataManager::iniDataManager()
{
}


iniDataManager::~iniDataManager()
{
}

HRESULT iniDataManager::init()
{
	return S_OK;
}

void iniDataManager::release()
{
}

void iniDataManager::addData(const char * subject, const char * title, const char * body)
{
	//iniData 구조체
	tagIniData iniData;

	iniData.subject = subject;
	iniData.title = title;
	iniData.body = body;
	
	//구조체의 데이터를 벡터에 담고
	arrIniData vIniData;
	vIniData.push_back(iniData);

	//데이터를 관리하는 벡터를 또 벡터에 담는다
	_vIniData.push_back(vIniData);
}

void iniDataManager::iniSave(const char * fileName)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	//현재 디렉토리 경로를 받아오는 함수
	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);

	for (int i = 0; i < _vIniData.size(); i++)
	{
		arrIniData vData = _vIniData[i];

		//[서브젝트]
		//타이틀 = 값
		WritePrivateProfileString(vData[0].subject, vData[0].title, vData[0].body, str);

		vData.clear();
	}

	_vIniData.clear();
}

int iniDataManager::loadDataInterger(const char * fileName, const char * subject, const char * title)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);


	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);

	return GetPrivateProfileInt(subject, title, 0, str);
}

string iniDataManager::loadDataString(const char* fileName, const char* subject, const char* title)
{
	char str[256];
	char dir[256];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);


	GetCurrentDirectory(256, str);
	strncat_s(str, 256, dir, 254);

	char data[128] = "";
	GetPrivateProfileString(subject, title, "", data, 64, str);

	string temp = data;
	return temp;
}
