#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"
#include "Resources.h"

class Button {
public:
	Button(Btns type);
	~Button() {};
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;

	//set sprite
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);

private:
	sf::Sprite m_button;
};