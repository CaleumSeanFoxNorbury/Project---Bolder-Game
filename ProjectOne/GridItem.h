#pragma once

class GridItem
{
public:
	GridItem(char const symbol);
	~GridItem();
	char GetSymbol();
private:
	const char symbol;
};