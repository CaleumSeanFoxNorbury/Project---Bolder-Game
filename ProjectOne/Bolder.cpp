#include "Bolder.h"

Bolder::Bolder(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

int Bolder::setupBolder()
{
	int direction = rng.GetRandomValue(4);

	if (direction <= 4  && direction >= 1) {
		return direction;
	}
	else {
		direction = rng.GetRandomValue(4);
		return direction;
	}
}

void Bolder::MoveBolder() { 
	int bolderx, boldery;
	set_direction(bolderx, boldery);
	if (((Get_X() + bolderx) >= 1) && ((Get_X() + bolderx) <= 20) &&
		((Get_Y() + boldery) >= 1) && ((Get_Y() + boldery) <= 20)) {
		Update_Position(bolderx, boldery);
	}
	else {
		int newx, newy;
		Bounce(newx, newy);
		if (((Get_X() + newx) >= 1) && ((Get_X() + newx) <= 20) &&
			((Get_Y() + newy) >= 1) && ((Get_Y() + newy) <= 20)) {
			Update_Position(newx, newy);
		}
	}
}

void Bolder::set_direction(int & bx, int & by)
{
	assert(direction_choice >= 1 && direction_choice <= 8);
	bx = 0; by = 0;
	if (direction_choice == 1) {
		//going down left
		by -= 1;
		bx += 1;
	}
	if (direction_choice == 2) {
		//going down right
		bx += 1;
		by += 1;
	}
	if (direction_choice == 3) {
		//going up right
		by += 1;
		bx -= 1;
	}
	if (direction_choice == 4) {
		//going up left 
		bx -= 1;
		by -= 1;
	}
}

void Bolder::Bounce(int& bx, int& by)
{
	bool Up_right = false;
	bool Up_left = false;
	bool Down_right = false;
	bool Down_left = false;

	switch (direction_choice) {
	case 1: {
		Down_left = true;
		break;
	}
	case 2: {
		Down_right = true;
		break;
	}
	case 3: {
		Up_right = true;
		break;
	}
	case 4: {
		Up_left = true;
		break;
		}
	}

	//GET Y && Y ARE BOTH == TO X's (CODE PROBLEM)
	if (Up_right) { 
		if (Get_X() <= 1) {			//this is actuall y 		
			direction_choice = 2;
		}
		if (Get_Y() >= 20) {		//this is actually x
			direction_choice = 4;
		}
	}
	if (Up_left) {
		if (Get_X() <= 1) {
			direction_choice = 1;
		}
		if (Get_Y() <= 1) {
			direction_choice = 3;
		}
	}
	if (Down_right) {
		if (Get_X() >= 20) {
			direction_choice = 3;
		}
		if (Get_Y() >= 20) {
			direction_choice = 1;
		}
	}
	if (Down_left) {
		if (Get_X() >= 20) {
			direction_choice = 4;
		}
		if (Get_Y() <= 1) {
			direction_choice = 2;
		}
	}
}