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
	int keyX = 0, keyY = 0;
	setDirection();

	if ((bolder_key_->Get_X() - 1) < 1){
		Set_XY(bolder_key_->Get_Y(), bolder_key_->Get_X() + 1);
	}
	else {
		Update_Position(keyX, keyY);
	}
	if ((bolder_key_->Get_X() + 1) > 20){
		Set_XY(bolder_key_->Get_Y(), bolder_key_->Get_X() - 1);
	}
	else {
		Update_Position(keyX, keyY);
	}
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

void Key::setDirection()
{
	assert(bolder_key_ != nullptr);	
	Set_XY(bolder_key_->Get_Y(), bolder_key_->Get_X() - 1);
}

