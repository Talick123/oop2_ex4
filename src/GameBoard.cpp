#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board(), m_cat(sf::Vector2f(35.f,0.f)), m_numOfMoves(0)
{
	setText();
}

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
	window.draw(m_numOfMovesTitleText);
}

void GameBoard::handleClick(const sf::Event& event)
{
	if (m_board.handleClick(event))
	{
		m_numOfMoves++;
		updateNumOfMovesString();
		m_cat.handleClick();
	}

	//check which part of gameboard event happened
	//handle event in part of board
}

void GameBoard::setText()
{
	loadFont();
	setNumOfMovesText();
}

void GameBoard::setNumOfMovesText()
{
	m_numOfMovesTitleText.setFont(m_font);
	float offsetX = BOARD_AREA_LENGTH + 10;
	m_numOfMovesTitleText.setPosition(sf::Vector2f(offsetX, 70.f));
	m_numOfMovesTitleText.setFillColor(sf::Color(34, 34, 34));
	m_numOfMovesTitleText.setCharacterSize(30);
	updateNumOfMovesString();
}

void GameBoard::loadFont()
{
	if (!m_font.loadFromFile("YatraOne.ttf")) 
	{
		std::cerr << "error loading font from file";
	}
}

void GameBoard::updateNumOfMovesString()
{
	m_numOfMovesTitleText.setString("Number of Moves:\n" + std::to_string(m_numOfMoves));
}
