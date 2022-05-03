#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"

class Cat {
public:
	//Cat(sf::Vector2f position);
	Cat(std::pair<int,int> location);


	void draw(sf::RenderWindow& window);
	void handleClick();
	std::pair<int, int> getLocation();
	void setLocation(std::pair<int, int> location);
private:
	sf::CircleShape m_triangle;
	std::pair<int, int> m_location;
};