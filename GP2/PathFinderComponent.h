#pragma once

#include "IComponent.h"
#include <D3D10.h>
#include <D3DX10.h>

class CPathFinderComponent:public CBaseComponent
{
public:
	CPathFinderComponent();
	~CPathFinderComponent();

	D3DXVECTOR3 enemyPosition;

	//TO DO: list of waypoints

	int currentWaypoint;

	void update(float elapsedTime);





}