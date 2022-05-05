#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"
#include "Resources.h"
#include "NewGameButton.h"

class DataDisplay {
public:
	DataDisplay();
	void draw(sf::RenderWindow& window);
	Btns handleClick(sf::Event event);

	void setNumOfMovesText(unsigned int moves);
	void updateNumOfMovesString(unsigned int moves);
	

private:
	void setBtns();
	void setUndoBtn();
	void setResetLevelBtn();
	void setNewGameButton();
private:
	sf::Text m_numOfMovesTitleText;
	
	//Game Buttons
	NewGameButton m_newGameBtn;
};