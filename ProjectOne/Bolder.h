#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void MoveBolder();
private:
	void set_direction(int& bx, int& by);
	RNG rng;
	static int direction;
	int bolder_x;
	int bolder_y;
};