#include "..\include\DataDisplay.h"
#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_newGameBtn()
{
	setBtns();
	setNumOfMovesText(0);
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	window.draw(m_numOfMovesTitleText);
	m_newGameBtn.draw(window);
	m_undoGameBtn.draw(window);
}

Btns DataDisplay::handleClick(sf::Event event)
{
	if (m_newGameBtn.isContain(event))
	{
		return Btns::NewGame;
	}
	else if (m_undoGameBtn.isContain(event))
	{
		return Btns::Undo;
	}
	else return Btns::None;
}

void DataDisplay::setNumOfMovesText(unsigned int moves)
{
	m_numOfMovesTitleText.setFont(*(Resources::instance().getFont()));
	float offsetX = BOARD_AREA_LENGTH + 10;
	m_numOfMovesTitleText.setPosition(sf::Vector2f(offsetX, 70.f));
	m_numOfMovesTitleText.setFillColor(sf::Color(41, 86, 79));
	m_numOfMovesTitleText.setCharacterSize(30);
	updateNumOfMovesString(moves);
}

void DataDisplay::updateNumOfMovesString(unsigned int moves)
{
	m_numOfMovesTitleText.setString("Moves: " + std::to_string(moves));
	if (moves == 0)
		m_undoGameBtn.setColor(sf::Color(115, 115, 115));
	else
		m_undoGameBtn.setColor(sf::Color(252, 252, 252));
}

void DataDisplay::setBtns()
{
	//set undo button
	setUndoBtn();
	
	//set reset level button
	//setResetLevelBtn();

	//set new game button
	setNewGameButton();
}

void DataDisplay::setUndoBtn()
{
	m_undoGameBtn.setTexture(*(Resources::instance().getNewGameTexture()));
	m_undoGameBtn.setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 400));
	m_undoGameBtn.setScale(sf::Vector2f(2, 2));
}

void DataDisplay::setNewGameButton()
{
	m_newGameBtn.setTexture(*(Resources::instance().getNewGameTexture()));
	m_newGameBtn.setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 200));
	m_newGameBtn.setScale(sf::Vector2f(2, 2));
}

