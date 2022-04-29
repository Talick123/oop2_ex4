#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board()
{
}

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
}

void GameBoard::handleClick(const sf::Event& event)
{
	m_board.handleClick(event);
	//check which part of gameboard event happened
	//handle event in part of board
}
