#include "Game.hpp"

Game::Game()
: mWindow(sf::VideoMode(640, 680), "PacMan") , pacman(100, "media/images/Pacman16.png"),
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
	mWindow.draw(*pacman.getSprite());
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
	pacman.move(deltaTime);
}
