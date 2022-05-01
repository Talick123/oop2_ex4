#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	int offsetX, offsetY;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			offsetX = (i % 2 == 0) ? TOTAL_TILE_SIZE * j : TOTAL_TILE_SIZE * j + TILE_RADIUS;
			offsetY = TOTAL_TILE_SIZE * i;
			
			float x = BOARD_OFFSET_X + offsetX;
			float y = BOARD_OFFSET_Y + offsetY;

			sf::Vector2f position(x, y);
			m_tiles[i][j].setPosition(position);
			//set neighbours
		}
	}
}
/*
sf::Vector2f Board::createPosition(int row, int col, float square_size)
{
	sf::Vector2f position;
	float xPos, yPos;

	float col_offsetX = (WINDOW_W - square_size * m_width) / 2;
	float col_offsetY = (BOARD_H - square_size * m_height) / 2;

	xPos = (float)(col * (square_size) + col_offsetX);
	yPos = (float)(row * (square_size) + col_offsetY);
	position = { xPos, yPos };

	return position;
}*/

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
