#include "GameController.h"



GameController::GameController()
	: m_currPage(Page::GameBoard), m_numOfLevelsComplete(0)
{
	initPages();
}

void GameController::startGame()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "Circle the Cat", sf::Style::Close);
	//GameBoard gameBoard(14); //TODO: const
	GameBoard gameBoard(25); //TODO: const

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
		Btns clicked = gameBoard.handleClick(event);
		switch (clicked)
		{
		case Btns::NewGame:
			startNewLevel(gameBoard);
			break;
		case Btns::Undo:
		case Btns::Reset:
		default:
			break;
		}
	}
	case sf::Event::MouseMoved:
	{
		sf::Vector2f location = window.mapPixelToCoords(
			{ event.mouseMove.x, event.mouseMove.y });
			gameBoard.handleHover(location);
		break;
	}
	case sf::Event::KeyReleased:
	{
		if (event.key.code == sf::Keyboard::W)
		{
			updateWin(gameBoard);
		}
		else if (event.key.code == sf::Keyboard::L)
			updateLose(gameBoard);
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
			//create new level or restart level
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
	m_levelComplete.setFillColor(sf::Color(179, 255, 179));
	//m_levelComplete.setTexture(Resources::instance().getLevelCompleted());

	m_levelLost = sf::RectangleShape(sf::Vector2f(float(WINDOW_LENGTH), float(WINDOW_HEIGHT)));
	m_levelLost.setFillColor(sf::Color(102, 0, 0));
	//m_levelLost.setTexture(Resources::instance().getLevelLost());
}

void GameController::updateWin(GameBoard& gameBoard)
{
	//gameBoard.resetMoves();
	m_currPage = Page::UserWin;
	m_numOfLevelsComplete += 1;
	startNewLevel(gameBoard);

	//create new level or restart level
}

void GameController::updateLose(GameBoard& gameBoard)
{
	gameBoard.resetMoves();
	m_currPage = Page::UserLose;
	//create new level or restart level
}

void GameController::startNewLevel(GameBoard& gameBoard)
{
	gameBoard = GameBoard(generateLevelDifficulty());
}

unsigned int GameController::generateLevelDifficulty() const
{
	int x = 14 <= m_numOfLevelsComplete > 0 ? 4 : 14 - m_numOfLevelsComplete;
	int r = (x) + rand() % 3;
	return r < 4 ? 4 : r;
}
