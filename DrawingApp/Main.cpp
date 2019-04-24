#include "Interface.h"
#include <Windows.h>
#include <crtdbg.h>   // for debug memory stuff


using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef _DEBUG   // only include this section of code in the DEBUG build
	//  _CrtSetBreakAlloc(65);  // really useful line of code to help find memory leaks
	_onexit(_CrtDumpMemoryLeaks); // check for memory leaks when the program exits
#endif

	Interface inter(hInstance);

	return 0;
}