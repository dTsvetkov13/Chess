#pragma once
#include <iostream>
#include "Figure.h"

class Field
{
private:
	Figure* m_field[8][8];
public:
	Field();
	~Field();
	void FillField();
	//Figure* GetField();
	void Move(char*, char*);
	Figure* getFigure(char *x, int y);
	bool isFigure(char *x, int y);
	void Show();
};

