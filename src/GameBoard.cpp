#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board(), m_cat(sf::Vector2f(35.f,0.f))
{
}

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
}

void GameBoard::handleClick(const sf::Event& event)
{
	m_board.handleClick(event);
	m_cat.handleClick();

	//check which part of gameboard event happened
	//handle event in part of board
}
