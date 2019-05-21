#pragma once
#include <iostream>

class Figure
{
private:
	char m_team;
public:
	Figure();
	~Figure();
	void SetTeam(char);
	char* GetTeam();
	virtual bool CanReach(char *, char*);
};

