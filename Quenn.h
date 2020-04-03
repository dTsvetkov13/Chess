#pragma once
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Quenn : public Rook, public Bishop
{
private:
	virtual bool CanReach(const Cord& from, const Cord& to) override;
	virtual bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Quenn();
	Quenn(Team team);
	~Quenn();
	void SetTeam(Team);
	std::string GetFigureSymbol() override;
	//bool Move(char *from, char *to);
};

