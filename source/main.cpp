#include "SFML/Graphics.hpp"
#include <iostream>
#include "objects/headers/Menu.h"
#include "objects/headers/Game.h"

/** \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */

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
