#pragma once
#include "Figure.h"

class Bishop : public Figure
{
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	Bishop();
	~Bishop();
	bool CanReach1(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay1(int fromX, int fromY, int toX, int toY);
};

