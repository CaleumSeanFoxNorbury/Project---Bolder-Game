#include<iostream>
#include<string>

#include"UI.h"
#include"Game.h"
#include"Player.h"

int main() {
	UserInterface ui;
	std::string Name;											//{
	int Score = 0;
	std::cout << "Please Enter Your NickName: " << std::endl;	//	create this as a message functions within an output .h and .cpp
	std::cin >> Name;											//}

	char carry_on;
	do {
		Player player(Name, Score);
		Game game(&player);
		game.SetUpGame();

		std::cout << "Play again? (Y/N): ";
		std::cin >> carry_on;
	} while (tolower(carry_on) == 'y');
	ui.Hold_Window();
	
	return(0);
}

//TODO::
//apply polomorhic behavour ansd inheritance to bolder and create player