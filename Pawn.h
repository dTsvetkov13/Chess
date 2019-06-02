#pragma once
#include "Figure.h"

class Pawn : public Figure
{
protected:
	bool isMoved = false;
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	Pawn();
	~Pawn();
};

