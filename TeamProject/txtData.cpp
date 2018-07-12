#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{
}

HRESULT txtData::init()
{

	return S_OK;
}

void txtData::release()
{

}

//����
void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;
	DWORD write;

	char str[500000];

	strncpy_s(str, 500000, vectorArrayCombine(vStr), 499998);

	file = CreateFile(saveFileName, GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 500000, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	//���۴� �켱 128�� ��ƵӴϴ� 
	//�������� ���۰����� ���ص�������, ���ö����� ũ�⿡����
	//���ڿ� �����Ҵ��� �ϰԲ� �ٲ�θ� ���ϰԧt?
	char str[500000];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		strncat_s(str, 500000, vArray[i].c_str(), 499998);
		// vArray[0] vArray[1] vArray[2] vArray[3]
		// 20, 20, 30, 30
		if (i + 1 < vArray.size()) strcat_s(str, ",");
	}

	return str;
}

//�ε�
vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;
	DWORD read;

	char str[500000] = "";

	file = CreateFile(loadFileName, GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 500000, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;

	char* temp;
	const char* separator = ",";
	char* token;

	token = strtok_s(charArray, separator, &temp);

	if (token == NULL)
	{
		vArray.push_back("����");
		return vArray;
	}

	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}