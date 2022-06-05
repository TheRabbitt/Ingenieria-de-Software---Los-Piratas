#include "Game.hpp"
#include <iostream>

Game* Game::game_{ nullptr };

Game::Game(GameController* controller, sf::RenderWindow* mWindow, int entityTileSize, int mapTileSize)
: map("media/images/Map", sf::Vector2u(mapTileSize, mapTileSize), 28, 36),
  dots(level, 28, 36),
  pacman(entityTileSize, "media/images/Pacman", 100, &map),
  ghost(entityTileSize, "media/images/Ghost", 100, &map)
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
	int i;
	getWindow()->clear();
	getWindow()->draw(map);
	for (i = 0; i < 240; i++)
	{
		if (dots.getDotsPtr()[i] != nullptr)
		getWindow()->draw(*dots.getDotsPtr()[i]);
	}
	getWindow()->draw(pacman);
	getWindow()->draw(ghost);
	getWindow()->display();
}

void Game::update(sf::Time deltaTime)
{
	int i;
	pacman.refreshImage();
	ghost.refreshImage();
	ghost.updateImageCoord();
	pacman.movePacman(deltaTime);
	
	for (i = 0; i < 240; i++)
	{
		if (dots.getDotsPtr()[i] != nullptr)
		{
			if (pacman.getPosition()[0].position.x < dots.getDotsPtr()[i]->getPosition().x + 10 &&
				pacman.getPosition()[0].position.x + 10 > dots.getDotsPtr()[i]->getPosition().x &&
				pacman.getPosition()[0].position.y < dots.getDotsPtr()[i]->getPosition().y +10 &&
				pacman.getPosition()[0].position.y + 10 > dots.getDotsPtr()[i]->getPosition().y)
			{
				dots.nullDotPtr(i);
				std::cout << "freeing dot" << std::endl;
			}
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	    getController()->standBy();
	}
}
