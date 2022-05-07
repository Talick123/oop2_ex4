#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "macros.h"
#include "Resources.h"

#include "Animation.h"

#include <queue>
#include <utility>
#include <vector>

enum dir { L, R, LU, RU, LD, RD, NONE };

class Cat {
public:
	Cat();
	//Cat(std::pair<int,int> location);

	void move(bool visited[][SIZE]);
	void draw(sf::RenderWindow& window);
	//void handleClick();
	std::pair<int, int> getLocation();
	void setLocation(std::pair<int, int> location);
	void setCurrLocation(std::pair<int, int> newDest);

	void update(float deltaTime);

	bool isContain(sf::Event event);
	bool isStoped();
private:
	sf::Vector2f getCatDirection(float deltaTime);
	void setDirection();
	bool checkStop();
	bool BFS(std::pair<int, int>& end_tile, std::pair<int, int> prev[][SIZE], bool visited[][SIZE]);
	bool isValid(int row, int col);
private:
	sf::RectangleShape m_triangle;
	Animation m_animation;

	std::pair<int, int> m_location; // location as matrix index

	int m_direction;
	sf::Vector2f m_currLocation; //destination (in pixels)
	sf::Vector2f m_oldLocation; // (in pixels)
	float m_speed; 
	bool m_stop;

};