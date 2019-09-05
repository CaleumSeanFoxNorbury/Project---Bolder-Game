#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void MoveBolder();
	void BounceOffObjects();
	int setupBolder();
	int direction_choice = 0;
	void GatherKey(int&, int&);
private:
	RNG rng;
	void set_direction(int& bx, int& by);
	void SetDirectionToKey(int&, int&);
	void Bounce();
	int bolder_x;
	int bolder_y;
};