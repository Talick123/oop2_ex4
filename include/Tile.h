#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "macros.h"

class Tile {
public:
	Tile();
	
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	bool isContain(sf::Event event);
private:
	sf::CircleShape m_tile;
	bool m_blocked;
	//std::map<int, int> m_neighbours;
	
};