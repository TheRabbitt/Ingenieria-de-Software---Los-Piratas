#ifndef INCLUDE_PACMAN_ // guarda
#define INCLUDE_PACMAN_

#include "SFML/Graphics.hpp"
#include "Entity.hpp"

constexpr auto DOWN = 1;
constexpr auto LEFT = 2;
constexpr auto RIGHT = 3;
constexpr auto UP = 4;

class PacMan : public Entity
{
    public:
        PacMan(float, const std::string&);;
        void move(sf::Time);
        void updateImageCoord();
        bool refreshImage();
        void setDirection(int);
        int getDirection();
    private:
        sf::Clock clock;
        sf::Time updateTime;
        int direction;
        int imageCoord;
};

#endif /* INCLUDE_PACMAN_ */