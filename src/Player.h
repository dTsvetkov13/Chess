#pragma once

#include <iostream>
#include <string>
#include "Figure.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void SetName(string);
	string& GetName();
	void SetTeam(Team);
	Team GetTeam();
	bool IsValid(int x, int y);
	bool Turn();
	bool isKingCheckmated();
	void SetKingIntoChess();
	void SetKingCords(const Cord&);

private:
	Cord m_king;
	bool kingIsInChess = false;
	string m_name;
	Team m_team;
};

