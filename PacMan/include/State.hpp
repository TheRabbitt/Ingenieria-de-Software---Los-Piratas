#ifndef INCLUDE_STATE_ // guarda
#define INCLUDE_STATE_

#include "SFML/Graphics.hpp"
//#include "GameController.hpp"

class GameController;

class State
{
public:
    State();
    void setWindow(sf::RenderWindow*);
    void setController(GameController*);
    GameController* getController();
    sf::Font* getMenuFont();
    sf::Font* getTitleFont();
    sf::RenderWindow* getWindow();
    bool loadMenuFont(const std::string&);
    bool loadTitleFont(const std::string&);
    void processEvents();
    virtual void render();
    virtual void update(sf::Time);
private:
    GameController* controller;
    sf::RenderWindow* mWindow;
    sf::Font titleFont;
    sf::Font menuFont;
};

#endif /* INCLUDE_STATE_ */
