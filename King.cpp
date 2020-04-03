#include "King.h"
#include "Pawn.h"
#include "Field.h"
#include <array>

King::King()
{
	SetFigureType(Figures::King);
}

King::King(Team team)
{
	SetFigureType(Figures::King);
	SetTeam(team);
}

King::~King()
{
}

std::string King::GetFigureSymbol()
{
	if (GetTeam() == Team::Black)
	{
		return "bK";
	}
	else
	{
		return "wK";
	}
}

bool King::isCheckmated(const Cord &cord)
{
	int y = cord.y - 1;
	int x = cord.x - 1;

	int freeSpaces = 0;
	Cord temp;
	bool canFigureFreeSpace = false;

	if (y <= 8 && y > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!((x + i) < 1 || (x + i) > 8))
			{
				temp = Cord(x + i, y);

				if (isFreeSpace(temp, canFigureFreeSpace))
				{
					freeSpaces++;
				}
			}
		}
	}

	if (y + 2 < 8 && y + 2 > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!((x + i) < 1 || (x + i) > 8))
			{
				temp = Cord(x + i, y + 2);

				if (isFreeSpace(temp, canFigureFreeSpace))
				{
					freeSpaces++;
				}
			}
		}
	}

	if (!((y + 1) < 1 || (y + 1) > 8 || (x) < 0 || (x) >= 8))
	{
		temp = Cord(x, y + 1);

		if (isFreeSpace(temp, canFigureFreeSpace))
		{
			freeSpaces++;
		}
	}

	if (!((y + 1) < 1 || (y + 1) > 8 || (x + 2) < 1 || (x + 2) > 8))
	{
		temp = Cord(x + 2, y + 1);

		if (isFreeSpace(temp, canFigureFreeSpace))
		{
			freeSpaces++;
		}
	}

	if (freeSpaces > 0)
	{
		return false;
	}

	for (auto it : *Field::Instance()->getFigure(cord)->getFiguresPointingToThisFigure())
	{
		if (Field::Instance()->getFigure(it)->CanBeReached(it))
		{
			Field::Instance()->getFigure(it)->ClearPointingFigures();
			return false;
		}
	}

	return true;
}

bool King::isFreeSpace(const Cord &cord, bool &canFigureFreeSpace)
{
	if (Field::Instance()->isFigure(cord))
	{
		if (Field::Instance()->getFigure(cord)->GetTeam() != GetTeam())
		{
			if (Field::Instance()->getFigure(cord)->CanBeReached(cord))
			{
				Field::Instance()->getFigure(cord)->ClearPointingFigures();
				return false;
			}
		}
	}
	else
	{
		Pawn *p = new Pawn(GetTeam());

		if (!p->CanBeReached(cord))
		{
			return true;
		}
		else
		{
			if (!canFigureFreeSpace)
			{
				if (GetTeam() == Team::White)
				{
					p->SetTeam(Team::Black);
				}
				else
				{
					p->SetTeam(Team::White);
				}

				if (p->CanBeReached(cord))
				{
					Figure* kingInFiguresPointingToThisFigure = p->kingInFiguresPointingToThisFigure();

					if (kingInFiguresPointingToThisFigure != nullptr)
					{
						if (kingInFiguresPointingToThisFigure->GetTeam() == GetTeam())
						{
							return false;
						}
					}

					canFigureFreeSpace = true;
					delete p;
					return true;
				}
			}
		}
		delete p;
	}

	return false;
}

bool King::IsInChess(const Cord& cord)
{
	CanBeReached(cord);
	
	if (getFiguresPointingToThisFigure()->size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool King::CanReach(const Cord& from, const Cord& to)
{
	if (from.x == to.x)
	{
		if (std::abs(from.y - to.y) == 1)
		{
			return true;
		}
	}
	else if (from.y == to.y)
	{
		if (std::abs(from.x - to.x) == 1)
		{
			return true;
		}
	}

	if (std::abs(from.x - to.x) && std::abs(from.y - to.y))
	{
		return true;
	}

	return false;
}

bool King::FigureOnTheWay(const Cord& from, const Cord& to)
{
	if (from.y == to.y && std::abs(from.x - to.x) == 2)
	{
		if (from.x > to.x)
		{
			for (int i = 1; i <= 3; i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x - i, to.y)))
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			for (int i = 1; i <= 2; i++)
			{
				if (Field::Instance()->isFigure(Cord(from.x + i, to.y)))
				{
					return true;
				}
			}
			return false;
		}
	}

	if(Field::Instance()->isFigure(Cord(to.x, to.y)))
		if (Field::Instance()->getFigure(Cord(to.x, to.y))->GetTeam()
			== GetTeam())
		{	
			return true;
		}

	return false;
}

int King::GetFiguresChessing()
{
	return getFiguresPointingToThisFigure()->size();
}