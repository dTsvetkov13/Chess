#pragma once
	
#include "Figure.h"
#include <fstream>
#include <vector>
#include <array>
#include <memory>
#include "King.h"

static std::pair<int, int> anPasan;

class Field
{
private:
	std::array<std::array<std::unique_ptr<Figure>, 8>, 8 > m_field;
	static Field* instance;
	Field();
	Field(Field const& copy);
	const Field& operator=(Field const& copy);
	std::pair<int, int> whiteKing;
	std::pair<int, int> blackKing;

public:
	~Field();
	static Field* Instance();
	std::array<std::array<std::unique_ptr<Figure>, 8>, 8 >& getField();
	Figure* getFigure(const Cord&);
	std::pair<int, int> GetCordsOfWhiteKing();
	std::pair<int, int> GetCordsOfBlackKing();
	std::pair<int, int> GetCordsOfEnemyKing(Team myTeam);
	bool isFigure(const Cord&);
	void SetToNullPointer(const Cord&);
	friend std::ostream& operator<<(std::ostream& os, Field* f);

	void swapTwoFigures(const Cord& from, const Cord& to);
	void setFigure(const Cord& cord, Figures &figureType, Team team);
	King* getKing(const Cord& cord);
	bool CastlingMove(const Cord& king, const Cord& rook, bool &left);
	bool isCastlingMove(const Cord& king, const Cord& rook);
	void pawnSwapWithAnotherFigure(const Cord &cord);
};

