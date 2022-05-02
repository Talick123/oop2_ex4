#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Resources
{
public:
	~Resources();
	static Resources& instance();

	////Access Functions
	sf::Font* getFont();
	sf::Texture* getUndoTexture();
	

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();
	void loadUndoTexture();

	//======Members==========

	//Fonts
	sf::Font m_font;

	//Textures
	sf::Texture m_undoTexture;

	//Audio
	
};