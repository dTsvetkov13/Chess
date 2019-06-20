#pragma once
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Quenn : public Rook, public Bishop
{
protected:
	virtual bool CanReach(int fromX, int fromY, int toX, int toY) override;
	virtual bool FigureOnTheWay(int fromX, int fromY, int toX, int toY) override;
public:
	void SetTeam(char);
	//bool Move(char *from, char *to);
	Quenn();
	~Quenn();
};

