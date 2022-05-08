#include "Resources.h"
#include "macros.h"


Resources::Resources()
{
	loadFont();
	loadBtnTextures();
	loadCatSpriteSheet();
	loadAudioClick();
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

sf::Texture* Resources::getBtnTexture(Btns button)
{
	return &m_btnTextures[(int)button];
}

//-----------------------------------------------------------------

sf::Texture* Resources::getCatSpriteSheet()
{
	return &m_catSpriteSheet;
}

//-----------------------------------------------------------------

sf::SoundBuffer* Resources::getAudioClick()
{
	return &m_audioClick;
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

void Resources::loadBtnTextures()
{
	m_btnTextures.resize(NUM_OF_BTNS);

	if (!m_btnTextures[(int)Btns::NewGame].loadFromFile("new_game_btn.png")
		|| !m_btnTextures[(int)Btns::Undo].loadFromFile("undo_btn.png")
		|| !m_btnTextures[(int)Btns::Reset].loadFromFile("resart_btn.png"))
	{
		std::cerr << "error loading button textures from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadCatSpriteSheet()
{
	if (!m_catSpriteSheet.loadFromFile("cat.png"))
	{
		std::cerr << "error loading cat textures from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadAudioClick()
{
	if (!m_audioClick.loadFromFile("click.wav"))
	{
		std::cerr << "error loading game music from file";
	}
}
