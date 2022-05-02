#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.h"

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window);
	bool handleClick(const sf::Event& event);
private:
	void initBoard();
	void setNeighbours();
	std::vector<std::vector<Tile>> m_tiles;
};