#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Turn(Field &field)
{
	string moveFrom;
	string moveTo;

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

	if (field.isFigure(&moveFrom[0], (moveFrom[1] - '0'))
		&& field.getFigure(&moveFrom[0], (moveFrom[1] - '0'))->GetTeam() == &team
		&& field.getFigure(&moveFrom[0], (moveFrom[1] - '0'))->CanReach(&moveFrom[0], &moveTo[0]))
	{
		field.Move(&moveFrom[0], &moveTo[0]);
	}
	else
	{
		cout << "Wrong input, try again: " << endl;
		Turn(field);
	}

	// mat
	// pat
	// shah
	// funkcii za tqh


}