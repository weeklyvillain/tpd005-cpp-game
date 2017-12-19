#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void onKey(sf::Keyboard::Key const& key, sf::RenderWindow &);

private:
	float item_width;
	float item_height;
	int menu_depth;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	Game game{};
};
