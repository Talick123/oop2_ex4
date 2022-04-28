#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board()
{
}

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
}

void GameBoard::handleEvent(const sf::Event& event)
{
	//check which part of gameboard event happened
	//handle event in part of board
}
