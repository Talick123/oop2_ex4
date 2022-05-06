#include "Cat.h"
//
//Cat::Cat(sf::Vector2f position)
//	:m_triangle(sf::CircleShape(30.f, 3))
//{
//	m_triangle.setPosition(position);
//	m_triangle.setFillColor(sf::Color(194, 113, 86));
//}

Cat::Cat()
	:m_triangle(sf::CircleShape(30.f, 3)), m_speed(60), m_direction(NONE), m_stop(true)
{
	//setLocation(location);
	//setCurrLocation(location);
	m_triangle.setFillColor(sf::Color(194, 113, 86));
}

void Cat::draw(sf::RenderWindow& window)
{
	window.draw(m_triangle);
}

void Cat::handleClick()
{
	sf::Vector2f newpos(m_triangle.getPosition().x + 70, m_triangle.getPosition().y);
	m_triangle.setPosition(newpos);
}

std::pair<int, int> Cat::getLocation()
{
	return m_location;
}

void Cat::setLocation(std::pair<int, int> location)
{
	m_location = location;
	std::cout << "set location " << location.first << " " << location.second << std::endl;
	auto x = (location.first % 2 == 0) ? TOTAL_TILE_SIZE * location.second : TOTAL_TILE_SIZE * location.second + TILE_RADIUS;
	auto y = TOTAL_TILE_SIZE * location.first;
	m_triangle.setPosition(sf::Vector2f(x + BOARD_OFFSET_X, y + BOARD_OFFSET_Y));

	m_currLocation.x = x + BOARD_OFFSET_X;
	m_currLocation.y = y + BOARD_OFFSET_Y;
}

void Cat::setCurrLocation(std::pair<int, int> newDest)
{
	m_location = newDest;
	//std::cout << "set location " << newDest.first << " " << newDest.second << std::endl;
	auto x = (newDest.first % 2 == 0) ? TOTAL_TILE_SIZE * newDest.second : TOTAL_TILE_SIZE * newDest.second + TILE_RADIUS;
	auto y = TOTAL_TILE_SIZE * newDest.first;

	m_oldLocation = m_currLocation;
	m_currLocation.x = x + BOARD_OFFSET_X;
	m_currLocation.y = y + BOARD_OFFSET_Y;

	setDirection();
}

void Cat::update(float deltaTime)
{
	sf::Vector2f direction = { 0.0f, 0.0f };
	bool stop = true;
	if (!checkStop() && m_direction != NONE)
	{
		m_stop = false;
		direction = getCatDirection(deltaTime);
		//animation here
	}
	else
	{
		m_stop = true;
	}
	
	m_triangle.move(direction);
}

bool Cat::isContain(sf::Event event)
{
	return m_triangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

bool Cat::isStoped()
{
	return m_stop;
}

sf::Vector2f Cat::getCatDirection(float deltaTime)
{
	sf::Vector2f dir(0.0f, 0.0f);

	if(m_direction == L) //left
	{ 
		dir.x -= m_speed * deltaTime;
	}
	else if (m_direction == R) //right
	{
		dir.x += m_speed * deltaTime;
	}
	else if (m_direction == LU) //left up
	{
		dir.x -= (m_speed * deltaTime) / 2;
		dir.y -= m_speed * deltaTime;
	}
	else if (m_direction ==RU) //right up
	{
		dir.x += (m_speed * deltaTime) / 2;
		dir.y -= m_speed * deltaTime;
	}
	else if (m_direction == LD) //left down
	{
		dir.x -= (m_speed * deltaTime) / 2;
		dir.y += m_speed * deltaTime;
	}
	else if (m_direction == RD) //right down
	{
		dir.x += (m_speed * deltaTime) / 2;
		dir.y += m_speed * deltaTime;
	}

	return dir;
}

void Cat::setDirection()
{
	if (m_currLocation.x < m_oldLocation.x) //left
	{
		if (m_currLocation.y < m_oldLocation.y) //up
			m_direction = LU;
		else if (m_currLocation.y > m_oldLocation.y) //down
			m_direction = LD;
		else m_direction = L; //just left
	}
	else if (m_currLocation.x > m_oldLocation.x) //right
	{
		if (m_currLocation.y < m_oldLocation.y) //up
			m_direction = RU;
		else if (m_currLocation.y > m_oldLocation.y) //down
			m_direction = RD;
		else m_direction = R; //just right
	}
}

bool Cat::checkStop()
{
	if ((abs(m_triangle.getPosition().x - m_currLocation.x) < 10 &&
		abs(m_triangle.getPosition().y - m_currLocation.y) < 10))
	{
		m_triangle.setPosition(m_currLocation);
		m_direction = NONE;
		return true;
	}
	return false;
}
