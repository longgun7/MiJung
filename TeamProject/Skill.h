#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;				// ��ų �̹���
	RECT rc;				// ��ų ����
	float fireX, fireY;		// ��ų ���� ��ǥ
	float x, y;				// ��ų ��ǥ
	bool start;				// ��ų ����
	int count;				// ��ų ī��Ʈ
	float speed;			// ��ų �ӵ�
	float angle;			// ��ų ����
	int level;
};
//======= ��Ÿȣ ���� ��ų 1�� : ȣ�ݱ� ========
class atahoTargetSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;			// ��ų ����

	int _alphaColor;	// ���� ��
	int _alphaCount;	// ���� ī��Ʈ
	int _alphaMaxCount;	// ���� �ִ� ī��Ʈ

public:
	atahoTargetSkill1();
	~atahoTargetSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);

	vector<tagSkill> getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

//======= ��Ÿȣ ���� ��ų 2�� : ��ȣ����� ========
class atahoTargetSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;			// ��ų ����

	int _alphaColor;	// ���� ��
	int _alphaCount;	// ���� ī��Ʈ
	int _alphaMaxCount;	// ���� �ִ� ī��Ʈ

public:
	atahoTargetSkill2();
	~atahoTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);
	void moveSkill();

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

//======= ��Ÿȣ ���� ��ų 3�� : ��� - ��ȣ������ ========
class atahoTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _currentExp;
	int _maxExp;
	int _level;

	int _alphaColor;
	int _alphaCount;
	int _alphaMaxCount;

public:
	atahoTargetSkill3();
	~atahoTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);
	void moveSkill();

	void chargingSkill12(float x, float y);
	void chargingSkill3(float x, float y);
	void chargingSkill4(float x, float y);

};