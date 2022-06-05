#include "Ghost.hpp"

Ghost::Ghost(int tileSize, const std::string& filename, float s, Map* m)
    : direction(0), imageCoord(0), updateTime(sf::seconds(0.07f)), map(m)
{
    setTileSize(tileSize);
    if (!loadImage(filename + std::to_string(tileSize) + ".png"))
        throw std::runtime_error("Failed to load Image " + filename);

    setPosition(218.f, 270.f);
    eyes.setScale(0.1, 0.1);
    eyes.setPosition(218.f, 270.f);
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

sf::Sprite* Ghost::getEyes()
{
    return &eyes;
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
        if (imageCoord > (getTileSize() * 5))
            imageCoord = 0;
        clock.restart();
    }
}


bool Ghost::loadImage(const std::string& filename)
{
    if (!getTexture().loadFromFile(filename))
        throw std::runtime_error("Texture failed to load Image");
    if (!eyesTexture.loadFromFile(filename, sf::IntRect(0, 32, getTileSize(), getTileSize())))
        throw std::runtime_error("Texture failed to load Image");
    eyes.setTexture(eyesTexture);
    return true;
}

