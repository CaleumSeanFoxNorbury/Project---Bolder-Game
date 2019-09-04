#include "Key.h"

Key::Key(const char symbol):MoveableGridItem(rng.GetRandomValue(20), rng.GetRandomValue(20), symbol)
{
}

void Key::SpotBolder(Bolder * bolder_key)
{
	assert(bolder_key != nullptr);
	bolder_key_ = bolder_key;
}

void Key::Follow_Bolder()
{
	int keyX, keyY;
	setDirection(keyX, keyY);
	Update_Position(keyX, keyY);
}

bool Key::PersonCollected() const
{
	return Personcollected;
}

bool Key::BolderCollected() const
{
	return Boldercollected;
}

void Key::KeyFollowBolder()
{
	Boldercollected = true;
}
bool Key::BolderGotKey()
{
	return Boldercollected;
}

void Key::Person_NutDisappear()
{
	Personcollected = true;
}

void Key::setDirection(int & bx, int & by)
{
	//IF THIS DOESNT WORK TRY SET GET AND Y TO BOLDER Y - 1
	assert(bolder_key_ != nullptr);
	
	bx = 0; by = 0;
	if (Get_X() < bolder_key_->Get_X()) {
		bx = 1;
	}else
		if (Get_X() > bolder_key_->Get_X()) {
			bx = -1;
		}
		else
			if (Get_Y() < bolder_key_->Get_Y()) {
				by = 1;
			}
			else
				if (Get_Y() > bolder_key_->Get_Y()) {
					by = -1;
				}
}

