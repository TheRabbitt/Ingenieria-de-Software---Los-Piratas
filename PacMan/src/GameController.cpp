#include "GameController.hpp"
#include <iostream>

GameController* GameController::gameController_{ nullptr };

GameController::GameController(int entityTileSize, int mapTileSize)
	: entityTileSize(entityTileSize), mapTileSize(mapTileSize),
	  mWindow(sf::VideoMode(28 * mapTileSize, 36 * mapTileSize), "PacMan"),
	  timePerFrame(sf::seconds(1.f / 60.f))
{
	state = Menu::createMenu(this, &mWindow);
}

GameController* GameController::createGameController(int entityTileSize, int mapTileSize)
{
	if (gameController_ == nullptr)
		gameController_ = new GameController(entityTileSize, mapTileSize);
	return gameController_;
}

void GameController::setPlayer(std::string p)
{
	player = p;
}

void GameController::setState(State* s)
{
	state = s;
}

std::string GameController::getPlayer()
{
	return player;
}

void GameController::init()
{
	setTimePerFrame(5.f);
	state = Menu::createMenu(this, &mWindow);
}


void GameController::standBy()
{
	std::cout << "in standby()" << std::endl;
	if (typeid(Menu).hash_code() == typeid(*state).hash_code())
	{
		setTimePerFrame(1.f);
		state = Game::createGame(this, &mWindow, entityTileSize, mapTileSize);
	}
	else if (typeid(Game).hash_code() == typeid(*state).hash_code())
	{
		setTimePerFrame(4.f);
		state = Menu::createMenu(this, &mWindow);
	}
}

void GameController::run()
{
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		state->processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			state->processEvents();
			state->update(timePerFrame);
		}
		state->render();
	}
}

void GameController::setTimePerFrame(float t)
{
	timePerFrame = sf::seconds(t / 60.f);
}