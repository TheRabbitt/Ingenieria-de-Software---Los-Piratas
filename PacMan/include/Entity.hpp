#ifndef INCLUDE_ENTITY_ // guarda
#define INCLUDE_ENTITY_

#include "SFML/Graphics.hpp"

class Entity
{
    public:
        Entity();
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vx, float vy);
        void setSpeed(float);
        void setSpriteScale(sf::Vector2f);
        void setTextureImage(sf::Image, int, int, int, int);
        void setTileSize(int);
        sf::Vector2f getVelocity();
        float getSpeed();
        sf::Image getImage();
        sf::Sprite getSprite();
        sf::Texture getTexture();
        int getTileSize();
        void moveSprite(sf::Vector2f);
        bool loadImage(const std::string&);
    private:
        int tileSize;
        float speed;
        sf::Image mImage;
        sf::Sprite mSprite;
        sf::Texture mTexture;
        sf::Vector2f mVelocity;

};
#endif /* INCLUDE_ENTITY_ */