#pragma once

#include <ctype.h>
#include <iostream>
#include "Field.h"
#include "Figure.h"

using namespace std;

class Rook : public Figure
{
public:
	Rook();
	~Rook();
	bool CanReach(char*, char*);
};

