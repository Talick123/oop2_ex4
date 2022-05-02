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

	//Noga: I know we can create function and send to it bool argument but i think its more understandable like that (this?),  yes? no? are you with me?
	void blockTile();
	void unBlockTile();
private:
	sf::CircleShape m_tile;
	bool m_blocked;
	//std::map<int, int> m_neighbours;
	
};