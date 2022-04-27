#pragma once

#include <SFML/Graphics.hpp>

class GameWindow {
public:
	GameWindow();
	bool isOpen();
private:
	sf::RenderWindow m_window;
};