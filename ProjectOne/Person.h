#pragma once

#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

#define LEFT	(75)
#define RIGHT	(77)
#define DOWN	(80)
#define UP		(72)

class Person : public MoveableGridItem {
public:
	Person(char const);
	void scamper(char k);
private:
	static RNG rng_;
	int person_x;
	int person_y;

};