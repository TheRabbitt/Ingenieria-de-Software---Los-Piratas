#ifndef INCLUDE_GAME_ // guarda
#define INCLUDE_GAME_

#include "SFML/Graphics.hpp"
#include "PacMan.hpp"
#include "Map.hpp"

class Game
{
    public:
	    Game(int, int);
	    void run();
    private:
		void handlePlayerInput(sf::Keyboard::Key, bool);
	    void processEvents();
		void render();
	    void update(sf::Time);
    private:
	    sf::RenderWindow mWindow;
		sf::Clock clock;
		sf::Time TimePerFrame;
		PacMan pacman;
		Map map;
};
#endif /* INCLUDE_GAME_ */