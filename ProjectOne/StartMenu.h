#pragma once
#include<string>

#include"UI.h"
#include"StartGame.h"
#include"Menu.h"
#include"Application.h"
class StartMenu : public Menu {
public:
	StartMenu(const std::string&, Application*);
	void OutputMenuOptions() final;
	bool HandleMenuOption(char) final;
};