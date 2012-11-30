#pragma once

#include <D3D10.h>
#include <D3DX10.h>
#include <vector>
#include "IComponent.h"
#include <list>
#include "GameObjectManager.h"
#include "GameApplication.h"
using namespace std;



class CPathFinding: public CBaseComponent
{
public:
	CPathFinding();
	~CPathFinding();

	void update(float elapsedTime);
	void findAngle();
	void moveForward();
	
private:
	D3DXVECTOR3 m_vObjectDirection;

	list<string> m_lwaypoint;

	int m_iCurrentWaypoint;

};

