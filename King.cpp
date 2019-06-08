#include "King.h"
#include "Field.h"
#include <array>

King::King()
{
	SetFirstLetter('K'); 
}

King::~King()
{
}

bool King::VerticalAndHorizontal(int x, int y)
{
	for (int i = x; i <= 8; i++)
	{
		if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
		{
			if (Field::Instance().getFigure(i, y)->GetFirstLetter() == 'r'
				|| Field::Instance().getFigure(i, y)->GetFirstLetter() == 'Q')
			{
				return true;
			}
		}

		if (Field::Instance().isFigure(i, y))
		{
			break;
		}
	}

	for (int i = x; i > 0; i--)
	{
		if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
		{
			if (Field::Instance().getFigure(i, y)->GetFirstLetter() == 'r'
				|| Field::Instance().getFigure(i, y)->GetFirstLetter() == 'Q')
			{
				return true;
			}
		}

		if (Field::Instance().isFigure(i, y))
		{
			break;
		}
	}

	for (int i = y; i <= 8; i++)
	{
		if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
		{
			if (Field::Instance().getFigure(x, i)->GetFirstLetter() == 'r'
				|| Field::Instance().getFigure(x, i)->GetFirstLetter() == 'Q')
			{
				return true;
			}
		}

		if (Field::Instance().isFigure(x, i))
		{
			break;
		}
	}

	for (int i = y; i > 0; i--)
	{
		if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
		{
			if (Field::Instance().getFigure(x, i)->GetFirstLetter() == 'r'
				|| Field::Instance().getFigure(x, i)->GetFirstLetter() == 'Q')
			{
				return true;
			}
		}

		if (Field::Instance().isFigure(x, i))
		{
			break;
		}
	}

	return false;
}

bool King::Diagonals(int x, int y)
{
	// first check for pawns
	std::array<bool, 4> pawnInQadrant = {false};

	if (GetTeam() == 'b')
	{
		if (Field::Instance().getFigure(x - 1, y - 1)->GetTeam() == 'w'
			&& Field::Instance().getFigure(x - 1, y - 1)->GetFirstLetter() == 'p')
		{
			pawnInQadrant[2] = true;
		}

		if (Field::Instance().getFigure(x + 1, y - 1)->GetTeam() == 'w'
			&& Field::Instance().getFigure(x + 1, y - 1)->GetFirstLetter() == 'p')
		{
			pawnInQadrant[3] = true;
		}
	}
	else
	{
		if (Field::Instance().getFigure(x + 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance().getFigure(x + 1, y + 1)->GetFirstLetter() == 'p')
		{
			pawnInQadrant[0] = true;
		}

		if (Field::Instance().getFigure(x - 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance().getFigure(x - 1, y + 1)->GetFirstLetter() == 'p')
		{
			pawnInQadrant[4] = true;
		}
	}

	if (!pawnInQadrant[0])
	{
		for (int i = 1; ((x + i) >= 8) || ((y + i) >= 8); i++)
		{
			if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance().getFigure(x + i, y + i)->GetFirstLetter() == 'r'
					|| Field::Instance().getFigure(x + i, y + i)->GetFirstLetter() == 'Q')
				{
					return true;
				}
			}

			if (Field::Instance().isFigure(x + i, y + i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[1])
	{
		for (int i = 1; ((x - i) > 0) || ((y + i) <= 8); i++)
		{
			if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance().getFigure(x - i, y + i)->GetFirstLetter() == 'r'
					|| Field::Instance().getFigure(x - i, y + i)->GetFirstLetter() == 'Q')
				{
					return true;
				}
			}

			if (Field::Instance().isFigure(x - i, y + i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[2])
	{
		for (int i = 1; ((x - i) > 0) || ((y - i) > 0); i++)
		{
			if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance().getFigure(x - i, y - i)->GetFirstLetter() == 'r'
					|| Field::Instance().getFigure(x - i, y - i)->GetFirstLetter() == 'Q')
				{
					return true;
				}
			}

			if (Field::Instance().isFigure(x - i, y - i))
			{
				break;
			}
		}
	}

	if (pawnInQadrant[3])
	{
		for (int i = 1; ((x + i) >= 8) || ((y - i) > 0); i++)
		{
			if (Field::Instance().getFigure(x + i, y - 1)->GetTeam() != GetTeam())
			{
				if (Field::Instance().getFigure(x + i, y - i)->GetFirstLetter() == 'r'
					|| Field::Instance().getFigure(x + i, y - i)->GetFirstLetter() == 'Q')
				{
					return true;
				}
			}

			if (Field::Instance().isFigure(x + i, y - i))
			{
				break;
			}
		}
	}

	return false;
}

bool King::KnightMove(int x, int y)
{
	/*
	x + 2, y - 1
	x + 2, y + 1
	x - 2, y - 1
	x - 2, y + 1
	x + 1, y + 2
	x + 1, y - 2
	x - 1, y + 2
	x - 1, y - 2
	*/

	if ((Field::Instance().getFigure(x + 2, y - 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 2, y - 1)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x + 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 2, y + 1)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x - 2, y - 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 2, y - 1)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x - 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 2, y + 1)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x + 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 1, y + 2)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x + 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 1, y - 2)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x - 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 1, y + 2)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	if ((Field::Instance().getFigure(x - 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 1, y - 2)->GetFirstLetter() == 'k'))
	{
		return true;
	}

	return false;
}

bool King::IsChess(int x, int y)
{
	if (VerticalAndHorizontal(x, y) || Diagonals(x, y) || KnightMove(x, y))
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

bool King::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (Field::Instance().getFigure(toX, toY)->GetTeam()
		== Field::Instance().getFigure(fromX, fromY)->GetTeam())
	{
		return false;
	}
	return true;
}