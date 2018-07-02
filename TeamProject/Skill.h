#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;			// ��ų ����Ʈ �̹���
	RECT rc;			// ��ų ����
	float x, y;			// ��ų ��ǥ
	bool start;			// ��ų ����
	int count;			// ��ų ī��Ʈ
};

class targetSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;			// ��ų ����

	int _alphaColor;	// ��ų ���� ��
	int _alphaCount;	// ��ų ���� ī��Ʈ
	int _alphaMaxCount;	// ��ų ���� �ִ� ī��Ʈ

public:
	targetSkill1();
	~targetSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y, int dmage);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

class targetSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;			// ��ų ����

	int _alphaColor;	// ��ų ���� ��
	int _alphaCount;	// ��ų ���� ī��Ʈ
	int _alphaMaxCount;	// ��ų ���� �ִ� ī��Ʈ

public:
	targetSkill2();
	~targetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};
