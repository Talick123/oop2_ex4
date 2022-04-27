#include "GameWindow.h"

GameWindow::GameWindow()
	: m_window(sf::RenderWindow(sf::VideoMode(610, 610), "Circle the Cat", sf::Style::Close))
{
}

bool GameWindow::isOpen()
{
	return m_window.isOpen();
}

