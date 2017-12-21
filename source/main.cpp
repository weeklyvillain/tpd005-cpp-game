#include "SFML/Graphics.hpp"
#include "objects/headers/Menu.h"
#include "objects/headers/Game.h"

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
