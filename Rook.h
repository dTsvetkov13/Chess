#pragma once

#include <ctype.h>
#include <iostream>
#include "Figure.h"

//TODO rokado changes, isMoved

class Rook : public virtual Figure
{
private:
	//bool isMoved = false;
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY) override;
	bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	//delete this 2 funcs
	Rook();
	~Rook();
	bool CanReach1(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay1(int fromX, int fromY, int toX, int toY);
//	bool IsMoved();
};

