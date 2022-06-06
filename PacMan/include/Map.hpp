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

const int level[] =
{
	00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	02, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4,
	01,99,99,99,99,99,99,99,99,99,99,99,99, 8, 9,99,99,99,99,99,99,99,99,99,99,99,99, 5,
	01,99,15,17,17,16,99,15,17,17,17,16,99, 8, 9,99,15,17,17,17,16,99,15,17,17,16,99, 5,
	01,99, 8, 0, 0, 9,99, 8, 0, 0, 0, 9,99, 8, 9,99, 8, 0, 0, 0, 9,99, 8, 0, 0, 9,99, 5,
	01,99,13,18,18,14,99,13,18,18,18,14,99,13,14,99,13,18,18,18,14,99,13,18,18,14,99, 5,
	01,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, 5,
	01,99,15,17,17,16,99,15,16,99,15,17,17,17,17,17,17,16,99,15,16,99,15,17,17,16,99, 5,
	01,99,13,18,18,14,99, 8, 9,99,13,18,18,22,20,18,18,14,99, 8, 9,99,13,18,18,14,99, 5,
	01,99,99,99,99,99,99, 8, 9,99,99,99,99, 8, 9,99,99,99,99, 8, 9,99,99,99,99,99,99, 5,
	10,11,11,11,11,32,99, 8,19,17,17,16,99, 8, 9,99,15,17,17,21, 9,99,31,11,11,11,11,12,
	00, 0, 0, 0, 0, 1,99, 8,20,18,18,14,99,13,14,99,13,18,18,22, 9,99, 5, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 1,99, 8, 9,99,99,99,99,99,99,99,99,99,99, 8, 9,99, 5, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 1,99, 8, 9,99,27,11,11,35,35,11,11,28,99, 8, 9,99, 5, 0, 0, 0, 0, 0,
	03, 3, 3, 3, 3,34,99,13,14,99, 5, 0, 0, 0, 0, 0, 0, 1,99,13,14,99,33, 3, 3, 3, 3, 3,
	00, 0, 0, 0, 0, 0,99,99,99,99, 5, 0, 0, 0, 0, 0, 0, 1,99,99,99,99, 0, 0, 0, 0, 0, 0,
	11,11,11,11,11,32,99,15,16,99, 5, 0, 0, 0, 0, 0, 0, 1,99,15,16,99,31,11,11,11,11,11,
	00, 0, 0, 0, 0, 1,99, 8, 9,99,29, 3, 3, 3, 3, 3, 3,30,99, 8, 9,99, 5, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 1,99, 8, 9,99,99,99,99,99,99,99,99,99,99, 8, 9,99, 5, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 1,99, 8, 9,99,15,17,17,17,17,17,17,16,99, 8, 9,99, 5, 0, 0, 0, 0, 0,
	02, 3, 3, 3, 3,34,99,13,14,99,13,18,18,22,20,18,18,14,99,13,14,99,33, 3, 3, 3, 3, 4,
	01,99,99,99,99,99,99,99,99,99,99,99,99, 8, 9,99,99,99,99,99,99,99,99,99,99,99,99, 5,
	01,99,15,17,17,16,99,15,17,17,17,16,99, 8, 9,99,15,17,17,17,16,99,15,17,17,16,99, 5,
	01,99,13,18,22, 9,99,13,18,18,18,14,99,13,14,99,13,18,18,18,14,99, 8,20,18,14,99, 5,
	01,99,99,99, 8, 9,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, 8, 9,99,99,99, 5,
	23,17,16,99, 8, 9,99,15,16,99,15,17,17,17,17,17,17,16,99,15,16,99, 8, 9,99,15,17,25,
	24,18,14,99,13,14,99, 8, 9,99,13,18,18,22,20,18,18,14,99, 8, 9,99,13,14,99,13,18,26,
	01,99,99,99,99,99,99, 8, 9,99,99,99,99, 8, 9,99,99,99,99, 8, 9,99,99,99,99,99,99, 5,
	01,99,15,17,17,17,17,21,19,17,17,16,99, 8, 9,99,15,17,17,21,19,17,17,17,17,16,99, 5,
	01,99,13,18,18,18,18,18,18,18,18,14,99,13,14,99,13,18,18,18,18,18,18,18,18,14,99, 5,
	01,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, 5,
	10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,12,
	00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#endif /* INCLUDE_MAP_ */