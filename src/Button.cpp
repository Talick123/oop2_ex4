#include "Button.h"

Button::Button(Btns type)
{
	m_button.setTexture(*Resources::instance().getBtnTexture(type));
	m_button.setScale(sf::Vector2f(1, 1));
}


void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
}

bool Button::isContain(sf::Event event) const
{
	return m_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Button::setPosition(sf::Vector2f pos)
{
	m_button.setPosition(pos);
}

void Button::setColor(sf::Color color)
{
	m_button.setColor(color);
}
