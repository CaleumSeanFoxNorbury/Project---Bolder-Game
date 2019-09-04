#include "Game.h"

Game::Game(Player * player) : player(player), person(PERSON), bolder(BOLDER), gridb_(GRIDBOARDER), gridkey(GRIDKEY)//NEEDS TO CHECK AS SHOULDNT LINK TO CONSTRUCTOR LINK
{
}

void Game::run()
{
	int eachcircle = 0;
	int score = 0;
	UserInterface ui_G;
	bolder.direction_choice = bolder.setupBolder();
	person.RandomPosition();
	bolder.RandomPosition();
	gridkey.RandomPosition();
	gridb_.Create_Boarders();
	//TODO::MAKE SURE NOTHING OVERLAPS WITHIN THE GRID WHILE BEING POSITIONED RANDOMLY 
	ui_G.DrawGrid(Prepare_Grid());
	ui_G.GameData(player->getName());
	GameOneRules();
	key = ui_G.GetKeypressFromUser();
	while (!game_ended(key)) {	
		if (!gridkey.BolderCollected()) {
			int gridKeyx = 0; int gridKeyy = 0;
			gridKeyx = gridkey.Get_X();
			gridKeyy = gridkey.Get_Y();
			bolder.GatherKey(gridKeyx, gridKeyy);
		}
		if(gridkey.BolderGotKey()){
			bolder.MoveBolder();	
			gridkey.SpotBolder(&bolder);
			gridkey.Follow_Bolder();			
		}
		//	APPLY BOLDER COLLECTED KEY FUNCTION THAT FOLLOWS BOLDER
		//if (eachcircle == 10) {
			//move direction 
			//also allow bolders special moves after so long on the game
		//}
		if (isArrowKeyCode(key)) {
			person.scamper(key);
			ui_G.DrawGrid(Prepare_Grid());
			ui_G.GameData(player->getName());
			GameOneRules();
			eachcircle++;
		}
		key = ui_G.GetKeypressFromUser();
	}
	ui_G.EndGameMessages(score);
}

std::string Game::Prepare_Grid() 
{
	std::ostringstream os;
	for (int row(1); row <= SIZE; ++row) {
		for (int col(1); col <= SIZE; ++col) {
			for (int i(0); i < gridb_.border.size(); i++) {
				if ((row == gridb_.border[i].Get_X()) && (col == gridb_.border[i].Get_Y())) {		//OUTPUTS THE ADDRESS NOT THE SYMBOL one step closer
					os << gridb_.border[i];
				}
				else {
					if ((row == person.Get_Y()) && (col == person.Get_X())) {		
						os << PERSON;
					}
					else
					{
						if ((row == bolder.Get_X()) && (col == bolder.Get_Y()))/*this is where my code swopped its x and ys*/ {
							os << BOLDER;
						}
						else {
							if ((row == gridkey.Get_Y()) && (col == gridkey.Get_X()) && (!gridkey.PersonCollected())) {
								os << GRIDKEY;
							}
							else {
								os << FREECELL;
							}
						}
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
	return (key == 'Q') || (!person.IsStillAlive()); //add more stuff to end the game
}

bool Game::isArrowKeyCode(int Keycode)
{
	return (Keycode == LEFT) || (Keycode == RIGHT) || (Keycode == UP) || (Keycode == DOWN);
}

void Game::GameOneRules()
{
	if ((bolder.Get_Y() == person.Get_X()) && (bolder.Get_X() == person.Get_Y())) /*bolder x is bolder y*/ {
		person.Die();
	}
	if ((person.Get_X() == gridkey.Get_X()) && (person.Get_Y() == gridkey.Get_Y())) {
		gridkey.Person_NutDisappear();
	}
	if ((bolder.Get_Y() == gridkey.Get_X()) && (bolder.Get_X() == gridkey.Get_Y())) {
		gridkey.KeyFollowBolder();
	}
}
