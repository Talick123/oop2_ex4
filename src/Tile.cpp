#include "..\include\Tile.h"
#include "Tile.h"

Tile::Tile()
	:m_tile(sf::CircleShape((float)TILE_RADIUS)), m_blocked(false)
{
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
