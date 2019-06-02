#include "King.h"
#include "Field.h"

King::King()
{
	SetFirstLetter('K');
}

King::~King()
{
}

bool King::CanReach(int fromX, int fromY, int toX, int toY)
{
	if (fromX == toX)
	{
		if (std::abs(fromY - toY) == 1)
		{
			return true;
		}
	}
	else if (fromY == toY)
	{
		if (std::abs(fromX - toX) == 1)
		{
			return true;
		}
	}

	return false;
}

bool King::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (Field::Instance().getFigure(toX, toY)->GetTeam()
		== Field::Instance().getFigure(fromX, fromY)->GetTeam())
	{
		return false;
	}
	return true;
}