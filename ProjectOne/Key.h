#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Key : public MoveableGridItem {
public:
	Key(const char);
	bool keyHasBeenCollected() const;
private:
	bool collected = false;
	RNG rng;
};