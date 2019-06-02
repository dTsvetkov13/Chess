#pragma once
#include "Figure.h"

class King : public Figure
{
private:
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	King();
	~King();
};

