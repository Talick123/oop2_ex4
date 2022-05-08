#pragma once
#include <SFML/Graphics.hpp>

#include <queue>
#include <utility>
#include <vector>
#include <exception>

#include "Resources.h"

#include "Board.h"
#include "Cat.h"
#include "DataDisplay.h"

class GameBoard {
public:
	GameBoard(int numOfBlockedTiles);
	void draw(sf::RenderWindow& window);
	Btns handleClick(const sf::Event& event, GameStatus &status);
	void handleHover(sf::Vector2f location);
	void update(float deltaTime);
	void undo();
	void resetLevel();

private:	
	void moveCat(GameStatus& status);
	void placeCat();
	bool isCatHere(sf::Event event) const;
	void initVisited(bool visited[][SIZE]);

private:
	Board m_board;
	Cat m_cat;
	DataDisplay m_dataDisplay;
	std::vector<std::pair<std::pair<int, int>, Tile*>> m_gameMoves;
};