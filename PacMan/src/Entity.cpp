#include "Entity.hpp"

Entity::Entity()
	: speed(0), mImage(), mSprite(), mTexture(), tileSize(16)
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

void Entity::setSpriteScale(sf::Vector2f scale)
{
	mSprite.setScale(scale);
}

void Entity::setTextureImage(sf::Image img, int left, int top , int width, int height)
{
	if (!mTexture.loadFromImage(img, sf::IntRect(left, top, width, height)))
		throw std::runtime_error("Texture failed to load Image");
}

void Entity::setTileSize(int size)
{
	tileSize = size;
}

sf::Vector2f Entity::getVelocity()
{
	return mVelocity;
}

sf::Image Entity::getImage()
{
	return mImage;
}

sf::Sprite Entity::getSprite()
{
	return mSprite;
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

void Entity::moveSprite(sf::Vector2f d)
{
	mSprite.move(d);
}

bool Entity::loadImage(const std::string& filename)
{
	if (!mImage.loadFromFile(filename))
		throw std::runtime_error("Failed to load Image" + filename);
	if (!mTexture.loadFromImage(mImage, sf::IntRect(0, 0, tileSize, tileSize)))
		throw std::runtime_error("Texture failed to load Image");
	mSprite.setTexture(mTexture);
	mSprite.setPosition(100.f, 100.f);
	return true;
}