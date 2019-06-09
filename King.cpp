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
				figuresChessing++;
				break;
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
				figuresChessing++;
				break;
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
				figuresChessing++;
				break;
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
				figuresChessing++;
				break;
			}
		}

		if (Field::Instance().isFigure(x, i))
		{
			break;
		}
	}

	if (figuresChessing > 0)
	{
		return true;
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
			figuresChessing++;
			pawnInQadrant[2] = true;
		}

		if (Field::Instance().getFigure(x + 1, y - 1)->GetTeam() == 'w'
			&& Field::Instance().getFigure(x + 1, y - 1)->GetFirstLetter() == 'p')
		{
			figuresChessing++;
			pawnInQadrant[3] = true;
		}
	}
	else
	{
		if (Field::Instance().getFigure(x + 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance().getFigure(x + 1, y + 1)->GetFirstLetter() == 'p')
		{
			figuresChessing++;
			pawnInQadrant[0] = true;
		}

		if (Field::Instance().getFigure(x - 1, y + 1)->GetTeam() == 'b'
			&& Field::Instance().getFigure(x - 1, y + 1)->GetFirstLetter() == 'p')
		{
			figuresChessing++;
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
					figuresChessing++;
					break;
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
					figuresChessing++;
					break;
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
					figuresChessing++;
					break;
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
					figuresChessing++;
					break;
				}
			}

			if (Field::Instance().isFigure(x + i, y - i))
			{
				break;
			}
		}
	}

	if (figuresChessing > 0)
	{
		return true;
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
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x + 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 2, y + 1)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x - 2, y - 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 2, y - 1)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x - 2, y + 1)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 2, y + 1)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x + 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 1, y + 2)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x + 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x + 1, y - 2)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x - 1, y + 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 1, y + 2)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if ((Field::Instance().getFigure(x - 1, y - 2)->GetTeam() != GetTeam())
		&& (Field::Instance().getFigure(x - 1, y - 2)->GetFirstLetter() == 'k'))
	{
		figuresChessing++;
	}

	if (figuresChessing > 0)
	{
		return true;
	}

	return false;
}

bool King::isCheckmated(int x, int y)
{
	y -= 1;
	x -= 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!Field::Instance().isFigure(x + j, y + i)
				&& !IsChess(x + j, y + i))
			{
				return false;
			}
		}
	}

	if (figuresChessing == 1)
	{
		// TODO : check if there is a possible way to "unchess"
		// the King, so the game can continue

		return false;
	}

	return true;
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
	if (IsChess(toX, toY))
	{
		return false;
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

bool King::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (Field::Instance().getFigure(toX, toY)->GetTeam()
		== Field::Instance().getFigure(fromX, fromY)->GetTeam())
	{
		return false;
	}
	return true;
}