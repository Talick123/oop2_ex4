#include "Board.h"

Board::Board()
	: m_tiles(11, std::vector<Tile>(11))
{
	int x, offsetY;
	int padding = 10;
	int totalTileSpace = TILE_RADIUS*2 + padding; 
	
	float BOARD_OFFSET_Y = (WINDOW_HEIGHT - totalTileSpace * 11 - 10) / 2;

	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			x = i % 2 == 0 ? totalTileSpace * j + (totalTileSpace/2) : totalTileSpace * j; 
			offsetY = totalTileSpace * i;


			//float col_offsetX = (WINDOW_LENGTH - square_size * m_width) / 2;
			float y = BOARD_OFFSET_Y + offsetY;

			sf::Vector2f position(x, y);
			m_tiles[i][j].setPosition(position);
			//set neighbours
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
