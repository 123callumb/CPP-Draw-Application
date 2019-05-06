#pragma once
#include "EasyGraphics.h"
#include "MenuUI.h"
#include "Tools.h"
#include "Canvas.h"
#include "GlobalSettings.h"

using namespace std;

class Interface :
	public EasyGraphics
{
public:
	Interface(HINSTANCE hInstance);
	~Interface();
	void onClose();
private:
	HINSTANCE hInst;

	Canvas canvas;
	MenuUI controlMenu;
	Tools tools;

	void onCreate();
	void onDraw();
	void onMouseMove(UINT nFlags, int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
	// For tools that use shift as a function
	void onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);  
	void onKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

