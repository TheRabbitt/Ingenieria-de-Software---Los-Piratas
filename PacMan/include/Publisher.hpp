#ifndef INCLUDE_PUBLISHER_ // guarda
#define INCLUDE_PUBLISHER_

#include <string>

class Publisher
{
public:
	Publisher(Publisher& other) = delete;      // Singleton no es clonable
	void operator=(const Publisher&) = delete; // Singleton no es asignable
	static Publisher* createPublisher();       // Llama al constructor si no hay instancia. Garantiza singleton.
	void addSubscriber(std::string);
	void loadScores(sf::Text*);
	void notify(std::string);
	void notifyWindow(std::string);
	void processNotifyEvents();
	void removeSubscriber(std::string);
private:
	Publisher();
private:
	static Publisher* publisher_;
	sf::Clock clock;
	sf::Font menuFont;
	sf::RenderWindow nWindow;
};

#endif /* INCLUDE_PUBLISHER_ */