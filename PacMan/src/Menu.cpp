#include "Menu.hpp"
#include <iostream>

Menu* Menu::menu_{nullptr};

Menu::Menu(GameController* controller, sf::RenderWindow* mWindow)
	: selection(0)//, TimePerFrame(sf::seconds(1.f / 60.f))
{
	if (!loadTitleFont("media/font/pac-font.ttf"))
		throw std::runtime_error("Failed to load font pac-font.ttf");
	if (!loadMenuFont("media/font/namco.ttf"))
		throw std::runtime_error("Failed to load font namco.ttf");
	setController(controller);
	setWindow(mWindow);

	titleText.setFont(titleFont);
	titleText.setString("PAC MAN");
	titleText.setCharacterSize(50);
	titleText.setPosition(sf::Vector2f(70.f,100.f));
	titleText.setFillColor(sf::Color::Yellow);
	titleText.setStyle(sf::Text::Bold);

	opt1.setFont(menuFont);
	opt1.setString("new game");
	opt1.setCharacterSize(15);
	opt1.setPosition(sf::Vector2f(150.f, 220.f));
	opt1.setFillColor(sf::Color::Yellow);
	opt1.setStyle(sf::Text::Bold);

	opt2.setFont(menuFont);
	opt2.setString("scores");
	opt2.setCharacterSize(15);
	opt2.setPosition(sf::Vector2f(150.f, 260.f));
	opt2.setFillColor(sf::Color::Yellow);
	//opt2.setStyle(sf::Text::Bold);

	opt3.setFont(menuFont);
	opt3.setString("config");
	opt3.setCharacterSize(15);
	opt3.setPosition(sf::Vector2f(150.f, 300.f));
	opt3.setFillColor(sf::Color::Yellow);
	//opt3.setStyle(sf::Text::Bold);
}

Menu* Menu::createMenu(GameController* controller, sf::RenderWindow* mWindow)
{
	if (menu_ == nullptr)
	{
		std::cout << "creating menu" << std::endl;
		menu_ = new Menu(controller, mWindow);
	}
	return menu_;
}

bool Menu::loadMenuFont(const std::string& filename)
{
	if (!menuFont.loadFromFile(filename))
		throw std::runtime_error("Failed to load menu font");
	return true;
}

bool Menu::loadTitleFont(const std::string& filename)
{
	if (!titleFont.loadFromFile(filename))
		throw std::runtime_error("Failed to load title font");
	return true;
}

void Menu::render()
{
	getWindow()->clear();
	getWindow()->draw(titleText);
	getWindow()->draw(opt1);
	getWindow()->draw(opt2);
	getWindow()->draw(opt3);
	getWindow()->display();
}

void Menu::update(sf::Time deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		selection++;
		if (selection > 3)
			selection = 0;
		std::cout << "down pressed - selection = " << selection << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		selection--;
		if (selection < 0)
			selection = 3;
		std::cout << "up pressed - selection = " << selection << std::endl;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		std::cout << "enter pressed - selection = " << selection << std::endl;
		if (selection == 0)
		getController()->standBy();
	}
}