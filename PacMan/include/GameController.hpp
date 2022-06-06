#ifndef INCLUDE_GAMECONTROLLER_ // guarda
#define INCLUDE_GAMECONTROLLER_

#include "State.hpp"
#include "Game.hpp"
#include "Menu.hpp"

class GameController
{
public:
	GameController(GameController& other) = delete;        // Singleton no es clonable
	void operator=(const GameController&) = delete;        // Singleton no es asignable
	static GameController* createGameController(int, int); // Llama al constructor si no hay instancia. Garantiza singleton.
	void init();
	void setState(State*);
	void standBy();
	void run();
private:
	GameController(int, int);
	void setTimePerFrame(float t);
private:
	static GameController* gameController_;
	State* state;
	sf::RenderWindow mWindow;
	sf::Clock clock;
	sf::Time timePerFrame;
	int entityTileSize;
	int mapTileSize;
};

#endif /* INCLUDE_GAMECONTROLLER_ */
