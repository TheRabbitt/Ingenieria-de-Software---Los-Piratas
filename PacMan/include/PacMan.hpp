#ifndef INCLUDE_PACMAN_ // guarda
#define INCLUDE_PACMAN_

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Map.hpp"

constexpr auto DOWN = 0;
constexpr auto LEFT = 1;
constexpr auto RIGHT = 2;
constexpr auto UP = 3;

class PacMan : public Entity
{
public:
    PacMan(int, const std::string&, float, Map*);;
    void movePacman(sf::Time);
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

#endif /* INCLUDE_PACMAN_ */