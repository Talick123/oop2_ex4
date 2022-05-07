#include "Cat.h"
//
//Cat::Cat(sf::Vector2f position)
//	:m_triangle(sf::CircleShape(30.f, 3))
//{
//	m_triangle.setPosition(position);
//	m_triangle.setFillColor(sf::Color(194, 113, 86));
//}

Cat::Cat()
	:m_triangle(sf::Vector2f((float)TILE_RADIUS*2.2, (float)TILE_RADIUS * 2.2)),
	m_animation(Resources::instance().getCatSpriteSheet(), sf::Vector2u(4, 16), 0.2f), m_speed(60),
	m_direction(Direction::NONE), m_stop(true)
{
	m_triangle.setTexture(Resources::instance().getCatSpriteSheet());
	//setLocation(location);
	//setCurrLocation(location);
	//m_triangle.setFillColor(sf::Color(194, 113, 86));
	//m_triangle.setScale(2, 2);
}

//-----------------------------------------------------------------

void Cat::draw(sf::RenderWindow& window)
{
	window.draw(m_triangle);
}

//-----------------------------------------------------------------

void Cat::move(bool visited[][SIZE])
{
	std::pair<int, int> prev[SIZE][SIZE];	//mat of parents of each tile
	std::pair<int, int> end_tile;
	std::vector<std::pair<int, int>> path;
	visited[m_location.first][m_location.second] =  true; //setting cats location as visited

	//init prev
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			prev[i][j] = NO_PARENT;

	if (BFS(end_tile, prev, visited))
	{
		if (end_tile == m_location)
			throw std::out_of_range("");
		
		createPath(end_tile, prev, path);
		moveAccordingly(path);
	}
	else
		findPosInEnclosure(prev);
}
//-----------------------------------------------------------------

void Cat::findPosInEnclosure(std::pair<int, int> prev[][SIZE])
{
	std::vector<std::pair<int, int>> path, temp_path;
	int longest_path = 0;

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			temp_path.clear();
			if (prev[row][col] != NO_PARENT)
			{
				std::pair<int, int> curr_end(row, col);

				createPath(curr_end, prev, temp_path);

				if (temp_path.size() > longest_path)
				{
					longest_path = temp_path.size();
					path = temp_path;
				}
			}
		}
	}
	if (longest_path <= 0)
		throw std::domain_error("");
	moveAccordingly(path);
}

//-----------------------------------------------------------------

void Cat::createPath(std::pair<int, int> end_tile, std::pair<int, int> prev[][SIZE], std::vector<std::pair<int, int>>& path)
{
	for (auto curr = end_tile; curr != NO_PARENT; curr = prev[curr.first][curr.second])
		path.push_back(curr);
}

//-----------------------------------------------------------------

void Cat::moveAccordingly(std::vector<std::pair<int, int>> path)
{
	if (path.back() == m_location)
	{
		path.pop_back();
		setCurrLocation(path.back());
	}
}
//-----------------------------------------------------------------

bool Cat::BFS(std::pair<int, int>& end_tile, std::pair<int, int> prev[][SIZE], bool visited[][SIZE])
{
	std::queue<std::pair<int, int>> q;		//queue of neighbours

	q.push(m_location);			//setting starting location as cats location

	while (!q.empty())
	{
		std::pair<int, int> tile = q.front(); //get tile from queue
		q.pop();							  //remove from queue
		int x = tile.first, y = tile.second;

		//if current tile is end
		if (x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1)
		{
			end_tile = tile;
			return true;
		}
		//checking neighbours
		for (int i = 0; i < 6; i++)
		{
			int adjX = (x % 2 == 0) ? x + D_VEC_ROW_E[i] : x + D_VEC_ROW_O[i];
			int adjY = (x % 2 == 0) ? y + D_VEC_COL_E[i] : y + D_VEC_COL_O[i];

			if (isValid(adjX, adjY) && !visited[adjX][adjY])
			{
				q.push({ adjX, adjY });
				visited[adjX][adjY] = true;
				prev[adjX][adjY] = tile;
			}
		}
	}
	return false;
}

//-----------------------------------------------------------------

bool Cat::isValid(int row, int col)
{
	if (row < 0 || col < 0 || row >= SIZE || col >= SIZE)
		return false;
	return true;
}

//-----------------------------------------------------------------

std::pair<int, int> Cat::getLocation()const
{
	return m_location;
}

//-----------------------------------------------------------------

void Cat::setLocation(std::pair<int, int> location)
{
	m_location = location;
	auto x = (location.first % 2 == 0) ? TOTAL_TILE_SIZE * location.second : TOTAL_TILE_SIZE * location.second + TILE_RADIUS;
	auto y = TOTAL_TILE_SIZE * location.first;
	m_triangle.setPosition(sf::Vector2f(x + BOARD_OFFSET_X, y + BOARD_OFFSET_Y));

	m_currLocation.x = x + BOARD_OFFSET_X;
	m_currLocation.y = y + BOARD_OFFSET_Y;
}

//-----------------------------------------------------------------

void Cat::setCurrLocation(std::pair<int, int> newDest)
{
	m_location = newDest;
	auto x = (newDest.first % 2 == 0) ? TOTAL_TILE_SIZE * newDest.second : TOTAL_TILE_SIZE * newDest.second + TILE_RADIUS;
	auto y = TOTAL_TILE_SIZE * newDest.first;

	m_oldLocation = m_currLocation;
	m_currLocation.x = x + BOARD_OFFSET_X;
	m_currLocation.y = y + BOARD_OFFSET_Y;

	setDirection();
}

//-----------------------------------------------------------------

void Cat::update(float deltaTime)
{
	m_animation.update(int(m_direction), 4, deltaTime);
	m_triangle.setTextureRect(m_animation.m_uvRect);

	sf::Vector2f direction = { 0.0f, 0.0f };
	//bool stop = true;
	if (!checkStop() && m_direction != Direction::NONE)
	{
		m_stop = false;
		direction = getCatDirection(deltaTime);
		//update animation here
	}
	else
	{
		m_stop = true;
	}
	
	m_triangle.move(direction);
}

//-----------------------------------------------------------------

bool Cat::isContain(sf::Event event)
{
	return m_triangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

//-----------------------------------------------------------------

bool Cat::isStoped()
{
	return m_stop;
}

//-----------------------------------------------------------------

sf::Vector2f Cat::getCatDirection(float deltaTime)
{
	sf::Vector2f dir(0.0f, 0.0f);

	if(m_direction == Direction::L) //left
	{ 
		dir.x -= m_speed * deltaTime;
	}
	else if (m_direction == Direction::R) //right
	{
		dir.x += m_speed * deltaTime;
	}
	else if (m_direction == Direction::LU) //left up
	{
		dir.x -= (m_speed * deltaTime) / 2;
		dir.y -= m_speed * deltaTime;
	}
	else if (m_direction == Direction::RU) //right up
	{
		dir.x += (m_speed * deltaTime) / 2;
		dir.y -= m_speed * deltaTime;
	}
	else if (m_direction == Direction::LD) //left down
	{
		dir.x -= (m_speed * deltaTime) / 2;
		dir.y += m_speed * deltaTime;
	}
	else if (m_direction == Direction::RD) //right down
	{
		dir.x += (m_speed * deltaTime) / 2;
		dir.y += m_speed * deltaTime;
	}

	return dir;
}

//-----------------------------------------------------------------

void Cat::setDirection()
{
	if (m_currLocation.x < m_oldLocation.x) //left
	{
		if (m_currLocation.y < m_oldLocation.y) //up
			m_direction = Direction::LU;
		else if (m_currLocation.y > m_oldLocation.y) //down
			m_direction = Direction::LD;
		else m_direction = Direction::L; //just left
	}
	else if (m_currLocation.x > m_oldLocation.x) //right
	{
		if (m_currLocation.y < m_oldLocation.y) //up
			m_direction = Direction::RU;
		else if (m_currLocation.y > m_oldLocation.y) //down
			m_direction = Direction::RD;
		else m_direction = Direction::R; //just right
	}
}

//-----------------------------------------------------------------

bool Cat::checkStop()
{
	if ((abs(m_triangle.getPosition().x - m_currLocation.x) < 10 &&
		abs(m_triangle.getPosition().y - m_currLocation.y) < 10))
	{
		m_triangle.setPosition(m_currLocation);
		m_direction = Direction::NONE;
		return true;
	}
	return false;
}
