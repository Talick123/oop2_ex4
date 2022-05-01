#include "GameController.h"


GameController::GameController()
{
}

void GameController::startGame()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "Circle the Cat", sf::Style::Close);
	GameBoard gameBoard;

	while (window.isOpen())
	{
		processEvents(window, gameBoard);
		update();
		render(window, gameBoard); //maybe put first
	}
}

void GameController::processEvents(sf::RenderWindow &window, GameBoard &gameBoard)
{

	if (auto event = sf::Event{}; window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonReleased:
			gameBoard.handleClick(event);
			break;
		}
	}
}

void GameController::update()
{
}

void GameController::render(sf::RenderWindow& window, GameBoard& gameBoard)
{
	window.clear(sf::Color(13, 125, 87));
	gameBoard.draw(window);
	window.display();
}

