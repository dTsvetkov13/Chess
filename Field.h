#pragma once
#include <iostream>
#include "Figure.h"
#include <fstream>

static std::pair<int, int> anPasan;

class Field
{
private:
	Figure* m_field[8][8];
public:
	Field();
	~Field();
	static Field& Instance();
	void FillField();
	//Figure* GetField();
	void Move(char*, char*);
	Figure* getFigure(char *x, int y);
	Figure* getFigure(int x, int y);
	bool isFigure(int x, int y);
	bool isFigure(char *x, int y);
	friend std::ostream& operator<<(std::ostream& os, Field& f);
};

