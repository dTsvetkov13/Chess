#pragma once
#include "Figure.h"

class Pawn : public Figure
{
protected:
//	bool isMoved = false;
	bool CanReach(int fromX, int fromY, int toX, int toY) override;
	bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	Pawn();
	~Pawn();
};

