#include "Resources.h"

Resources::Resources()
{
	loadFont();
	loadUndoTexture();
	loadNewGameTexture();
}


//-----------------------------------------------------------------

Resources::~Resources()
{
}

//-----------------------------------------------------------------

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}


//===============================================================//
//							 GET DATA
//===============================================================//


sf::Font* Resources::getFont()
{
	return &m_font;
}


//-----------------------------------------------------------------

sf::Texture* Resources::getUndoTexture()
{
	return &m_undoTexture;
}

sf::Texture* Resources::getNewGameTexture()
{
	return &m_newGameTexture;
}




//===============================================================//
//							 LOAD DATA
//===============================================================//


void Resources::loadFont()
{
	if (!m_font.loadFromFile("YatraOne.ttf"))
	{
		std::cerr << "error loading font from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadUndoTexture()
{
	if (!m_undoTexture.loadFromFile("undo.png"))
	{
		std::cerr << "error loading home button textures from file";
	}
}

void Resources::loadNewGameTexture()
{
	if (!m_newGameTexture.loadFromFile("new-game.png"))
	{
		std::cerr << "error loading home button textures from file";
	}
}
