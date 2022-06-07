#include "Strategy.hpp"

void Strategy::act(sf::Time deltaTime)
{
}

void Strategy::setGhost(Ghost* g)
{
	ghost = g;
}

Ghost* Strategy::getGhost()
{
	return ghost;
}