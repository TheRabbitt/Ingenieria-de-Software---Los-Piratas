#ifndef INCLUDE_DOTS_ // guarda
#define INCLUDE_DOTS_

#include "SFML/Graphics.hpp"
#include "Map.hpp"

class Dots
{
public:
    Dots(const int*, int, int);
    void setDots(const int*, int, int);
    void nullDotPtr(int);
    sf::CircleShape** getDotsPtr();

    //sf::CircleShape dots[240];  
private:
    sf::CircleShape dots[240];
    sf::CircleShape* dotsPtr[240];
};

#endif /* INCLUDE_DOTS_ */