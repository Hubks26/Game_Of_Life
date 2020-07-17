#include "Game.h"

const sf::Time Game::m_timePerFrame = sf::seconds(0.1);

Game::Game()
: m_window(sf::VideoMode(600, 600), "Game of Life")
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		
		while (timeSinceLastUpdate > m_timePerFrame)
		{
			timeSinceLastUpdate -= m_timePerFrame;
			update();
		}

		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Game::update()
{
	m_grid.update();
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_grid);
	m_window.display();
}

/*void Game::handlePlayerInput()
{
    m_isGameStarted = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}*/
