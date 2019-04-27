#pragma once
// This is an abstract class for a collection of controls to be placed.
class ControlPanel
{
public:
	ControlPanel();
	~ControlPanel();
	inline void setSelectedControl(int value);
	inline int getSelectedControl();
private:
	int selectedControlID = 0; // 0 is no conrol selected. All control IDs should start from 1 index.
};

inline int ControlPanel::getSelectedControl()
{
	return selectedControlID;
}

inline void ControlPanel::setSelectedControl(int value)
{
	selectedControlID = value;
}

