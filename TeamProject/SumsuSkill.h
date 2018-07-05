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
	float _width;			// ��ų �̹��� ���� ũ��
};
//======= ������ ���� �̹��� ========
class sumsuCut : public gameNode
{
private:

public:
	sumsuCut();
	~sumsuCut();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);		// ��ų ����
};
//======= ������ ���� ��ų 2�� : ������ ========
class sumsuTargetSkill2 : public gameNode
{
private:

	int _count;					// ��ų ī��Ʈ

public:
	sumsuTargetSkill2();
	~sumsuTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);		// ��ų ����

	int setCount(int count) { return _count = count; }
};
//======= ������ ���� ��ų 3�� : ������ ========
class sumsuTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;

	int _alphaColor;	// ���� ��
	int _alphaCount;	// ���� ī��Ʈ
	int _alphaMaxCount;	// ���� �ִ� ī��Ʈ

public:
	sumsuTargetSkill3();
	~sumsuTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void cutUpSkill(float x, float y);			// �� ���� ��ų ����
	void cutDownSkill(float x, float y);		// �Ʒ� ���� ��ų ����
	void cutDiagonalSkill(float x, float y);	// �밢�� ���� ��ų ����
	void cutBigSkill(float x, float y);			// ������ ���� ��ų ����
	void moveSkill();

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};

class sumsuAreaSkill1 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;

	float _range;

public:
	sumsuAreaSkill1();
	~sumsuAreaSkill1();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addAreaSkill(float x, float y, int monsterNum);

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};