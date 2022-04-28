#include "Tile.h"

Tile::Tile()
	:m_tile(sf::CircleShape(30.f)), m_blocked(false)
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
