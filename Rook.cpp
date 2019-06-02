#include "Rook.h"
#include "Field.h"

Rook::Rook()
{
	SetFirstLetter('r');
}

Rook::~Rook()
{
}

bool Rook::CanReach(int fromX, int fromY, int toX, int toY)
{
	if (fromX == toX || fromY == toY)
	{
		//if the validation check if the x1 != x2 or y1 != y2
		return true;
	}
	else return false;
}

bool Rook::AllyOnTheWay(int fromX, int fromY, int toX, int toY)
{
	if (fromX == toX)
	{
		bool up = true;
		int dist = fromY = toY;
		if (fromY < toY)
		{
			up = false;
			dist = toY - fromY;
		}

		if (up)
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance().isFigure(toX, toY + i))
				{
					return true;
				}
			}
		}
		else
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance().isFigure(toX, toY - i))
				{
					return true;
				}
			}
		}
	}
	else
	{
		bool left = true;
		int dist = fromX - toX;
		if (fromX < toX)
		{
			left = false;
			dist = toX - fromX;
		}

		if (left)
		{
			for (int i = 1; i <= dist; i++)
			{
				if (Field::Instance().isFigure(toX + i, toY))
				{
					return true;
				}
			}
		}
		else
		{
			for (int i = 1; i < dist; i++)
			{
				if (Field::Instance().isFigure(toX - i, toY))
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Rook::CanReach1(int fromX, int fromY, int toX, int toY)
{
	if (CanReach(fromX, fromY, toX, toY))
	{
		return true;
	}
	return false;
}

bool Rook::AllyOnTheWay1(int fromX, int fromY, int toX, int toY)
{
	if (AllyOnTheWay(fromX, fromY, toX, toY))
	{
		return true;
	}
	return false;
}