#pragma once 
#include<string>

class Player {
public:
	Player(const std::string);
	std::string getName() const;
private:
	const std::string Name;
};