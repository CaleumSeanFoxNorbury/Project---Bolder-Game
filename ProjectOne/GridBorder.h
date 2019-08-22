#pragma once
#include"GridItem.h"
#include<vector>

class GridBorder :public GridItem {
public:
	GridBorder(const char);
private:
	std::vector<GridBorder> border;

};