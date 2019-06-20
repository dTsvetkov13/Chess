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
	if (Rook::CanReach(fromX, fromY, toX, toY))
	{
		return true;
	}

	if (Bishop::CanReach(fromX, fromY, toX, toY))
	{
		return true;
	}

	return false;
}

bool Quenn::FigureOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (Rook::FigureOnTheWay(fromX, fromY, toX, toY))
	{
		return true;
	}

	if (Bishop::FigureOnTheWay(fromX, fromY, toX, toY))
	{
		return true;
	}

	return false;
}