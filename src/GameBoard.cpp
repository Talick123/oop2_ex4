#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board(), m_cat(sf::Vector2f(35.f,0.f)), m_numOfMoves(0)
{
	setNumOfMovesText();

	//UNDO BUTTON 
	//Noga: maybe because we have 2 buttons we can create tiny tiny tinyyyy class to them - with sprite member and handle click ? :)
	setBtns();
}

//-----------------------------------------------------------------

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
	window.draw(m_numOfMovesTitleText);
	window.draw(m_undo);
}

//-----------------------------------------------------------------

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

void GameBoard::resetMoves()
{
	m_numOfMoves = 0;
	updateNumOfMovesString(); //TODO: ?
}

//-----------------------------------------------------------------

void GameBoard::setNumOfMovesText()
{
	m_numOfMovesTitleText.setFont(*(Resources::instance().getFont()));
	float offsetX = BOARD_AREA_LENGTH + 10;
	m_numOfMovesTitleText.setPosition(sf::Vector2f(offsetX, 70.f));
	m_numOfMovesTitleText.setFillColor(sf::Color(41, 86, 79));
	m_numOfMovesTitleText.setCharacterSize(30);
	updateNumOfMovesString();
}

//-----------------------------------------------------------------

void GameBoard::setBtns()
{
	//set undo button
	setUndoBtn();
	//set reset level button
	setResetLevelBtn();
}

//-----------------------------------------------------------------

void GameBoard::setUndoBtn()
{
	m_undo.setTexture(*(Resources::instance().getUndoTexture()));
	m_undo.setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 200));
	m_undo.setScale(sf::Vector2f(0.15, 0.15));
}

//-----------------------------------------------------------------

void GameBoard::setResetLevelBtn()
{
	//TODO: you kknow... etc etc
}

//-----------------------------------------------------------------

void GameBoard::updateNumOfMovesString()
{
	m_numOfMovesTitleText.setString("Number of Moves:\n" + std::to_string(m_numOfMoves));
}
