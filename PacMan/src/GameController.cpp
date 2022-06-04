#include "GameController.hpp"
#include <iostream>

GameController* GameController::gameController_{ nullptr };

//Constructor privado
GameController::GameController(int entityTileSize, int mapTileSize)
	: entityTileSize(entityTileSize), mapTileSize(mapTileSize),
	  mWindow(sf::VideoMode(28 * mapTileSize, 36 * mapTileSize), "PacMan"),
	  TimePerFrame(sf::seconds(1.f / 60.f))
{
	state = Menu::createMenu(this, &mWindow);
}

//Constructor public
GameController* GameController::createGameController(int entityTileSize, int mapTileSize)
{
	if (gameController_ == nullptr)
		gameController_ = new GameController(entityTileSize, mapTileSize);
	return gameController_;
}

void GameController::setState(State* s)
{
	state = s;
}

void GameController::init()
{
	state = Menu::createMenu(this, &mWindow);
}


void GameController::standBy()
{
	std::cout << "in standby()" << std::endl;
	if (typeid(Menu).hash_code() == typeid(*state).hash_code())
		state = Game::createGame(this, &mWindow, entityTileSize, mapTileSize);
	else if (typeid(Game).hash_code() == typeid(*state).hash_code())
		state = Menu::createMenu(this, &mWindow);
}

void GameController::run()
{
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		state->processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			state->processEvents();
			state->update(TimePerFrame);
		}
		state->render();
	}
}