#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	initBoard();
}

void Board::initBoard()
{
	float x, y;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			x = (i % 2 == 0) ? TOTAL_TILE_SIZE * j : TOTAL_TILE_SIZE * j + TILE_RADIUS;
			y = TOTAL_TILE_SIZE * i;

			m_tiles[i][j].setPosition(sf::Vector2f(x + BOARD_OFFSET_X, y + BOARD_OFFSET_Y));
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
				m_tiles[i][j].blockTile();
				return true;
			}
		}
	return false;
}

Tile& Board::at(int row, int col) //maybe make this const so they cant change it (const on return)
{
	return m_tiles[row][col];
}
