#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	int row, col;
	int radius = 30; //TODO: add to macros 
	int padding = 10;
	int totalTileSpace = radius*2 + padding; 
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			row = i % 2 == 0 ? totalTileSpace * j + (totalTileSpace/2) : totalTileSpace * j; 
			col = 70 * i;
			sf::Vector2f position(row, col);
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

bool Board::handleClick(const sf::Event& event)
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			if (m_tiles[i][j].isContain(event))
			{
				std::cout << "Click on tile. row: " << i << ", col: " << j << std::endl;
				return true;
			}
		}
	return false;
}
