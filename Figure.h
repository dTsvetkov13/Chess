#pragma once
#include <iostream>

class Figure
{
private:
	char m_team;
	char m_firstLetter;
protected:
	virtual bool CanReach(int fromX, int fromY, int toX, int toY) = 0;
	bool virtual AllyOnTheWay(int fromX, int fromY, int toX, int toY) = 0;
public:
	Figure();
	~Figure();
	void SetTeam(char);
	char GetTeam();
	void SetFirstLetter(char letter);
	char GetFirstLetter();
	bool Move(char *, char *);
};

