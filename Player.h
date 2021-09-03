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

	Player(const std::string &name, const Mark &mark);

	~Player();

	std::string GetName();

	Mark GetMark();

	void ChangeName(const std::string &name) {
		m_Name = name;
	}

	void ChangeMark(const Mark &mark) {
		m_mark = mark;
	}
};

