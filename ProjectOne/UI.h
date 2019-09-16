#pragma once

#include<iostream>
#include<conio.h>
#include<string>

#include"Game.h"
#include"Application.h"
#include"Utils.h"

class UserInterface {
public:
	//maybe sort these fucntions out
	void GettingUser(std::string&);
	void GameData(std::string, int, std::string&);
	void EndGameMessages(int&, int&);
	void DrawGrid(std::string grid_data); 
	void Hold_Window();
	int GetKeypressFromUser() const;
	void CreatePlayer(std::string&, std::string&, std::string&);

	void ClearScreen();
	
	void Line();
	void Line(const std::string&);
	void Option(int, const std::string&);
	//void Option(char id, const std::string& option);
	std::string Question(const std::string&);

private: 
	Application app;
	Utils ut;
};
