#pragma once
#include "Board.h"
#include "Player.h"
#include <memory>

class Game
{
private:
	Board m_board;
	Player m_playerO;
	Player m_playerX;
	Player m_activePlayer;

public:

	Game();
	~Game();


	bool CreateBoard();
	bool SetPlayers();


	bool PlayerTurn();
	bool CheckIfWin(Mark mark);
	bool CheckIfDraw();

	bool CheckResult();

	bool Play();

};
