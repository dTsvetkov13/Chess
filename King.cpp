#include "King.h"
#include "Field.h"
#include "Rook.h"
#include <array>

King::King()
{
	SetFirstLetter('K'); 
}

King::~King()
{
}

bool King::isCheckmated(int x, int y)
{
	y -= 1;
	x -= 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!Field::Instance()->isFigure(x + j, y + i)
				&& !IsInChess(x + j, y + i))
			{
				return false;
			}
		}
	}

	if (figuresChessing == 1)
	{
		// TODO : check if there is a possible way to "unchess"
		// the King, so the game can continue
		//DONE

		if (CanBeUnchessed(x, y))
		{
			return false;
		}
	}

	return true;
}

bool King::IsInChess(int x, int y)
{
	/*if (CanBeReached(x, y))
	{
		figuresChessing = CanBeReached(x, y);
		return true;
	}
	else
	{
		return false;
	}*/

	figuresChessing = CanBeReached(x, y);
	
	if (figuresChessing)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool King::CanReach(int fromX, int fromY, int toX, int toY)
{
	if (IsInChess(toX, toY))
	{
		return false;
	}

	if (fromY == toY && std::abs(fromX - toX) == 2 && !IsMoved())
	{
		//CASTLING (ROCADO)

		if (fromX > toX)
		{
			if (Field::Instance()->isFigure(toX - 2, toY))
			{
				if (Field::Instance()->getFigure(toX - 2, toY)->GetFirstLetter() == 'r'
					&& !Field::Instance()->getFigure(toX - 2, toY)->IsMoved())
				{
					return true;
				}
			}
		}
		else
		{
			if (Field::Instance()->isFigure(toX + 1, toY))
			{
				if (Field::Instance()->getFigure(toX + 1, toY)->GetFirstLetter() == 'r'
					&& !Field::Instance()->getFigure(toX + 1, toY)->IsMoved())
				{
					return true;
				}
			}
		}
	}

	if (fromX == toX)
	{
		if (std::abs(fromY - toY) == 1)
		{
			return true;
		}
	}
	else if (fromY == toY)
	{
		if (std::abs(fromX - toX) == 1)
		{
			return true;
		}
	}

	return false;
}

bool King::FigureOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (fromY == toY && std::abs(fromX - toX) == 2)
	{
		if (fromX > toX)
		{
			for (int i = 1; i <= 3; i++)
			{
				if (Field::Instance()->isFigure(fromX - i, toY))
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
				if (Field::Instance()->isFigure(fromX + i, toY))
				{
					return true;
				}
			}
			return false;
		}
	}

	if(Field::Instance()->isFigure(toX, toY))
		if (Field::Instance()->getFigure(toX, toY)->GetTeam()
			== GetTeam())
		{	
			return true;
		}		

//	isMoved = true;

	return false;
}

bool King::CanBeUnchessed(int x, int y)
{
	for (int i = x; i >= 0; i--)
	{
		if (Field::Instance()->getFigure(i, y)->GetTeam() != GetTeam())
		{
			if (Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'Q'
				|| Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'rook')
			{
				if (CanBeReached(i, y))
				{
					return true;
				}
			}
		}
	}

	for (int i = x; i < 8; i++)
	{
		if (Field::Instance()->getFigure(i, y)->GetTeam() != GetTeam())
		{
			if (Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'Q'
				|| Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'rook')
			{
				if (CanBeReached(i, y))
				{
					return true;
				}
			}
		}
	}

	for (int i = y; i < 8; i++)
	{
		if (Field::Instance()->getFigure(x, i)->GetTeam() != GetTeam())
		{
			if (Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'Q'
				|| Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'rook')
			{
				if (CanBeReached(i, y))
				{
					return true;
				}
			}
		}
	}

	for (int i = y; i >= 8; i++)
	{
		if (Field::Instance()->getFigure(x, i)->GetTeam() != GetTeam())
		{
			if (Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'Q'
				|| Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'rook')
			{
				if (CanBeReached(i, y))
				{
					return true;
				}
			}
		}
	}

	std::array<bool, 4> pawnInQadrant = { false };

	if (GetTeam() == 'b')
	{
		if (Field::Instance()->getFigure(x - 1, y - 1)->GetTeam() == 'w'
			&& Field::Instance()->getFigure(x - 1, y - 1)->GetFirstLetter() == 'p')
		{
			if (CanBeReached(x - 1, y - 1))
			{
				return true;
			}
			pawnInQadrant[2] = true;
		}

		if (Field::Instance()->getFigure(x + 1, y - 1)->GetTeam() == 'w'
			&& Field::Instance()->getFigure(x + 1, y - 1)->GetFirstLetter() == 'p')
		{
			if (CanBeReached(x + 1, y - 1))
			{
				return true;
			}
			pawnInQadrant[3] = true;
		}
	}
	else
	{
		if (Field::Instance()->getFigure(x + 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance()->getFigure(x + 1, y + 1)->GetFirstLetter() == 'p')
		{
			if (CanBeReached(x + 1, y + 1))
			{
				return true;
			}
			pawnInQadrant[0] = true;
		}

		if (Field::Instance()->getFigure(x - 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance()->getFigure(x - 1, y + 1)->GetFirstLetter() == 'p')
		{
			if (CanBeReached(x - 1, y + 1))
			{
				return true;
			}
			pawnInQadrant[4] = true;
		}
	}

	if (!pawnInQadrant[0])
	{
		for (int i = 1; ((x + i) <= 8) || ((y + i) <= 8); i++)
		{
			if (Field::Instance()->getFigure(x + i, y + 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x + i, y + i)->GetFirstLetter() == 'b'
					|| Field::Instance()->getFigure(x + i, y + i)->GetFirstLetter() == 'Q')
				{
					if (CanBeReached(x + i, y + i))
					{
						return true;
					}
					break;
				}
			}

			if (Field::Instance()->isFigure(x + i, y + i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[1])
	{
		for (int i = 1; ((x - i) > 0) || ((y + i) <= 8); i++)
		{
			if (Field::Instance()->getFigure(x - i, y + 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x - i, y + i)->GetFirstLetter() == 'b'
					|| Field::Instance()->getFigure(x - i, y + i)->GetFirstLetter() == 'Q')
				{
					if (CanBeReached(x - i, y + i))
					{
						return true;
					}
					break;
				}
			}

			if (Field::Instance()->isFigure(x - i, y + i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[2])
	{
		for (int i = 1; ((x - i) > 0) || ((y - i) > 0); i++)
		{
			if (Field::Instance()->getFigure(x - i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x - i, y - i)->GetFirstLetter() == 'b'
					|| Field::Instance()->getFigure(x - i, y - i)->GetFirstLetter() == 'Q')
				{
					if (CanBeReached(x - i, y - i))
					{
						return true;
					}
					break;
				}
			}

			if (Field::Instance()->isFigure(x - i, y - i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[3])
	{
		for (int i = 1; ((x + i) >= 8) || ((y - i) > 0); i++)
		{
			if (Field::Instance()->getFigure(x + i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x + i, y - i)->GetFirstLetter() == 'b'
					|| Field::Instance()->getFigure(x + i, y - i)->GetFirstLetter() == 'Q')
				{
					if (CanBeReached(x + i, y - i))
					{
						return true;
					}
					break;
				}
			}

			if (Field::Instance()->isFigure(x + i, y - i))
			{
				break;
			}
		}
	}

	if ((Field::Instance()->getFigure(x + 2, y - 1)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x + 2, y - 1)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x + 2, y - 1))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x + 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x + 2, y + 1)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x + 2, y - 1))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x - 2, y - 1)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x - 2, y - 1)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x - 2, y - 1))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x - 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x - 2, y + 1)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x - 2, y + 1))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x + 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x + 1, y + 2)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x + 1, y + 2))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x + 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x + 1, y - 2)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x + 1, y - 2))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x - 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x - 1, y + 2)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x - 1, y + 2))
		{
			return true;
		}
	}

	if ((Field::Instance()->getFigure(x - 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance()->getFigure(x - 1, y - 2)->GetFirstLetter() == 'k'))
	{
		if (CanBeReached(x - 1, y - 2))
		{
			return true;
		}
	}

	return false;
}

int King::GetFiguresChessing()
{
	return figuresChessing;
}

/*bool King::IsMoved()
{
	return isMoved;
}

//Make function that check the vert, dia, hor, knights only for the king
//it is searching for a figure
//then this figure need to be CanBeReached
//if it returns true, the king can be "unchessed"
//done*/