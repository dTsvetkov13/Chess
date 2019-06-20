#pragma once
#include "Figure.h"

class Bishop : public virtual Figure
{
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY) override;
	bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	Bishop();
	~Bishop();
	bool CanReach1(int fromX, int fromY, int toX, int toY);
	bool AllyOnTheWay1(int fromX, int fromY, int toX, int toY);
};

