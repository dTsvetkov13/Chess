#pragma once
#include "Figure.h"

class Knight: public Figure
{
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY) override;
	bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	Knight();
	~Knight();
};

