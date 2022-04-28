#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board()
{
}

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	/*sf::RectangleShape rec(sf::Vector2f(30, 30));
	rec.setFillColor(sf::Color::Blue);
	window.draw(rec);*/
}

void GameBoard::handleEvent(const sf::Event& event)
{
}
