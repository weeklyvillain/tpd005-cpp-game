#include "SFML/Graphics.hpp"
#include <iostream>
#include "objects/Menu.h"
#include "objects/Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Menu!");
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				menu.onKey(event.key.code, window);
				break;
			case sf::Event::Closed:
				window.close();
            default:
				break;
			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}
}
