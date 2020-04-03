#pragma once
#include "Figure.h"

class Knight: public Figure
{
protected:
	bool CanReach(const Cord& from, const Cord& to) override;
	bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Knight();
	Knight(Team team);
	~Knight();
	std::string GetFigureSymbol() override;
};

