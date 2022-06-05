#include "Game.hpp"
#include <iostream>

Game* Game::game_{ nullptr };

Game::Game(GameController* controller, sf::RenderWindow* mWindow, int entityTileSize, int mapTileSize)
: map("media/images/Map", sf::Vector2u(mapTileSize, mapTileSize), 28, 36),
  pacman(entityTileSize, "media/images/Pacman", 100, &map)
  //TimePerFrame(sf::seconds(1.f / 60.f))
{
	setController(controller);
	setWindow(mWindow);
}


Game* Game::createGame(GameController* controller, sf::RenderWindow* mWindow, int entityTileSize, int mapTileSize)
{
	if (game_ == nullptr)
	{
		std::cout << "creating game" << std::endl;
		game_ = new Game(controller, mWindow, entityTileSize, mapTileSize);
	}
	return game_;
}

void Game::render()
{
	getWindow()->clear();
	getWindow()->draw(map);
	getWindow()->draw(pacman);
	getWindow()->display();
}

void Game::update(sf::Time deltaTime)
{
	pacman.refreshImage();
	pacman.movePacman(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	    getController()->standBy();
	}
}
