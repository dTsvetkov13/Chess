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

bool Bishop::FigureOnTheWay(int fromX, int fromY, int toX, int toY)
{
	// "1" is quadrant 1, 4 3 3 4, - +
	// "2" is quadrant 2, 4 3 3 2, - -
	// "3" is quadrant 3, 4 3 5 2, + -
	// "4" is quadrant 4, 4 3 5 4, + +
	
	int quadrant = 4;

	if (fromX < toX && fromY > toY)
	{
		quadrant = 1;
	}
	else if (fromX > toX && fromY > toY)
	{
		quadrant = 2;
	}
	else if (fromX > toX && fromY < toY)
	{
		quadrant = 3;
	}

	std::cout << "qadrant = " << quadrant << std::endl;

	switch (quadrant)
	{
		case 1 :
		{
			for (int i = 1; i < std::abs(fromX - toX); i++)
			{
				if (Field::Instance()->isFigure(fromX + i, fromY - i))
				{
					std::cout << "there is an ally on the way" << std::endl;
					return true;
				}
			}
			break;
		}
		case 2 :
		{
			for (int i = 1; i < std::abs(fromX - toX); i++)
			{
				if (Field::Instance()->isFigure(fromX - i, fromY - i))
				{
					std::cout << "there is an ally on the way";
					return true;
				}
			}
			break;
		}
		case 3:
		{
			//3 1 1 3
			for (int i = 1; i < std::abs(fromX - toX); i++)
			{
				if (Field::Instance()->isFigure(fromX - i, fromY + i))
				{
					std::cout << "there is an ally on the way";
					return true;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 1; i < std::abs(fromX - toX); i++)
			{
				if (Field::Instance()->isFigure(fromX + i, fromY + i))
				{
					std::cout << "there is an ally on the way";
					return true;
				}
			}
			break;
		}
	}

	return false;
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
	if (FigureOnTheWay(fromX, fromY, toX, toY))
	{
		return true;
	}
	return false;
}