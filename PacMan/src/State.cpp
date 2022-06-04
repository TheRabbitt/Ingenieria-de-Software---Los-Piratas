#include "State.hpp"

void State::setWindow(sf::RenderWindow* w)
{
	mWindow = w;
}

void State::setController(GameController* c)
{
	controller = c;
}

GameController* State::getController()
{
	return controller;
}

sf::RenderWindow* State::getWindow()
{
	return mWindow;
}

void State::processEvents()
{
	sf::Event event{};
	while (mWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow->close();
			break;
		default:
			break;
		}
	}
}

void State::render()
{
}


void State::update(sf::Time)
{
}
