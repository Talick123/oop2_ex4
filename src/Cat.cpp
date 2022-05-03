#include "Cat.h"
//
//Cat::Cat(sf::Vector2f position)
//	:m_triangle(sf::CircleShape(30.f, 3))
//{
//	m_triangle.setPosition(position);
//	m_triangle.setFillColor(sf::Color(194, 113, 86));
//}

Cat::Cat(std::pair<int, int> location)
	:m_triangle(sf::CircleShape(30.f, 3)), m_location(location)
{
	std::cout << "initial location " << location.first << " " << location.second << std::endl;
	setLocation(location);
	m_triangle.setFillColor(sf::Color(194, 113, 86));

}

void Cat::draw(sf::RenderWindow& window)
{
	window.draw(m_triangle);
}

void Cat::handleClick()
{
	sf::Vector2f newpos(m_triangle.getPosition().x + 70, m_triangle.getPosition().y);
	m_triangle.setPosition(newpos);
}

std::pair<int, int> Cat::getLocation()
{
	return m_location;
}

void Cat::setLocation(std::pair<int, int> location)
{
	m_location = location;
	std::cout << "set location " << location.first << " " << location.second << std::endl;
	auto x = (location.first % 2 == 0) ? TOTAL_TILE_SIZE * location.second : TOTAL_TILE_SIZE * location.second + TILE_RADIUS;
	auto y = TOTAL_TILE_SIZE * location.first;
	m_triangle.setPosition(sf::Vector2f(x + BOARD_OFFSET_X, y + BOARD_OFFSET_Y));
}
