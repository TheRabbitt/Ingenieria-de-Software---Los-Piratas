#ifndef INCLUDE_DOTS_ // guarda
#define INCLUDE_DOTS_

#include "SFML/Graphics.hpp"
#include "Map.hpp"

class Dots
{
public:
    Dots(const int*, int, int);
    void setDots(const int*, int, int);
    sf::CircleShape** getDotsPtr();
    int getNumDots();
    void nullDotPtr(int);
    void resetDotsPtr();
private:
    static const int numDots{ 1 }; //288
    sf::CircleShape dots[numDots];
    sf::CircleShape* dotsPtr[numDots]{nullptr};
};

#endif /* INCLUDE_DOTS_ */
