#include "Bolder.h"

Bolder::Bolder(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

int Bolder::setupBolder()
{
	/*int direction = rng.GetRandomValue(4);

	if (direction >= 1 && direction <= 4) {
		return direction;
	}
	else if (direction = 0) {
		return direction += 2;
	}
	return direction = 4;*/
	int direction = 3; //remove this
	return direction;
}

void Bolder::MoveBolder(int direction_choice) { 
	int bolderx, boldery;
	set_direction(bolderx, boldery, direction_choice);
	if (((Get_X() + bolderx) >= 1) && ((Get_X() + bolderx) <= 20) &&
		((Get_Y() + boldery) >= 1) && ((Get_Y() + boldery) <= 20)) {
		Update_Position(bolderx, boldery);
	}
	else {
		int newx, newy;
		Bounce(newx, newy, direction_choice);
		if (((Get_X() + newx) >= 1) && ((Get_X() + newx) <= 20) &&
			((Get_Y() + newy) >= 1) && ((Get_Y() + newy) <= 20)) {
			Update_Position(newx, newy);
		}
	}
}

void Bolder::set_direction(int & bx, int & by, int & direction_choice)
{
	assert(direction_choice >= 1 && direction_choice <= 8);
	bx = 0; by = 0;
	//replace all these with switch statements
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

void Bolder::Bounce(int& bx, int& by, int & direction_choice)
{
	//TODO::
	//MOVE BOLDER AS IT BOUNCES 
	// SET NEW DIRECTION COURSE

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
	// this is nearly correct ////////////////////////////////////////////////////
	if (Up_right) {
		if (Get_X() >= 1) {	//this is actuall y 		
			direction_choice = 2; //down right 
		}
		if (Get_Y() >= 20) {	//this is actually x

			direction_choice = 4;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	if (Up_left) {
		if (Get_X() <= 1) {
			by += 1;
			bx += 1;
		}
		if (Get_Y() <= 1) {
			bx += 1;
			by -= 1;
		}
	}
	if (Down_right) {

	}
	if (Down_left) {

	}

	/*
	//these are correct
	if (Get_X() <= 1) {
		bx -= 1;
	}
	if (Get_X() >= 20) {
		Set_XY(20, 20);
	}
	if (Get_Y() <= 1) {
		Set_XY(10, 10);
	}
	if (Get_Y() >= 20) {
		Set_XY(20, 20);
	}
	*/
	/*
	
	switch (Get_X()) {
	case 1: {
		bx++;
	}
	case 19: {
		bx--;
	}
	}

	switch (Get_Y()) {
	case 1: {
		by++;
	}
	case 19: {
		by--;
	}
	}
	*/




	/*

		//USING
	//Set_XY(21, 21);
	while (MoveableGridItem::Get_X() == 1) {
		by++;
	}
	if (MoveableGridItem::Get_X() == 1) {
		by += 1;
	}
	if (MoveableGridItem::Get_X() == 21) {
		bx -= 1;
		Update_Position(bx, by);
	}
	if (MoveableGridItem::Get_Y() == 1) {
		by += 1;
		Update_Position(bx, by);
	}
	if (MoveableGridItem::Get_Y() == 21) {
		by -= 1;
		Update_Position(bx, by);
	}

	if ((new_y > old_y) &&)) {
		//going down
	}
		if (IsAtPossition(bx == 1, by++)) {
		bx += 1;
		by -= 1;
	}
	if (IsAtPossition(bx == 1, by--)) {
		bx += 1;
		by += 1;
	}
	if (IsAtPossition(bx++, by == by)) {
		bx += 1;
	}
	*/
}


