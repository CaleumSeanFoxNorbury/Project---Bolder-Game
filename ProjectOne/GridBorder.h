#pragma once
#include"MoveableGridItem.h"
#include<iostream>
#include<vector>
#include<sstream>

class GridBorder : public MoveableGridItem{
public:
	GridBorder(const char);
	void Create_Boarders();
	std::vector<MoveableGridItem> border;
private:
	int gridBorader_x, gridBorader_y;
	int xposition, yposition;
};