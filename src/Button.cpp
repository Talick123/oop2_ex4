#include "Button.h"

Button::Button(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f scale)
{
	setTexture(texture);
	setPosition(pos);
	setScale(scale);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
}

void Button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
}

void Button::setColor(sf::Color color)
{
	m_button.setColor(color);
}

void Button::setScale(sf::Vector2f scale)
{
	m_button.setScale(scale);
}

void Button::setTexture(sf::Texture &texture)
{
	m_button.setTexture(texture);
}
