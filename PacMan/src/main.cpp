#include "Game.hpp"
#include "GameController.hpp"

int main()
{
	int mapTileSize = 16;			//Tamaño del personaje
	int entityTileSize = 16;

	//Controla si se va a cargar el menu o el juego
	GameController* controller = GameController::createGameController(mapTileSize, entityTileSize);
	controller->init();
	controller->run();
	
	//sf::RenderWindow mWindow(sf::VideoMode(28 * mapTileSize, 36 * mapTileSize), "PacMan");
	//Game* game = Game::createGame(&mWindow,16,16);
	//game->run();
	//Game game(&mWindow, 16, 16);
	//game.run();
}



