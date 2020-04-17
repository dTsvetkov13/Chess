#pragma once
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
private:
	virtual bool CanReach(const Cord& from, const Cord& to) override;
	virtual bool FigureOnTheWay(const Cord& from, const Cord& to) override;
public:
	Queen();
	Queen(Team team);
	~Queen();
	void SetTeam(Team);
	std::string GetFigureSymbol() override;
	//bool Move(char *from, char *to);
};

