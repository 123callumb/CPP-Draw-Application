#pragma once
#include "EasyGraphics.h"

// This is a singleton class that stores the current values of current colours and selected tools.
class GlobalSettings
{
public:
	inline static GlobalSettings * getInstance();
	inline int getFillColour(), getOutlineColour(), getControl();
	inline bool isShiftDown();
	void setFillColour(int colour), setOutlineColour(int colour), setControlID(int controlID), setShiftDown(bool value);
private:
	GlobalSettings();
	~GlobalSettings();
	static GlobalSettings * instance;
	CRITICAL_SECTION lock;
	int currentFilllColour = EasyGraphics::clBlack;
	int currentOutlineColour = EasyGraphics::clBlack;
	int currentControlID = 0; // set as draw rectangle as defualt.
	bool shiftDown = false;
};


inline GlobalSettings::GlobalSettings() {
	InitializeCriticalSection(&lock);
}

inline GlobalSettings * GlobalSettings::getInstance()
{
	if (!instance)
		instance = new GlobalSettings();
	return instance;
}

inline int GlobalSettings::getFillColour()
{
	return currentFilllColour;
}

inline int GlobalSettings::getOutlineColour()
{
	return currentOutlineColour;
}

inline int GlobalSettings::getControl()
{
	return currentControlID;
}

inline bool GlobalSettings::isShiftDown()
{
	return shiftDown;
}

inline void GlobalSettings::setFillColour(int colour)
{
	EnterCriticalSection(&lock);
	currentFilllColour = colour;
	LeaveCriticalSection(&lock);
}

inline void GlobalSettings::setOutlineColour(int colour)
{
	EnterCriticalSection(&lock);
	currentOutlineColour = colour;
	LeaveCriticalSection(&lock);
}

inline void GlobalSettings::setControlID(int controlID)
{
	EnterCriticalSection(&lock);
	currentControlID = controlID;
	LeaveCriticalSection(&lock);
}

inline void GlobalSettings::setShiftDown(bool value)
{
	EnterCriticalSection(&lock);
	shiftDown = value;
	LeaveCriticalSection(&lock);
}

