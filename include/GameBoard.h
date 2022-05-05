#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"

#include "Board.h"
#include "Cat.h"
#include "DataDisplay.h"

#include <queue>
#include <utility>
#include <vector>

class GameBoard {
public:
	GameBoard();
	GameBoard(int numOfBlockedTiles);
	void draw(sf::RenderWindow& window);
	void handleClick(const sf::Event& event);

	void resetMoves();
	void update(float deltaTime);
private:	
	void moveCat();
	bool BFS(std::pair<int, int>& end_tile, std::pair<int, int> prev[SIZE][SIZE]);
	bool isValid(int row, int col);

private:
	Board m_board;
	Cat m_cat;
	DataDisplay m_dataDisplay;

	int m_numOfMoves;
};