#include "Rook.h"
#include "Field.h"

Rook::Rook()
{
	SetFigureType(Figures::Rook);
}

Rook::Rook(Team team)
{
	SetFigureType(Figures::Rook);
	SetTeam(team);
}

Rook::~Rook()
{
}

std::string Rook::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "br";
	}
	else
	{
		return "wr";
	}
}

bool Rook::CanReach(const Cord& from, const Cord& to)
{
	if (from.x == to.x || from.y == to.y)
	{
		return true;
	}
	else return false;
}

bool Rook::FigureOnTheWay(const Cord& from, const Cord& to)
{
	if (from.x == to.x)
	{
		bool up = true;
		int dist = std::abs(from.y - to.y);
		if (from.y < to.y)
		{
			up = false;
		}

		if (up)
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x, to.y + i)))
				{
					return true;
				}
			}
		}
		else
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x, to.y - i)))
				{
					return true;
				}
			}
		}
	}
	else
	{
		bool left = true;
		int dist = from.x - to.x;
		if (from.x < to.x)
		{
			left = false;
			dist = to.x - from.x;
		}

		if (left)
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance()->isFigure(Cord(to.x + i, to.y)))
				{
					return true;
				}
			}
		}
		else
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance()->isFigure(Cord(to.x + i, to.y)))
				{
					return true;
				}
			}
		}
	}

	return false;
}
