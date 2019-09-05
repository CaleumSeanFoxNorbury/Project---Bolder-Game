#pragma once
#include"MoveableGridItem.h"
#include"RandomNumberaGenerator.h"

class Gate : public MoveableGridItem {
public:
	Gate(const char);

private:
	RNG rng;
};