#include "StartMenu.h"

StartMenu::StartMenu(const std::string & title, Application * app) : Menu(title, app)
{
	DisplayMenu();
}

void StartMenu::OutputMenuOptions()
{
	if (!app->IsUserLoggedIn()) {
		ui_M.Option(1, "Start Game");
		ui_M.Option(2, "LogIn");
		ui_M.Option(3, "Create an Account");
		ui_M.Option(5, "Choose Level");		//REMOVE

	}
	if (app->IsUserLoggedIn()) {
		ui_M.Option(4, "Start/Resume Game");//TODO
		ui_M.Option(5, "Choose Level");		
		ui_M.Option(6, "Profile Menu");		//TODO
		ui_M.Option(7, "LogOut");			//TODO
		ui_M.Option(8, "Settings");			//restart game and more TODO
	}
}

bool StartMenu::HandleMenuOption(char choice)
{
	switch (choice) {
	case '1': {
		char carry_on;
		app->LogInDefaultUser();		
		do {
			StartGame("LevelOne", app); 
			std::cout << "Play again? (Y/N): ";
			std::cin >> carry_on;
			if (tolower(carry_on) == 'n') {
				DisplayMenu();
			}
		} while (tolower(carry_on) == 'y');
		ui_M.Hold_Window();
		break;
	}
	case '2': {
		std::string playerusername;
		std::string name;
		std::string password;
		int score=0;
		ui_M.ClearScreen();
		ui_M.GettingUser(playerusername);
		for (int i(0); i < app->GetPlayers().length(); i++) {
			if (playerusername == app->GetPlayer(i)->GetUsername()) {
				app->LogIn(app->GetPlayer(i));
			}
			else {
				ui_M.ClearScreen();
				ui_M.Line("WARNING :: Please enter a valid username and password! :: WARNING");
				ui_M.Line();
				ui_M.GettingUser(playerusername);
				if (playerusername == app->GetPlayer(i)->GetUsername()) {
					app->LogIn(app->GetPlayer(i));
				}
			}
		}
		break;
	}
	case '3': {
		std::string name, password;				
		int score = 0;
		ui_M.CreatePlayer(name, name, password);
		Player* newplayer = new Player(name, score, name, password);
		app->AddNewUser(newplayer);
		app->LogIn(newplayer);
		break;
	}
	case '4': {
		char carry_on;
		do {
			if (app->IsUserLoggedIn()) {
				//app.Load(app);			//TODO
			}
			if (!app->IsUserLoggedIn()) {
				app->LogInDefaultUser();
			}
			StartGame("LevelOne", app);

			//app.Save(app); // this is causing trouble not working properly	//TODO
			std::cout << "Play again? (Y/N): ";
			std::cin >> carry_on;
			if (tolower(carry_on) == 'n') {
				DisplayMenu();
			}
		} while (tolower(carry_on) == 'y');
		ui_M.Hold_Window();
		break;
	}
	case '5': {
		if (!app->IsUserLoggedIn()) {
			app->LogInDefaultUser();	//REMOVE THIS 
		}
		ui_M.ClearScreen();
		switch (ui_M.ChooseLevel()) {
		case'1': {
				StartGame("StartGame", app);
				break;
			}
		case'2': {
			ChapterTwo("ChapterTwo", app);
			break;
		}
		}
		break;
	}
	}
	return false;
}
