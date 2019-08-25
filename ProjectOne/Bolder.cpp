#include "Bolder.h"

Bolder::Bolder(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

void Bolder::setupBolder()
{
	get_Direction();
}

void Bolder::MoveBolder() { //needs to be applied within a loop probs on game
	int bolderx, boldery;
	set_direction(bolderx, boldery);
	Update_Position(bolderx, boldery);
}

int Bolder::get_Direction()
{
	int direction = rng.GetRandomValue(8);

	do {
		direction = rng.GetRandomValue(8);
	} while (direction != 0);
	
	if (direction >= 1 && direction <= 8) {
		return direction;
	}
}

void Bolder::set_direction(int & bx, int & by)
{
	bx = 0; by = 0;
	if (get_Direction() == 1) {
		bx += 1;
	}
	else {
		bx = - 1;	//moving bolder 
		by = - 1;	//moving bolder 
	}
}

