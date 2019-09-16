#include "Utils.h"

std::string Utils::Getlinefromuser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char Utils::getCHARfromuser()
{
	return toupper(Getlinefromuser()[0]);
}

const std::string & Utils::ToUpper(std::string & string)
{
	for (int i(0); i < string.length(); i++) {
		string.at(i) = toupper(string.at(i));
	}
	return string;
}
