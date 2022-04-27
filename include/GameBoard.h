#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"


class GameBoard {
public:
	GameBoard();
	void draw(sf::RenderWindow& window);
	void handleEvent(const sf::Event& event);
private:
	Board m_board;
};