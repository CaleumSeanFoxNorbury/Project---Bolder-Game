#pragma once
#include<sstream>
#include<assert.h>

#include"Game.h"
#include"Player.h"
#include"UI.h"

class StartGame : Game {
public:
	StartGame(Player* player);
	void GridItemPositioning() final;
	std::string Prepare_Grid() final;
private:
	UserInterface ui_G2;
	void GameConditions();
	void GameRules();  //can make vertual and reuse but chnage form, rename to fit function name properly 
	void EndGame();


};