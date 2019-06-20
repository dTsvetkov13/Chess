#pragma once
#include <iostream>
#include "Figure.h"
#include <fstream>
#include <vector>
#include <array>
#include <memory>

static std::pair<int, int> anPasan;

class Field
{
private:
	std::array<std::array<std::unique_ptr<Figure>, 8>, 8 > m_field;
	static Field* instance;
	Field();
	Field(Field const& copy);
	Field& operator=(Field const& copy);
	std::pair<int, int> whiteKing;
	std::pair<int, int> blackKing;

public:
	~Field();
	static Field* Instance();
	//Figure* GetField();
	void Move(int fromX, int fromY, int toX, int toY);
	//Figure* getFigure(char *x, int y);
	Figure* getFigure(int x, int y);
	std::pair<int, int> GetCordsOfWhiteKing();
	std::pair<int, int> GetCordsOfBlackKing();
	std::pair<int, int> GetCordsOfEnemyKing(char myTeam);
	bool isFigure(int x, int y);
	//bool isFigure(char *x, int y);
	void SetToNullPointer(int x, int y);
	void CastlingMove(int fromX, int fromY, int toX, int toY);
	friend std::ostream& operator<<(std::ostream& os, Field* f);
};

