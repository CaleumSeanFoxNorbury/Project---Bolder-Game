#include "Game.h"

Game::Game(const std::string& title, Application* app) : title(title), app(app)
{
}

void Game::SetUpGame()
{
	UserInterface ui;
	GridItemPositioning();
	//ui.OutputLevel(title);
	ui.DrawGrid(Prepare_Grid());
	ui.GameData(app->GetCurrentPlayer()->GetUsername(), app->GetCurrentPlayer()->GetScore());
	key = ui.GetKeypressFromUser();
	GameRules();
	GameConditions();		
	//ui.OutputLevel(title);
	ui.DrawGrid(Prepare_Grid());
	EndGame();
}

bool Game::isArrowKeyCode(int Keycode)
{
	return (Keycode == LEFT) || (Keycode == RIGHT) || (Keycode == UP) || (Keycode == DOWN);
}
