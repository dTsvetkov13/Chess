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
	void SetName(string);
	string& GetName();
	void SetTeam(char);
	char GetTeam();
	void Turn(Field &field);

private:
	string m_name;
	char m_team; //w - white, b - black

};

