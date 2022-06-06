#include "Menu.hpp"
#include <iostream>
#include <fstream>
#include <string>

Menu* Menu::menu_{nullptr};

Menu::Menu(GameController* controller, sf::RenderWindow* mWindow)
	: pacmanImage(), imageUpdateTime(sf::seconds(0.07f)), 
	  selection(0),imageCoord(0), numWindow(0), numScores(3) //, TimePerFrame(sf::seconds(1.f / 60.f))
{
	// Setea el gameController y la ventana
	setController(controller);
	setWindow(mWindow);
	loadScores();

	// Carga la imagen pacman de seleccion y la posiciona
	pacmanImage.setTileSize(16);
	if (!pacmanImage.loadImage("media/images/Pacman16.png"))
		throw std::runtime_error("Failed to load Image ");
	pacmanImage.setPosition(120.f, 220.f);

	// Configura y posiciona el titulo menu principal
	titleText.setFont(*getTitleFont());
	titleText.setString("PAC MAN");
	titleText.setCharacterSize(50);
	titleText.setPosition(sf::Vector2f(70.f,100.f));
	titleText.setFillColor(sf::Color::Yellow);
	titleText.setStyle(sf::Text::Bold);

	// Configura y posiciona el titulo tabla scores
	scoreText.setFont(*getTitleFont());
	scoreText.setString("HIGH SCORES");
	scoreText.setCharacterSize(40);
	scoreText.setPosition(sf::Vector2f(45.f, 100.f));
	scoreText.setFillColor(sf::Color::Yellow);
	scoreText.setStyle(sf::Text::Bold);

	// Configura y posiciona opcion 1
	opt0.setFont(*getMenuFont());
	opt0.setString("new game");
	opt0.setCharacterSize(15);
	opt0.setPosition(sf::Vector2f(150.f, 220.f));
	opt0.setFillColor(sf::Color::Yellow);
	opt0.setStyle(sf::Text::Bold);

	// Configura y posiciona opcion 2
	opt1.setFont(*getMenuFont());
	opt1.setString("scores");
	opt1.setCharacterSize(15);
	opt1.setPosition(sf::Vector2f(150.f, 260.f));
	opt1.setFillColor(sf::Color::Yellow);

	// Configura y posiciona opcion 3
	opt2.setFont(*getMenuFont());
	opt2.setString("config");
	opt2.setCharacterSize(15);
	opt2.setPosition(sf::Vector2f(150.f, 300.f));
	opt2.setFillColor(sf::Color::Yellow);
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

void Menu::loadScores()
{
	// Carga los 3 Top Scores
	std::fstream file;
	std::string name;
	std::string score;
	file.open("scores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	int i = 0;
	while (file >> name >> score)
	{
		//std::getline(file, line);
		scores.push_back(sf::Text());
		scores[i].setFont(*getMenuFont());
		scores[i].setString(name + " " + score);
		scores[i].setCharacterSize(10);
		scores[i].setPosition(sf::Vector2f(150.f, 220.f + i * 40.f));
		scores[i].setFillColor(sf::Color::Yellow);
		i++;
	}
	file.close();
}

void Menu::refreshImage()
{
	pacmanImage.setQuadTextureCoords((float)imageCoord, 0.f);
}
void Menu::render()
{
	if (numWindow == 0)
	{
		getWindow()->clear();
		getWindow()->draw(pacmanImage);
		getWindow()->draw(titleText);
		getWindow()->draw(opt0);
		getWindow()->draw(opt1);
		getWindow()->draw(opt2);
		getWindow()->display();
	}
	else if ((numWindow == 1))
	{
		getWindow()->clear();
		getWindow()->draw(scoreText);
		for (sf::Text i : scores)
		{
			getWindow()->draw(i);
		}
		getWindow()->display();
	}
}

void Menu::update(sf::Time deltaTime)
{
	if (numWindow == 0)
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
			if (selection == 1)
			{
				numWindow = 1;
				loadScores();
			}
		}
		updateImageCoord();
	}
	else if ((numWindow == 1))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
		    numWindow = 0;
		}
	}

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

sf::Text Menu::getOpt0()
{
	return opt0;
}

sf::Text Menu::getOpt1()
{
	return opt1;
}

sf::Text Menu::getOpt2()
{
	return opt2;
}

Entity Menu::getPacmanImage()
{
	return pacmanImage;
}