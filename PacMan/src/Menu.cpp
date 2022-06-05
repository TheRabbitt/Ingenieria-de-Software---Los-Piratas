#include "Menu.hpp"
#include <iostream>

Menu* Menu::menu_{nullptr};

Menu::Menu(GameController* controller, sf::RenderWindow* mWindow)
	: pacmanImage(), imageUpdateTime(sf::seconds(0.07f)), selection(0),
	  imageCoord(0) //, TimePerFrame(sf::seconds(1.f / 60.f))
{
	// Carga las fuentes
	if (!loadTitleFont("media/font/pac-font.ttf"))
		throw std::runtime_error("Failed to load font pac-font.ttf");
	if (!loadMenuFont("media/font/namco.ttf"))
		throw std::runtime_error("Failed to load font namco.ttf");

	// Setea el gameController y la ventana
	setController(controller);
	setWindow(mWindow);

	// Carga la imagen pacman de seleccion y la posiciona
	pacmanImage.setTileSize(16);
	
	if (!pacmanImage.loadImage("media/images/Pacman16.png"))
		throw std::runtime_error("Failed to load Image ");
	pacmanImage.setPosition(120.f, 220.f);

	// Configura y posiciona el titulo
	titleText.setFont(titleFont);
	titleText.setString("PAC MAN");
	titleText.setCharacterSize(50);
	titleText.setPosition(sf::Vector2f(70.f,100.f));
	titleText.setFillColor(sf::Color::Yellow);
	titleText.setStyle(sf::Text::Bold);

	// Configura y posiciona opcion 1
	opt1.setFont(menuFont);
	opt1.setString("new game");
	opt1.setCharacterSize(15);
	opt1.setPosition(sf::Vector2f(150.f, 220.f));
	opt1.setFillColor(sf::Color::Yellow);
	opt1.setStyle(sf::Text::Bold);

	// Configura y posiciona opcion 2
	opt2.setFont(menuFont);
	opt2.setString("scores");
	opt2.setCharacterSize(15);
	opt2.setPosition(sf::Vector2f(150.f, 260.f));
	opt2.setFillColor(sf::Color::Yellow);

	// Configura y posiciona opcion 3
	opt3.setFont(menuFont);
	opt3.setString("config");
	opt3.setCharacterSize(15);
	opt3.setPosition(sf::Vector2f(150.f, 300.f));
	opt3.setFillColor(sf::Color::Yellow);
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

void Menu::refreshImage()
{
	pacmanImage.setQuadTextureCoords((float)imageCoord, 0.f);
}
void Menu::render()
{
	getWindow()->clear();
	getWindow()->draw(pacmanImage);
	getWindow()->draw(titleText);
	getWindow()->draw(opt1);
	getWindow()->draw(opt2);
	getWindow()->draw(opt3);
	getWindow()->display();
}

void Menu::update(sf::Time deltaTime)
{
	refreshImage();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pacmanImage.move(0.f, -40.f);
		selection--;
		if (selection < 0)
			selection = 2;
		if (pacmanImage.getPosition()[0].position.y < 220.f)
			pacmanImage.setPosition(120.f, 300.f);
		std::cout << "down pressed - selection = " << selection << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pacmanImage.move(0.f, 40.f);
		selection++;
		if (selection > 2)
			selection = 0;
		if (pacmanImage.getPosition()[0].position.y > 300.f)
			pacmanImage.setPosition(120.f, 220.f);
		std::cout << "up pressed - selection = " << selection << std::endl;
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		std::cout << "enter pressed - selection = " << selection << std::endl;
		if (selection == 0)
		getController()->standBy();
	}
	updateImageCoord();
}

void Menu::updateImageCoord()
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= imageUpdateTime.asSeconds())
	{
		imageCoord += 16;
		if (imageCoord > (16 * 5))
			imageCoord = 0;
		clock.restart();
	}
}

//Metodos exclusivos para testing, quitar para el release
sf::Text Menu::getTitleText() 
{
	return titleText;
}

sf::Text Menu::getOpt1()
{
	return opt1;
}

sf::Text Menu::getOpt2()
{
	return opt2;
}

sf::Text Menu::getOpt3()
{
	return opt3;
}

Entity Menu::getPacmanImage()
{
	return pacmanImage;
}