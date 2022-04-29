#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Tile.h"

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window);
	void handleClick(const sf::Event& event);
private:
	std::vector<std::vector<Tile>> m_tiles;
};