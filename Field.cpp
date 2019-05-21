#include "Field.h"
#include <ctype.h>

Field::Field()
{
}


Field::~Field()
{
}

void Field::FillField()
{
	//TODO : make algorithm to fill the field
}

//Figure* Field::GetField()
//{
//	return m_field[0][0];
//}

Figure* Field::getFigure(char *x, int y)
{
	return m_field[y-1][(tolower(*x) - 'a')];
}

bool Field::isFigure(char *x, int y)
{
	if (m_field[y - 1][(tolower(*x) - 'a')] != nullptr)
	{
		return true;
	}
	else return false;
}

void Show()
{
	//TODO : output like if there is fig, print (k, K, ...), else "-"
}

void Field::Move(char* moveFrom, char* moveTo)
{
	Figure* temp = m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')];
	
	m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')]
		= m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')];
	
	m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')] = temp;
}