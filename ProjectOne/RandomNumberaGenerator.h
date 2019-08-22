#pragma once
#include<stdlib.h>
#include<cassert>
#include<ctime>

class RNG {
public:
	RNG();
	int GetRandomValue(int) const;
private:
	void Seed();
};