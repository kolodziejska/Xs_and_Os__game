#include "Game.h"
#include <iostream>
#include "Converter.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::CreateBoard()
{
	m_board = Board();
	m_board.DrawBoard();
	return true;
}

bool Game::SetPlayers()
{
	std::string player1;
	std::string player2;

	std::cout << "Player 1 - give your name: ";
	std::cin >> player1;
	std::cout << std::endl;
	std::cout << "Player 2 - give your name: ";
	std::cin >> player2;
	std::cout << std::endl;

	m_playerO = Player(player1, Mark::O);
	m_playerX = Player(player2, Mark::X);
	m_activePlayer = Player();

	//setting random starting player
	srand(static_cast<unsigned>(time(NULL)));
	if (rand() % 2 == 0) {
		m_activePlayer.ChangeName(m_playerO.GetName());
		m_activePlayer.ChangeMark(m_playerO.GetMark());
	}
	else {
		m_activePlayer.ChangeName(m_playerX.GetName());
		m_activePlayer.ChangeMark(m_playerX.GetMark());
	}


	return true;
}

bool Game::CheckIfWin(Mark mark)
{

	int sideLength = m_board.GetSideLength();
	int marksNumber;

	//check rows
	for (int i = 0; i < sideLength; ) {
		marksNumber = 0;
		for (int j = 0; j < sideLength; j++) {
			if (m_board.GetMark(i, j) == mark)
			{
				marksNumber++;
			}
		}
		if (marksNumber == sideLength) { return true; break; }
		else { marksNumber = 0; i++; }
	}

	//check columns
	for (int i = 0; i < sideLength; ) {
		marksNumber = 0;
		for (int j = 0; j < sideLength; j++) {

			if (m_board.GetMark(j, i) == mark)
			{
				marksNumber++;
			}
		}
		if (marksNumber == sideLength) { return true; break; }
		else { marksNumber = 0; i++; }

	}

	//check top-left to bottom-right diagonal
	marksNumber = 0;

	for (int i = 0; i < sideLength; i++) {
		int j = i;
		if (m_board.GetMark(i, j) == mark)
		{
			marksNumber++;
		}
	}
	if (marksNumber == sideLength) { return true; }

	//check top-right to bottom-left diagonal
	marksNumber = 0;

	for (int i = 0; i < sideLength; i++) {
		int j = sideLength - 1 - i;
		if (m_board.GetMark(i, j) == mark)
		{
			marksNumber++;
		}
	}
	if (marksNumber == sideLength) { return true; }


	return false;
}

bool Game::PlayerTurn()
{
	std::string spaceName;
	int spaceNumber;
	int boardSize = m_board.GetTotalSize();

	std::cout << "Turn: " << m_activePlayer.GetName() << std::endl;
	std::cout << "- choose space to put " << Converter::MarkToChar(m_activePlayer.GetMark()) << " : ";
	std::cin >> spaceName;

	spaceNumber = Converter::SpaceNameToInt(spaceName);

	while (m_board.GetMark(spaceNumber) != Mark::NTH) {
		std::cout << "WRONG VALUE!!! CHOOSE A VALUE THAT IS AVAILABLE ON THE BOARD: ";
		std::cin >> spaceName;
		spaceNumber = Converter::SpaceNameToInt(spaceName);
		while (((spaceNumber > boardSize || spaceNumber < 1) && spaceName.length() <= 2) || spaceName.length() > 2) {
			std::cout << "WRONG VALUE!!! CHOOSE A VALUE THAT IS AVAILABLE ON THE BOARD: " << std::endl;
			std::cin >> spaceName;
			spaceNumber = Converter::SpaceNameToInt(spaceName);
		}
	}

	m_board.SetMark(spaceNumber, m_activePlayer.GetMark());

	m_board.DrawBoard();

	if (m_activePlayer.GetMark() == Mark::O) {
		m_activePlayer.ChangeName(m_playerX.GetName());
		m_activePlayer.ChangeMark(m_playerX.GetMark());
	}
	else {
		m_activePlayer.ChangeName(m_playerO.GetName());
		m_activePlayer.ChangeMark(m_playerO.GetMark());
	}
	return true;
}

bool Game::CheckIfDraw() {

	int NthNumber = 0;
	int sideLength = m_board.GetSideLength();
	for (int i = 0; i < sideLength; i++) {
		for (int j = 0; j < sideLength; j++)
			if (m_board.GetMark(i, j) == Mark::NTH)
				++NthNumber;
	}
	if (NthNumber == 0) return true;
	else return false;
}

bool Game::CheckResult() {

	if (CheckIfWin(Mark::O)) std::cout << m_playerO.GetName() << " is a winner! Congratulations!" << std::endl;
	else if (CheckIfWin(Mark::X)) std::cout << m_playerX.GetName() << " is a winner! Congratulations!" << std::endl;
	else std::cout << "It's a draw!" << std::endl;
	return true;
}

bool Game::Play() {
	SetPlayers();
	CreateBoard();

	while (true) {
		PlayerTurn();
		if (CheckIfWin(Mark::O) || CheckIfWin(Mark::X) || CheckIfDraw()) { break; }
	}

	CheckResult();
	return true;
}
