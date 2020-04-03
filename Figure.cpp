#include "Figure.h"
#include "Field.h"
#include "Quenn.h"
#include "King.h"

Figure::Figure()
{
}

Figure::Figure(Team team)
{
	m_team = team;
}

Figure::Figure(Team team, Figures figureType)
{
	m_team = team;
	m_figureType = figureType;
}

Figure::~Figure()
{
	
}

void Figure::SetTeam(Team team)
{
	m_team = team;
}

Team Figure::GetTeam()
{
	return m_team;
}

void Figure::SetFigureType(Figures c)
{
	m_figureType = c;
}

Figures Figure::GetFigureType()
{
	return m_figureType;
}

std::string Figure::GetFigureSymbol()
{
	return "f";
}

bool Figure::IsMoved()
{
	return isMoved;
}

bool Figure::Move(const Cord& from, const Cord& to)
{
	if (CanReach(from, to))
	{
		if (!FigureOnTheWay(from, to))
		{
			isMoved = true;

			return true;
		}
		else
		{
			std::cout << "There is a figure on the way" << std::endl;
			return false;
			//TODO throw exception or enum 
		}
	}
	else
	{
		std::cout << "Cannot be reached!" << std::endl;
		return false;
	}
}

int Figure::VerticalAndHorizontal(const Cord& cord)
{
	int figuresChessing = 0;

	Cord temp;

	for (int i = cord.x + 1; i <= 8; i++)
	{
		temp = Cord(i, cord.y);

		if (Field::Instance()->isFigure(temp))
		{
			if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Rook
					|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	for (int i = cord.x - 1; i > 0; i--)
	{
		temp = Cord(i, cord.y);

		if (Field::Instance()->isFigure(temp))
		{
			if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Rook
					|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	for (int i = cord.y + 1; i <= 8; i++)
	{
		temp = Cord(cord.x, i);

		if (Field::Instance()->isFigure(temp))
		{
			if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Rook
					|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	for (int i = cord.y - 1; i > 0; i--)
	{
		temp = Cord(cord.x, i);

		if (Field::Instance()->isFigure(temp))
		{
			if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
			{
				if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Rook
					|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return getFiguresPointingToThisFigure()->size();
}

int Figure::Diagonals(const Cord& cord)
{
	// first check for Pawns and King
	int figuresChessing = 0;
	std::array<bool, 4> pawnInQadrant = { false };

	Cord temp;

	if (GetTeam() == Team::Black)
	{
		if (!(cord.x - 1 < 1 || (cord.y + 1 > 8)))
		{
			temp = Cord(cord.x - 1, cord.y + 1);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() == Team::White
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Pawn
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::King))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					pawnInQadrant[1] = true;
				}
		}	

		if (!(cord.x + 1 > 8 || (cord.y + 1 > 8)))
		{
			temp = Cord(cord.x + 1, cord.y + 1);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() == Team::White
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Pawn
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::King))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					pawnInQadrant[0] = true;
				}
		}
	}
	else
	{
		if (!(cord.x + 1 > 8 || (cord.y - 1 < 1)))
		{
			temp = Cord(cord.x + 1, cord.y - 1);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() == Team::Black
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Pawn
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::King))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					pawnInQadrant[3] = true;
				}
		}

		if (!(cord.x - 1 < 1 || (cord.y - 1 < 1)))
		{
			temp = Cord(cord.x - 1, cord.y - 1);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() == Team::Black
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Pawn
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::King))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
					pawnInQadrant[2] = true;
				}
		}
	}
	
	if (!pawnInQadrant[0])
	{
		for (int i = 1; ((cord.x + i) <= 8) && ((cord.y + i) <= 8); i++)
		{
			temp = Cord(cord.x + i, cord.y + i);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(temp)->GetFigureType() ==	Figures::Bishop
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
					{
						figuresPointingToThisFigure.push_back(temp);
						figuresChessing++;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
		}
	}

	if (!pawnInQadrant[1])
	{
		for (int i = 1; ((cord.x - i) > 0) && ((cord.y + i) <= 8); i++)
		{
			temp = Cord(cord.x - i, cord.y + i);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Bishop
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
					{
						figuresPointingToThisFigure.push_back(temp);
						figuresChessing++;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
		}
	}

	if (!pawnInQadrant[2])
	{
		for (int i = 1; ((cord.x - i) > 0) && ((cord.y - i) > 0); i++)
		{
			temp = Cord(cord.x - i, cord.y - i);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Bishop
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
					{
						figuresPointingToThisFigure.push_back(temp);
						figuresChessing++;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
		}
	}

	if (!pawnInQadrant[3])
	{
		for (int i = 1; ((cord.x + i) <= 8) && ((cord.y - i) > 0); i++)
		{
			temp = Cord(cord.x + i, cord.y - i);

			if (Field::Instance()->isFigure(temp))
				if (Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				{
					if (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Bishop
						|| Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Quenn)
					{
						figuresPointingToThisFigure.push_back(temp);
						figuresChessing++;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
		}
	}

	return figuresChessing;
}

int Figure::KnightMove(const Cord& cord)
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
	Cord temp;

	if (cord.x > 0 && cord.x + 2 <= 8 && cord.y <= 8)
	{
		if (cord.y - 1 > 0)
		{
			temp = Cord(cord.x + 2, cord.y - 1);

			if (Field::Instance()->isFigure(temp))
				if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
				}
		}

		if (cord.y + 1 <= 8)
		{
			temp = Cord(cord.x + 2, cord.y + 1);

			if (Field::Instance()->isFigure(temp))
				if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
					&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
				{
					figuresPointingToThisFigure.push_back(temp);
					figuresChessing++;
				}
		}
	}

	if (cord.x - 2 >= 1 && ((cord.y - 1) > 0) && cord.y <= 8)
	{
		temp = Cord(cord.x - 2, cord.y - 1);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}

		temp = Cord(cord.x - 2, cord.y + 1);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}
	}

	if (((cord.x - 1) > 0) && cord.x <= 8 && cord.y + 2 <= 8)
	{
		temp = Cord(cord.x + 1, cord.y + 2);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}

		temp = Cord(cord.x - 1, cord.y + 2);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}
	}

	if (((cord.x - 1) > 0) && cord.x <= 8 && cord.y - 2 > 0)
	{
		temp = Cord(cord.x + 1, cord.y - 2);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}

		temp = Cord(cord.x - 1, cord.y - 2);

		if (Field::Instance()->isFigure(temp))
			if ((Field::Instance()->getFigure(temp)->GetTeam() != GetTeam())
				&& (Field::Instance()->getFigure(temp)->GetFigureType() == Figures::Knight))
			{
				figuresPointingToThisFigure.push_back(temp);
				figuresChessing++;
			}
	}

	return figuresChessing;
}

int Figure::CanBeReached(const Cord& cord)
{
	return VerticalAndHorizontal(cord) + Diagonals(cord) + KnightMove(cord);
}

void Figure::ClearPointingFigures()
{
	figuresPointingToThisFigure.clear();
}

std::list<Cord>* Figure::getFiguresPointingToThisFigure()
{
	return &figuresPointingToThisFigure;
}

Figure * Figure::kingInFiguresPointingToThisFigure()
{
	for (auto it : figuresPointingToThisFigure)
	{
		if (Field::Instance()->getFigure(it)->GetFigureType() == Figures::King)
		{
			return Field::Instance()->getFigure(it);
		}
	}
	return nullptr;
}
