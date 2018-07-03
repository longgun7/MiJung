#pragma once
#include "gameNode.h"
#include "skeleton.h"
#include "spearMan.h"

#define MAXSKELETON 20

class player;
class player2;

class enemyManager : public gameNode
{
private:

	typedef vector<skeleton*> vSkeleton;					// skeleton�� ��� ���� ����
	typedef vector<skeleton*>::iterator viSkeleton;			// ���� �������� iterator ����

	typedef vector<spearMan*> vSpearMan;					// spearMan�� ��� ���� ����
	typedef vector<spearMan*>::iterator viSpearMan;			// ���� �����ڴ� iterator ���� 

private:

	vSkeleton _vSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	viSkeleton _viSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	vSpearMan _vSpearMan;
	viSpearMan _viSpearMan;

	player* _ataho;
	player2* _smasu;
	skeleton* _skeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����
	spearMan * _spearMan;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSkeleton();
	void setSpearMan();

	void hitDamge();
	void hitSpearMan(int index, int damage);

	void setPlayerAddressLink(player* _player) { _ataho = _player; }
	void setPlayer2AddressLink(player2* _player2) { _smasu = _player2; }
	vector<spearMan*> getSpearMan()
	{
		for (int i = 0; i < _vSpearMan.size(); ++ i)
		{
			return _vSpearMan;
		}
	}
	enemyManager();
	~enemyManager();
};