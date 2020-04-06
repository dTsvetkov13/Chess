#pragma once
#include "Figure.h"

class Bishop : public virtual Figure
{
protected:
	bool CanReach(const Cord& from, const Cord& to) override;
	bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Bishop();
	Bishop(Team);
	~Bishop();
	std::string GetFigureSymbol() override;
};

