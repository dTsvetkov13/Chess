#include "Knight.h"
#include "Field.h"


Knight::Knight()
{
	SetFirstLetter('k');
}

Knight::~Knight()
{
}

bool Knight::CanReach(int fromX, int fromY, int toX, int toY)
{
	if (std::abs(fromX - toX) == 2 && std::abs(fromY - toY) == 1
		|| std::abs(fromY - toY) == 2 && std::abs(fromX - toX) == 1)
	{
		return true;
	}
	return false;
}

bool Knight::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (Field::Instance().getFigure(toX, toY)->GetTeam()
		== Field::Instance().getFigure(fromX, fromY)->GetTeam())
	{
		return false;
	}
	return true;
}