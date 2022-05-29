#ifndef INCLUDE_GAME_ // guarda
#define INCLUDE_GAME_

#include "SFML/Graphics.hpp"
#include "PacMan.hpp"

class Game
{
    public:
	    Game();
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
};
#endif /* INCLUDE_GAME_ */