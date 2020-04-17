#include <iostream>
#include <string>
#include "Figure.h"
#include "Player.h"
#include "Field.h"

int main()
{
	std::pair<int, int> blackKing;
	std::pair<int, int> whiteKing;

	Player p1, p2;
	p1.SetTeam(Team::White);
	p2.SetTeam(Team::Black);

	std::cout << "Welcome to Chess!" << std::endl;

	string name;
	std::cout << "Enter the name of player 1: ";
	std::getline(std::cin, name);
	p1.SetName(name);

	std::cout << "Enter the name of player 2: ";
	std::getline(std::cin, name);
	p2.SetName(name);

	bool firstPlayer = true;
	bool anPasanInCurrentTurn = false;

	if (firstPlayer)
	{
		p1.SetKingCords(Cord(5, 8));
		p2.SetKingCords(Cord(5, 1));
	}
	else
	{
		p1.SetKingCords(Cord(5, 1));
		p2.SetKingCords(Cord(5, 8));
	}

	while (true)
	{
		system("cls");
		anPasanInCurrentTurn = false;
		int currentAnPasanX = anPasan.first;
		int currentAnPasanY = anPasan.second;

		if (firstPlayer)
		{
			if (!p1.isKingCheckmated())
			{
				if (!p1.Turn())
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
				std::cout << Field::Instance() << std::endl;

				std::cout << "The end! The player with the black figures wins!" << std::endl;
				break;
			}
		}
		else
		{
			if(!p2.isKingCheckmated())
			{
				if (!p2.Turn())
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
				std::cout << Field::Instance() << std::endl;

				std::cout << "The end! The player with the white figures wins!" << std::endl;
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

	system("pause");

	return 0;
}	