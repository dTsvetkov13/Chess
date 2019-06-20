#include "Field.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Quenn.h"
#include "Figure.h"
#include <ctype.h>
#include <fstream>

Field::Field()
{
	std::unique_ptr<Figure> rook(new Rook());
	std::unique_ptr<Figure> knight(new Knight());
	std::unique_ptr<Figure> bishop(new Bishop());
	std::unique_ptr<Figure> rook1(new Rook());
	std::unique_ptr<Figure> knight1(new Knight());
	std::unique_ptr<Figure> bishop1(new Bishop());
	std::unique_ptr<Figure> quenn(new Quenn());
	std::unique_ptr<Figure> king(new King());
	char team = 'b';
	//1cite
	rook.get()->SetTeam(team);
	knight.get()->SetTeam(team);
	bishop.get()->SetTeam(team);
	rook1.get()->SetTeam(team);
	knight1.get()->SetTeam(team);
	bishop1.get()->SetTeam(team);
	king.get()->SetTeam(team);
	quenn.get()->SetTeam(team);

	std::cout << king.get()->GetFirstLetter() << bishop.get()->GetFirstLetter() << std::endl;

	m_field[0][0] = std::move(rook1);
	m_field[0][7] = std::move(rook);
	m_field[0][1] = std::move(knight1);
	m_field[0][6] = std::move(knight);
	m_field[0][2] = std::move(bishop1);
	m_field[0][5] = std::move(bishop);
	m_field[0][4] = std::move(king);
	m_field[0][3] = std::move(quenn);

	std::cout << m_field[0][4]->GetFirstLetter() << m_field[0][2]->GetFirstLetter() << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Figure> pawn(new Pawn());
		pawn.get()->SetTeam(team);
		m_field[1][i] = std::move(pawn);
		std::cout << m_field[1][i].get()->GetFirstLetter();
	}
	
	std::cout << std::endl;

	for (int i = 2; i < 6; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			m_field[i][k] = nullptr;
		}
	}

	team = 'w';

	std::cout << "kdsds" << std::endl;

	std::unique_ptr<Figure> whiteRook(new Rook());
	std::unique_ptr<Figure> whiteKnight(new Knight());
	std::unique_ptr<Figure> whiteBishop(new Bishop());
	std::unique_ptr<Figure> whiteRook1(new Rook());
	std::unique_ptr<Figure> whiteKnight1(new Knight());
	std::unique_ptr<Figure> whiteBishop1(new Bishop());
	std::unique_ptr<Figure> whiteQuenn(new Quenn());
	std::unique_ptr<Figure> whiteKing(new King());

	whiteRook.get()->SetTeam(team);
	whiteKnight.get()->SetTeam(team);
	whiteBishop.get()->SetTeam(team);
	whiteRook1.get()->SetTeam(team);
	whiteKnight1.get()->SetTeam(team);
	whiteBishop1.get()->SetTeam(team);
	whiteKing.get()->SetTeam(team);
	whiteQuenn.get()->SetTeam(team);
	//pawn.get()->SetTeam(team);

	std::cout << "aaaaa" << std::endl;

	m_field[7][0] = std::move(whiteRook1);
	m_field[7][7] = std::move(whiteRook);
	m_field[7][1] = std::move(whiteKnight1);
	m_field[7][6] = std::move(whiteKnight);
	m_field[7][2] = std::move(whiteBishop1);
	m_field[7][5] = std::move(whiteBishop);
	m_field[7][4] = std::move(whiteKing);
	m_field[7][3] = std::move(whiteQuenn);

	std::cout << m_field[7][4]->GetFirstLetter() << m_field[7][2]->GetFirstLetter() << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Figure> pawn(new Pawn());
		pawn.get()->SetTeam(team);
		m_field[6][i] = std::move(pawn);
	}

	//std::cout << Instance();
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

//Figure* Field::GetField()
//{
//	return m_field[0][0];
//}

//This is useless and awful
//Figure* Field::getFigure(char *x, int y)
//{
//	return m_field[y - 1][(tolower(*x) - 'a')].get();
//}

Figure* Field::getFigure(int x, int y)
{
	return m_field[y - 1][x-1].get();
}

std::pair<int, int> Field::GetCordsOfWhiteKing()
{
	return whiteKing;
}

std::pair<int, int> Field::GetCordsOfBlackKing()
{
	return blackKing;
}

std::pair<int, int> Field::GetCordsOfEnemyKing(char myTeam)
{
	//make exception for wrong team
	if (myTeam == 'w')
	{
		return blackKing;
	}
	else
	{
		return whiteKing;
	}
}


//This is useless and awful
//bool Field::isFigure(char *x, int y)
//{
//	if (m_field[y - 1][(tolower(*x) - 'a')] != nullptr)
//	{
//		return true;
//	}
//	else return false;
//}

bool Field::isFigure(int x, int y)
{
	if (m_field[y - 1][x - 1] != nullptr)
	{
		return true;
	}
	else return false;
}

std::ostream& operator<<(std::ostream& os, Field* f)
{
	//TODO : output like if there is fig, print (k, K, ...), else "-"
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
			if (!f->isFigure(k, i))
			{
				os << " - ";
			}
			else
			{
				os << " " << f->getFigure(k, i)->GetTeam() << f->getFigure(k, i)->GetFirstLetter();
			}
		}

		os << std::endl;
	}

	for (int i = 0; i < 28; i++) os << "-";

	os << std::endl;

	return os;
}

void Field::SetToNullPointer(int x, int y)
{
	m_field[y - 1][x - 1] = nullptr;
}

void Field::Move(int fromX, int fromY, int toX, int toY)
{
	/*Figure* temp = m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')];
	
	m_field[(moveTo[1] - '0') - 1][(tolower(moveTo[0]) - 'a')]
		= m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')];
	
	m_field[(moveFrom[1] - '0') - 1][(tolower(moveFrom[0]) - 'a')] = temp;*/

	if (m_field[fromY - 1][fromX - 1].get()->GetFirstLetter() == 'K')
	{
		if (m_field[fromY - 1][fromX - 1].get()->GetTeam() == 'w')
		{
			whiteKing.first = toX;
			whiteKing.second = toY;
		}
		else
		{
			blackKing.first = toX;
			blackKing.second = toY;
		}
	}
	std::cout << "the m_field x = " << toX - 1 << " and m_field y = " << toY - 1 << std::endl;
	std::cout << "the m_field x = " << fromX - 1 << " and m_field y = " << fromY - 1 << std::endl;
	

	m_field[toY - 1][toX - 1].swap(m_field[fromY - 1][fromX - 1]);
	//m_field[toY - 1][toX - 1] = std::move(m_field[fromY - 1][fromX - 1]);
	m_field[fromY - 1][fromX - 1] = nullptr;
}

void Field::CastlingMove(int fromX, int fromY, int toX, int toY)
{
	if (fromX > toX)
	{
		toX -= 2;
	}
	else
	{
		toX += 1;
	}

	std::unique_ptr<Figure> temp = std::move(m_field[fromY - 1][fromX - 1]);
	m_field[fromY - 1][fromX - 1] = std::move(m_field[toY - 1][toX - 1]);
	m_field[toY - 1][toX - 1] = std::move(temp);
}