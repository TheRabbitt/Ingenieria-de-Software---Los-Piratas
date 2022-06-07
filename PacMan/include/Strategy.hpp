#ifndef INCLUDE_STRATEGY_ // guarda
#define INCLUDE_STRATEGY_

#include "SFML/Graphics.hpp"

class Ghost;

class Strategy
{
public:
	virtual void act(sf::Time);
	void setGhost(Ghost*);
	Ghost* getGhost();
private:
	Ghost* ghost;
};

#endif /* INCLUDE_STRATEGY_ */