#include "Figure.h"
#include "Field.h"
#include "Quenn.h"

Figure::Figure()
{
}

Figure::Figure(char team)
{
	m_team = team;
}

Figure::~Figure()
{
}

void Figure::SetTeam(char team)
{
	m_team = team;
}

char Figure::GetTeam()
{
	return m_team;
}

void Figure::SetFirstLetter(char c)
{
	m_firstLetter = c;
}

char Figure::GetFirstLetter()
{
	return m_firstLetter;
}

bool Figure::IsMoved()
{
	return isMoved;
}

bool Figure::Move(int fromX, int fromY, int toX, int toY)
{
	if (CanReach(fromX, fromY, toX, toY))
	{
		if (!FigureOnTheWay(fromX, fromY, toX, toY))
		{
			isMoved = true;

			return true;
			//TODO check if the enemy king is in chess
			//TODO check if this figure can protect the their king
		}
		else
		{
			std::cout << "There is a figure on the way";
			return false;
			//TODO throw exception or enum 
		}
	}
	else
	{
		//TODO better message
		std::cout << "can't reach";
		return false;
	}
}

int Figure::VerticalAndHorizontal(int x, int y)
{
	int figuresChessing = 0;

	for (int i = x; i <= 8; i++)
	{
		if (Field::Instance()->isFigure(x + i, y))
		{
			if (Field::Instance()->getFigure(x + i, y)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'r'
					|| Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'Q')
				{
					figuresChessing++;
					break;
				}
			}
		}

		if (Field::Instance()->isFigure(i, y))
		{
			break;
		}
	}

	for (int i = x; i > 0; i--)
	{
		if (Field::Instance()->isFigure(i, y))
		{
			if (Field::Instance()->getFigure(i, y)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'r'
					|| Field::Instance()->getFigure(i, y)->GetFirstLetter() == 'Q')
				{
					figuresChessing++;
					break;
				}
			}
		}

		if (Field::Instance()->isFigure(i, y))
		{
			break;
		}
	}

	for (int i = y; i <= 8; i++)
	{
		if (Field::Instance()->isFigure(x, i))
		{
			if (Field::Instance()->getFigure(x, i)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'r'
					|| Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'Q')
				{
					figuresChessing++;
					break;
				}
			}
		}

		if (Field::Instance()->isFigure(x, i))
		{
			break;
		}
	}

	for (int i = y; i > 0; i--)
	{
		if (Field::Instance()->isFigure(x, i))
		{
			if (Field::Instance()->getFigure(x, i)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'r'
					|| Field::Instance()->getFigure(x, i)->GetFirstLetter() == 'Q')
				{
					figuresChessing++;
					break;
				}
			}
		}

		if (Field::Instance()->isFigure(x, i))
		{
			break;
		}
	}
	
	return figuresChessing;
}

int Figure::Diagonals(int x, int y)
{
	// first check for pawns
	int figuresChessing = 0;
	std::array<bool, 4> pawnInQadrant = { false };

	if (GetTeam() == 'b')
	{
		if(Field::Instance()->isFigure(x - 1, y - 1))
			if (Field::Instance()->getFigure(x - 1, y - 1)->GetTeam() == 'w'
				&& Field::Instance()->getFigure(x - 1, y - 1)->GetFirstLetter() == 'p')
			{
				figuresChessing++;
				pawnInQadrant[2] = true;
			}
		if (Field::Instance()->isFigure(x + 1, y - 1))
			if (Field::Instance()->getFigure(x + 1, y - 1)->GetTeam() == 'w'
				&& Field::Instance()->getFigure(x + 1, y - 1)->GetFirstLetter() == 'p')
			{
				figuresChessing++;
				pawnInQadrant[3] = true;
			}
	}
	else
	{
		if (Field::Instance()->isFigure(x + 1, y + 1))
			if (Field::Instance()->getFigure(x + 1, y + 1)->GetTeam() == 'b'
				&& Field::Instance()->getFigure(x + 1, y + 1)->GetFirstLetter() == 'p')
			{
				figuresChessing++;
				pawnInQadrant[0] = true;
			}

		if (Field::Instance()->isFigure(x - 1, y + 1))
			if (Field::Instance()->getFigure(x - 1, y + 1)->GetTeam() == 'b'
				&& Field::Instance()->getFigure(x - 1, y + 1)->GetFirstLetter() == 'p')
			{
				figuresChessing++;
				pawnInQadrant[4] = true;
			}
	}
	// CHECK THIS SEGMENT, change r with b, check the iterating ("x + 1")
	if (!pawnInQadrant[0])
	{
		for (int i = 1; ((x + i) <= 8) || ((y + i) <= 8); i++)
		{
			if (Field::Instance()->getFigure(x + i, y + 1))
				if (Field::Instance()->getFigure(x + i, y + 1)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(x + i, y + i)->GetFirstLetter() == 'b'
						|| Field::Instance()->getFigure(x + i, y + i)->GetFirstLetter() == 'Q')
					{
						figuresChessing++;
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
			if (Field::Instance()->isFigure(x - i, y + i))
				if (Field::Instance()->getFigure(x - i, y + i)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(x - i, y + i)->GetFirstLetter() == 'b'
						|| Field::Instance()->getFigure(x - i, y + i)->GetFirstLetter() == 'Q')
					{
						figuresChessing++;
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
			if (Field::Instance()->isFigure(x - i, y - 1))
				if (Field::Instance()->getFigure(x - i, y - 1)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(x - i, y - i)->GetFirstLetter() == 'b'
						|| Field::Instance()->getFigure(x - i, y - i)->GetFirstLetter() == 'Q')
					{
						figuresChessing++;
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
		for (int i = 1; ((x + i) <= 8) || ((y - i) > 0); i++)
		{
			if (Field::Instance()->isFigure(x + i, y - 1))
				if (Field::Instance()->getFigure(x + i, y - 1)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(x + i, y - i)->GetFirstLetter() == 'b'
						|| Field::Instance()->getFigure(x + i, y - i)->GetFirstLetter() == 'Q')
					{
						figuresChessing++;
						break;
					}
				}

			if (Field::Instance()->isFigure(x + i, y - i))
			{
				break;
			}
		}
	}

	return figuresChessing;
}

int Figure::KnightMove(int x, int y)
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

	int figuresChessing = 0;
		
	if (Field::Instance()->isFigure(x + 2, y - 1))
		if ((Field::Instance()->getFigure(x + 2, y - 1)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x + 2, y - 1)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x + 2, y + 1))
		if ((Field::Instance()->getFigure(x + 2, y + 1)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x + 2, y + 1)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x - 2, y - 1))
		if ((Field::Instance()->getFigure(x - 2, y - 1)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x - 2, y - 1)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x - 2, y + 1))
		if ((Field::Instance()->getFigure(x - 2, y + 1)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x - 2, y + 1)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x + 1, y + 2))
		if ((Field::Instance()->getFigure(x + 1, y + 2)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x + 1, y + 2)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}
	if (Field::Instance()->isFigure(x + 1, y - 2))
		if ((Field::Instance()->getFigure(x + 1, y - 2)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x + 1, y - 2)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x - 1, y + 2))
		if ((Field::Instance()->getFigure(x - 1, y + 2)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x - 1, y + 2)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	if (Field::Instance()->isFigure(x - 1, y - 2))
		if ((Field::Instance()->getFigure(x - 1, y - 2)->GetTeam() != GetTeam())
			&& (Field::Instance()->getFigure(x - 1, y - 2)->GetFirstLetter() == 'k'))
		{
			figuresChessing++;
		}

	return figuresChessing;
}

int Figure::CanBeReached(int x, int y)
{
	/*if (VerticalAndHorizontal(x, y) || Diagonals(x, y) || KnightMove(x, y))
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return VerticalAndHorizontal(x, y) + Diagonals(x, y) + KnightMove(x, y);
}