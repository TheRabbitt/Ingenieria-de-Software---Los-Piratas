//#include "PacMan.hpp"
//#include "Map.hpp"
#include "Menu.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	int mapTileSize = 16;
	sf::RenderWindow mWindow(sf::VideoMode(28 * mapTileSize, 36 * mapTileSize), "PacMan");
	Menu* menu = Menu::createMenu(&mWindow);
	menu->run();
}