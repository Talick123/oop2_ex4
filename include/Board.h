#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.h"

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window);
private:
	std::vector<std::vector<Tile>> m_tiles;
};