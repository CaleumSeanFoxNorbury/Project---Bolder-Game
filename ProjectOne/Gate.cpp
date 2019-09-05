#include "Gate.h"

Gate::Gate(const char symbol) : MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}
