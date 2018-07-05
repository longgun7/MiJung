#pragma once
#include "gameNode.h"
#include "fildSkeleton.h"
#include "enemys.h"

#define MAXSKELETON 20
#define PLAYMAPSIZEY 525 

class player;
class player2;

class enemyManager : public gameNode
{
private:

	typedef vector<fildSkeleton*> vFildSkeleton;					// skeleton�� ��� ���� ����
	typedef vector<fildSkeleton*>::iterator viFildSkeleton;			// ���� �������� iterator ����

	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;

private:

	vFildSkeleton _vFildSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	viFildSkeleton _viFildSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	player* _ataho;
	player2* _smasu;
	
	fildSkeleton* _fildSkeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����
	
	int _randNum;
	int _interval;

	int _enemyIndex;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy();

	void setPlayerAddressLink(player* _player) { _ataho = _player; }
	void setPlayer2AddressLink(player2* _player2) { _smasu = _player2; }

	enemyManager();
	~enemyManager();
};