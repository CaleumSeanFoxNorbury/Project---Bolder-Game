#pragma once 
#include<string>

#include"List.h"


class Player {
public:
	Player(const std::string&, int, std::string&, std::string&);

	std::string getName() const; 
	const std::string& GetUsername() const;
	const std::string& GetPassword() const;
	const int GetScore() const;	
	void UpdateScore(int&);
	
private:
	const std::string Name;
	const std::string username;
	const std::string password;
	int Score = 0;
};