#include "Player.h"

#include "IComponent.h"
#include "TransformComponent.h"

//constructor
CPlayer::CPlayer()
{
	//Create transform component
	m_pTransform=new CTransformComponent();
	//attach it to the game object
	addComponent(m_pTransform);
}

CPlayer::~CPlayer()
{
	vector<IComponent*>::iterator iter=m_Components.begin();
	while(iter!=m_Components.end())
	{
		if ((*iter))
		{
			delete (*iter);
			(*iter)=NULL;
			iter=m_Components.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	m_ComponentMap.clear();
}

//Add component
void CPlayer::addComponent(IComponent * pComponent)
{
	//Add to the vector
	m_Components.push_back(pComponent);
	//Add to map
	m_ComponentMap[pComponent->getName()]=pComponent;
	//set the parent of the component
	//pComponent->setParent(this);
};


//init, cycle through the vector and call init method of the component
void CPlayer::init()
{
	for (vector<IComponent*>::iterator iter=m_Components.begin();iter!=m_Components.end();iter++)
	{
		(*iter)->init();
	}
}

//render, cycle through each component and call render
void CPlayer::render()
{
	for (vector<IComponent*>::iterator iter=m_Components.begin();iter!=m_Components.end();iter++)
	{
		(*iter)->render();
	}
}

//update, cycle through each compoent and call update
void CPlayer::update(float elapsedTime)
{
	for (vector<IComponent*>::iterator iter=m_Components.begin();iter!=m_Components.end();iter++)
	{
		(*iter)->update(elapsedTime);
	}
}