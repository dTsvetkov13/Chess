#include "Quenn.h"
#include "Bishop.h"
#include "Rook.h"


Quenn::Quenn()
{
	Figure::SetFigureType(Figures::Quenn);
}

Quenn::Quenn(Team team)
{
	SetFigureType(Figures::Quenn);
	SetTeam(team);
}

Quenn::~Quenn()
{
}

std::string Quenn::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "bQ";
	}
	else
	{
		return "wQ";
	}
}

void Quenn::SetTeam(Team team)
{
	Figure::SetTeam(team);
}

bool Quenn::CanReach(const Cord& from, const Cord& to)
{
	if (Rook::CanReach(from, to))
	{
		return true;
	}

	if (Bishop::CanReach(from, to))
	{
		return true;
	}

	return false;
}

bool Quenn::FigureOnTheWay(const Cord& from, const Cord& to)
{
	if (Rook::FigureOnTheWay(from, to))
	{
		return true;
	}

	if (Bishop::FigureOnTheWay(from, to))
	{
		return true;
	}

	return false;
}