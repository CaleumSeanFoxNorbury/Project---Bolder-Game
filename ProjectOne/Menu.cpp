#include "Menu.h"

Menu::Menu(const std::string & title, Application * app) : _title(title), app(app)
{

}

void Menu::DisplayMenu()
{
	do {
		Header();
		OutputMenuOptions();
		Footer();

		char choice = ut.getCHARfromuser();
		if (choice == 'B') {
			readytogoback = true;
		}
		else {
			readytogoback = HandleMenuOption(choice);
		}
	} while (!readytogoback);
}

void Menu::Header()
{
	ui_M.ClearScreen();
	std::cout << "*******************" << std::endl;
	std::cout << "*   " << _title << "     *" << std::endl;
	std::cout << "*******************" << std::endl;
}

void Menu::Footer()
{
	std::cout << "*******************" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << ">>> ";
}
