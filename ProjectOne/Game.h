#pragma once
#include"Application.h"
#include"UI.h"
#include"Player.h"

#include<assert.h>
#include<string>
#include<iostream>
#include<sstream>

#define LEFT	(75)
#define RIGHT	(77)
#define DOWN	(80)
#define UP		(72)
#define QUIT	('Q')
#define GRIDBOARDERS	('O')

class Game {
public:
	Game(const std::string&, Application*);

	void SetUpGame();
	virtual void GridItemPositioning() = 0;
	virtual std::string Prepare_Grid() = 0;											
	virtual void GameRules() = 0;  //can make vertual and reuse but chnage form, rename to fit function name properly 
	virtual void GameConditions() = 0;
	virtual void EndGame() = 0;

	bool isArrowKeyCode(int Keycode);
private:
	int key = 0;
	Player* player;
protected:
	Application* app;
	std::string title;
};