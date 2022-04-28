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
		if (event.type == sf::Event::Closed)
			window.close();
		else
			gameBoard.handleEvent(event);
	}
}

void GameController::update()
{
}

void GameController::render(sf::RenderWindow& window, GameBoard& gameBoard)
{
	window.clear(sf::Color(237, 237, 237));
	gameBoard.draw(window);
	window.display();
}

