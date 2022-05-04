#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"

class Button {
public:
	Button() {};
	Button(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f scale);
	virtual ~Button() {};
	void draw(sf::RenderWindow& window);
	virtual void handleClick() = 0;

	//set sprite
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);
	void setScale(sf::Vector2f scale);
	void setTexture(sf::Texture &texture);

private:
	sf::Sprite m_button;
};