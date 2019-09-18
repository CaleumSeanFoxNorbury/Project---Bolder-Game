#pragma once
#include "GridItem.h"
#include "RandomNumberaGenerator.h"
#include<sstream>


class MoveableGridItem : public GridItem
{
public:
	MoveableGridItem(int,int, char);
	~MoveableGridItem();
	int Get_X();
	int Get_Y();
	bool const IsAtPossition(int, int);
	void Set_XY(int, int);
	void Update_Position(int, int);
	//positioning 
	void RandomPosition();
	void GRIDTWO_RandomPositon();
	//

	friend std::ostream& operator<<(std::ostream & os, MoveableGridItem & rhs);
private:
	RNG rng;
	//int x, y;
	int _x;
	int _y;
};