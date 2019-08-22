#include "RandomNumberaGenerator.h"

RNG::RNG()
{
	Seed();
}

int RNG::GetRandomValue(int max) const
{
	return (rand() % max) + 1;
}

void RNG::Seed()
{
	srand(static_cast<unsigned>(time(0)));
}
