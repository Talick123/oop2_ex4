#pragma once
#include <SFML/Graphics.hpp>

#include "GameBoard.h"
#include "macros.h"


class GameController {
public:
	GameController();
	void startGame();
private:
	void processEvents(sf::RenderWindow& window, GameBoard& gameBoard);
	void update();
	void render(sf::RenderWindow& window, GameBoard& gameBoard);

};