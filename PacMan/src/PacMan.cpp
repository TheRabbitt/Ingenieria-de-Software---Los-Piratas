#include "PacMan.hpp"

PacMan::PacMan(float s, const std::string& filename)
: direction(RIGHT), image(0), updateTime(sf::seconds(0.07f))
{
    loadImage("media/images/Pacman16.png");
    setSpeed(s);
}

sf::Sprite PacMan::getSprite()
{
    return pacmanSprite;
}

bool PacMan::loadImage(const std::string& filename)
{
    if (!pacmanImage.loadFromFile(filename))
    {
        return false;
    }
    if (!pacmanTexture.loadFromImage(pacmanImage, sf::IntRect(0, 0, 16, 16)))
    {
        return false;
    }
    pacmanSprite.setTexture(pacmanTexture);
    pacmanSprite.setPosition(100.f, 100.f);
    sf::Vector2f scale(2.f, 2.f);
    pacmanSprite.setScale(scale);
    return true;
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
    pacmanSprite.move(getVelocity() * deltaTime.asSeconds());
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
    {
        if (!pacmanTexture.loadFromImage(pacmanImage, sf::IntRect(image, 48, 16, 16)))
        {
            return false;
        }
    }
    if (direction == LEFT)
    {
        if (!pacmanTexture.loadFromImage(pacmanImage, sf::IntRect(image, 32, 16, 16)))
        {
            return false;
        }
    }
    if (direction == RIGHT)
    {
        if (!pacmanTexture.loadFromImage(pacmanImage, sf::IntRect(image, 0, 16, 16)))
        {
            return false;
        }
    }
    if (direction == UP)
    {
        if (!pacmanTexture.loadFromImage(pacmanImage, sf::IntRect(image, 16, 16, 16)))
        {
            return false;
        }
    }
    updateImage();
    pacmanSprite.setTexture(pacmanTexture);
    return true;
}

void PacMan::updateImage()
{
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() >= updateTime.asSeconds())
    {
        image += 16;
        if (image > 80)
            image = 0;
        clock.restart();
    }
}
    