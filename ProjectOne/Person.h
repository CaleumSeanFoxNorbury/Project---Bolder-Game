#pragma once

#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"
#include"Gate.h"

#define LEFT	(75)
#define RIGHT	(77)
#define DOWN	(80)
#define UP		(72)

class Person : public MoveableGridItem {
public:
	Person(char const);
	void scamper(char k); //will be inherited in stage two
	bool IsStillAlive() const;
	bool GateOpen() const; //can be virutal for stage two (game two)
	void Die();
	void OpenGate();
private:
	static RNG rng_;
	Gate gate;
	bool HasKey = false;
	bool alive = true;
	int person_x;
	int person_y;

};