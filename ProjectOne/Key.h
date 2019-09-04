#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"
#include"Bolder.h"

class Key : public MoveableGridItem {
public:
	Key(const char);
	void SpotBolder(Bolder * bolder);
	void Follow_Bolder();
	bool PersonCollected() const;
	bool BolderCollected() const;
	void Person_NutDisappear();
	void setDirection(int& bx, int& by);
	void KeyFollowBolder();
	bool BolderGotKey();
	Bolder * bolder_key_;
private:
	bool Boldercollected = false;
	bool Personcollected = false;
	RNG rng;
};