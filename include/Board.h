#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Board {
public:
	Board();
	void draw(sf::RenderWindow& window);
private:
	std::vector<std::vector<sf::CircleShape>> m_tiles;
};