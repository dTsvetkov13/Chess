#include "Pawn.h"
#include "Field.h"

Pawn::Pawn()
{
	SetFirstLetter('p');
}


Pawn::~Pawn()
{
}

bool Pawn::CanReach(int fromX, int fromY, int toX, int toY)
{
	if (Field::Instance().getFigure(fromX, fromY)->GetTeam() == 'w')
	{
		if ((toY - fromY == 2) && !isMoved)
		{
			return true;
		}
		else if (((toY - fromY) == 1) && std::abs(fromX - toX) == 1)
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
		if ((fromY - toY == 2) && !isMoved)
		{
			return true;
		}
		else if (((fromY - toY) == 1) && std::abs(fromX - toX) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Pawn::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (((toY - fromY) == 1) && std::abs(fromX - toX) == 1)
	{
		if (Field::Instance().isFigure(toX, toY))
		{
			if (Field::Instance().getFigure(toX, toY)->GetTeam()
				!= Field::Instance().getFigure(fromX, fromY)->GetTeam())
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
			if ((Field::Instance().isFigure(toX, fromY))
				&& (anPasan.first == toX) 
				&& (anPasan.second == fromY))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (Field::Instance().getFigure(fromX, fromY)->GetTeam() == 'w')
		{
			for (int i = 1; i <= (toY - fromY); i++)
			{
				if (Field::Instance().isFigure(fromX, fromY + i))
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = 1; i <= (fromY - toY); i++)
			{
				if (Field::Instance().isFigure(fromX, fromY - i))
				{
					return false;
				}
			}
		}
		return true;
	}
}