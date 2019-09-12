#pragma once 
#include<string>

class Player {
public:
	Player(const std::string, int);
	std::string getName() const; 
	int GetScore() const;
	void UpdateScore(int&);
private:
	const std::string Name;
	int Score;
};