#ifndef INCLUDE_GAME_ // guarda
#define INCLUDE_GAME_

#include "SFML/Graphics.hpp"
#include "GameController.hpp"
#include "State.hpp"
#include "PacMan.hpp"
#include "Map.hpp"

class Game : public State
{
public:
	Game(Game& other) = delete;           // Singleton no es clonable
	void operator=(const Game&) = delete; // Singleton no es asignable
	static Game* createGame(GameController*, sf::RenderWindow*, int, int); // Llama al constructor si no hay instancia. Garantiza singleton.
private:
	Game(GameController*, sf::RenderWindow*, int, int);
	void render() override;
	void update(sf::Time) override;
private:
	static Game* game_;
	PacMan pacman;
	Map map;
};



#endif /* INCLUDE_GAME_ */