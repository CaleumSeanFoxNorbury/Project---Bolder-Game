#include "Player.h"

Player::Player(const std::string Name, int Score) : Name(Name), Score(Score)
{

}

std::string Player::getName() const
{
	return Name;
}

int Player::GetScore() const
{
	return Score;
}

void Player::UpdateScore(int& updateamount)
{
	updateamount += Score;
}
