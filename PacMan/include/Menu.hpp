#ifndef INCLUDE_MENU_ // guarda
#define INCLUDE_MENU_

#include "SFML/Graphics.hpp"
#include "GameController.hpp"
#include "State.hpp"
#include "Entity.hpp"

class Menu : public State
{
public:
    Menu(Menu& other) = delete;                 // Singleton no es clonable
    void operator=(const Menu&) = delete;       // Singleton no es asignable
    static Menu* createMenu(GameController*, sf::RenderWindow*); // Llama al constructor si no hay instancia. Garantiza singleton.
    sf::Text getTitleText();
    sf::Text getOpt0();
    sf::Text getOpt1();
    sf::Text getOpt2();
    Entity getPacmanImage();
private:
    Menu(GameController*, sf::RenderWindow*);
    void loadScores();
    void refreshImage();
    void render() override;
    void update(sf::Time) override;
    void updateImageCoord();
private:
    static Menu* menu_;
    int selection;
    int numWindow;
    int numScores;
    int imageCoord;
    Entity pacmanImage;
    sf::Clock clock;
    sf::Time imageUpdateTime;
    sf::Text titleText;
    sf::Text scoreText;
    sf::Text opt0;
    sf::Text opt1;
    sf::Text opt2;
    std::vector<sf::Text> scores;

};

#endif /* INCLUDE_MENU_ */