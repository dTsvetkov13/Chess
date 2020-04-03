#pragma once
#include "Figure.h"
#include <list>

class King : public Figure
{
private:
	bool CanReach(const Cord& from, const Cord& to) override;
	bool FigureOnTheWay(const Cord& from, const Cord& to) override;
	bool isFreeSpace(const Cord& cord, bool &canFigureFreeSpace);
public:
	King();
	King(Team);
	~King();
	std::string GetFigureSymbol() override;
	int GetFiguresChessing();
	bool isCheckmated(const Cord&);
	bool IsInChess(const Cord&);
};

