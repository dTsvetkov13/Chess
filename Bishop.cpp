#include "Bishop.h"
#include "Field.h"
#include <cmath>

Bishop::Bishop()
{
	SetFigureType(Figures::Bishop);
}

Bishop::Bishop(Team team)
{
	SetFigureType(Figures::Bishop);
	SetTeam(team);
}

Bishop::~Bishop()
{
}

std::string Bishop::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "bb";
	}
	else
	{
		return "wb";
	}
}

bool Bishop::CanReach(const Cord& from, const Cord& to)
{
	if (std::abs(from.x - to.x) == std::abs(from.y - to.y))
	{
		return true;
	}
	else return false;
}

bool Bishop::FigureOnTheWay(const Cord& from, const Cord& to)
{
	// "1" is quadrant 1, 4 3 3 4, - +
	// "2" is quadrant 2, 4 3 3 2, - -
	// "3" is quadrant 3, 4 3 5 2, + -
	// "4" is quadrant 4, 4 3 5 4, + +
	
	int quadrant = 4;

	if (from.x < to.x && from.y > to.y)
	{
		quadrant = 1;
	}
	else if (from.x > to.x && from.y > to.y)
	{
		quadrant = 2;
	}
	else if (from.x > to.x && from.y < to.y)
	{
		quadrant = 3;
	}

	if (Field::Instance()->isFigure(to))
	{
		if (Field::Instance()->getFigure(to)->GetTeam() == GetTeam())
		{
			return true;
		}
	}

	switch (quadrant)
	{
		case 1 :
		{
			for (int i = 1; i < std::abs(from.x - to.x); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x + i, from.y - i)))
				{
					return true;
				}
			}
			break;
		}
		case 2 :
		{
			for (int i = 1; i < std::abs(from.x - to.x); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x - i, from.y - i)))
				{
					return true;
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < std::abs(from.x - to.x); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x - i, from.y + i)))
				{
					return true;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 1; i < std::abs(from.x - to.x); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x + i, from.y + i)))
				{
					return true;
				}
			}
			break;
		}
	}

	return false;
}