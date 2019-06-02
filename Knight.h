#pragma once
#include "Figure.h"

class Knight: public Figure
{
public:
	Knight();
	~Knight();
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
};

