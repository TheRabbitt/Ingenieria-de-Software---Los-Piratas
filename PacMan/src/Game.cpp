#include "Game.hpp"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

Game* Game::game_{ nullptr };

Game::Game(GameController* controller, sf::RenderWindow* mWindow, int entityTileSize, int mapTileSize)
	: map("media/images/Map", sf::Vector2u(mapTileSize, mapTileSize), 28, 36),
	dots(level, 28, 36),
	pacman(entityTileSize, "media/images/Pacman", 100, &map),
	ghost(entityTileSize, "media/images/Ghost", 100, &map),
	actScore(0), dotsLeft(dots.getNumDots()), gameWon(false)
{
	setController(controller);
	setWindow(mWindow);

	std::fstream file;
	std::string name;
	std::string score;
	file.open("scores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	file >> name >> score;
	highScore.setFont(*getMenuFont());
	highScore.setString("high score " + score);
	highScore.setCharacterSize(8);
	highScore.setPosition(sf::Vector2f(10.f, 30.f));
	highScore.setFillColor(sf::Color::Yellow);
	try {
		hScore = std::stoi(score);
	}
	catch (const std::exception& e)
	{
		(void)e;
		hScore = 0;
	}
	file.close();

	actualScore.setFont(*getMenuFont());
	actualScore.setCharacterSize(8);
	actualScore.setPosition(sf::Vector2f(250.f, 30.f));
	actualScore.setFillColor(sf::Color::Yellow);
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

void Game::processScores()
{
	std::array<std::string, 5> names{""};
	std::array<int, 5> scores{0};
	std::fstream file;
	std::string name;
	std::string score;
	file.open("scores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	int i,j,s, numScores = 0;
	bool empty = true;
	i = 0;
	while(file >> name >> score)
	{
		if (!name.empty())
		{
			empty = false;
			numScores++;
			names[i] = name;
			try {
				s = std::stoi(score);
				scores[i] = s;
			}
			catch (const std::exception& e)
			{
				(void)e;
				s = 0;
			}
		}
		i++;
	}
	file.close();
	if (empty)
	{
		names[0] = "nn";
		scores[0] = actScore;
	}
	else
	{
		if (numScores == 5)
		{
			if (actScore > scores[numScores - 1])
			{
				names[numScores - 1] = "nn";
				scores[numScores - 1] = actScore;
			}
		}
		else
		{
			if (actScore != scores[numScores - 1])
			{
				names[numScores] = "nn";
				scores[numScores] = actScore;
				numScores++;
			}
		}
	}
	for (i = 0; i < numScores - 1; i++) {
		for (j = 0; j < numScores - i - 1; j++) {
			if (scores[j] < scores[j + 1]) {
				int tempScore = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = tempScore;
				std::string tempName = names[j];
				names[j] = names[j + 1];
				names[j + 1] = tempName;
			}
		}
	}
	file.open("scores.txt", std::fstream::in | std::fstream::out | std::ofstream::trunc);
	for (i = 0; i < 5; i++)
	{
		if (!names[i].empty() && scores[i] != 0)
		{
			file << names[i] << " " << scores[i] << "\n";
		}
	}
	file.close();
}

void Game::render()
{
	if (!gameWon)
	{
		int i;
		getWindow()->clear();
		getWindow()->draw(map);
		getWindow()->draw(highScore);
		getWindow()->draw(actualScore);
		int numDots = dots.getNumDots();
		for (i = 0; i < numDots; i++)
		{
			if (dots.getDotsPtr()[i] != nullptr)
				getWindow()->draw(*dots.getDotsPtr()[i]);
		}
		getWindow()->draw(pacman);
		getWindow()->draw(ghost);
		getWindow()->display();
	}
	if (gameWon)
	{
		getWindow()->clear();
		getWindow()->draw(map);
		getWindow()->draw(highScore);
		getWindow()->draw(actualScore);
		getWindow()->draw(pacman);
		getWindow()->draw(ghost);
		getWindow()->display();
	}
}

void Game::resetGame()
{
	gameWon = false;
	pacman.setPosition(50.f, 65.f);
	dots.resetDotsPtr();
	actScore = 0;
	dotsLeft = dots.getNumDots();
}

void Game::update(sf::Time deltaTime)
{
	if (!gameWon)
	{
		int i;
		pacman.refreshImage();
		ghost.refreshImage();
		ghost.updateImageCoord();
		pacman.movePacman(deltaTime);
		int numDots = dots.getNumDots();
		for (i = 0; i < numDots; i++)
		{
			if (dots.getDotsPtr()[i] != nullptr)
			{
				if (pacman.getPosition()[0].position.x < dots.getDotsPtr()[i]->getPosition().x + 10 &&
					pacman.getPosition()[0].position.x + 10 > dots.getDotsPtr()[i]->getPosition().x &&
					pacman.getPosition()[0].position.y < dots.getDotsPtr()[i]->getPosition().y + 10 &&
					pacman.getPosition()[0].position.y + 10 > dots.getDotsPtr()[i]->getPosition().y)
				{
					dots.nullDotPtr(i);
					actScore += 10;
					dotsLeft--;
					if (dotsLeft <= 0)
						gameWon = true;
					actualScore.setString("score: " + std::to_string(actScore));
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			resetGame();
			getController()->standBy();
		}
	}
	else if (gameWon)
	{
		processScores();
		std::this_thread::sleep_for(std::chrono::seconds(4));
		resetGame();
		getController()->standBy();
	}
}
