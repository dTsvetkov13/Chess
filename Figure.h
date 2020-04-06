#pragma once
#include <iostream>
#include <string>
#include <list>

enum class Figures
{
	Bishop,
	King,
	Knight,
	Pawn,
	Quenn,
	Rook
};

enum class Team
{
	White,
	Black
};

struct Cord
{
	int x;
	int y;

	Cord()
	{

	}

	Cord(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Figure
{
private:
	Team m_team;
	Figures m_figureType;
	bool isMoved = false;
	std::list<Cord> figuresPointingToThisFigure;

	int VerticalAndHorizontal(const Cord&);
	int Diagonals(const Cord&);
	int KnightMove(const Cord&);

protected:
	virtual bool CanReach(const Cord& from, const Cord& to) = 0;
	virtual bool FigureOnTheWay(const Cord& from, const Cord& to) = 0;
public:
	Figure();
	Figure(Team team);
	Figure(Team team, Figures figureType);
	virtual ~Figure();
	void SetTeam(Team);
	Team GetTeam();
	void SetFigureType(Figures);
	Figures GetFigureType();
	virtual std::string GetFigureSymbol() = 0;
	bool Move(const Cord& from, const Cord& to);
	int CanBeReached(const Cord&);
	bool IsMoved();
	void ClearPointingFigures();
	std::list<Cord>* getFiguresPointingToThisFigure();
	Figure* kingInFiguresPointingToThisFigure();
};