#include <iostream>
#include <string>
#include "Figure.h"
#include "Player.h"

int main()
{
	std::pair<int, int> blackKing;
	std::pair<int, int> whiteKing;

	Player p1, p2;
	p1.SetTeam('w');
	p2.SetTeam('b');

	std::cout << "Welcome to Chess!" << std::endl;

	string name;
	std::cout << "Enter the name of player 1: ";
	cin >> name;
	p1.SetName(name);

	std::cout << "Enter the name of player 2: ";
	cin >> name;
	p2.SetName(name);

	//std::cout << Field::Instance();

	bool firstPlayer = true;
	bool anPasanInCurrentTurn = false;

	while (true)
	{
		anPasanInCurrentTurn = false;
		int currentAnPasanX = anPasan.first;
		int currentAnPasanY = anPasan.second;

		if (firstPlayer)
		{
			if (!p1.isKingCheckmated())
			{
				if (!p1.Turn(p2))
				{
					firstPlayer = true;
				}
				else
				{
					firstPlayer = false;
				}
			}
			else
			{
				std::cout << "The end! The player with the black figures wins!";
				//WHO WIN, bool type
				break;
			}
		}
		else
		{
			if(!p2.isKingCheckmated())
			{
				if (!p2.Turn(p1))
				{
					firstPlayer = false;
				}
				else
				{
					firstPlayer = true;
				}
			}
			else
			{
				std::cout << "The end! The player with the white figures wins!";
				break;
			}
		}

		if (anPasan.first != currentAnPasanX || anPasan.second != currentAnPasanY)
		{
			anPasanInCurrentTurn = true;
		}

		if (!anPasanInCurrentTurn)
		{
			anPasan.first = -1;
			anPasan.second = -1;
		}
	}

	return 0;
}