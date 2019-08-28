#include "GridBorder.h"

GridBorder::GridBorder(const char symbol) : MoveableGridItem(xposition, yposition, symbol){

}

void GridBorder::Create_Boarders()
{
	//CREATES A BORDER
	int xc(1), yc(1);
	MoveableGridItem Border = MoveableGridItem(GetSymbol(), xc, yc);
	Border.Set_XY(xc, yc);
	border.push_back(Border);

	/*
	do { //this double everything 
		MoveableGridItem Border = MoveableGridItem('0', xc, yc);
		Border.Set_XY(xc, yc++);
		border.push_back(Border);
	} while (yc == 20);
	*/
	/*
	const int SIZE(20);
	MoveableGridItem * Startone = new MoveableGridItem('O', 0, 0);
	MoveableGridItem * Starttwo = new MoveableGridItem('O', 0, 0);
	border.push_back(Startone);
	border.push_back(Starttwo);
	int xchange = 0, ychange = 0;
	
	do {
		MoveableGridItem * TopBoarder = new MoveableGridItem('O', 0, xchange++);
		border.push_back(TopBoarder);
	} while (xchange != 20 && ychange == 0);
	do {
		MoveableGridItem * LeftSide = new MoveableGridItem('O', 0, ychange++);
		border.push_back(LeftSide);
	} while (ychange != 20 && xchange == 0);
	do {

		MoveableGridItem * RightSide = new MoveableGridItem('O', 0, ychange++);
		border.push_back(RightSide);
	} while (xchange == 20 && ychange != 20);
	do {
		MoveableGridItem * Bottom = new MoveableGridItem('O', 0, ychange++);
		border.push_back(Bottom);
	} while (xchange == 20 && ychange != 20);
	*/
}

