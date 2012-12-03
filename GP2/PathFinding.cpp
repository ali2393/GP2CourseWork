#include "PathFinding.h"
#include "GameObject.h"
#include "GameApplication.h"
#include "GameObjectManager.h"


CPathFinding::CPathFinding()
{
	m_iCurrentWaypoint = 1;
	m_lwaypoint;
	m_vObjectDirection;

}

CPathFinding::~CPathFinding()
{

}


void moveForward()
{
	
}

void findAngle()
{

}

void CPathFinding::update(float elapsedTime)
{
	if(m_iCurrentWaypoint=1)
	{
		//D3DXVECTOR3 nextPoint=GameApplication->m_pGameObjectManager->findGameObject("waypoint1")->getTransform()->getPosition();
	}

}