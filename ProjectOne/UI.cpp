#include<iostream>
#include "UI.h"


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
