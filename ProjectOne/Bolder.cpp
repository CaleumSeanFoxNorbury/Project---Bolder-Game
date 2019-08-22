#include "Bolder.h"

Bolder::Bolder(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

void Bolder::MoveBolder() { //needs to be applied within a loop probs on game
	int bolderx, boldery;
	set_direction(bolderx, boldery);
	Update_Position(bolderx, boldery);
}

void Bolder::set_direction(int & bx, int & by)
{
	bx = 0; by = 0;
	
	bx = - 1;	//moving bolder 
	by = - 1;	//moving bolder 
}

