#include "GridBorder.h"

GridBorder::GridBorder(const char symbol, int x, int y) : x(x), y(y) {

}

void GridBorder::Create_Position_Borders()
{
	/*
	
	GridBorder* BORDER = new GridBorder(gridBorader_x, 2);
	border.push_back(BORDER);
	
	do this witin a loop twenty times will co-ordinates are the borders
	*/
}

//THIS FUNCTION HASNT BEEN IMPLEMENTED YET
void GridBorder::Create_Boarders()
{
	const int SIZE(20);
	int xchange = 0 , ychange = 0;

	//examples of what i can use
	GridBorder * Startone = new GridBorder('O', 0, 0);
	GridBorder * Starttwo = new GridBorder('O', 0, 0);
	border.push_back(Startone);
	border.push_back(Starttwo);
	do {
		GridBorder * TopBoarder = new GridBorder('O', 0, xchange++);
		border.push_back(TopBoarder);
	} while (xchange != 0 && ychange == 0);
	do {
		GridBorder * LeftSide = new GridBorder('O', 0, ychange++);
		border.push_back(LeftSide);
	} while (ychange != 20 && xchange == 0);
	do {
		GridBorder * RightSide = new GridBorder('O', 0, ychange++);
		border.push_back(RightSide);
	} while (xchange == 20 && ychange != 20);
	do {
		GridBorder * Bottom = new GridBorder('O', 0, ychange++);
		border.push_back(Bottom);
	} while (xchange == 20 && ychange != 20);
}

int GridBorder::Get_X()
{
	return x;
}

int GridBorder::Get_Y()
{
	return y;
}

void GridBorder::display_boarders()
{
	for (int i(0); i < border.size(); i++) {
		
	}
}
