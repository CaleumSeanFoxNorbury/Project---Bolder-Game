#include "Game.h"

Game::Game(Player * player) : player(player), person(PERSON), bolder(BOLDER), gridb_(GRIDBOARDERS) //NEEDS TO CHECK AS SHOULDNT LINK TO CONSTRUCTOR LINK
{
}

void Game::run()
{
	UserInterface ui_G;
	int Bolders_Direction = bolder.setupBolder();
	
	person.RandomPosition();
	bolder.RandomPosition();
	//TODO::MAKE SURE NOTHING OVERLAPS WITHIN THE GRID WHILE BEING POSITIONED RANDOMLY 
	ui_G.DrawGrid(Prepare_Grid());
	//TODO::PRING SCORES, NAME AND OTHER INFO FOR GAME(RUNNING INFO)
	key = ui_G.GetKeypressFromUser();
	while (!game_ended(key)) {
		bolder.MoveBolder(Bolders_Direction);
		if (isArrowKeyCode(key)) {
			person.scamper(key);
			ui_G.DrawGrid(Prepare_Grid());
			//apply scores and stuff again
			//apply rules fucntion goes here
		}
		key = ui_G.GetKeypressFromUser();
	}
	//GETRESULTS AND END GAME STUFF
}

std::string Game::Prepare_Grid() 
{
	std::ostringstream os;
	for (int row(1); row <= SIZE; ++row) {
		for (int col(1); col <= SIZE; ++col) {
			if ((row == person.Get_Y()) && (col == person.Get_X())) {
				os << PERSON;
				//os << person.GetSymbol();
			}
			else
			{
				if ((row == bolder.Get_X()) && (col == bolder.Get_Y())) {
					os << BOLDER;
				}
				else {
					if ((row == 0) && (col == 0)) {
						os << GRIDBOARDER;
					}
					else {
						os << FREECELL;
					}
				}
			}
		}
		os << std::endl;
	}
	return os.str();
}

bool Game::game_ended(char key)
{
	return (key == 'Q'); //add more stuff to end the game
}

std::string Game::GameEnded(char key)
{
	std::ostringstream os;
	if (key == QUIT) {
		os << "Game Has Ended!" << std::endl; // or prep end game message
	}
	return os.str();
}

bool Game::isArrowKeyCode(int Keycode)
{
	return (Keycode == LEFT) || (Keycode == RIGHT) || (Keycode == UP) || (Keycode == DOWN);
}

/*
					if ((row == gridb_.Get_X()) && (col == gridb_.Get_Y())) {
						for (int i(0); i < gridb_.border.size(); i++) {
							os << GRIDBOARDER;
						}
					}
*/