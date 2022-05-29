#ifndef INCLUDE_ENTITY_ // guarda
#define INCLUDE_ENTITY_

#include "SFML/Graphics.hpp"

class Entity
{
    public:
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vx, float vy);
        sf::Vector2f getVelocity();
        void setSpeed(float);
        float getSpeed();
    private:
        sf::Vector2f mVelocity;
        float speed;

};
#endif /* INCLUDE_ENTITY_ */