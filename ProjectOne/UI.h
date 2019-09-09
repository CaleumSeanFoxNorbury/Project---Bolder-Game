#pragma once
#include<conio.h>
#include<string>
#include"Game.h"


class UserInterface {
public:
	void GameData(std::string);
	void EndGameMessages(int&, int&);
	void DrawGrid(std::string grid_data); //override
	void Hold_Window();
	int GetKeypressFromUser() const;
};
