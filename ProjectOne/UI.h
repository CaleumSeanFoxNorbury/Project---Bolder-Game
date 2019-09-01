#pragma once
#include<conio.h>
#include<string>
#include"Game.h"


class UserInterface {
public:
	std::ostringstream GameData(std::string);
	void DrawGrid(std::string grid_data); //override
	void Hold_Window();
	int GetKeypressFromUser() const;
};
