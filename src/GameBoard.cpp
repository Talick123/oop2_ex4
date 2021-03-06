#include "GameBoard.h"


GameBoard::GameBoard(int numOfBlockedTiles)
	:m_board(numOfBlockedTiles), m_cat()
{
	placeCat();
	m_gameMoves.emplace_back(m_cat.getLocation(),&m_board.at(m_cat.getLocation().first, m_cat.getLocation().second));
	m_dataDisplay.setNumOfMovesText(m_gameMoves.size() - 1);
}

//-----------------------------------------------------------------

void GameBoard::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_cat.draw(window);
	m_dataDisplay.draw(window);
}

//-----------------------------------------------------------------

Btns GameBoard::handleClick(const sf::Event& event, GameStatus &status)
{
	Tile* tile = NULL;
	if (!isCatHere(event) && m_cat.isStoped() && m_board.handleClick(event, tile))
	{
		moveCat(status);
		m_gameMoves.emplace_back(m_cat.getLocation(), tile);
		m_dataDisplay.updateNumOfMovesString(m_gameMoves.size() - 1);
		return Btns::None;
	}
	return m_dataDisplay.handleClick(event); 
}

//-----------------------------------------------------------------

void GameBoard::handleHover(sf::Vector2f location)
{
	m_board.handleHover(location);
}

//-----------------------------------------------------------------

void GameBoard::moveCat(GameStatus &status)
{
	bool visited[SIZE][SIZE];
	memset(visited, false, sizeof visited);
	initVisited(visited);
	try {
		m_cat.move(visited);
	}
	catch (std::out_of_range& e)
	{
		status = GameStatus::Lose;
	}
	catch (std::domain_error& e)
	{
		status = GameStatus::Won;
	}
}

//-----------------------------------------------------------------

void GameBoard::initVisited(bool visited[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (m_board.at(i, j).isBlocked())
				visited[i][j] = true;
}

//-----------------------------------------------------------------

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

//-----------------------------------------------------------------

bool GameBoard::isCatHere(sf::Event event) const
{
	return m_cat.isContain(event);
}

//-----------------------------------------------------------------

void GameBoard::update(float deltaTime)
{
	m_cat.update(deltaTime);
}

//-----------------------------------------------------------------

void GameBoard::undo()
{
	if (m_gameMoves.size() <= 1 || !m_cat.isStoped()) return;

	if (m_gameMoves.back().second)
		m_gameMoves.back().second->unBlockTile();

	m_gameMoves.pop_back();
	m_cat.setCurrLocation(m_gameMoves.back().first);
	m_dataDisplay.updateNumOfMovesString(m_gameMoves.size()- 1);
}

//-----------------------------------------------------------------

void GameBoard::resetLevel()
{
	m_cat.setLocation(m_gameMoves.front().first);
	while (m_gameMoves.size() > 1)
	{
		m_gameMoves.back().second->unBlockTile();
		m_gameMoves.pop_back();
	}
	m_dataDisplay.updateNumOfMovesString(m_gameMoves.size() - 1);
}