#include "Game.hpp"

Game::Game(int entityTileSize, int mapTileSize)
: mWindow(sf::VideoMode(28 * mapTileSize, 36 * mapTileSize), "PacMan"), pacman(entityTileSize, "media/images/Pacman", 100),
  map("media/images/Map", sf::Vector2u(mapTileSize, mapTileSize), 28, 36),
  TimePerFrame(sf::seconds(1.f / 60.f))
{
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				break;
		}
	}
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(map);
	mWindow.draw(pacman);
	mWindow.display();
}

void Game::run()
{
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::update(sf::Time deltaTime)
{
	pacman.refreshImage();
	pacman.movePacman(deltaTime);
}
