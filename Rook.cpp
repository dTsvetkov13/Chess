#include "Rook.h"

Rook::Rook()
{
}

Rook::~Rook()
{
}

bool Rook::CanReach(char* from, char* to)
{
	int toX = tolower(to[0]) - 'a';
	int toY = to[1] - '0';
	int fromX = tolower(from[0] - 'a');
	int fromY = from[1] - '0';

	if (toX >= 0 && toX <= 7 && toY >= 0 && toY <= 7) {
		if(toX == fromX)
		{
			if (fromY > toY)
			{
				for (int i = fromY; i >= toY; i--)
				{
					if (true)
					{
						
					}
				}
			}
			else
			{

			}
		}
		else if (toY == fromY)
		{

		}
		else
		{
			cout << "cant reach/n";
			return false;
		}
	}
	else
	{
		return false;
	}
}