#include "Player.h"

Player::Player(const std::string Name) : Name(Name)
{

}

std::string Player::getName() const
{
	return Name;
}
