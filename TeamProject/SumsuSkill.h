#pragma once
#include "gameNode.h"
#include <vector>

struct tagSumsuSkill
{
	image* img;				// ��ų �̹���
	RECT rc;				// ��ų ����
	float fireX, fireY;		// ��ų ���� ��ǥ
	float x, y;				// ��ų ��ǥ
	bool start;				// ��ų ����
	int count;				// ��ų ī��Ʈ
	float width;			// ��ų �̹��� ���� ũ��
	int currentFrameX;		// ���� ������ ��ȣ
	float angle;			// ��ų ����
	float angle1;			// ������ 3�ܰ� ��ü�� �� ���� �߰�
	float speed;			// ��ų ���ǵ�
	float speedx;			// ������ 3�ܰ� ��ü�� �� ���ǵ� �߰�
	int number;				// ������ 3�ܰ� ��ü�� �� ���� ȸ�� ��
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

	// ��ų ���� x(�ش� �� x��ǥ, �ش� �� y��ǥ)
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

	// ��ų ���� x(�ش� �� x��ǥ, �ش� �� y��ǥ)
	void addFireSkill(float x, float y);		// ��ų ����

	int setCount(int count) { return _count = count; }
};
//======= ������ ���� ��ų 3�� : ������ ========
class sumsuTargetSkill3 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

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

	// �� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
	void cutUpSkill(float x, float y);
	// �Ʒ� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
	void cutDownSkill(float x, float y);
	// �밢�� ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
	void cutDiagonalSkill(float x, float y);
	// ������ ���� ��ų ���� (�ش� �� x��ǥ, �ش� �� y��ǥ)
	void cutBigSkill(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }
};
//======= ������ ��ü ��ų 1�� : �����ϼ� ========
class sumsuAreaSkill1 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

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

	// ��ų ���� (���� �� ���� ���� ���� ����) x(ù��° ���� x��ǥ), y(ù��° ���� y��ǥ), ��Ÿ�� ���� ��
	void addAreaSkill(float x, float y, int monsterNum);

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};
//======= ������ ��ü ��ų 2�� : �нż� ========
class sumsuAreaSkill2 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;

	int _alphaColor;	// ���� ��

public:
	sumsuAreaSkill2();
	~sumsuAreaSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	// �н� ĳ���� ���� x(ĳ���� x��ǥ), y(ĳ���� y��ǥ)
	void addAreaSkill(float x, float y);
	void addAreaSkill1(float x, float y);
	void addAreaSkill2(float x, float y);
	void addAreaSkill3(float x, float y);
	void addAreaSkill4(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};

class sumsuAreaSkill3 : public gameNode
{
private:
	vector<tagSumsuSkill>			_vTagSumsuSkill;
	vector<tagSumsuSkill>::iterator	_viTagSumsuSkill;

	image* _img[2];
	RECT _rc[2];

	float _range;

	int _currentExp;	// ��ų ���� ����ġ
	int _maxExp;		// ��ų �ִ� ����ġ
	int _level;

	int _currentFrameX1;
	int _currentFrameX2;

	int _count;
	int _expCount;
public:
	sumsuAreaSkill3();
	~sumsuAreaSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	// ������ x(���� ��ǥ), y(���� ��ǥ)
	void addAreaSkill(float x, float y);
	void addAreaSkill1(float x, float y);
	void addAreaSkill2(float x, float y);
	void addAreaSkill3(float x, float y);
	void addAreaSkill4(float x, float y);
	void moveSkill();

	vector<tagSumsuSkill>getVTagSkill() { return _vTagSumsuSkill; }
	vector<tagSumsuSkill>::iterator getVITagSkill() { return _viTagSumsuSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};