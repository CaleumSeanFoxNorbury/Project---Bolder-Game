#include<iostream>
#include<string>

#include"UI.h"
#include"Player.h"
#include"StartMenu.h"
#include"Application.h"

int main() {
	UserInterface ui;
	Application app;

	std::string name = "caleum";
	int score = 0;

	Player * caleum = new Player(name, score, name, name);
	app.AddNewUser(caleum);

	StartMenu("StartMenu", &app);

	return(0);
}
