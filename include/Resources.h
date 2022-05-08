#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "macros.h"


class Resources
{
public:
	~Resources();
	static Resources& instance();

	////Access Functions
	sf::Font* getFont();
	sf::Texture* getBtnTexture(Btns button);
	sf::Texture* getCatSpriteSheet();
	sf::SoundBuffer* getAudioClick();
	

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();
	void loadBtnTextures();
	void loadCatSpriteSheet();
	void loadAudioClick();

	//======Members==========

	//Fonts
	sf::Font m_font;

	//Textures
	sf::Texture m_catSpriteSheet;
	std::vector<sf::Texture> m_btnTextures;

	//Audio
	sf::SoundBuffer m_audioClick;
};