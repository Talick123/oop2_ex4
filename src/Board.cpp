#include "Board.h"

const int DEFAULT_LEVEL = 10;


Board::Board(int numOfBlockedTiles)
	: m_tiles(SIZE, std::vector<Tile>(SIZE))
{
	initBoard();
	randomizeLevel(numOfBlockedTiles);
}

void Board::initBoard()
{
	float x, y;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			x = (i % 2 == 0) ? TOTAL_TILE_SIZE * j : TOTAL_TILE_SIZE * j + TILE_RADIUS;
			y = TOTAL_TILE_SIZE * i;

			m_tiles[i][j].setPosition(sf::Vector2f(x + BOARD_OFFSET_X, y + BOARD_OFFSET_Y));
		}
	}
}

void Board::randomizeLevel(int numOfBlockedTiles)
{
	int counter = 0;
	while (counter < numOfBlockedTiles) { //looping while 3 distinct cells are not set to true
		int rRow = rand() % SIZE;
		int rCol = rand() % SIZE;

		if (!m_tiles[rRow][rCol].isBlocked()) {
			m_tiles[rRow][rCol].blockTile();
			counter++; //increasing the counter only when a new cell is set to true
		}
	}
}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			m_tiles[i][j].draw(window);
		}
}

bool Board::handleClick(const sf::Event& event, Tile*& tile_clicked)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			if (m_tiles[i][j].isContain(event))
			{
				if (m_tiles[i][j].isBlocked()) return false;

				tile_clicked = &m_tiles[i][j];
				m_tiles[i][j].blockTile();
				m_tiles[i][j].clicked();
				return true;
			}
		}
	return false;
}

void Board::handleHover(sf::Vector2f location)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (!at(i, j).isBlocked() && at(i,j).isContain(location))
			{
				at(i,j).setFillColor(sf::Color(221, 158, 110));
			}
			else
			{
				at(i, j).isBlocked() ? at(i, j).setFillColor(sf::Color(184, 221, 214)) : at(i, j).setFillColor(sf::Color(230, 183, 148));
			}
		}
	}
}

Tile& Board::at(int row, int col)
{
	return m_tiles[row][col];
}
