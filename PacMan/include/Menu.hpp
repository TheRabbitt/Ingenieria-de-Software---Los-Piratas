#ifndef INCLUDE_MENU_ // guarda
#define INCLUDE_MENU_

#include "SFML/Graphics.hpp"
#include "GameController.hpp"
#include "State.hpp"

class Menu : public State
{
public:
    Menu(Menu& other) = delete;                 // Singleton no es clonable
    void operator=(const Menu&) = delete;       // Singleton no es asignable
    static Menu* createMenu(GameController*, sf::RenderWindow*); // Llama al constructor si no hay instancia. Garantiza singleton.
    bool Menu::loadMenuFont(const std::string&);
    bool loadTitleFont(const std::string&);
private:
    void update(sf::Time) override;
    Menu(GameController*, sf::RenderWindow*);
    void render() override;
private:
    static Menu* menu_;
    int selection;
    sf::Font titleFont;
    sf::Font menuFont;
    sf::Text titleText;
    sf::Text opt1;
    sf::Text opt2;
    sf::Text opt3;
    sf::Text opt4;
    sf::Text opt5;
};

#endif /* INCLUDE_MENU_ */