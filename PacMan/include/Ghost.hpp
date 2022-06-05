#ifndef INCLUDE_GHOST_ // guarda
#define INCLUDE_GHOST_

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Map.hpp"


class Ghost : public Entity
{
public:
    Ghost(int, const std::string&, float, Map*);;
    //void moveGhosts(sf::Time);
    void updateImageCoord();
    void refreshImage();
    void setDirection(int);
    int getDirection();
    bool loadImage(const std::string&) override;
    sf::Sprite* Ghost::getEyes();
    


private:
    sf::Clock clock;
    sf::Time updateTime;
    sf::Sprite eyes;
    sf::Texture eyesTexture;
    int direction;
    int imageCoord;
    Map* map;
    
};

#endif /* INCLUDE_GHOSTS_ */