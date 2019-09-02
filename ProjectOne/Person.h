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
	bool IsStillAlive() const;
	void Die();
private:
	static RNG rng_;
	bool alive = true;
	int person_x;
	int person_y;

};