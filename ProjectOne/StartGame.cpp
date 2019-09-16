#include "StartGame.h"

StartGame::StartGame(const std::string& title, Application *app) : Game(title, app), person(PERSON), bolder(BOLDER), 
gridb_(GRIDBOARDER), gridkey(GRIDKEY), gate(GATE)
{	
		SetUpGame();	
}


void StartGame::GridItemPositioning()
{
	person.RandomPosition();
	bolder.RandomPosition();
	gridkey.RandomPosition();
	gate.RandomPosition();
	gridb_.Create_Boarders();
}

std::string StartGame::Prepare_Grid()
{
	std::ostringstream os;
	for (int row(1); row <= SIZE; ++row) {
		for (int col(1); col <= SIZE; ++col){
			for (int i(0); i < gridb_.border.size(); i++) {
				if ((row == gridb_.border[i].Get_X()) && (col == gridb_.border[i].Get_Y())) {
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
							//os << bolder.GetSymbol();
						}
						else {
							if ((row == gridkey.Get_Y()) && (col == gridkey.Get_X()) && (!gridkey.PersonCollected())) {
								os << GRIDKEY;
							}
							else {
								if ((row == gate.Get_X()) && (col == gate.Get_Y()) && (gridkey.PersonCollected())) {
									os << GATE;
								}
								else {
									os << FREECELL;
								}
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

void StartGame::GameConditions()
{
	//something on this function isnt working properly
	while (!game_ended(key)) {
		if ((!gridkey.BolderCollected()) && (!person.GateOpen())) {
			int gridKeyx = 0; int gridKeyy = 0;
			gridKeyx = gridkey.Get_X();
			gridKeyy = gridkey.Get_Y();
			bolder.GatherKey(gridKeyx, gridKeyy);
		}
		if ((gridkey.BolderGotKey()) && (!person.GateOpen())) {
			bolder.MoveBolder();
			gridkey.SpotBolder(&bolder);
			gridkey.Follow_Bolder();
		}
		if ((person.GateOpen()) && (!gridkey.BolderGotKey())) {
			bolder.MoveBolder();
			gridkey.SpotBolder(&bolder);
			gridkey.Follow_Bolder();
		}
		if ((gridkey.BolderGotKey()) && (person.GateOpen())) {
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
			ui_G2.DrawGrid(Prepare_Grid());	
			ui_G2.GameData(app->GetCurrentPlayer()->getName(), app->GetCurrentPlayer()->GetScore(), title); 
			GameRules();
		}
	key = ui_G2.GetKeypressFromUser();
	}
}

void StartGame::GameRules()
{
	if ((bolder.Get_Y() == person.Get_X()) && (bolder.Get_X() == person.Get_Y())) /*bolder x is bolder y*/ {
		person.Die();
	}
	if ((person.Get_X() == gridkey.Get_X()) && (person.Get_Y() == gridkey.Get_Y())) {
		gridkey.Person_NutDisappear();
		person.OpenGate();
	}
	if ((bolder.Get_Y() == gridkey.Get_X()) && (bolder.Get_X() == gridkey.Get_Y())) {
		gridkey.KeyFollowBolder();

	}
	if ((bolder.Get_Y() == gate.Get_X()) && (bolder.Get_X() == gate.Get_Y())) /*bolder x is bolder y*/ {
		bolder.BounceOffObjects();
	}
	if ((person.Get_Y() == gate.Get_X()) && (person.Get_X() == gate.Get_Y()) && (person.GateOpen())) {
		PlayerEscaped();
	}
}

void StartGame::EndGame()
{
	if (person_escaped()) {
		GameResults = 2;
		int EndgameData = 1;
		app->GetCurrentPlayer()->UpdateScore(EndgameData);
		ui_G2.EndGameMessages(GameResults, EndgameData);
	}
	else {
		GameResults = 1;
		int EndgameData = 0;
		ui_G2.EndGameMessages(GameResults, EndgameData);
	}
}

void StartGame::PlayerEscaped()
{
	escaped = true;
}

bool StartGame::person_escaped() const
{
	return escaped;
}

bool StartGame::game_ended(char key)
{
	return (key == 'Q') || (!person.IsStillAlive()) || (person_escaped());
}
