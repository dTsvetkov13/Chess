#include "Player.h"
#include "King.h"
#include "Figure.h"
#include <ctype.h>
#include <stdio.h>

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

void Player::SetTeam(char team)
{
	m_team = team;
}

char Player::GetTeam()
{
	return m_team;
}

bool Player::isKingCheckmated()
{
	King k;

	if (kingIsInChess && k.isCheckmated(m_king.first, m_king.second))
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool Player::Turn(Player &enemyPlayer)
{
	string moveFrom;
	string moveTo;

	int fromX, fromY, toX, toY;

	std::cout << Field::Instance();

	while (true)
	{
		cout << "Please, " << m_name << ", enter your choice : " << endl;
		cout << "From : ";
		cin >> moveFrom;
		cout << "To : ";
		cin >> moveTo;

		if (moveFrom.size() == 2 && moveTo.size() == 2)
		{
			fromX = tolower(moveFrom[0]) - 'a' + 1;
			fromY = 9 - (moveFrom[1] - '0');
			toX = tolower(moveTo[0]) - 'a' + 1;
			toY = 9 - (moveTo[1] - '0');

			if (!IsValid(fromX, fromY) || !IsValid(toX, toY))
			{
				continue;
			}

			break;
		}
		else
		{
			cout << "Wrong input, try again: " << endl;
		}
	}

	std::cout << fromX << " + " << fromY << " to " << toX << " + " << toY << std::endl;

	if (Field::Instance()->isFigure(fromX, fromY)) std::cout << "it is figure and = " <<
		Field::Instance()->getFigure(fromX, fromY)->GetFirstLetter() << " t = " <<
		Field::Instance()->getFigure(fromX, fromY)->GetTeam() << " my t = " << GetTeam() << std::endl;

	//Change Field::Instance() with pointer

	if (Field::Instance()->getFigure(fromX, fromY)->GetTeam() == m_team)
	{
		if (kingIsInChess)
		{
			King k;
			k.SetTeam(GetTeam());
			k.SetFirstLetter('K');
			
			if (Field::Instance()->getFigure(fromX, fromY)->Move(fromX, fromY, toX, toY))
			{
				Field::Instance()->Move(fromX, fromY, toX, toY);

				if (k.CanBeReached(m_king.first, m_king.second))
				{
					Field::Instance()->Move(toX, toY, fromX, fromY);
					std::cout << "The king is still in chess! Try again : \n";
					return false;
				}
				kingIsInChess = false;
				return true;
			}

			std::cout << "Can not do this move" << std::endl;

			return false;
		}
		else
		{
			if (Field::Instance()->getFigure(fromX, fromY)->Move(fromX, fromY, toX, toY))
			{
				if (fromY == toY && std::abs(fromX - toX) == 2
					&& Field::Instance()->getFigure(fromX, fromY)->GetFirstLetter() == 'K')
				{
					Field::Instance()->CastlingMove(fromX, fromY, toX, toY);
				}
				else
				{
					Field::Instance()->Move(fromX, fromY, toX, toY);
				}

				//Check if the it put the enemy King into chess

				if (Field::Instance()->getFigure(toX, toY)
					->Move(toX, toY, 
							Field::Instance()->GetCordsOfEnemyKing(GetTeam()).first,
							Field::Instance()->GetCordsOfEnemyKing(GetTeam()).second))
				{
					//set the enemy kingIsInChess to true
					enemyPlayer.SetKingIntoChess();
					
					kingIsInChess = true;
				}

				return true;
			}
			else
			{
				std::cout << "Can not reach it!" << std::endl;
				return false;
			}
			//CHECK THIS SEGMENT FOR LOGICAL ERRS
			//done
		}
	}
	else
	{
		cout << "Wrong input, try again: " << endl;
		return false;
		//Turn(field);
	}

	/*
	if (Field::Instance().isFigure(&moveFrom[0], (moveFrom[1] - '0'))
		&& Field::Instance().getFigure(&moveFrom[0], (moveFrom[1] - '0'))->GetTeam() == m_team
		&& Field::Instance().getFigure(&moveFrom[0], (moveFrom[1] - '0'))->Move(&moveFrom[0], &moveTo[0]))
	{
		Field::Instance().Move(&moveFrom[0], &moveTo[0]);
		return true;
	}
	else
	{
		cout << "Wrong input, try again: " << endl;
		return false;
		//Turn(field);
	}
	*/
	// mat
	// pat
	// shah
	// funkcii za tqh
	//ROKADO

}

void Player::SetKingIntoChess()
{
	kingIsInChess = true;
}