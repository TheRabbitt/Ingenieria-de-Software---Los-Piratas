#include "PacMan.hpp"

PacMan::PacMan(float s, const std::string& filename)
: direction(RIGHT), imageCoord(0), updateTime(sf::seconds(0.07f))
{
    if(!loadImage(filename))
        throw std::runtime_error("Failed to load Image" + filename);
    setSpeed(s);
    sf::Vector2f scale(2.f, 2.f);
    getSprite()->setScale(scale);
}

void PacMan::move(sf::Time deltaTime)
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
    sf::Vector2f v = getVelocity();
    getSprite()->move(getVelocity() * deltaTime.asSeconds());
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
        setTextureImage(*getImage(), imageCoord, 48, 16, 16);
    if (direction == LEFT)
        setTextureImage(*getImage(), imageCoord, 32, 16, 16);
    if (direction == RIGHT)
        setTextureImage(*getImage(), imageCoord, 0, 16, 16);
    if (direction == UP)
        setTextureImage(*getImage(), imageCoord, 16, 16, 16);
    updateImageCoord();
    getSprite()->setTexture(*getTexture());
    return true;
}

void PacMan::updateImageCoord()
{
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= updateTime.asSeconds())
    {
        imageCoord += 16;
        if (imageCoord > 80)
            imageCoord = 0;
        clock.restart();
    }
}
    