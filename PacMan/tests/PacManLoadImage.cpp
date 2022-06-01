#include "PacMan.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	std::cout << "Creating Window\n";
	sf::RenderWindow mWindow(sf::VideoMode(640, 680), "Test");
	std::cout << "Window Creation succeded\n";
	std::cout << "Creating PacMan\n";
	PacMan pacman(32, "media/images/Pacman", 100);
	std::cout << "PacMan Creation succeded\n";
	int i = 3;
	while (i > 0)
	{
		sf::Event event;
		mWindow.pollEvent(event);
		mWindow.clear();
		mWindow.draw(pacman.getSprite());
		mWindow.display();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		i--;
	}
	std::cout << "Closing window\n";
	mWindow.close();
	std::cout << "Test Passed\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
