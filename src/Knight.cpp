#include "Knight.h"
#include "Field.h"

Knight::Knight()
{
	SetFigureType(Figures::Knight);
}

Knight::Knight(Team team)
{
	SetFigureType(Figures::Knight);
	SetTeam(team);
}

Knight::~Knight()
{
}

std::string Knight::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "bk";
	}
	else
	{
		return "wk";
	}
}

bool Knight::CanReach(const Cord& from, const Cord& to)
{
	if (std::abs(from.x - to.x) == 2 && std::abs(from.y - to.y) == 1
		|| std::abs(from.y - to.y) == 2 && std::abs(from.x - to.x) == 1)
	{
		return true;
	}
	return false;
}

bool Knight::FigureOnTheWay(const Cord& from, const Cord& to)
{
	if (!Field::Instance()->isFigure(to))
	{
		return false;
	}

	if (Field::Instance()->getFigure(to)->GetTeam()
		!= Field::Instance()->getFigure(from)->GetTeam())
	{
		return false;
	}
	
	return true;
}
