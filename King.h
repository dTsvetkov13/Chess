#pragma once
#include "Figure.h"

class King : public Figure
{
private:
	bool VerticalAndHorizontal(int x, int y);
	bool Diagonals(int x, int y);
	bool KnightMove(int x, int y);
	bool IsChess(int x, int y);
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	King();
	~King();
};

