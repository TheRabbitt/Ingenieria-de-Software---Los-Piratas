#include "State.hpp"

State::State()
{
	// Carga las fuentes
	if (!loadTitleFont("media/font/pac-font.ttf"))
		throw std::runtime_error("Failed to load font pac-font.ttf");
	if (!loadMenuFont("media/font/namco.ttf"))
		throw std::runtime_error("Failed to load font namco.ttf");
}

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

sf::Font* State::getMenuFont()
{
	return &menuFont;
}

sf::Font* State::getTitleFont()
{
	return &titleFont;
}

sf::RenderWindow* State::getWindow()
{
	return mWindow;
}

bool State::loadMenuFont(const std::string& filename)
{
	if (!menuFont.loadFromFile(filename))
		throw std::runtime_error("Failed to load menu font");
	return true;
}

bool State::loadTitleFont(const std::string& filename)
{
	if (!titleFont.loadFromFile(filename))
		throw std::runtime_error("Failed to load title font");
	return true;
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
