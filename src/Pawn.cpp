#include "Pawn.h"
#include "Field.h"

Pawn::Pawn()
{
	SetFigureType(Figures::Pawn);
}

Pawn::Pawn(Team team)
{
	SetFigureType(Figures::Pawn);
	SetTeam(team);
}

Pawn::~Pawn()
{
}

std::string Pawn::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "bp";
	}
	else
	{
		return "wp";
	}
}

bool Pawn::CanReach(const Cord& from, const Cord& to)
{
	if (Field::Instance()->getFigure(from)->GetTeam() == Team::White)
	{
		if ((from.y - to.y == 2) && !IsMoved())
		{
			return true;
		}
		else if (((from.y - to.y) == 1) && std::abs(from.x - to.x) == 1)
		{
			return true;
		}
		else if (((from.y - to.y) == 1) && std::abs(from.x - to.x) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ((to.y - from.y == 2) && !IsMoved())
		{
			return true;
		}
		else if (((to.y - from.y) == 1) && std::abs(from.x - to.x) == 1)
		{
			return true;
		}
		else if (((to.y - from.y) == 1) && std::abs(from.x - to.x) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Pawn::FigureOnTheWay(const Cord& from, const Cord& to)
{
	if ((std::abs(to.y - from.y) == 1) && std::abs(from.x - to.x) == 1)
	{
		if (Field::Instance()->isFigure(to))
		{
			if (Field::Instance()->getFigure(to)->GetTeam()
				== GetTeam())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ((Field::Instance()->isFigure(Cord(to.x, from.y)))
				&& (anPasan.first == to.x) 
				&& (anPasan.second == from.y))
			{
				Field::Instance()->SetToNullPointer(Cord(anPasan.first, anPasan.second));
				anPasan.first = -1;
				anPasan.second = -1;

				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (Field::Instance()->getFigure(from)->GetTeam() == Team::White)
		{
			for (int i = 1; i <= (from.y - to.y); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x, from.y - i)))
				{
					return true;
				}
				if (i == 2)
				{
					anPasan.first = to.x;
					anPasan.second = to.y;
				}
			}

			return false;
		}
		else
		{
			for (int i = 1; i <= (to.y - from.y); i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x, from.y + i)))
				{
					return true;
				}
				if (i == 2)
				{
					anPasan.first = to.x;
					anPasan.second = to.y;
				}
			}

			return false;
		}
		return true;
	}
}
