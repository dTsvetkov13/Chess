#pragma once

#include <iostream>
#include <string>
#include "Field.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void SetName(string);
	string& GetName();
	void SetTeam(char);
	char GetTeam();
	bool IsValid(int x, int y);
	bool Turn(Player &enemyPlayer);
	bool isKingCheckmated();
	void SetKingIntoChess();

private:
	std::pair<int, int> m_king;
	bool kingIsInChess = false;
	string m_name;
	char m_team; //w - white, b - black
};

