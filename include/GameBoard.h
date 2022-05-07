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
	//GameBoard();
	GameBoard(int numOfBlockedTiles);
	void draw(sf::RenderWindow& window);
	Btns handleClick(const sf::Event& event);
	void handleHover(sf::Vector2f location);

	void resetMoves();
	void update(float deltaTime);

	void undo();
private:	
	void moveCat();
	void placeCat();
	bool isCatHere(sf::Event event);

	void initVisited(bool visited[][SIZE]);

private:
	Board m_board;
	Cat m_cat;
	DataDisplay m_dataDisplay;
	std::vector<std::pair<std::pair<int, int>, Tile*>> m_gameMoves;

	int m_numOfMoves; //Tali: do we need num of moves? m_gameMoves.size() - 1 will tell us how much 
};