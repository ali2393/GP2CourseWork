#pragma once
#include "Win32Window.h"
#include "Timer.h"
#include <D3D10.h>
#include <D3DX10.h>
#include <fmod.hpp>

#include "GameObjectManager.h"

#include "MaterialComponent.h"

#include "GeometryComponent.h"

#include "TransformComponent.h"
#include "CameraComponent.h"
#include "DirectionLightComponent.h"
#include "MeshComponent.h"

#include "AudioListenerComponent.h"
#include "AudioSourceComponent.h"
#include "AudioSystem.h"

#include "Player.h"

#include "ModelLoader.h"
#include "GUIManager.h"

#include "Physics.h"
#include "BodyComponent.h"
#include "BoxCollider.h"
#include "MeshCollider.h"

#include <vector>


enum GameState
{
	Menu,
	Play,
	Pause,
	Quit
};


using namespace std;

class CGameApplication:public hkpContactListener 
{
public:
	CGameApplication(void);
	~CGameApplication(void);
	bool init();
	void run();
private:
	bool initInput();
	bool initGame();
	bool initGraphics();
	bool initGUI();
	bool initPhysics();
	bool initAudio();
	bool initWindow();
	void render();
	void update();

	void initMenu();
	void initGameMain();

	void updateMenu();
	void updateGameMain();
	void updatePause();

	void contactPointCallback(const hkpContactPointEvent &event);
	void createBox(float x,float y,float z);
private:
	//Graphics
	ID3D10Device * m_pD3D10Device;
	IDXGISwapChain * m_pSwapChain;
	ID3D10RenderTargetView * m_pRenderTargetView;
	ID3D10DepthStencilView * m_pDepthStencelView;
	ID3D10Texture2D *m_pDepthStencilTexture;

	CWin32Window * m_pWindow;

	CTimer m_Timer;
	
	//Get Game Object Manager
	CGameObjectManager *m_pGameObjectManager;

	CModelLoader modelloader;

	Rocket::Core::ElementDocument *m_pMenu;
	Rocket::Core::ElementDocument *m_pInGameGUI;
	Rocket::Core::ElementDocument *m_pPause;

	GameState m_GameState;


	bool m_bUsingJoypad;

};