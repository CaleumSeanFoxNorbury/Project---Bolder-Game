#include "Key.h"

Key::Key(const char symbol):MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

bool Key::keyHasBeenCollected() const
{
	return collected;
}
