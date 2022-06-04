#ifndef INCLUDE_STATE_ // guarda
#define INCLUDE_STATE_

#include "SFML/Graphics.hpp"
//#include "GameController.hpp"

class GameController;

class State
{
public:
    void setWindow(sf::RenderWindow*);
    void setController(GameController*);
    GameController* getController();
    sf::RenderWindow* getWindow();
    void processEvents();
    virtual void render();
    virtual void update(sf::Time);
private:
    GameController* controller;
    sf::RenderWindow* mWindow;
};

#endif /* INCLUDE_STATE_ */
