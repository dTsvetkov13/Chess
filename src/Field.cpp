#include "Field.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Figure.h"
#include <ctype.h>
#include <fstream>
#include <memory>

Field::Field()
{
	Team team = Team::Black;

	std::unique_ptr<Figure> rook(new Rook(team));
	std::unique_ptr<Figure> knight(new Knight(team));
	std::unique_ptr<Figure> bishop(new Bishop(team));
	std::unique_ptr<Figure> rook1(new Rook(team));
	std::unique_ptr<Figure> knight1(new Knight(team));
	std::unique_ptr<Figure> bishop1(new Bishop(team));
	std::unique_ptr<Figure> quenn(new Queen(team));
	std::unique_ptr<Figure> king(new King(team));
	
	m_field[0][0] = std::move(rook1);
	m_field[0][7] = std::move(rook);
	m_field[0][1] = std::move(knight1);
	m_field[0][6] = std::move(knight);
	m_field[0][2] = std::move(bishop1);
	m_field[0][5] = std::move(bishop);
	m_field[0][4] = std::move(king);
	m_field[0][3] = std::move(quenn);

	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Figure> pawn(new Pawn(team));
		m_field[1][i] = std::move(pawn);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			m_field[i][k] = nullptr;
		}
	}

	team = Team::White;

	std::unique_ptr<Figure> whiteRook(new Rook(team));
	std::unique_ptr<Figure> whiteKnight(new Knight(team));
	std::unique_ptr<Figure> whiteBishop(new Bishop(team));
	std::unique_ptr<Figure> whiteRook1(new Rook(team));
	std::unique_ptr<Figure> whiteKnight1(new Knight(team));
	std::unique_ptr<Figure> whiteBishop1(new Bishop(team));
	std::unique_ptr<Figure> whiteQuenn(new Queen(team));
	std::unique_ptr<Figure> whiteKing(new King(team));

	m_field[7][0] = std::move(whiteRook1);
	m_field[7][7] = std::move(whiteRook);
	m_field[7][1] = std::move(whiteKnight1);
	m_field[7][6] = std::move(whiteKnight);
	m_field[7][2] = std::move(whiteBishop1);
	m_field[7][5] = std::move(whiteBishop);
	m_field[7][4] = std::move(whiteKing);
	m_field[7][3] = std::move(whiteQuenn);

	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Figure> pawn(new Pawn(team));
		m_field[6][i] = std::move(pawn);
	}
}

Field::~Field()
{
}

Field *Field::instance = nullptr;

Field* Field::Instance()
{
	if (instance == nullptr)
		instance = new Field;
	return instance;
}

const Field& Field::operator=(Field const& copy)
{
	*instance = copy;
	return *instance;
}

Figure* Field::getFigure(const Cord& cord)
{
	return m_field[cord.y - 1][cord.x-1].get();
}

std::pair<int, int> Field::GetCordsOfWhiteKing()
{
	return whiteKing;
}

std::pair<int, int> Field::GetCordsOfBlackKing()
{
	return blackKing;
}

std::pair<int, int> Field::GetCordsOfEnemyKing(Team myTeam)
{
	if (myTeam == Team::White)
	{
		return blackKing;
	}
	else
	{
		return whiteKing;
	}
}

bool Field::isFigure(const Cord& cord)
{
	if (cord.x - 1 < 0 || cord.x - 1 >= 8
		|| cord.y - 1 < 0 || cord.y - 1 >= 8)
	{
		return false;
	}

	if (m_field[cord.y - 1][cord.x - 1] != nullptr)
	{
		return true;
	}
	else return false;
}

std::ostream& operator<<(std::ostream& os, Field* f)
{
	os << "  |";
	for (char i = 'A'; i <= 'H'; i++)
	{
		os << " " << i << " ";
	}
	os << std::endl;

	for (int i = 0; i < 28; i++) os << "-";

	os << std::endl;

	for (int i = 1; i <= 8; i++)
	{
		os << " " << 9 - i << "|";
		for (int k = 1; k <= 8; k++)
		{
			if (!f->isFigure(Cord(k, i)))
			{
				os << " - ";
			}
			else
			{
				os << " " << f->getFigure(Cord(k, i))->GetFigureSymbol();
			}
		}

		os << std::endl;
	}

	for (int i = 0; i < 28; i++) os << "-";

	os << std::endl;

	return os;
}

void Field::SetToNullPointer(const Cord& cord)
{
	m_field[cord.y - 1][cord.x - 1] = nullptr;
}

void Field::swapTwoFigures(const Cord& from, const Cord& to)
{
	m_field[to.y - 1][to.x - 1].swap(m_field[from.y - 1][from.x - 1]);
}

std::array<std::array<std::unique_ptr<Figure>, 8>, 8 >& Field::getField()
{
	return m_field;
}

void Field::setFigure(const Cord& cord, Figures &figureType, Team team)
{
	switch(figureType)
	{
		case(Figures::Bishop):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new Bishop(Team::White));
			break;
		}
		case(Figures::King):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new King(Team::White));
			break;
		}
		case(Figures::Knight):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new Knight(Team::White));
			break;
		}
		case(Figures::Pawn):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new Pawn(Team::White));
			break;
		}
		case(Figures::Quenn):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new Queen(Team::White));
			break;
		}
		case(Figures::Rook):
		{
			m_field[cord.y - 1][cord.x - 1].reset(new Rook(Team::White));
			break;
		}
		break;
	}
}

King* Field::getKing(const Cord& cord)
{
	if (m_field[cord.y - 1][cord.x - 1].get()->GetFigureType() == Figures::King)
	{
		return (King*)m_field[cord.y - 1][cord.x - 1].get();
	}

	return nullptr;
}

bool Field::CastlingMove(const Cord& king, const Cord& rook, bool &left)
{
	if (m_field[king.y - 1][king.x - 1].get()->IsMoved())
	{
		std::cout << "You cannot do castling move because your king is moved!" << std::endl;
		return false;
	}

	if (m_field[rook.y - 1][rook.x - 1].get()->IsMoved())
	{
		std::cout << "You cannot do castling move because this rook is moved!" << std::endl;
		return false;
	}

	if (king.x > rook.x)
	{
		//BIG CASTLING
		for (int i = 0; i < 3; i++)
		{
			if (m_field[rook.y - 1][rook.x + i] != nullptr)
			{
				std::cout << "You cannot do castling move because there is a figure between them!" << std::endl;
				return false;
			}
		}

		left = true;

		swapTwoFigures(king, Cord(king.x - 2, king.y));
		swapTwoFigures(rook, Cord(rook.x + 3, rook.y));
		return true;
	}
	else
	{
		//SMALL CASTLING
		for (int i = 0; i < 2; i++)
		{
			if (m_field[rook.y - 1][king.x + i] != nullptr)
			{
				std::cout << "You cannot do castling move because there is a figure between them!" << std::endl;
				return false;
			}
		}

		left = false;

		swapTwoFigures(king, Cord(king.x + 2, king.y));
		swapTwoFigures(rook, Cord(rook.x - 2, rook.y));
		return true;
	}
}

bool Field::isCastlingMove(const Cord& first, const Cord& second)
{
	if (m_field[first.y - 1][first.x - 1] != nullptr && m_field[second.y - 1][second.x - 1] != nullptr)
	{
		Figure *firstFigure = m_field[first.y - 1][first.x - 1].get();
		Figure *secondFigure = m_field[second.y - 1][second.x - 1].get();

		if (firstFigure->GetTeam() == secondFigure->GetTeam())
		{
			if (!((firstFigure->GetFigureType() == Figures::King && secondFigure->GetFigureType() == Figures::Rook)
				|| (firstFigure->GetFigureType() == Figures::Rook && secondFigure->GetFigureType() == Figures::King)))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	if (first.y == second.y && ((std::abs(first.x - second.x) == 4) || (std::abs(second.x - first.x) == 3)))
	{
		return true;
	}

	else return false;
}

void Field::pawnSwapWithAnotherFigure(const Cord &cord)
{
	std::string input;
	bool inProgress = true;

	do
	{
		std::cout << "What figure do you want to get between Queen, Rook, Bishop and Knight? Enter the first character: " << std::endl;
		std::cin >> input;

		if (input.length() > 1)
		{
			std::cout << "Wrong input! Enter again!" << std::endl;
			continue;
		}

		switch (tolower(input[0]))
		{
		case('q') :
		{
			Team team = m_field[cord.y - 1][cord.x - 1].get()->GetTeam();
			m_field[cord.y - 1][cord.x - 1].reset(new Queen(team));
			inProgress = false;
			break;
		}
		case('b') :
		{
			Team team = m_field[cord.y - 1][cord.x - 1].get()->GetTeam();
			m_field[cord.y - 1][cord.x - 1].reset(new Bishop(team));
			inProgress = false;
			break;
		}
		case('r'):
		{
			Team team = m_field[cord.y - 1][cord.x - 1].get()->GetTeam();
			m_field[cord.y - 1][cord.x - 1].reset(new Rook(team));
			inProgress = false;
			break;
		}
		case('k'):
		{
			Team team = m_field[cord.y - 1][cord.x - 1].get()->GetTeam();
			m_field[cord.y - 1][cord.x - 1].reset(new Knight(team));
			inProgress = false;
			break;
		}
		default:
			std::cout << "Wrong input! Enter again!" << std::endl;
			continue;
		}
	} while (inProgress);
}