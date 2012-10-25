//Are we on the windows platform?
#ifdef WIN32
//if so include the header for windows applications
#include <Windows.h>
#endif


#include "GameApplication.h"

//Check to see if we are on windows
#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, 
					HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine,
					int nCmdShow)
{
	CGameApplication*pApp=new CGameApplication();//Allocates pointer to the GameApplicationClass

	if(!pApp->init())//Checks to see if it can be Initilized
	{
		delete pApp;//if it cannot be Initilized delete th epointer
		pApp=NULL;
		return 1;
	}

	pApp->run();//If it can be Initilized call the run function which acts as the game loop

	if(pApp)
	{
		delete pApp;//once the game loop is over delete the pointer
		pApp=NULL;
	}
	return 0;
}


#else
//we are on some other platform
int main(int argc, char **argv)
#endif


