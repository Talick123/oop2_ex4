#include "..\include\Tile.h"
#include "Tile.h"

Tile::Tile()
	:m_tile(sf::CircleShape(30.f)), m_blocked(false) //TODO: add to macros (radius)
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
