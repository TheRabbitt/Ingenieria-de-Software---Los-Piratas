#ifndef INCLUDE_GHOST_ // guarda
#define INCLUDE_GHOST_

#include "SFML/Graphics.hpp"
#include "Chase.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "PacMan.hpp"
#include "Strategy.hpp"


enum class GhostName { Blinky, Pinky, Inky, Clyde };

class Ghost : public Entity
{
public:
    Ghost(GhostName, int, const std::string&, float, PacMan*, Map*);;
    //void moveGhost(sf::Time);
    void update(int, sf::Time);
    void updateImageCoord();
    void refreshImage(int);
    void setDirection(int);
    void setStrategy(Strategy*);
    int getDirection();
    Strategy* getStrategy();
private:
    GhostName name;
    sf::Clock clock;
    sf::Time updateTime;
    int direction;
    int imageCoord;
    Map* map;
    PacMan* pacman;
    Strategy* strategy;
    
};

#endif /* INCLUDE_GHOSTS_ */