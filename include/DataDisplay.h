#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"
#include "Resources.h"
#include "Button.h"



class DataDisplay {
public:
	DataDisplay();
	void draw(sf::RenderWindow& window);
	Btns handleClick(sf::Event event);
	void setNumOfMovesText(unsigned int moves);
	void updateNumOfMovesString(unsigned int moves);
private:
	void setBtns();
	void setBackground();
private:
	sf::Text m_numOfMovesTitleText;
	sf::RectangleShape m_background;
	std::vector<Button> m_buttons;
};