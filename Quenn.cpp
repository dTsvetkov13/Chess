#include "Quenn.h"
#include "Bishop.h"
#include "Rook.h"


Quenn::Quenn()
{
	Figure::Figure::SetFirstLetter('Q');
}

Quenn::~Quenn()
{
}

void Quenn::SetTeam(char team)
{
	Figure::SetTeam(team);
}

bool Quenn::CanReach(int fromX, int fromY, int toX, int toY)
{
	Rook r;
	Bishop b;

	if (r.CanReach1(fromX, fromY, toX, toY))
	{
		return true;
	}

	if (b.CanReach1(fromX, fromY, toX, toY))
	{
		return true;
	}

	return false;
}

bool Quenn::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	Rook r;
	Bishop b;

	if (r.AllyOnTheWay1(fromX, fromY, toX, toY))
	{
		return true;
	}

	if (b.AllyOnTheWay1(fromX, fromY, toX, toY))
	{
		return true;
	}

	return false;
}