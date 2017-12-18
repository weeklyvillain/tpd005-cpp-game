#pragma once

#include <SFML/Graphics.hpp>

class Key_Handling {
public:
	bool jump{false};
	bool left{false};
	bool right{false};
	bool shoot{false};
	bool quit{false};
	sf::Keyboard::Key jump_key{};
	sf::Keyboard::Key left_key{};
	sf::Keyboard::Key right_key{};
	sf::Keyboard::Key shoot_key{};

    Key_Handling();
	Key_Handling(sf::Keyboard::Key, sf::Keyboard::Key, 
		sf::Keyboard::Key, sf::Keyboard::Key);
	void onKey(bool, sf::Keyboard::Key const&);
	sf::Vector2f direction() const;
};
