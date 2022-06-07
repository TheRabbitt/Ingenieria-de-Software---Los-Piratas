#ifndef INCLUDE_GAME_ // guarda
#define INCLUDE_GAME_

#include "SFML/Graphics.hpp"
#include "Dots.hpp"
#include "GameController.hpp"
#include "Ghost.hpp"
#include "Map.hpp"
#include "PacMan.hpp"
#include "Publisher.hpp"
#include "State.hpp"

class Game : public State
{
public:
	Game(Game& other) = delete;           // Singleton no es clonable
	void operator=(const Game&) = delete; // Singleton no es asignable
	static Game* createGame(GameController*, Publisher*,sf::RenderWindow*, int, int); // Llama al constructor si no hay instancia. Garantiza singleton.
private:
	Game(GameController*, Publisher*, sf::RenderWindow*, int, int);
	void loadHighScore();
	void processScores();
	void render() override;
	void resetGame();
	void update(sf::Time) override;
private:
	static Game* game_;
	PacMan pacman;
	Ghost blinky;
	Ghost pinky;
	Ghost inky;
	Ghost clyde;
	Map map;
	Dots dots;
	int actScore;
	int hScore;
	int dotsLeft;
	bool gameWon;
	bool restart;
	sf::Clock clock;
	sf::Text highScore;
	sf::Text winText;
	sf::Text actualScore;
};



#endif /* INCLUDE_GAME_ */