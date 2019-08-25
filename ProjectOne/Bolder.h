#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void setupBolder();
	void MoveBolder();
private:
	int get_Direction();
	void set_direction(int& bx, int& by);
	RNG rng;
	int bolder_x;
	int bolder_y;
};