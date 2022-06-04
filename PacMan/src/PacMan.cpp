#include "PacMan.hpp"

PacMan::PacMan(int tileSize, const std::string& filename, float s, Map* m)
 : direction(RIGHT), imageCoord(0), updateTime(sf::seconds(0.07f)), map(m)
{
    setTileSize(tileSize);
    if(!loadImage(filename + std::to_string(tileSize) + ".png"))
        throw std::runtime_error("Failed to load Image " + filename);
    setPosition(50.f, 65.f);
    setSpeed(s);
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
    move(getVelocity() * deltaTime.asSeconds());
    // Detecta colision con paredes
    if (map->detectCollision(getPosition()[0].position.x, getPosition()[0].position.y))
        move(-getVelocity() * deltaTime.asSeconds());
    // Vuelve por el otro lado al cruzar el tunel
    if (getPosition()[1].position.x <= -16)
        setPosition(448.f, getPosition()[0].position.y);
    if (getPosition()[0].position.x > 448)
        setPosition(0.f, getPosition()[0].position.y);
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
        setQuadTextureCoords((float)imageCoord, (float)getTileSize()*3);
    if (direction == LEFT)
        setQuadTextureCoords((float)imageCoord, (float)getTileSize()*2);
    if (direction == RIGHT)
        setQuadTextureCoords((float)imageCoord, (float)getTileSize()*0);
    if (direction == UP)
        setQuadTextureCoords((float)imageCoord, (float)getTileSize()*1);
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