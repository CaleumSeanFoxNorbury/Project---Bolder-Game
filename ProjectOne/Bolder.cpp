#include "Bolder.h"

Bolder::Bolder(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

int Bolder::setupBolder()
{
	int direction = rng.GetRandomValue(8);

	if (direction >= 1 && direction <= 8) {
		return direction;
	}
	else if(direction = 0){
		return direction += 2;
	}
}

void Bolder::MoveBolder(int direction_choice) { //needs to be applied within a loop probs on game
	int bolderx, boldery;
	set_direction(bolderx, boldery, direction_choice);
	Update_Position(bolderx, boldery);
}

void Bolder::set_direction(int & bx, int & by, int & direction_choice)
{
	assert(direction_choice >= 1 && direction_choice <= 8);
	bx = 0; by = 0;
	//replace all these with switch statements
	if (direction_choice == 1) {
		by -= 1;
		//maybe add another fucntion to keep taking it move and bounce off walls under all these ifs
	}
	if (direction_choice == 2) {
		by -= 1;
		bx += 1;
	}
	if (direction_choice == 3) {
		bx += 1;
	}
	if (direction_choice == 4) {
		bx += 1;
		by += 1;
	}
	if (direction_choice == 5) {
		by += 1;
	}
	if (direction_choice == 6) {
		by += 1;
		bx -= 1;
	}
	if (direction_choice == 7) {
		bx -= 1;
	}
	if (direction_choice == 8) {
		bx -= 1;
		by -= 1;
	}
}

