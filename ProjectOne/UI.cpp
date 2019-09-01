#include<iostream>
#include "UI.h"


std::ostringstream UserInterface::GameData(std::string name)
{
	std::ostringstream os;
	os << "Players Name: " << name << std::endl;
	return os;
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
