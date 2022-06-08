#include "Ghost.hpp"
#include "PacMan.hpp"
#include "Map.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	Map map("media/images/Map", sf::Vector2u(16, 16), 28, 36);
	std::cout << "Creating Window\n";
	sf::RenderWindow mWindow(sf::VideoMode(448, 608), "Test");
	std::cout << "Window Creation succeded\n";
	std::cout << "Creating PacMan\n";
	PacMan pacman(16, "media/images/Pacman", 100, &map);
	Ghost ghostB(GhostName::Blinky, 16, "media/images/Ghost", 100, &pacman, &map);
	Ghost ghostP(GhostName::Pinky, 16, "media/images/Ghost", 100, &pacman, &map);
	Ghost ghostI(GhostName::Inky, 16, "media/images/Ghost", 100, &pacman, &map);
	Ghost ghostC(GhostName::Clyde, 16, "media/images/Ghost", 100, &pacman, &map);
	ghostB.refreshImage(0);
	ghostP.refreshImage(1);
	ghostI.refreshImage(2);
	ghostC.refreshImage(3);

	int i = 3;
	while (i > 0)
	{
		sf::Event event;
		mWindow.pollEvent(event);
		mWindow.clear();
		mWindow.draw(ghostB);
		mWindow.draw(ghostP);
		mWindow.draw(ghostC);
		mWindow.draw(ghostI);
		mWindow.display();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		i--;
	}
	std::cout << "Closing window\n";
	mWindow.close();
	std::cout << "Test Passed\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));

}