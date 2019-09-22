#pragma once
//#include"SDL.h"

#include"Application.h"
#include"UI.h"
#include"Person.h"

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
	virtual void GameRules() = 0;  
	virtual void GameConditions() = 0;
	virtual void EndGame() = 0;
	virtual bool game_ended(char) = 0;
	
	bool isArrowKeyCode(int Keycode);
protected:
	Player* player;
	Application* app;
	Person person = 'P';
	std::string title;
private:
	int key;


	//frame delay
	const int FramePerSecond = 60;
	const int FrameDelay = 1000 / FramePerSecond;
	int framestart;
	int frametime;
};