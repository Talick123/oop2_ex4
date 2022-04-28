#include "Board.h"

Board::Board()
	//: m_tiles(11, std::vector<sf::CircleShape(23.f, 23)>(11))
	: m_tiles(11, std::vector<sf::CircleShape>(11, sf::CircleShape(30.f)))
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			m_tiles[i][j].setPosition(sf::Vector2f(i % 2 == 0 ? 60 * j + 30 : 60 * j, 60 * i));
		}
	//sf::CircleShape circle(13.f, 13.f);
	//std::vector<std::vector<sf::CircleShape>> m(11, std::vector<sf::CircleShape>(11, sf::CircleShape(13.f, 13.f)));
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			window.draw(m_tiles[i][j]);
		}
}
