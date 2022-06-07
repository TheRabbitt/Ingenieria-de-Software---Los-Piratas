#ifndef INCLUDE_CHASE_ // guarda
#define INCLUDE_CHASE_

#include "Ghost.hpp"
#include "Map.hpp"
#include "PacMan.hpp"
#include "Strategy.hpp"

class Chase : public Strategy
{
public:
	Chase(Ghost*, PacMan*, Map*);
	//Chase(PacMan*, Map*);
	void act(sf::Time) override;
private:
	Map* map;
	PacMan* pacman;
	int resetDirection;
};

#endif /* INCLUDE_CHASE_ */