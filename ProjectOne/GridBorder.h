#pragma once
#include"MoveableGridItem.h"
#include<vector>

class GridBorder {
public:
	GridBorder(const char, int, int);
	void Create_Position_Borders();
	int Get_X();
	int Get_Y();
	void display_boarders();
	std::vector<GridBorder*> border;
private:
	void Create_Boarders();
	int gridBorader_x, gridBorader_y;
	int x, y;
};