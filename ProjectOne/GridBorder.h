#pragma once
#include"MoveableGridItem.h"
#include<vector>

class GridBorder :public MoveableGridItem {
public:
	GridBorder(const char);
	void Create_Position_Borders();
private:
	std::vector<GridBorder> border;
	int gridBorader_x, gridBorader_y;

};