#pragma once
#include "EasyGraphics.h"
#include "MenuUI.h"
using namespace std;



class Interface :
	public EasyGraphics
{
public:
	Interface(HINSTANCE hInstance);
	~Interface();
private:
	MenuUI controlMenu;

	void onCreate();
	void onDraw();
	void onMouseMove(UINT nFlags, int x, int y);
	void onLButtonDown(UINT nFlags, int x, int y);
};

