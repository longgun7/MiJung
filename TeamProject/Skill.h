#pragma once
#include "gameNode.h"
#include <vector>

struct tagSkill
{
	image* img;				// ��ų �̹���
	image* img1;			// ��Ÿȣ 3�ܰ� ���α� ������ �̹��� �߰�
	image* img2;			// ��Ÿȣ 3�ܰ� ���α� ������ �̹��� �߰�
	RECT rc;				// ��ų ����
	RECT rc1;				// ��Ÿȣ 3�ܰ� ���α� ������ ���� �߰�
	RECT rc2;				// ��Ÿȣ 3�ܰ� ���α� ������ ���� �߰�
	float fireX, fireY;		// ��ų ���� ��ǥ
	float x, y;				// ��ų ��ǥ
	float stoneX, stoneY;	// ��Ÿȣ 3�ܰ� ��ü�� �� ��ǥ
	bool start;				// ��ų ����
	int count;				// ��ų ī��Ʈ
	float speed;			// ��ų �ӵ�
	float angle;			// ��ų ����
	float _width;			// ��ų �̹��� ���� ũ��
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
	int _width;

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

	void addSkill(float x, float y);				// ��ų ����

	vector<tagSkill> getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
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

public:
	atahoTargetSkill2();
	~atahoTargetSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);			// ��ų ����
	void moveSkill();							// ��ų ������

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};

//======= ��Ÿȣ ���� ��ų 3�� : ��� - ��ȣ������ ========
class atahoTargetSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	image * _img;			// ������ �̹���
	RECT _rc;				// ������ ����
	float _x, _y;			// ������ x, y ��ǥ

	float _range;			// �ִ� ����

	int _count;				// ī��Ʈ
	int _expCount;			// ����ġ ī��Ʈ
	int _currentExp;		// ���� ����ġ
	int _maxExp;			// �ִ� ����ġ
	int _level;				// ���� ����
	int _width;				// �þ ���� ũ��
	bool _start;			// ����������� ���������� Ȯ��

public:
	atahoTargetSkill3();
	~atahoTargetSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);		// ������� ����
	void moveSkill();						// ������� ������

	void chargingSkill12(float x, float y);	// ��¡ 1,2�ܰ� ��ġ �� ����
	void chargingSkill3(float x, float y);	// ��¡ 3�ܰ� ��ġ �� ����
	void chargingSkill4(float x, float y);	// ��¡ 4�ܰ� ��ġ �� ����

	void fireAddSkill(float x, float y);	// �� �߻� ����
	void fireSkill1(float x, float y);		// �� �߻� 1�ܰ� ��ġ �� �ʱ� ��
	void fireSkill2(float x, float y);		// �� �߻� 2�ܰ� ��ġ �� �ʱ� ��
	void fireSkill3(float x, float y);		// �� �߻� 3�ܰ� ��ġ �� �ʱ� ��
	void fireSkill4(float x, float y);		// �� �߻� 4�ܰ� ��ġ �� �ʱ� ��

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }

	int getCurrentExp() { return _currentExp; }
	int getLevel() { return _level; }
};
//======= ��Ÿȣ ��ü ��ų 2�� : ȭ��! ========
class atahoAreaSkill2 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _range;				// ��ų �ִ� ���� ����

	float _angle;				// ��ų ����
	bool _start;				// ��ų ���� ����

public:
	atahoAreaSkill2();
	~atahoAreaSkill2();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addSkill(float x, float y);		// ��ų ����
	void moveSkill();						// ��ų ������

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
};
//======= ��Ÿȣ ���� ��ų 3�� : ������ ������ ========
class atahoAreaSkill3 : public gameNode
{
private:
	vector<tagSkill>			_vTagSkill;
	vector<tagSkill>::iterator	_viTagSkill;

	float _randnumFireX;					// �� x ��ǥ ����
	float _randnumFireY;					// �� y ��ǥ ����
	float _randnumStoneX;					// �� x ��ǥ ����
	float _randnumStoneY;					// �� y ��ǥ ����

	int _randStone;							// �� ������ 0 or 1 ����
	int _stoneCount;						// �� 4���� ���� �ǰ� ���ִ� ī��Ʈ

public:
	atahoAreaSkill3();
	~atahoAreaSkill3();

	HRESULT init();
	void realse();
	void update();
	void render();

	void addFireSkill(float x, float y);	// ��ų ����
	void moveSkill();						// ��ų ������

	vector<tagSkill>getVTagSkill() { return _vTagSkill; }
	vector<tagSkill>::iterator getVITagSkill() { return _viTagSkill; }
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