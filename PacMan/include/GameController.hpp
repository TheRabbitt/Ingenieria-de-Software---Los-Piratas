#ifndef INCLUDE_GAMECONTROLLER_ // guarda
#define INCLUDE_GAMECONTROLLER_

#include "Game.hpp"
#include "Menu.hpp"
#include "Publisher.hpp"
#include "State.hpp"

class GameController
{
public:
	GameController(GameController& other) = delete;        // Singleton no es clonable
	void operator=(const GameController&) = delete;        // Singleton no es asignable
	static GameController* createGameController(int, int); // Llama al constructor si no hay instancia. Garantiza singleton.
	void setPlayer(std::string);
	void setState(State*);
	std::string getPlayer();
	void init();
	void standBy();
	void run();
private:
	GameController(int, int);
	void setTimePerFrame(float t);
private:
	static GameController* gameController_;
	Publisher* publisher;
	State* state;
	sf::RenderWindow mWindow;
	sf::Clock clock;
	sf::Time timePerFrame;
	int entityTileSize;
	int mapTileSize;
	std::string player{""};
};

#endif /* INCLUDE_GAMECONTROLLER_ */
