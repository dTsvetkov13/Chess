#pragma once

#include <ctype.h>
#include <iostream>
#include "Figure.h"

//TODO rokado changes, isMoved

class Rook : public Figure
{
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	bool CanReach1(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay1(int fromX, int fromY, int toX, int toY);
	Rook();
	~Rook();
};

