#include "ChapterTwo.h"

ChapterTwo::ChapterTwo(const std::string &title, Application *app) : Game(title, app)
{
	SetUpGame();
}

void ChapterTwo::GridItemPositioning()
{
	person.Set_XY(10, 10); //TODO::wont be random positioning will be set 
}

std::string ChapterTwo::Prepare_Grid()
{
	std::ostringstream os;

	int row_x = 30;
	int col_y =30;

	for (int row(1); row <= row_x; ++row) {
		for (int col(1); col <= col_y; ++col) {
			if ((row == person.Get_Y()) && (col == person.Get_X())) {
				os << person;
			}
			else {
				os << FREEBLOCK;
			}
		}
			os << std::endl;
	}
	return os.str();
}

void ChapterTwo::GameConditions()
{

}

void ChapterTwo::GameRules()
{
}

void ChapterTwo::EndGame()
{
}

bool ChapterTwo::game_ended(char key)
{
	return (key == 'Q');
}

/*if ((row == person.Get_X()) && (col == person.Get_Y())) {
				os << person.GetSymbol();	//disworks
			}
			else
				os << FREEBLOCK;
			}*/