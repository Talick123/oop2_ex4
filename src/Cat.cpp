#include "Cat.h"

Cat::Cat(sf::Vector2f position)
	:m_triangle(sf::CircleShape(30.f, 3)) //Tali: to make a triangle : use circleshape with 3 points (second value) just saying
{
	m_triangle.setPosition(position);
	m_triangle.setFillColor(sf::Color::Blue);
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
