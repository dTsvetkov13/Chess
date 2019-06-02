#include "Bishop.h"
#include "Field.h"
#include <cmath>

Bishop::Bishop()
{
	SetFirstLetter('b');
}


Bishop::~Bishop()
{
}

bool Bishop::CanReach(int fromX, int fromY, int toX, int toY) //modification : fromX and fromY arent needed
{
	if (std::abs(fromX - toX) == std::abs(fromY - toY))
	{
		return true;
	}
	else return false;
}

bool Bishop::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	// "1" is quadrant 1
	// "2" is quadrant 2
	// "3" is quadrant 3
	// "4" is quadrant 4
	
	int quadrant = 4;

	if (fromX < toX && fromY < toY)
	{
		quadrant = 1;
	}
	else if (fromX > toX && fromY < toY)
	{
		quadrant = 2;
	}
	else if (fromX > toX && fromY > toY)
	{
		quadrant = 3;
	}

	switch (quadrant)
	{
		case 1 :
		{
			for (int i = 1; i <= std::abs(fromX - toX); i++)
			{
				if (Field::Instance().isFigure(fromX + i, fromY + i))
				{
					std::cout << "there is an ally on the way";
					return false;
				}
			}
			break;
		}
		case 2 :
		{
			for (int i = 1; i <= std::abs(fromX - toX); i++)
			{
				if (Field::Instance().isFigure(fromX - i, fromY + i))
				{
					std::cout << "there is an ally on the way";
					return false;
				}
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i <= std::abs(fromX - toX); i++)
			{
				if (Field::Instance().isFigure(fromX - i, fromY - i))
				{
					std::cout << "there is an ally on the way";
					return false;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 1; i <= std::abs(fromX - toX); i++)
			{
				if (Field::Instance().isFigure(fromX + i, fromY - i))
				{
					std::cout << "there is an ally on the way";
					return false;
				}
			}
			break;
		}
	}

	return true;
}

bool Bishop::CanReach1(int fromX, int fromY, int toX, int toY)
{
	if (CanReach(fromX, fromY, toX, toY))
	{
		return true;
	}
	return false;
}

bool Bishop::AllyOnTheWay1(int fromX, int fromY, int toX, int toY)
{
	if (AllyOnTheWay(fromX, fromY, toX, toY))
	{
		return true;
	}
	return false;
}