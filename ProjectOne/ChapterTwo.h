#pragma once
#include<string>
#include"UI.h"
#include"Person.h"
#include"Game.h"

class ChapterTwo : public Game {
public:
	ChapterTwo(const std::string&, Application*);
private:
	void GridItemPositioning() final;
	std::string Prepare_Grid() final;
	void GameConditions() final;
	void GameRules() final;
	void EndGame() final;
	bool game_ended(char key) final;

	int  GridSizeX = 100, GridSizeY = 100;
	const char FREEBLOCK = '*';
	const char StageObject = '3';	//remove 
	UserInterface ui_G3;
		//maybe trees
		//dark looking cottages
		//bushes
		//cats 
		//more horror gridobjects that can be interactable
};