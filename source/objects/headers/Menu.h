#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "Game.h"

/**
 * \brief Menu har hand om menyer innan man börjar spela spelet.
 *
 *
 */


class Menu{
public:
	///
	Menu(float width, float height);
	///
	~Menu() = default;

	///
	void draw(sf::RenderWindow &window);
	///
	void MoveUp();
	///
	void MoveDown();
	///
	int GetPressedItem() { return selectedItemIndex; }
	///
	void read_score(sf::RenderWindow &window);
	///
	void onKey(sf::Keyboard::Key const& key, sf::RenderWindow &);
	///
	void add_option(std::string);

private:
	///
	float item_width;
	///
	float item_height;
	///
	int menu_depth;
	///
	int selectedItemIndex;
	///
	sf::Font font;
	///
	std::vector<sf::Text> menu;
	///
	Game game{};
	std::string ip;
};
