#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void MoveBolder();
	int setupBolder();
	//void Bounce(int&, int&);
	
	int direction_choice = 0;
private:
	void set_direction(int& bx, int& by);
	void Bounce(int & bx, int & by);
	RNG rng;
	int bolder_x;
	int bolder_y;
};