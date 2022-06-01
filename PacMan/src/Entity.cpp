#include "Entity.hpp"

Entity::Entity()
	:quad(sf::Quads, 4), speed(0), mImage(), mTexture(), tileSize(16)
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

void Entity::setSpeed(float s)
{
	speed = s;
}

void Entity::setTileSize(int size)
{
	tileSize = size;
}

void Entity::setQuadCoords(float dx, float dy)
{
	quad[0].texCoords = sf::Vector2f(dx, dy);
	quad[1].texCoords = sf::Vector2f(dx+(float)tileSize, dy);
	quad[2].texCoords = sf::Vector2f(dx+(float)tileSize, dy+(float)tileSize);
	quad[3].texCoords = sf::Vector2f(dx, dy+(float)tileSize);
}

sf::Vector2f Entity::getVelocity()
{
	return mVelocity;
}

sf::Image Entity::getImage()
{
	return mImage;
}


sf::Texture Entity::getTexture()
{
	return mTexture;
}

float Entity::getSpeed()
{
	return speed;
}

int Entity::getTileSize()
{
	return tileSize;
}

void Entity::move(sf::Vector2f d)
{
	quad[0].position.x += d.x;
	quad[0].position.y += d.y;
	quad[1].position.x += d.x;
	quad[1].position.y += d.y;
	quad[2].position.x += d.x;
	quad[2].position.y += d.y;
	quad[3].position.x += d.x;
	quad[3].position.y += d.y;
}

bool Entity::loadImage(const std::string& filename)
{
	if (!mTexture.loadFromFile(filename))
		throw std::runtime_error("Texture failed to load Image");
	// Posicion de la textura en el mapa
	quad[0].position = sf::Vector2f(100.f, 100.f);
	quad[1].position = sf::Vector2f((float)(100 + tileSize), 100.f);
	quad[2].position = sf::Vector2f((float)(100+tileSize), (float)(100+tileSize));
	quad[3].position = sf::Vector2f(100.f, (float)(100 + tileSize));
	// Coordenadas de la textura en el textureSet
	quad[0].texCoords = sf::Vector2f(0.f, 0.f);
	quad[1].texCoords = sf::Vector2f((float)tileSize, 0.f);
	quad[2].texCoords = sf::Vector2f((float)tileSize, (float)tileSize);
	quad[3].texCoords = sf::Vector2f(0.f, (float)tileSize);
	return true;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	// Aplica la textura a dibujar
	states.texture = &mTexture;
	// Dibuja la textura en el quad
	target.draw(quad, states);
}