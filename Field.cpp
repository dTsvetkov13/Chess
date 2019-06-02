#include "Field.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Quenn.h"
#include <ctype.h>
#include <fstream>

Field::Field()
{
	Rook rook;
	Knight knight;
	Bishop bishop;
	Quenn quenn;
	King king;
	Pawn pawn;
	char team = 'b';

	rook.SetTeam(team);
	knight.SetTeam(team);
	bishop.SetTeam(team);
	king.SetTeam(team);
	quenn.SetTeam(team);
	pawn.SetTeam(team);

	m_field[0][0] = m_field[0][7] = &rook;
	m_field[0][1] = m_field[0][6] = &knight;
	m_field[0][1] = m_field[0][5] = &bishop;
	m_field[0][4] = &king;
	m_field[0][3] = &quenn;

	for (int i = 0; i < 8; i++)
	{
		m_field[1][i] = &pawn;
	}

	for (int i = 2; i < 6; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			m_field[i][k] = nullptr;
		}
	}

	team = 'w';

	rook.SetTeam(team);
	knight.SetTeam(team);
	bishop.SetTeam(team);
	king.SetTeam(team);
	quenn.SetTeam(team);
	pawn.SetTeam(team);

	m_field[7][0] = m_field[7][7] = &rook;
	m_field[7][1] = m_field[7][6] = &knight;
	m_field[7][1] = m_field[7][5] = &bishop;
	m_field[7][4] = &king;
	m_field[7][3] = &quenn;

	for (int i = 0; i < 8; i++)
	{
		m_field[7][i] = &pawn;
	}
}


Field::~Field()
{
}

Field& Field::Instance()
{
	static Field instance;
	return instance;
}

//Figure* Field::GetField()
//{
//	return m_field[0][0];
//}

Figure* Field::getFigure(char *x, int y)
{
	return m_field[y - 1][(tolower(*x) - 'a')];
}

Figure* Field::getFigure(int x, int y)
{
	return m_field[y - 1][x-1];
}

bool Field::isFigure(char *x, int y)
{
	if (m_field[y - 1][(tolower(*x) - 'a')] != nullptr)
	{
		return true;
	}
	else return false;
}

bool Field::isFigure(int x, int y)
{
	if (m_field[y - 1][x - 1] != nullptr)
	{
		return true;
	}
	else return false;
}

std::ostream& operator<<(std::ostream& os, Field& f)
{
	//TODO : output like if there is fig, print (k, K, ...), else "-"
	os << "  |";
	for (int i = 0; i < 8; i++)
	{
		os << " " << ('A' + i);
	}
	os << std::endl;

	for (int i = 0; i < 20; i++) os << "-";

	for (int i = 0; i < 8; i++)
	{
		os << " " << 8 - i << "|";
		for (int k = 0; k < 8; k++)
		{
			if (!f.isFigure(k, i))
			{
				os << " -";
			}
			else
			{
				os << " " << f.getFigure(k, i)->GetFirstLetter();
			}
		}
	}

	for (int i = 0; i < 20; i++) os << "-";

	return os;
}

void Field::Move(char* moveFrom, char* moveTo)
{
	/*Figure* temp = m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')];
	
	m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')]
		= m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')];
	
	m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')] = temp;*/

	int fromX = tolower(moveFrom[0] - 'a');
	int fromY = moveFrom[1] - '0';
	int toX = tolower(moveTo[0]) - 'a';
	int toY = moveTo[1] - '0';

	m_field[toY][toX] = m_field[fromY][fromX];
	m_field[fromY][fromX] = nullptr;
}