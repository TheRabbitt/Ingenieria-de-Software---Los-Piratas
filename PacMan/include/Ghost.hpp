#ifndef INCLUDE_GHOST_ // guarda
#define INCLUDE_GHOST_

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Map.hpp"

class Ghost : public Entity
{
public:
    Ghost(int, const std::string&, float, Map*);;
    //void moveGhost(sf::Time);
    void updateImageCoord();
    void refreshImage();
    void setDirection(int);
    int getDirection();
private:
    sf::Clock clock;
    sf::Time updateTime;
    int direction;
    int imageCoord;
    Map* map;
    
};

#endif /* INCLUDE_GHOSTS_ */