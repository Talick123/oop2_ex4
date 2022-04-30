#pragma once

#include <SFML/Graphics.hpp>

class Cat {
public:
	Cat(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	void handleClick();
private:
	sf::CircleShape m_triangle;
};