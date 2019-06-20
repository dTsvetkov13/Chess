#pragma once
#include "Figure.h"

class King : public Figure
{
private:
	int figuresChessing = 0;
	//bool isMoved = false;
protected:
	bool CanReach(int fromX, int fromY, int toX, int toY) override;
	bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	King();
	~King();
	int GetFiguresChessing();
	bool CanBeUnchessed(int x, int y);
	bool isCheckmated(int x, int y);
	bool IsInChess(int x, int y);
	//bool IsMoved();
};

