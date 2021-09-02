#pragma once
#include "Mark.h"

class Board
{
	static const unsigned DEFAULT = 3;

private:
	Mark m_Board[DEFAULT][DEFAULT];
	int m_SideLength;
	int m_TotalSize;

public:
	Board();
	~Board();

	int GetTotalSize() const;
	int GetSideLength() const;

	Mark GetMark(const int spaceNumber) const;
	Mark GetMark(const int rowNumber, const int columnNumber) const;
	bool SetMark(const int spaceNumber, Mark mark);

	bool DrawBoard();

};

