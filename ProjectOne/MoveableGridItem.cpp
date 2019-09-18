#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(int x, int y, char symbol): GridItem(symbol), _x(x), _y(y)
{
}

MoveableGridItem::~MoveableGridItem()
{
}

int MoveableGridItem::Get_X()
{
	return _x;
}

int MoveableGridItem::Get_Y()
{
	return _y;
}

bool const MoveableGridItem::IsAtPossition(int x, int y)
{
	return _x == x && _y == y;
}

void MoveableGridItem::Set_XY(int x_, int y_)
{
	_x = x_;
	_y = y_;
}

void MoveableGridItem::Update_Position(int x, int y)
{
	_x += x;
	_y += y;
}

void MoveableGridItem::RandomPosition()
{
	Set_XY(rng.GetRandomValue(20), rng.GetRandomValue(20));
}

std::ostream & operator<<(std::ostream & os, MoveableGridItem & rhs)
{
	os << rhs.GetSymbol();
	return os;
}





