#pragma once

#include "IComponent.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include <D3D10.h>
#include <D3DX10.h>
#include <math.h>

class CPlayerComponent:public CBaseComponent
{
public:
	CPlayerComponent();
	~CPlayerComponent();

	void update(float elapsedTime);

	D3DXMATRIX& getView()
	{
		return m_matView;
	};

	D3DXMATRIX& getProjection()
	{
		return m_matProjection;
	};


	void setLookAt(float x,float y,float z)
	{
		m_vecLookAt=D3DXVECTOR3(x,y,z);
	};

	void setUp(float x,float y,float z)
	{
		m_vecUp=D3DXVECTOR3(x,y,z);
	};

	void setFOV(float fov)
	{
		m_fFOV=fov;
	};

	void setAspectRatio(float aspectRatio)
	{
		m_fAspectRatio=aspectRatio;
	};

	void setNearClip(float nearClip)
	{
		m_fNearClip=nearClip;
	};

	void setFarClip(float farClip)
	{
		m_fFarClip=farClip;
	};
	
	void setYaw(float yaw)
    {
		m_fYaw=yaw;
	};

	void setPitch(float pitch)
	{
		m_fPitch=pitch;
	};

	void yaw(float yaw)
	{
		m_fYaw+=yaw;
	};

	void pitch(float p)
	{
		m_fPitch+=p;
	};

	void move(float x, float y, float z)
	{
		getParent()->getTransform()->translate(x,y,z);
		m_vecLookAt.x+=x;
		m_vecLookAt.y+=y;
		m_vecLookAt.z+=z;
	};

	void rotate()
	{
		getParent()->getTransform()->rotate(m_fYaw,0.0f,0.f);
	};

private:
	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProjection;

	D3DXVECTOR3 m_vecUp;
	D3DXVECTOR3 m_vecLookAt;

	float m_fAspectRatio;
	float m_fFOV;
	float m_fNearClip;
	float m_fFarClip;

	float m_fYaw;
	float m_fPitch;

};