#pragma once

#include <SFML/Graphics.hpp>

class Key_Handling {
public:
	bool jump{false};
	bool left{false}; 
	bool right{false};
	bool shoot{false};
	sf::Keyboard::Key jump_key{};
	sf::Keyboard::Key left_key{};
	sf::Keyboard::Key right_key{};
	sf::Keyboard::Key shoot_key{};

    Key_Handling(): jump{}, left{}, right{}, shoot{}, 
		jump_key{sf::Keyboard::Up}, left_key{sf::Keyboard::Left}, right_key{sf::Keyboard::Right}, shoot_key{sf::Keyboard::Space}{};
		
    Key_Handling(sf::Keyboard::Key j, sf::Keyboard::Key l, 
        sf::Keyboard::Key r, sf::Keyboard::Key s) 
		: jump{}, left{}, right{}, shoot{}, jump_key{j}, left_key{l}, right_key{r}, shoot_key{s}{}

	void onKey(bool pressed, sf::Keyboard::Key const& key) {
		if(key == jump_key){
			jump = pressed;
		}else if(key == left_key){
			left = pressed;
		}else if(key == right_key){
			right = pressed;			
		}else if(key == shoot_key){
			shoot = pressed;
		}
	}

	sf::Vector2f direction() const {
		sf::Vector2f dir;
		if (jump)
			dir.y -= 1.0f;
		if (left)
			dir.x -= 1.0f;
		if (right)
			dir.x += 1.0f;
		return dir;
	}
};

