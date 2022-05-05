#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.h"


class Board {
public:
	Board();
	Board(int numOfBlockedTiles);
	void draw(sf::RenderWindow& window);
	bool handleClick(const sf::Event& event);
	void handleHover(sf::Vector2f location);
	Tile& at(int row, int col);
private:
	void initBoard();
	void randomizeLevel(int numOfBlockedTiles);
	std::vector<std::vector<Tile>> m_tiles;
	
};