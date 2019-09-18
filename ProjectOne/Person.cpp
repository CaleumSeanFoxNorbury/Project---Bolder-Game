#include "Person.h"

RNG Person::rng_;
Person::Person(const char symbol) : MoveableGridItem(rng_.GetRandomValue(20), rng_.GetRandomValue(20), symbol), person_x(0), person_y(0), gate(gate)
{
}

void Person::scamper(char k, std::string& game)
{
	switch (k) {
	case LEFT:
		person_x = -1;
		person_y = 0;
		break;
	case RIGHT:
		person_x = +1;
		person_y = 0;
		break;
	case UP:
		person_x = 0;
		person_y = -1;
		break;
	case DOWN:
		person_x = 0;
		person_y = +1;
		break;
	}
	if (game == "LevelOne") {	//replace this title everywhere
		if (((Get_X() + person_x) >= 1) && ((Get_X() + person_x) <= 20) &&
			((Get_Y() + person_y) >= 1) && ((Get_Y() + person_y) <= 20))
		{
			Update_Position(person_x, person_y);
		}
	}
	if (game == "ChapterTwo") {
		if (((Get_X() + person_x) >= 1) && ((Get_X() + person_x) <= 100) &&
			((Get_Y() + person_y) >= 1) && ((Get_Y() + person_y) <= 100))
		{
			Update_Position(person_x, person_y);
		}
	}
}

bool Person::IsStillAlive() const
{
	return alive;
}

bool Person::GateOpen() const
{
	return HasKey;
}

void Person::Die()
{
	alive = false;
}

void Person::OpenGate()
{
	HasKey = true;
}

//cant include header files two way system game.h cant include person.h if person.h already includes game.h