#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"

#include "Button.h"

class UndoGameButton : public Button {
public:
	UndoGameButton() : Button() {};
	UndoGameButton(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f scale)
		: Button(texture, pos, scale) {};
	void handleClick() {};

private:
};