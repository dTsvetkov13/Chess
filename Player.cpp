#include "Player.h"
#include "King.h"

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

bool Player::Turn()
{
	string moveFrom;
	string moveTo;

	int fromX, fromY, toX, toY;
	King k;

	if (kingIsInChess && k.isCheckmated(m_king.first, m_king.second))
	{
		throw 1;
	}

	while (true)
	{
		cout << "Please, enter your choice : " << endl;
		cout << "From : ";
		cin >> moveFrom;
		cout << "To : ";
		cin >> moveTo;

		if (moveFrom.size() == 2 && moveTo.size() == 2)
		{
			break;
		}
		else
		{
			cout << "Wrong input, try again: " << endl;
		}
	}

	fromX = moveFrom[0];
	fromY = moveFrom[1];
	toX = moveTo[0];
	toY = moveTo[1];

	if (Field::Instance().getFigure(fromX, fromY)->GetTeam() == m_team)
	{
		if (kingIsInChess)
		{
			King k;
			k.SetTeam(GetTeam());
			k.SetFirstLetter('K');
			
			if (Field::Instance().getFigure(fromX, fromY)->Move(&moveFrom[0], &moveTo[0]))
			{
				Field::Instance().Move(&moveFrom[0], &moveTo[0]);
				if (k.IsChess(m_king.first, m_king.second))
				{
					Field::Instance().Move(&moveTo[0], &moveFrom[0]);
					std::cout << "The king is still in chess! Try again : \n";
					return false;
				}
				kingIsInChess = false;
				return true;
			}
		}
		else
		{
			if (Field::Instance().getFigure(fromX, fromY)->Move(&moveFrom[0], &moveTo[0]))
			{
				Field::Instance().Move(&moveFrom[0], &moveTo[0]);

				//TODO : Change Move's arguments to int and int
				if (Field::Instance().getFigure(toX, toY)->Move(m_king.first, m_king.second))
				{
					kingIsInChess = true;
				}

				return true;
			}
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


}