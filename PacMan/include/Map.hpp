#ifndef INCLUDE_MAP_ // guarda
#define INCLUDE_MAP_

#include "SFML/Graphics.hpp"

class Map : public sf::Drawable, public sf::Transformable
{
public:
    Map();
    Map(const std::string&, sf::Vector2u, unsigned int, unsigned int);
    bool load(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);
    bool detectCollision(float, float);
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
private:
    sf::VertexArray mVertices;
    sf::Texture textureSet;
};

#endif /* INCLUDE_MAP_ */