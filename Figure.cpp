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

char Figure::GetTeam()
{
	return m_team;
}

void Figure::SetFirstLetter(char c)
{
	m_firstLetter = c;
}

char Figure::GetFirstLetter()
{
	return m_firstLetter;
}

bool Figure::Move(char* from, char* to)
{
	int toX = tolower(to[0]) - 'a';
	int toY = to[1] - '0';
	int fromX = tolower(from[0] - 'a');
	int fromY = from[1] - '0';

	if (CanReach(fromX, fromY, toX, toY))
	{
		if (!AllyOnTheWay(fromX, fromY, toX, toY))
		{
			return true;
			//TODO check if the enemy king is in chess
			//TODO check if this figure can protect the their king
		}
		else
		{
			std::cout << "There is ally on the way";
			return false;
			//TODO throw exception or enum 
		}
	}
	else
	{
		//TODO better message
		std::cout << "can't reach";
		return false;
	}
}