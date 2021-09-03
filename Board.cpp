#include "Board.h"
#include <conio.h>
#include <iostream>
#include "Converter.h"

Board::Board():
	m_SideLength{ DEFAULT },
	m_TotalSize{ m_SideLength * m_SideLength }
{
	for (int i = 0; i < m_SideLength; i++) {
		for (unsigned j = 0; j < m_SideLength; j++) {
			m_Board[i][j] = Mark::NTH;
		}
	}
}

Board::~Board()
{
}

int Board::GetTotalSize() const
{
	return m_TotalSize;
}

int Board::GetSideLength() const
{
	return m_SideLength;
}

Mark Board::GetMark(const int spaceNumber) const
{
	if (spaceNumber <= m_TotalSize)
		return m_Board[(spaceNumber - 1) / m_SideLength][(spaceNumber - 1) % m_SideLength];
}

Mark Board::GetMark(const int rowNumber, const int columnNumber) const
{
	if (rowNumber <= m_SideLength && columnNumber <= m_SideLength)
		return m_Board[rowNumber][columnNumber];
}

bool Board::SetMark(const int spaceNumber, Mark mark)
{
	if (spaceNumber > m_TotalSize)
		return false;
	else m_Board[(spaceNumber - 1) / m_SideLength][(spaceNumber - 1) % m_SideLength] = mark;
	return true;
}

bool Board::DrawBoard()
{
	system("cls");

	for (int i = 0; i < m_SideLength; i++)
	{
		std::cout << " -";
		for (int k = 0; k < m_SideLength; k++) {
			std::cout << "---";
		}
		std::cout << std::endl;
		std::cout << " |";
		for (int j = 0; j < m_SideLength; j++) {
			if ((this->GetMark(i, j) == Mark::NTH) && (i * m_SideLength + j + 1 < 10)) std::cout << " " << i * m_SideLength + j + 1 << "|";
			else if (this->GetMark(i, j) == Mark::NTH) std::cout << i * m_SideLength + j + 1 << "|";
			else std::cout << " " << Converter::MarkToChar(this->GetMark(i, j)) << "|";
		}
		std::cout << std::endl;
	}
	std::cout << " -";
	for (int k = 0; k < m_SideLength; k++) {
		std::cout << "---";
	}
	std::cout << std::endl;
	return true;
}
