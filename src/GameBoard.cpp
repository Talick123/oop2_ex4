#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board(), /*m_cat(sf::Vector2f(35.f, 0.f))*/ m_cat(std::pair<int,int>(3, 4)) , m_numOfMoves(0)
{
	setNumOfMovesText();

	//UNDO BUTTON 
	//Noga: maybe because we have 2 buttons we can create tiny tiny tinyyyy class to them - with sprite member and handle click ? :)
	setBtns();
}

//-----------------------------------------------------------------

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
	window.draw(m_numOfMovesTitleText);
	window.draw(m_undo);
}

//-----------------------------------------------------------------

void GameBoard::handleClick(const sf::Event& event)
{
	if (m_board.handleClick(event))
	{
		moveCat();
		m_numOfMoves++;
		updateNumOfMovesString();
		//m_cat.handleClick();
	}

	//check which part of gameboard event happened
	//handle event in part of board
}

void GameBoard::moveCat()
{
	bool visited[SIZE][SIZE];				//mat of visited tiles
	std::pair<int, int> prev[SIZE][SIZE];	//mat of parents of each tile
	std::queue<std::pair<int, int>> q;		//queue of neighbours
	std::pair<int, int> end_tile;

	std::pair<int, int> NO_PARENT{ -1,-1 };
	memset(visited, false, sizeof visited); //setting all to not visited
	
	//init prev
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			prev[i][j] = NO_PARENT;
		}
	}

	bool reached_end = false;				//we have not found the end yet


	q.push(m_cat.getLocation());			//setting starting location as cats location
	visited[q.front().first][q.front().second] = true;	//setting cats location as visited

	while (!q.empty())
	{
		std::pair<int, int> tile = q.front(); //get tile from queue
		q.pop();							  //remove from queue
		int x = tile.first;
		int y = tile.second;
		std::cout << "curr tile x = " << x << "\ncurr tile y = " << y << std::endl;

		//if current tile 
		if (x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1)
		{
			std::cout << "end reached\n";
			reached_end = true;
			end_tile = tile;
			break;
		}

		//checking neighbours
		for (int i = 0; i < 6; i++)
		{

			int adjX = (x % 2 == 0) ? x + D_VEC_ROW_E[i] : x + D_VEC_ROW_O[i];
			int adjY = (x % 2 == 0) ? y + D_VEC_COL_E[i] : y + D_VEC_COL_O[i];

			if (isValid(visited[adjX][adjY], adjX, adjY))
			{
				q.push({ adjX, adjY });
				visited[adjX][adjY] = true;
				prev[adjX][adjY] = tile;

			}
		}
	}
	if (reached_end == true)
	{
		//bfs successful 
		std::vector<std::pair<int, int>> path;

		for (auto curr = end_tile; curr != NO_PARENT; curr = prev[curr.first][curr.second])
		{
			//std::cout << "parent of curr is: " << 
			path.push_back(curr);
		}
		if (path.back() == m_cat.getLocation())
		{
			path.pop_back();
			m_cat.setLocation(path.back());
		}

	}

}
bool GameBoard::isValid(bool visited, int row, int col)
{
	if (row < 0 || col < 0 || row >= SIZE || col >= SIZE
		|| visited || m_board.at(row, col).isBlocked())
		return false;
	return true;
}
//-----------------------------------------------------------------

void GameBoard::resetMoves()
{
	m_numOfMoves = 0;
	updateNumOfMovesString(); //TODO: ?
}

//-----------------------------------------------------------------

void GameBoard::setNumOfMovesText()
{
	m_numOfMovesTitleText.setFont(*(Resources::instance().getFont()));
	float offsetX = BOARD_AREA_LENGTH + 10;
	m_numOfMovesTitleText.setPosition(sf::Vector2f(offsetX, 70.f));
	m_numOfMovesTitleText.setFillColor(sf::Color(41, 86, 79));
	m_numOfMovesTitleText.setCharacterSize(30);
	updateNumOfMovesString();
}

//-----------------------------------------------------------------

void GameBoard::setBtns()
{
	//set undo button
	setUndoBtn();
	//set reset level button
	setResetLevelBtn();
}

//-----------------------------------------------------------------

void GameBoard::setUndoBtn()
{
	m_undo.setTexture(*(Resources::instance().getUndoTexture()));
	m_undo.setPosition(sf::Vector2f(BOARD_AREA_LENGTH + 50, 200));
	m_undo.setScale(sf::Vector2f(0.15, 0.15));
}

//-----------------------------------------------------------------

void GameBoard::setResetLevelBtn()
{
	//TODO: you kknow... etc etc
}

//-----------------------------------------------------------------

void GameBoard::updateNumOfMovesString()
{
	m_numOfMovesTitleText.setString("Number of Moves:\n" + std::to_string(m_numOfMoves));
}

