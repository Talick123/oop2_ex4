#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	initBoard();
}

void Board::initBoard()
{
	int offsetX, offsetY;
	float x, y;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			offsetX = (i % 2 == 0) ? TOTAL_TILE_SIZE * j : TOTAL_TILE_SIZE * j + TILE_RADIUS;
			offsetY = TOTAL_TILE_SIZE * i;

			x = BOARD_OFFSET_X + offsetX;
			y = BOARD_OFFSET_Y + offsetY;

			m_tiles[i][j].setPosition(sf::Vector2f(x,y));
			//set neighbours
		}
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
