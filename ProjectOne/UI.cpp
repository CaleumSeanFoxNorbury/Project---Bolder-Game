#include<iostream>
#include "UI.h"


void UserInterface::GameData(std::string name)
{
	std::cout << "PlayerName: " << name << std::endl;
	//std::cout << "Score: " << score << std::endl;
}

void UserInterface::EndGameMessages(int& GameResults, int& score)
{	
	switch (GameResults) {
		//needs editing 
	case 1: {
		//loose
		std::cout << "YOU LOST || PERSON HAS BEEN HIT BY THE BOLDER!" << std::endl;
		std::cout << "GAME ENDED!" << std::endl;
		std::cout << "Score: " << score << std::endl;
		break;
	}
	case 2: {
		//win
		std::cout << "YOU WON || PERSON ESCAPED!" << std::endl;
		std::cout << "GAME ENDED!" << std::endl;
		std::cout << "Score: " << score << std::endl;
		break;
	}
	}
}

void UserInterface::DrawGrid(std::string grid_data)
{
	system("cls");
	std::cout << grid_data;
}

void UserInterface::Hold_Window()
{
	std::cout << "\n\n";
	system("pause");
}

int UserInterface::GetKeypressFromUser() const
{
	int keyPress(_getch());
	while (keyPress == 224) {
		keyPress = _getch();
	}
	return(toupper(keyPress));
}
