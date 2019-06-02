#include <iostream>
#include <string>
#include "Figure.h"
#include "Player.h"

int main()
{
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

	

}