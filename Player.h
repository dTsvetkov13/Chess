#pragma once

#include <iostream>
#include <string>
#include "Field.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void Turn(Field &field);

private:
	string name;
	int turn; //1 or 2
	char team; //w - white, b - black

};

