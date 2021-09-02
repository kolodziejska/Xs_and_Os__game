#pragma once
#include <string>
#include "Mark.h"

class Player
{
private:
	std::string m_Name;
	Mark m_mark;

public:

	Player();

	Player(std::string name, Mark mark);

	~Player();

	std::string GetName();

	Mark GetMark();
};

