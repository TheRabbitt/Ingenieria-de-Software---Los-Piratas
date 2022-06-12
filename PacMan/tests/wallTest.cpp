#include "PacMan.hpp"
#include "Map.hpp"
#include <iostream>
#include <chrono>
#include <thread>
			

int main (){


	Map map("../media/images/Map", sf::Vector2u(16, 16), 28, 36);
	std::cout << "Creating Window\n";
	sf::RenderWindow mWindow(sf::VideoMode(448, 608), "Test");
	std::cout << "Window Creation succeded\n";
	std::cout << "Creating PacMan\n";
	PacMan pacman(16, "../media/images/Pacman", 100, &map);
	pacman.refreshImage();
	std::cout << "PacMan wall Test succeded\n";

  /*for (int i = 0, i<6, i++)*/
	    sf::Event event;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		pacman.setPosition(14.f, 65.f);
		pacman.setVelocity(-pacman.getSpeed(), 0);

		pacman.movePacman(sf::seconds(0.09f));
		pacman.setVelocity(-pacman.getSpeed(), 0);


		if (pacman.getPosition()[0].position.x == 14) {

			mWindow.close();
			std::cout << "Test Passed\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			return 0;

		}

		else {

			mWindow.close();
			std::cout << "Test not Passed\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));

			return -1; }


}