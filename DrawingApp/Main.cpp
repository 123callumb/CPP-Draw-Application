#include "Interface.h"
#include <Windows.h>
#include <crtdbg.h>   // for debug memory stuff

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
 //I have so many memeory leaks, I don't even know what half of them are caused by. I ran out of time.
#ifdef _DEBUG   // only include this section of code in the DEBUG build
	//_CrtSetBreakAlloc(310);  // really useful line of code to help find memory leaks
	_onexit(_CrtDumpMemoryLeaks); // check for memory leaks when the program exits
#endif

	Interface inter(hInstance);
	// this is mean to destroy everything created....
	inter.onClose();
	return 0;
}