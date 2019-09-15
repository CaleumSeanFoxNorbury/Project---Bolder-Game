#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Load(Application & app)
{
	std::ifstream infile("data.txt");
	std::string line;

	std::streampos previousLine;

	if (infile.is_open()) {
		//bool MianAccount = false;
		while (std::getline(infile, line)) {
			if (line == "Player") {
				std::string Name;
				std::string Score;
				std::string username;
				std::string password;
				std::getline(infile, Name);
				std::getline(infile, Score);
				std::getline(infile, username);
				std::getline(infile, password);
				app.GetPlayers().addInFront(new Player(Name, std::stoi(Score), username, password));
			}
		}
	}
	infile.close();
}

void Application::Save(Application & app)
{
	std::ofstream outfile("data.txt", std::ios::out);
	if (outfile.is_open()) {
		for (int i(0); i < app.GetPlayersLength(); i++) {
			outfile << "PLAYER: " << std::endl;
			outfile << i << std::endl; //player ID
			outfile << app.player_->getName(); //Name
			outfile << app.player_->GetScore(); //score
			outfile << "ACCOUNT DETAILS: " << std::endl;
			outfile << app.player_->GetUsername();
			outfile << app.player_->GetPassword();
		}
	}
	outfile.close();
}

void Application::AddNewUser(Player * player)
{
	players.addInFront(player);
}

void Application::LogIn(Player * currentplayer)
{
	this->currentPlayer = currentplayer;
	PlayerIsLoggedIn = true;
}

void Application::logOut()
{
	PlayerIsLoggedIn = false;
}

Player * Application::GetCurrentPlayer() 
{
	return currentPlayer;
}

Player * Application::GetPlayer(int& index) const
{
	return players[index];
}

List<Player*> Application::GetPlayers() const
{
	return players;
}

bool Application::IsUserLoggedIn()
{
	return PlayerIsLoggedIn;
}

const int Application::GetPlayersLength() const
{
	return players.length();
}


