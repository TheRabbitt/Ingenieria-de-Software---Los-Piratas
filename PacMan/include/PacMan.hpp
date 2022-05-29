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
        PacMan(float, const std::string&);
        sf::Sprite getSprite();
        //void move(int, sf::Time);
        void move(sf::Time);
        void updateImage();
        bool loadImage(const std::string&);
        bool refreshImage();
        void setDirection(int);
        int getDirection();
    private:
        sf::Clock clock;
        sf::Image pacmanImage;
        sf::Sprite pacmanSprite;
        sf::Texture pacmanTexture;
        sf::Time updateTime;
        int direction;
        int image;
};

#endif /* INCLUDE_PACMAN_ */