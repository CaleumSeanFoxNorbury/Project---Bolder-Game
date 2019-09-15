#include "Player.h"

Player::Player(const std::string & Name, int Score, std::string & username, std::string & password) : Name(Name), Score(Score), username(username), password(password)
{
}

std::string Player::getName() const
{
	return Name;
}

const std::string & Player::GetUsername() const
{
	return username;
}

const std::string & Player::GetPassword() const
{
	return password;
}

const int Player::GetScore() const
{
	return Score;
}

void Player::UpdateScore(int& updateamount)
{
	updateamount += Score;
}



