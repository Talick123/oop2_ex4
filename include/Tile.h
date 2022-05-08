#pragma once

#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Resources.h"

#include "Audio.h"

class Tile {
public:
	Tile();
	
	void setPosition(sf::Vector2f pos);
	void setFillColor(sf::Color color);
	void draw(sf::RenderWindow& window);
	bool isContain(sf::Event event);
	bool isContain(sf::Vector2f location);

	bool isBlocked();
	void blockTile();
	void unBlockTile();
	void clicked();
private:
	sf::CircleShape m_tile;
	bool m_blocked;
	Audio m_audio;
};