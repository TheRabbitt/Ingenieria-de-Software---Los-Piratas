#ifndef INCLUDE_ENTITY_ // guarda
#define INCLUDE_ENTITY_

#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
    public:
        Entity();
        void setVelocity(sf::Vector2f);
        void setVelocity(float, float);
        void setQuadCoords(float, float);
        void setSpeed(float);
        void setTileSize(int);
        sf::Vector2f getVelocity();
        float getSpeed();
        sf::Image getImage();
        sf::Texture getTexture();
        int getTileSize();
        void move(sf::Vector2f);
        bool loadImage(const std::string&);
        void draw(sf::RenderTarget&, sf::RenderStates) const;
    private:
        int tileSize;
        float speed;
        sf::Image mImage;
        sf::Texture mTexture;
        sf::Vector2f mVelocity;
        sf::VertexArray quad;

};
#endif /* INCLUDE_ENTITY_ */