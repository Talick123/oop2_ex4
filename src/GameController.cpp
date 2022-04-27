#include "GameController.h"


GameController::GameController()
{
}

void GameController::startGame()
{
	sf::RenderWindow window(sf::VideoMode(610, 610), "Circle the Cat", sf::Style::Close);
	GameBoard my_game;

	while (window.isOpen())
	{
		window.clear();
		my_game.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else
				my_game.handleEvent(event);
		}
	}
}

//void GameController::run(GameWindow& window)
//{
//	while (window.isOpen())
//	{
//		
//
//
//	}
//}
