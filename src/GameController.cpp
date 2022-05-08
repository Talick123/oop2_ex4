#include "GameController.h"


GameController::GameController()
	: m_currPage(Page::GameBoard), m_numOfLevelsComplete(0), m_playerStatus(GameStatus::Playing)
{
	initPages();
}

void GameController::startGame()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), GAME_TITLE, sf::Style::Close);
	setGameIcon(window);
	GameBoard gameBoard(MAX_BLOCK_TILES);

	while (window.isOpen())
	{
		processEvents(window, gameBoard);
		update(gameBoard);
		render(window, gameBoard);
	}
}

void GameController::processEvents(sf::RenderWindow &window, GameBoard &gameBoard)
{
	if (auto event = sf::Event{}; window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		switch (m_currPage)
		{
		case Page::GameBoard:
			gameBoardProcesEvents(event,window, gameBoard);
			break;
		case Page::UserWin:
		case Page::UserLose:
		default:
			emmptyPageProcessEvents(event); //TODO: empty
			break;
		}
	}
}

void GameController::gameBoardProcesEvents(sf::Event& event, sf::RenderWindow& window, GameBoard& gameBoard)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	{
		Btns clicked = gameBoard.handleClick(event , m_playerStatus);
		checkBtnClick(clicked, gameBoard);
		break;
	}
	case sf::Event::MouseMoved:
	{
		sf::Vector2f location = window.mapPixelToCoords(
			{ event.mouseMove.x, event.mouseMove.y });
			gameBoard.handleHover(location);
		break;
	}
	default:
		break;
	}
}

void GameController::emmptyPageProcessEvents(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
		if (event.key.code == sf::Keyboard::Space)
		{
			m_currPage = Page::GameBoard;
			m_playerStatus = GameStatus::Playing;
		}
}

void GameController::update(GameBoard& gameBoard)
{
	sf::Time deltaTime = m_timer.restart();
	gameBoard.update(deltaTime.asSeconds());
}

void GameController::render(sf::RenderWindow& window, GameBoard& gameBoard)
{
	window.clear(sf::Color(224, 235, 229));
	drawCurrPage(window, gameBoard);
	window.display();
}

void GameController::drawCurrPage(sf::RenderWindow& window, GameBoard& gameBoard)
{
	switch (m_currPage)
	{
	case Page::GameBoard:
		gameBoard.draw(window);
		break;
	case Page::UserWin:
		window.draw(m_levelComplete);
		break;
	case Page::UserLose:
		window.draw(m_levelLost);
		break;
	default:
		break;
	}
}

void GameController::initPages()
{
	m_levelComplete = sf::RectangleShape(sf::Vector2f(float(WINDOW_LENGTH), float(WINDOW_HEIGHT)));
	//m_levelComplete.setFillColor(sf::Color(179, 255, 179));
	m_levelComplete.setTexture(Resources::instance().getWinPageTexture());

	m_levelLost = sf::RectangleShape(sf::Vector2f(float(WINDOW_LENGTH), float(WINDOW_HEIGHT)));
	//m_levelLost.setFillColor(sf::Color(102, 0, 0));
	m_levelLost.setTexture(Resources::instance().getLosePageTexture());
}

void GameController::updateWin(GameBoard& gameBoard)
{
	m_currPage = Page::UserWin;
	m_numOfLevelsComplete += 1;
	startNewLevel(gameBoard);
}

void GameController::updateLose(GameBoard& gameBoard)
{
	gameBoard.resetLevel();
	m_currPage = Page::UserLose;
}

void GameController::startNewLevel(GameBoard& gameBoard)
{
	gameBoard = GameBoard(generateLevelDifficulty());
}

void GameController::changeGameStatus(GameBoard &gameBoard)
{
	switch (m_playerStatus)
	{
	case GameStatus::Won:
		updateWin(gameBoard);
		break;
	case GameStatus::Lose:
		updateLose(gameBoard);
		break;
	case GameStatus::Playing:
	default:
		break;
	}
}

void GameController::checkBtnClick(Btns clicked, GameBoard & gameBoard)
{
	switch (clicked)
	{
	case Btns::NewGame:
		startNewLevel(gameBoard);
		break;
	case Btns::Undo:
		gameBoard.undo();
		break;
	case Btns::Reset:
		gameBoard.resetLevel();
		break;
	case Btns::None:
		changeGameStatus(gameBoard);
		break;
	default:
		break;
	}
}

unsigned int GameController::generateLevelDifficulty() const
{
	int x = 14 <= m_numOfLevelsComplete > 0 ? 4 : 14 - m_numOfLevelsComplete;
	int r = (x) + rand() % 3;
	return r < 4 ? 4 : r;
}

void GameController::setGameIcon(sf::RenderWindow& window)
{
	sf::Image image = (*Resources::instance().getGameIcon());
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

}
