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
        void setTextureImage(sf::Image, int, int, int, int);
        sf::Vector2f getVelocity();
        float getSpeed();
        sf::Image* getImage();
        sf::Sprite* getSprite();
        sf::Texture* getTexture();
        bool loadImage(const std::string&);
    private:
        sf::Vector2f mVelocity;
        float speed;
        sf::Image* mImage;
        sf::Sprite* mSprite;
        sf::Texture* mTexture;

};
#endif /* INCLUDE_ENTITY_ */