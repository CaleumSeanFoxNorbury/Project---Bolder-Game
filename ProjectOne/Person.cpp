#include "Person.h"

RNG Person::rng_;
Person::Person(const char symbol) : MoveableGridItem(rng_.GetRandomValue(20), rng_.GetRandomValue(20), symbol), person_x(0), person_y(0)
{
}

void Person::scamper(char k)
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
	//UPDATE CO-ORDIATES(PRE-conditions)
	if (((Get_X() + person_x) >= 1) && ((Get_X() + person_x) <= 20) &&
		((Get_Y() + person_y) >= 1) && ((Get_Y() + person_y) <= 20))
	{
		Update_Position(person_x, person_y);
	}
}

//cant include header files two way system game.h cant include person.h if person.h already includes game.h