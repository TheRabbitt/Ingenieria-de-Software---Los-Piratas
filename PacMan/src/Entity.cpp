#include "Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity()
{
	return mVelocity;
}

void Entity::setSpeed(float s)
{
	speed = s;
}

float Entity::getSpeed()
{
	return speed;
}