#include "SFML/Graphics.hpp"
#include <iostream>
#include "objects/headers/Menu.h"
#include "objects/headers/Game.h"

/** \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * Det här är ett projekt där vi ville skapa en 
 * Bubble Bobble klon med networking som fokus. 
 * Vi lyckades skapa en fungerande klon men 
 * lyckades ej skapa networking.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Steg 1: Ladda ner .tar filen.
 * \subsection step2 Steg 2: Kör cmake . i ...\\projekt\\
 * \subsection step3 Steg 3: Kör make bubble
 * \subsection step4 Steg 4: Kör ./bubble
 *
 */

int main(){
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Bubble Bobble Menu");
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
			case sf::Event::KeyPressed:
				menu.onKey(event.key.code, window);
				break;
			case sf::Event::Closed:
				window.close();
				return 0;
            default:
				break;
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
	return 0;
}
