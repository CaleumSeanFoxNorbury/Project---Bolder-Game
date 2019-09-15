#pragma once
#include<sstream>
#include<assert.h>

#include"Game.h"
#include"UI.h"
#include"Person.h"
#include"Bolder.h"
#include"GridBorder.h"
#include"Key.h"
#include"Gate.h"

class StartGame : Game {
public:
	StartGame(const std::string&, Application*);

	void GridItemPositioning() final;
	std::string Prepare_Grid() final;
private:
	void GameConditions() final;
	void GameRules() final;  
	void EndGame() final;
	
	void PlayerEscaped();
	bool person_escaped() const;
	bool game_ended(char key);

	UserInterface ui_G2;
	Person person;
	Bolder bolder;
	GridBorder gridb_;
	Key gridkey;
	Gate gate;

	//data
	bool escaped = false;
	//symbols(chars)
	const char BOLDER = 'B';
	const char FREECELL = '*';
	const char GAMEBOARDBORDER = '0';
	const char PERSON = 'P';
	const char GRIDBOARDER = 'O';
	const char GRIDKEY = 'K';
	const char GATE = 'G';
	const int SIZE = 20;
	int key;
	int GameResults = 0;
};