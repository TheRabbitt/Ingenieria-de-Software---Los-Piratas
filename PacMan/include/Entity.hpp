#ifndef INCLUDE_ENTITY_ // guarda
#define INCLUDE_ENTITY_

#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
public:
    Entity();
    void setPosition(float x, float y);
    void setQuadTextureCoords(float, float);
    void setSpeed(float);
    void setTileSize(int);
    void setVelocity(sf::Vector2f);
    void setVelocity(float, float);
    sf::Image getImage();
    sf::VertexArray getPosition();
    float getSpeed();
    sf::Texture getTexture();
    int getTileSize();
    sf::Vector2f getVelocity();
    void move(sf::Vector2f);
    bool loadImage(const std::string&);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    //void printPosition(); //debug
private:
    int tileSize;
    float speed;
    sf::Image mImage;
    sf::Texture mTexture;
    sf::Vector2f mVelocity;
    sf::VertexArray quad;
};
#endif /* INCLUDE_ENTITY_ */