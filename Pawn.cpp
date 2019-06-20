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
	if (Field::Instance()->getFigure(fromX, fromY)->GetTeam() == 'w')
	{
		if ((fromY - toY == 2) && !IsMoved())
		{
			return true;
		}
		else if (((fromY - toY) == 1) && std::abs(fromX - toX) == 1)
		{
			return true;
		}
		else if (((fromY - toY) == 1) && std::abs(fromX - toX) == 0)
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
		if ((toY - fromY == 2) && !IsMoved())
		{
			return true;
		}
		else if (((toY - fromY) == 1) && std::abs(fromX - toX) == 1)
		{
			return true;
		}
		else if (((toY - fromY) == 1) && std::abs(fromX - toX) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Pawn::FigureOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if ((std::abs(toY - fromY) == 1) && std::abs(fromX - toX) == 1)
	{
		if (Field::Instance()->isFigure(toX, toY))
		{
			if (Field::Instance()->getFigure(toX, toY)->GetTeam()
				== GetTeam())//!= Field::Instance()->getFigure(fromX, fromY)->GetTeam())
			{
				return true;
			}
			else
			{
	//			isMoved = true;
				return false;
			}
		}
		else
		{
			if ((Field::Instance()->isFigure(toX, fromY))
				&& (anPasan.first == toX) 
				&& (anPasan.second == fromY))
			{
				Field::Instance()->SetToNullPointer(anPasan.first, anPasan.second);
				anPasan.first = -1;
				anPasan.second = -1;
			
//				isMoved = true;
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
		if (Field::Instance()->getFigure(fromX, fromY)->GetTeam() == 'w')
		{
			for (int i = 1; i <= (fromY - toY); i++)
			{
				std::cout << "toY + i = " << fromY - i << std::endl;
				if (Field::Instance()->isFigure(fromX, fromY - i))
				{
					return true;
				}
				if (i == 2)
				{
					anPasan.first = toX;
					anPasan.second = toY;
				}
			}
//			isMoved = true;
			return false;
		}
		else
		{
			for (int i = 1; i <= (toY - fromY); i++)
			{
				std::cout << "toY + i = " << fromY + i << std::endl;
				if (Field::Instance()->isFigure(fromX, fromY + i))
				{
					return true;
				}
				if (i == 2)
				{
					anPasan.first = toX;
					anPasan.second = toY;
				}
			}
//			isMoved = true;
			return false;
		}
		return true;
	}
}