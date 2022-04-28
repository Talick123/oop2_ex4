#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			sf::Vector2f position(i % 2 == 0 ? 60 * j + 30 : 60 * j, 60 * i);
			m_tiles[i][j].setPosition(position);
			//set neighbours
		}
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			m_tiles[i][j].draw(window);
		}
}
