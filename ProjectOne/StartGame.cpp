#include "StartGame.h"

StartGame::StartGame(Player* player) : Game(player)
{
	SetUpGame();
}

void StartGame::GridItemPositioning()
{
}

std::string StartGame::Prepare_Grid()
{
	return std::string();
}

void StartGame::GameConditions()
{
}

void StartGame::GameRules()
{
}

void StartGame::EndGame()
{
}
