#include "DataDisplay.h"

DataDisplay::DataDisplay()
{
	setBtns();
	setNumOfMovesText(0);
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	window.draw(m_numOfMovesTitleText);
	for (auto btn : m_buttons)
	{
		btn.draw(window);
	}
}

Btns DataDisplay::handleClick(sf::Event event)
{
	if (m_buttons[(int)Btns::NewGame].isContain(event))
	{
		return Btns::NewGame;
	}
	else if (m_buttons[(int)Btns::Undo].isContain(event))
	{
		return Btns::Undo;
	}
	else if (m_buttons[(int)Btns::Reset].isContain(event))
	{
		return Btns::Reset;
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
	{
		m_buttons[(int)Btns::Undo].setColor(sf::Color(115, 115, 115));
		m_buttons[(int)Btns::Reset].setColor(sf::Color(115, 115, 115));	
	}
	else
	{
		m_buttons[(int)Btns::Undo].setColor(sf::Color(252, 252, 252));
		m_buttons[(int)Btns::Reset].setColor(sf::Color(252, 252, 252));
	}
}

void DataDisplay::setBtns()
{

	m_buttons.push_back(Button(Btns::NewGame));
	m_buttons.push_back(Button(Btns::Undo));
	m_buttons.push_back(Button(Btns::Reset));

	m_buttons[(int)Btns::NewGame].setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 200));
	m_buttons[(int)Btns::Undo].setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 400));
	m_buttons[(int)Btns::Reset].setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 600));
}
