#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Bolder : public MoveableGridItem {
public:
	Bolder(const char);
	void MoveBolder();
	void BounceOffObjects();
	int setupBolder();
	void GatherKey(int&, int&);
	
	int direction_choice = 0;
private:
	RNG rng;
	void set_direction(int& bx, int& by);
	void SetDirectionToKey(int&, int&);
	void Bounce();
	int bolder_x;
	int bolder_y;
	
	const char symbol = 'B';
};