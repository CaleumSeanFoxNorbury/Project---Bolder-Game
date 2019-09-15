#include<iostream>
#include<string>

#include"UI.h"
#include"Player.h"
#include"StartGame.h"
#include"Application.h"

int main() {
	UserInterface ui;
	Application app;
	std::string playerusername;
	std::string password;
	int score = 0;

	std::string name = "caleum", pw = "merlin01";
	Player * caleum = new Player(name, score, name, pw);
	app.AddNewUser(caleum);

	ui.GettingUser(playerusername);
	for (int i(0); i < app.GetPlayers().length(); i++) {	//turn all this into a function 
		if (playerusername == app.GetPlayer(i)->GetUsername()) {
			app.LogIn(app.GetPlayer(i));
		}
		else if (!app.IsUserLoggedIn()) {
			ui.CreatePlayer(name, name, password);
			Player* newplayer = new Player(name, score, name, password);
			app.AddNewUser(newplayer);
		}
	}

	
	char carry_on;
	do {
		if (app.IsUserLoggedIn()) {
			//app.Load(app);
		}
		StartGame("LEVELONE", &app);
		
		//app.Save(app); // this is causing trouble not working properly 

		std::cout << "Play again? (Y/N): ";
		std::cin >> carry_on;
	} while (tolower(carry_on) == 'y');
	ui.Hold_Window();

	return(0);
}

//TODO::
//apply polomorhic behavour ansd inheritance to bolder and create player