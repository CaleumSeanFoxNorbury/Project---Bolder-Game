#pragma once
#include "UI.h"
#include"Player.h"
#include"Person.h"
#include"Bolder.h"
#include"GridBorder.h"
#include"Key.h"

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
	Game(Player* player);
	void run();
	std::string Prepare_Grid();
private:
	Player * player;
	Person person;
	Bolder bolder;
	GridBorder gridb_;
	Key gridkey;

	bool game_ended(char key);
	bool isArrowKeyCode(int Keycode);
	void GameOneRules();
	//symbols(chars)
	const char BOLDER = 'B';
	const char FREECELL = '*';
	const char GAMEBOARDBORDER = '0';
	const char PERSON = 'P';
	const char GRIDBOARDER = 'O';
	const char GRIDKEY = 'K';
	const int SIZE = 20;
	int key;
};