#include "GameBoard.h"

GameBoard::GameBoard()
	:m_board(10), /*m_cat(sf::Vector2f(35.f, 0.f))*/ m_cat(std::pair<int, int>(5, 4)), m_numOfMoves(0)
{
	m_dataDisplay.setNumOfMovesText(m_numOfMoves); // 0 = num of moves
}

GameBoard::GameBoard(int numOfBlockedTiles)
	:m_board(numOfBlockedTiles), /*m_cat(sf::Vector2f(35.f, 0.f))*/ m_cat(std::pair<int,int>(5, 4)) , m_numOfMoves(0)
{
	placeCat();
	m_dataDisplay.setNumOfMovesText(m_numOfMoves);
}

//-----------------------------------------------------------------

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
	m_dataDisplay.draw(window);
}

//-----------------------------------------------------------------

Btns GameBoard::handleClick(const sf::Event& event)
{
	if (!isCatHere(event) && m_cat.isStoped() && m_board.handleClick(event))
	{
		moveCat();
		m_numOfMoves++;
		m_dataDisplay.updateNumOfMovesString(m_numOfMoves);
		return Btns::None;
		//m_cat.handleClick();
	}
	return m_dataDisplay.handleClick(event); 
	
	//check which part of gameboard event happened
	//handle event in part of board
}

void GameBoard::handleHover(sf::Vector2f location)
{
	m_board.handleHover(location);
}

//-----------------------------------------------------------------

void GameBoard::moveCat()
{
	std::pair<int, int> NO_PARENT{ -1,-1 };
	std::pair<int, int> prev[SIZE][SIZE];	//mat of parents of each tile
	std::pair<int, int> end_tile;

	//init prev
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			prev[i][j] = NO_PARENT;
		}
	}

	if (BFS(end_tile, prev))
	{
		//if end_tile == m_cat.getLocation() then u lost
		std::vector<std::pair<int, int>> path;
		
		for (auto curr = end_tile; curr != NO_PARENT; curr = prev[curr.first][curr.second])
		{
			path.push_back(curr);
		}
		if (path.back() == m_cat.getLocation())
		{
			path.pop_back();
			//m_cat.setLocation(path.back());

			m_cat.setCurrLocation(path.back());

		}

	}
	//else move cat accordingly (maybe we reached end)
}

//-----------------------------------------------------------------

bool GameBoard::BFS(std::pair<int, int>& end_tile, std::pair<int, int> prev[][SIZE])
{

	std::pair<int, int> NO_PARENT{ -1,-1 };
	bool visited[SIZE][SIZE];				//mat of visited tiles
	std::queue<std::pair<int, int>> q;		//queue of neighbours

	memset(visited, false, sizeof visited); //setting all to not visited

	q.push(m_cat.getLocation());			//setting starting location as cats location
	visited[q.front().first][q.front().second] = true;	//setting cats location as visited

	while (!q.empty())
	{
		std::pair<int, int> tile = q.front(); //get tile from queue
		q.pop();							  //remove from queue
		int x = tile.first;
		int y = tile.second;


		//if current tile 
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

bool GameBoard::isValid(int row, int col)
{
	if (row < 0 || col < 0 || row >= SIZE || col >= SIZE
		 || m_board.at(row, col).isBlocked())
		return false;
	return true;
}

void GameBoard::placeCat()
{
	int counter = 0;
	while (counter < 1) { //looping while 3 distinct cells are not set to true
		int rRow = 3 + rand() % 5;
		int rCol = 3 + rand() % 5;

		if (!m_board.at(rRow, rCol).isBlocked()) 
		{
			m_cat.setLocation({ rRow, rCol });
			m_cat.setCurrLocation({ rRow, rCol });
			counter++; //increasing the counter only when a new cell is set to true
		}
	}
}
bool GameBoard::isCatHere(sf::Event event)
{
	return m_cat.isContain(event);
}
//-----------------------------------------------------------------

void GameBoard::resetMoves()
{
	m_numOfMoves = 0;
	m_dataDisplay.updateNumOfMovesString(0); //TODO: ?
}

void GameBoard::update(float deltaTime)
{
	m_cat.update(deltaTime);
}

//-----------------------------------------------------------------

//
//void GameBoard::moveCat()
//{
//	bool visited[SIZE][SIZE];				//mat of visited tiles
//	std::pair<int, int> prev[SIZE][SIZE];	//mat of parents of each tile
//	std::queue<std::pair<int, int>> q;		//queue of neighbours
//	std::pair<int, int> end_tile;
//
//	memset(visited, false, sizeof visited); //setting all to not visited
//	std::pair<int, int> NO_PARENT{ -1,-1 };
//	
//	//init prev
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//		{
//			prev[i][j] = NO_PARENT;
//		}
//	}
//
//	bool reached_end = false;				//we have not found the end yet
//
//
//	q.push(m_cat.getLocation());			//setting starting location as cats location
//	visited[q.front().first][q.front().second] = true;	//setting cats location as visited
//
//	while (!q.empty())
//	{
//		std::pair<int, int> tile = q.front(); //get tile from queue
//		q.pop();							  //remove from queue
//		int x = tile.first;
//		int y = tile.second;
//		
//
//		//if current tile 
//		if (x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1)
//		{
//			reached_end = true;
//			end_tile = tile;
//			break;
//		}
//
//		//checking neighbours
//		for (int i = 0; i < 6; i++)
//		{
//
//			int adjX = (x % 2 == 0) ? x + D_VEC_ROW_E[i] : x + D_VEC_ROW_O[i];
//			int adjY = (x % 2 == 0) ? y + D_VEC_COL_E[i] : y + D_VEC_COL_O[i];
//
//			if (isValid(adjX, adjY) && !visited[adjX][adjY])
//			{
//				q.push({ adjX, adjY });
//				visited[adjX][adjY] = true;
//				prev[adjX][adjY] = tile;
//
//			}
//		}
//	}
//	if (reached_end == true)
//	{
//		//bfs successful 
//		std::vector<std::pair<int, int>> path;
//
//		for (auto curr = end_tile; curr != NO_PARENT; curr = prev[curr.first][curr.second])
//		{
//			//std::cout << "parent of curr is: " << 
//			path.push_back(curr);
//		}
//		if (path.back() == m_cat.getLocation())
//		{
//			path.pop_back();
//			m_cat.setLocation(path.back());
//		}
//
//	}
//
//}