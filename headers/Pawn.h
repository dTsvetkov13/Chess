#pragma once
#include "Figure.h"

class Pawn : public Figure
{
protected:
	bool CanReach(const Cord& from, const Cord& to) override;
	bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Pawn();
	Pawn(Team team);
	~Pawn();
	std::string GetFigureSymbol() override;
};
