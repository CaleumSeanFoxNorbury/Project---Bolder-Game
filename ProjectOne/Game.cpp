#include "Game.h"

Game::Game(const std::string& title, Application* app) : title(title), app(app)
{
}

void Game::SetUpGame()
{
	UserInterface ui;
	GridItemPositioning();
	ui.DrawGrid(Prepare_Grid());
	ui.GameData(app->GetCurrentPlayer()->GetUsername(), app->GetCurrentPlayer()->GetScore(), title);
	key = ui.GetKeypressFromUser();
	while (!game_ended(key)) {
		GameConditions();
		if (isArrowKeyCode(key)) {
			person.scamper(key, title);
			ui.DrawGrid(Prepare_Grid());
			ui.GameData(app->GetCurrentPlayer()->GetUsername(), app->GetCurrentPlayer()->GetScore(), title);
			GameRules();
		}
		key = ui.GetKeypressFromUser();
	}
	ui.ClearScreen();
	ui.DrawGrid(Prepare_Grid());
	EndGame();
}

bool Game::isArrowKeyCode(int Keycode)
{
	return (Keycode == LEFT) || (Keycode == RIGHT) || (Keycode == UP) || (Keycode == DOWN);
}
