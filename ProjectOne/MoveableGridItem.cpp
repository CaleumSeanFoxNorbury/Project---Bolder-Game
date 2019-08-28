#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(int x, int y, char symbol): GridItem(symbol), _x(x), _y(y)
{
}

MoveableGridItem::~MoveableGridItem()
{
}

int MoveableGridItem::Get_X()
{
	return x;
}

int MoveableGridItem::Get_Y()
{
	return y;
}

bool const MoveableGridItem::IsAtPossition(int x_, int y_)
{
	return x_ == x && y_ == y;
}

void MoveableGridItem::Set_XY(int x_, int y_)
{
	x = x_;
	y = y_;
}

void MoveableGridItem::Update_Position(int dx, int dy)
{
	x += dx;
	y += dy;
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





