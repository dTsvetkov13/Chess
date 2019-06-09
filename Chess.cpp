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

	int turns = 0;

	while (true)
	{
		if (turns % 2 == 0)
		{
			if (!p1.Turn())
			{
				try
				{

				}

				catch (int e)
				{
					if (e == 1)
					{
						std::cout << "The end! The player with the black figures wins!";
						break;
					}
				}

				turns--;
			}
		}
		else
		{
			if (!p2.Turn())
			{
				try
				{

				}

				catch (int e)
				{
					if (e == 1)
					{
						std::cout << "The end! The player with the white figures wins!";
						break;
					}
				}

				turns--;
			}
		}

		turns++;
	}

}