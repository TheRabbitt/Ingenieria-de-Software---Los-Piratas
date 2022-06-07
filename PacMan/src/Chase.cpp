//#include <cstdlib> 
//#include <ctime> 
#include <random>
#include "SFML/Graphics.hpp"
#include "Chase.hpp"
#include <thread>


Chase::Chase(Ghost* g, PacMan* p, Map* m)
	: resetDirection(0)
{
	setGhost(g);
	pacman = p;
	map = m;
	//srand(time(NULL) - getpid());
}

void Chase::act(sf::Time deltaTime)
{
	if (resetDirection == 0)
	{
		resetDirection = 1;
		//int random = rand() % 4 + 1;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);
		int random = dist4(rng);

		if (random == 3)
			getGhost()->setVelocity(0, -getGhost()->getSpeed());
		if (random == 0)
			getGhost()->setVelocity(0, getGhost()->getSpeed());
		if (random == 1)
			getGhost()->setVelocity(-getGhost()->getSpeed(), 0);
		if (random == 2)
			getGhost()->setVelocity(getGhost()->getSpeed(), 0);
	}
	sf::Vector2f d = getGhost()->getVelocity();
	getGhost()->move(getGhost()->getVelocity() * deltaTime.asSeconds());
	// Detecta colision con paredes
	if (map->detectCollision(getGhost()->getPosition()[0].position.x, getGhost()->getPosition()[0].position.y))
	{
		getGhost()->move(-getGhost()->getVelocity() * deltaTime.asSeconds());
		resetDirection = 0;
	}
	//getGhost()->setVelocity(0.f, 0.f);

}