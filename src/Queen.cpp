#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"


Queen::Queen()
{
	Figure::SetFigureType(Figures::Quenn);
}

Queen::Queen(Team team)
{
	SetFigureType(Figures::Quenn);
	SetTeam(team);
}

Queen::~Queen()
{
}

std::string Queen::GetFigureSymbol()
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

void Queen::SetTeam(Team team)
{
	Figure::SetTeam(team);
}

bool Queen::CanReach(const Cord& from, const Cord& to)
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

bool Queen::FigureOnTheWay(const Cord& from, const Cord& to)
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
