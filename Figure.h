#pragma once
#include <iostream>

class Figure
{
private:
	char m_team;
	char m_firstLetter;
	bool isMoved = false;

	int VerticalAndHorizontal(int x, int y);
	int Diagonals(int x, int y);
	int KnightMove(int x, int y);

protected:
	virtual bool CanReach(int fromX, int fromY, int toX, int toY) = 0;
	virtual bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) = 0;
public:
	Figure();
	Figure(char team);
	~Figure();
	void SetTeam(char);
	char GetTeam();
	void SetFirstLetter(char letter);
	char GetFirstLetter();
	bool Move(int fromX, int fromY, int toX, int toY);
	int CanBeReached(int x, int y);
	bool IsMoved();
};

