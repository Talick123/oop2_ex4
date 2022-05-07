#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <exception>

#include "Animation.h"
#include "macros.h"
#include "Resources.h"



enum class Direction { L = 14 , R = 10, LU = 13, RU = 11, LD = 7, RD = 9, NONE = 4};
enum class NumOfImages { L = 4, R = 4, LU = 4, RU = 4, LD = 4, RD = 4, NONE = 4 };

class Cat {
public:
	Cat();
	//Cat(std::pair<int,int> location);

	void move(bool visited[][SIZE]);
	void draw(sf::RenderWindow& window);
	//void handleClick();
	std::pair<int, int> getLocation()const;
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
	void findPosInEnclosure(std::pair<int, int> prev[][SIZE]);
	void moveAccordingly(std::vector < std::pair<int, int>> path);
	void createPath(std::pair<int, int> end_tile, std::pair<int, int> prev[][SIZE], std::vector < std::pair<int, int>>& path);
private:
	sf::RectangleShape m_triangle;
	Animation m_animation;

	std::pair<int, int> m_location; // location as matrix index

	Direction m_direction;
	sf::Vector2f m_currLocation; //destination (in pixels)
	sf::Vector2f m_oldLocation; // (in pixels)
	float m_speed; 
	bool m_stop;

};