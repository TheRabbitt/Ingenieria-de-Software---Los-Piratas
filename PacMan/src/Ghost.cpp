#include "Ghost.hpp"

Ghost::Ghost(int tileSize, const std::string& filename, float s, Map* m)
    : direction(0), imageCoord(0), updateTime(sf::seconds(0.15f)), map(m)
{
    setTileSize(tileSize);
    if (!loadImage(filename + std::to_string(tileSize) + ".png"))
        throw std::runtime_error("Failed to load Image " + filename);
    setPosition(218.f, 270.f);
    setSpeed(s);
}

void Ghost::setDirection(int d)
{
    direction = d;
}

int Ghost::getDirection()
{
    return direction;
}


void Ghost::refreshImage()
{
   setQuadTextureCoords((float)imageCoord, (float)getTileSize() * 0);
}

void Ghost::updateImageCoord()
{
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= updateTime.asSeconds())
    {
        imageCoord += getTileSize();
        if (imageCoord > (getTileSize() * 3))
            imageCoord = 0;
        clock.restart();
    }
}


