#pragma once

#include <ctype.h>
#include <iostream>
#include "Figure.h"

class Rook : public virtual Figure
{
protected:
	bool CanReach(const Cord& from, const Cord& to) override;
	bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Rook();
	Rook(Team);
	~Rook();
	std::string GetFigureSymbol() override;
};

