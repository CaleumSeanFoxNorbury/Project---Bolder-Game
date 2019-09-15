#pragma once
#include<iostream>
#include<conio.h>
#include<string>

#include"Game.h"
#include"Application.h"

class UserInterface {
public:
	//maybe sort these fucntions out
	void GettingUser(std::string&);
	void GameData(std::string, int);
	void EndGameMessages(int&, int&);
	void DrawGrid(std::string grid_data); 
	void Hold_Window();
	int GetKeypressFromUser() const;
	void OutputLevel(std::string&) const;
	void CreatePlayer(std::string&, std::string&, std::string&);
private: 
	Application app;
};
