#include "PacMan.hpp"

PacMan::PacMan(int tileSize, const std::string& filename, float s)
: direction(RIGHT), imageCoord(0), updateTime(sf::seconds(0.07f))
{
    setTileSize(tileSize);
    if(!loadImage(filename + std::to_string(tileSize) + ".png"))
        throw std::runtime_error("Failed to load Image " + filename);
    setSpeed(s);
    //sf::Vector2f scale(1.f, 1.f);
}

void PacMan::movePacman(sf::Time deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        setDirection(UP);
        setVelocity(0,-getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        setDirection(DOWN);
        setVelocity(0,getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        setDirection(LEFT);
        setVelocity(-getSpeed(),0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        setDirection(RIGHT);
        setVelocity(getSpeed(),0);
    }
    sf::Vector2f d = getVelocity();
    move(getVelocity()*deltaTime.asSeconds());
    setVelocity(0.f, 0.f);
}

void PacMan::setDirection(int d)
{
    direction = d;
}

int PacMan::getDirection()
{
    return direction;
}

bool PacMan::refreshImage()
{
    if (direction == DOWN)
        setQuadCoords((float)imageCoord, (float)getTileSize()*3);
    if (direction == LEFT)
        setQuadCoords((float)imageCoord, (float)getTileSize()*2);
    if (direction == RIGHT)
        setQuadCoords((float)imageCoord, (float)getTileSize()*0);
    if (direction == UP)
        setQuadCoords((float)imageCoord, (float)getTileSize()*1);
    updateImageCoord();
    return true;
}

void PacMan::updateImageCoord()
{
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= updateTime.asSeconds())
    {
        imageCoord += getTileSize();
        if (imageCoord > (getTileSize()*5))
            imageCoord = 0;
        clock.restart();
    }
}
    