#include <array>
#include <fstream>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Publisher.hpp"

Publisher* Publisher::publisher_{ nullptr };

Publisher::Publisher()
{
	if (!menuFont.loadFromFile("media/font/namco.ttf"))
		throw std::runtime_error("Failed to load menu font");
}

Publisher* Publisher::createPublisher()
{
	if (publisher_ == nullptr)
	{
		publisher_ = new Publisher();
	}
	return publisher_;
}

void Publisher::addSubscriber(std::string sname)
{
	std::fstream file;
	std::string name;
	bool inList = false;
	file.open("subscribers.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while (file >> name)
	{
		if (!name.compare(sname))
		{
			inList = true;
			break;
		}
	}
	file.close();
	file.open("subscribers.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (!inList && !sname.empty())
		file << sname << "\n";
	file.close();
	std::cout << "inList : " << inList << std::endl;
	std::cout << "to subscribe: " << sname << std::endl;
}

void Publisher::loadScores(sf::Text* scores)
{
	std::fstream file;
	std::string name;
	std::string score;
	std::array<std::string, 5> s;
	file.open("scores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	int i = 0;
	float dy = 0.f;
	while (file >> name >> score)
	{
		std::cout << "score to copy: " << name << " " << score << std::endl;
		s[i] = name + " " + score;
		std::cout << "score to copy: " << s[i] << std::endl;
		(*(scores + i)).setFont(menuFont);
		(*(scores + i)).setCharacterSize(8);
		(*(scores + i)).setPosition(sf::Vector2f(70.f, 140.f + dy));
		(*(scores + i)).setFillColor(sf::Color::Yellow);
		(*(scores + i)).setString(s[i]);
		i++;
		dy += 20.f;
	}
	file.close();
}

void Publisher::notify(std::string sname)
{
	std::fstream file;
	std::string name;
	bool inList = false;
	file.open("subscribers.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while (file >> name)
	{
		if (!name.compare(sname))
		{
			inList = true;
			break;
		}
	}
	file.close();
	if (!inList)
		return;

	notifyWindow(sname);
	removeSubscriber(sname);
}

void Publisher::notifyWindow(std::string sname)
{
	nWindow.create(sf::VideoMode(250, 300), "Notify Window");
	sf::Text scores[5];
	sf::String playerInput;
	sf::Text name;
	sf::Text text;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	loadScores(scores);

	name.setFont(menuFont);
	name.setCharacterSize(10);
	name.setPosition(sf::Vector2f(70.f, 25.f));
	name.setFillColor(sf::Color::Yellow);
	name.setString(sname);
	text.setFont(menuFont);
	text.setCharacterSize(9);
	text.setPosition(sf::Vector2f(35.f, 50.f));
	text.setFillColor(sf::Color::Yellow);
	text.setString("you are no longer\n\n\non high score list\n\n\n\n      high scores\n");

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (nWindow.isOpen())
	{
		processNotifyEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processNotifyEvents();
			//updateLoginWindow(timePerFrame);
		}
		//renderLoginWindow();
		nWindow.clear();
		nWindow.draw(name);
		nWindow.draw(text);
		for (sf::Text s : scores)
		{
			nWindow.draw(s);
		}
		nWindow.display();
	}
}

void Publisher::processNotifyEvents()
{
	sf::Event event{};
	while (nWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			nWindow.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				nWindow.close();
			if (event.key.code == sf::Keyboard::Enter)
				nWindow.close();
			if (event.key.code == sf::Keyboard::Space)
				nWindow.close();
			break;
		}
	}
}

void Publisher::removeSubscriber(std::string sname)
{
	std::vector<std::string> names;
	std::fstream file;
	std::string name;
	file.open("subscribers.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	while (file >> name)
	{
	    names.push_back(name);
	}
	file.close();
	
	long long size = names.size();
	file.open("subscribers.txt", std::fstream::in | std::fstream::out | std::ofstream::trunc);
	for (std::string name : names)
	{
		if (name.compare(sname))
		{
			file << name << '\n';
		}
	}
	file.close();
}