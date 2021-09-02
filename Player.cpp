#include "Player.h"

Player::Player()
{
	m_Name = "aktualny gracz";
	m_mark = Mark::O;
}

Player::Player(std::string name, Mark mark)
{
	m_Name = name;
	m_mark = mark;
}

Player::~Player()
{
}

std::string Player::GetName()
{
	return m_Name;
}

Mark Player::GetMark()
{
	return m_mark;
}
