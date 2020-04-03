#include <ctype.h>
#include <stdio.h>
#include "Player.h"
#include "King.h"
#include "Field.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Quenn.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::SetName(string name)
{
	m_name = name;
}
string& Player::GetName()
{
	return m_name;
}

void Player::SetTeam(Team team)
{
	m_team = team;
}

Team Player::GetTeam()
{
	return m_team;
}

bool Player::isKingCheckmated()
{
	Figure* f = Field::Instance()->getFigure(m_king);
	if (!kingIsInChess)
	{
		if(f->CanBeReached(m_king)) kingIsInChess = true;
	}
	King king(GetTeam());

	if (kingIsInChess) cout << "The king is in chess! " << std::endl;
	else  cout << "The king is not in chess! " << std::endl;

	if (kingIsInChess && king.isCheckmated(m_king))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::SetKingCords(const Cord& cord)
{
	m_king = cord;
}

bool Player::IsValid(int x, int y)
{
	if ((y - 1) < 0 || (y - 1) >= 8 || (x - 1) < 0 || (x - 1) >= 8)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::Turn()
{
	string moveFrom;
	string moveTo;

	Cord from, to;

	std::cout << Field::Instance();

	while (true)
	{
		cout << "Please, " << m_name << ", enter your move: " << endl;
		cout << "From : ";
		cin >> moveFrom;
		cout << "To : ";
		cin >> moveTo;

		if (moveFrom.size() == 2 && moveTo.size() == 2)
		{
			from.x = tolower(moveFrom[0]) - 'a' + 1;
			from.y = 9 - (moveFrom[1] - '0');
			to.x = tolower(moveTo[0]) - 'a' + 1;
			to.y = 9 - (moveTo[1] - '0');

			if (!IsValid(from.x, from.y) || !IsValid(to.x, to.y))
			{
				std::cout << "Invalid data!" << std::endl;
				continue;
			}

			if (Field::Instance()->isFigure(from) && Field::Instance()->getFigure(from)->GetTeam() == GetTeam())
			{
				break;
			}
			else
			{
				std::cout << "This figure is not from your team." << std::endl;
				continue;
			}
		}

		std::cout << "Invalid data!" << std::endl;
	}

	if (Field::Instance()->isCastlingMove(from, to))
	{
		if(Field::Instance()->getFigure(from)->GetFigureType() == Figures::King
			&& Field::Instance()->getFigure(to)->GetFigureType() == Figures::Rook)
		{
			bool left = false;

			if (Field::Instance()->CastlingMove(from, to, left))
			{
				if (left)
				{
					m_king.x -= 2;
				}
				else
				{
					m_king.x += 2;
				}

				return true;
			}

			return false;
		}
		
		if (Field::Instance()->getFigure(to)->GetFigureType() == Figures::King
			&& Field::Instance()->getFigure(from)->GetFigureType() == Figures::Rook)
		{
			bool left = false;

			if (Field::Instance()->CastlingMove(to, from, left))
			{
				if (left)
				{
					m_king.x -= 2;
				}
				else
				{
					m_king.x += 2;
				}

				return true;
			}
			return false;
		}
	}

	King k;
	k.SetTeam(GetTeam());
	k.SetFigureType(Figures::King);

	if (Field::Instance()->getFigure(from)->Move(from, to))
	{
		Figures toFigureType;
		Team toTeam;

		bool isToFigure = false;

		if (Field::Instance()->isFigure(to))
		{
			isToFigure = true;
			toFigureType = Field::Instance()->getFigure(from)->GetFigureType();
			toTeam = Field::Instance()->getFigure(from)->GetTeam();
		}

		Field::Instance()->swapTwoFigures(from, to);

		Field::Instance()->SetToNullPointer(from);

		if (Field::Instance()->getFigure(to)->GetFigureType() == Figures::King)
		{
			m_king = Cord(to.x, to.y);
		}

		if (k.IsInChess(m_king))
		{
			Field::Instance()->swapTwoFigures(from, to);

			if (isToFigure)
			{
				Field::Instance()->setFigure(to, toFigureType, toTeam);
			}

			if (Field::Instance()->getFigure(from)->GetFigureType() == Figures::King)
			{
				cout << "There the king will be in chess!" << endl;
				m_king = Cord(from.x, from.y);
			}
			else
			{
				cout << "Your king is in chess!" << endl;
			}

			kingIsInChess = true;
			return false;
		}

		kingIsInChess = false;
		return true;
	}

	return false;
}

void Player::SetKingIntoChess()
{
	kingIsInChess = true;
}