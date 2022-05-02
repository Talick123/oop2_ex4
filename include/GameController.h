#pragma once
#include <SFML/Graphics.hpp>

#include "GameBoard.h"
#include "macros.h"


class GameController {
public:
	GameController();
	void startGame();
private:
	//process (events)
	void processEvents(sf::RenderWindow& window, GameBoard& gameBoard);
	void gameBoardProcesEvents(sf::Event& event, GameBoard& gameBoard);
	void emmptyPageProcessEvents(sf::Event& event);

	//update
	void update();
	
	//render (draw)
	void render(sf::RenderWindow& window, GameBoard& gameBoard);
	void drawCurrPage(sf::RenderWindow& window, GameBoard& gameBoard);

	//set
	void initPages();

	void updateWin(GameBoard& gameBoard);
	void updateLose(GameBoard& gameBoard);

private:

	//Data Types
	enum class Page
	{
		GameBoard = 0,
		UserWin,
		UserLose
	};

	//Members
	Page m_currPage = Page::GameBoard;
	
	sf::RectangleShape m_levelComplete;
	sf::RectangleShape m_levelLost; //Noga: ?
};