#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void MoveBolder(int);
	int setupBolder();
	//void Bounce(int&, int&);
	
private:
	void set_direction(int& bx, int& by, int& direction_choice);
	void Bounce(int & bx, int & by, int & direction_choice);
	RNG rng;
	int bolder_x;
	int bolder_y;
};