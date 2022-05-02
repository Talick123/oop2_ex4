#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Cat.h"

class GameBoard {
public:
	GameBoard();
	void draw(sf::RenderWindow& window);
	void handleClick(const sf::Event& event);
private:
	void setText();
	void setNumOfMovesText();
	void loadFont();
	void updateNumOfMovesString();
private:
	Board m_board;
	Cat m_cat;

	//Noga: move to kind of "DataDisplay" class ?
	sf::Text m_numOfMovesTitleText;
	int m_numOfMoves;
	sf::Font m_font; //Noga: move to singleton 'Resources' class

	sf::Sprite m_undo;
	sf::Texture m_t;

};