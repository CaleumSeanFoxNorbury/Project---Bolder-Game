#include "Bolder.h"

Bolder::Bolder(const char symbol) : symbol(symbol), MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
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

void Bolder::GatherKey(int & kx, int & ky)
{
	int Keyx = 0, Keyy = 0;
	SetDirectionToKey(kx, ky);
	set_direction(Keyx, Keyy);
	if (((Get_X() + Keyx) >= 1) && ((Get_X() + Keyx) <= 20) &&
		((Get_Y() + Keyy) >= 1) && ((Get_Y() + Keyy) <= 20)) {
		Update_Position(Keyx, Keyy);
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
		int newx = 0 , newy = 0;
		Bounce();
		if (((Get_X() + newx) >= 1) && ((Get_X() + newx) <= 20) &&
			((Get_Y() + newy) >= 1) && ((Get_Y() + newy) <= 20)) {
			Update_Position(newx, newy);
		}
	}
}

void Bolder::BounceOffObjects()
{
	Bounce();
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
	if (direction_choice == 5) {
		//Going left
		by -= 1;
	}
	if (direction_choice == 6) {
		//going right
		by += 1;
	}

	if (direction_choice == 7) {
		//Going up
		bx -= 1;
	}
	if (direction_choice == 8) {
		//going down
		bx += 1;
	}
}

void Bolder::SetDirectionToKey(int& kx, int& ky)
{
	assert(kx >= 1 && kx <= 20 && kx >= 1 && kx <= 20);
	if (Get_X() < ky && Get_Y() < kx) {
		//down right
		direction_choice = 2;
	}
	if (Get_X() < ky && Get_Y() > kx) {
		//up right
		direction_choice = 5;
	}
	if (Get_X() < ky && Get_Y() == kx) {
		//right
		direction_choice = 5;
	}
	if (Get_X() > ky && Get_Y() < kx) {
		//down and left
		direction_choice = 3;
	}
	if (Get_X() > ky && Get_Y() > kx) {
		//up and left
		direction_choice = 4;
	}
	if (Get_X() > ky && Get_Y() == kx) {
		//left
		direction_choice = 6;
	}
	if (Get_X() == ky && Get_Y() > kx) {
		//down
		direction_choice = 8;
	}
	if (Get_X() == ky && Get_Y() < kx) {
		//up
		direction_choice = 7;
	}
}

void Bolder::Bounce()
{
	bool Up_right = false;
	bool Up_left = false;
	bool Down_right = false;
	bool Down_left = false;
	bool Right = false;
	bool Left = false;

	
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
	case 5: {
		Left = true;
	}
	case 6: {
		Right = true;
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
	if (Left) {
		if (Get_X() <= 10)
			direction_choice = 2;
		if(Get_X() >= 10)
		direction_choice = 3;

	}
	if (Right) {
		if (Get_X() <= 10)
			direction_choice = 2;
		if (Get_X() >= 10)
			direction_choice = 3;
	}
}

