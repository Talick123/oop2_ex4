#include "..\include\Tile.h"
#include "Tile.h"

Tile::Tile()
	:m_tile(sf::CircleShape((float)TILE_RADIUS)), m_blocked(false)
{
	m_tile.setFillColor(sf::Color(230, 183, 148));
}

void Tile::setPosition(sf::Vector2f pos)
{
	m_tile.setPosition(pos);
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(m_tile);
}

bool Tile::isContain(sf::Event event)
{
	return m_tile.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Tile::blockTile()
{
	m_tile.setFillColor(sf::Color(184, 221, 214));
	m_blocked = true;
}

void Tile::unBlockTile()
{
	m_tile.setFillColor(sf::Color(230, 183, 148));
	m_blocked = false;
}

