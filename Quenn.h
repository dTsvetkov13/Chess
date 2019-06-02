#pragma once
#include "Figure.h"

class Quenn : public Figure
{
protected:
	virtual bool CanReach(int fromX, int fromY, int toX, int toY);
	virtual bool AllyOnTheWay(int fromX, int fromY, int toX, int toY);
public:
	void SetTeam(char);
	//bool Move(char *from, char *to);
	Quenn();
	~Quenn();
};

