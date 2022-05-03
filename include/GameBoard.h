#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"

#include "Board.h"
#include "Cat.h"

#include <queue>
#include <utility>
#include <vector>

class GameBoard {
public:
	GameBoard();
	void draw(sf::RenderWindow& window);
	void handleClick(const sf::Event& event);

	void resetMoves();
private:
	void setNumOfMovesText();
	void setBtns();
	void setUndoBtn();
	void setResetLevelBtn();
	
	void updateNumOfMovesString();

	void moveCat();
	bool isValid(bool visited, int row, int col);

private:
	Board m_board;
	Cat m_cat;

	//Noga: move to kind of "DataDisplay" class ?
	sf::Text m_numOfMovesTitleText;
	int m_numOfMoves;

	sf::Sprite m_undo;
};