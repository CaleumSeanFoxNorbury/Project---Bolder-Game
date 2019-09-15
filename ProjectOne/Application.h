#pragma once
#include<list>
#include <fstream>
#include <sstream>
#include <iomanip>

#include"List.h"
#include"Player.h"


class Application {
public:
	Application();
	~Application();

	void Load(Application& app);
	void Save(Application& app);

	void AddNewUser(Player*);

	void LogIn(Player*);
	void logOut();

	Player* GetCurrentPlayer();
	Player* GetPlayer(int&) const;
	List<Player*> GetPlayers() const;

	bool IsUserLoggedIn();
	const int GetPlayersLength() const;
private: 	
	List<Player*> players;

	Player* currentPlayer;
	Player* player_;

	bool PlayerIsLoggedIn = false;
};