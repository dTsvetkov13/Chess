#include "Figure.h"


Figure::Figure()
{
}

Figure::~Figure()
{
}

void Figure::SetTeam(char team)
{
	m_team = team;
}

char* Figure::GetTeam()
{
	return &m_team;
}