#ifndef KEY_HANDLING_H
#define KEY_HANDLING_H

#include <SFML/Graphics.hpp>

class Key_Handling {
public:
	bool jump{false};
	bool left{false}; 
	bool right{false};
	bool shoot{false};
	sf::Keyboard::Key const jump_key{sf::Keyboard::Up};
	sf::Keyboard::Key const left_key{sf::Keyboard::Left};
	sf::Keyboard::Key const right_key{sf::Keyboard::Right};
	sf::Keyboard::Key const shoot_key{sf::Keyboard::Space};

    Key_Handling(): jump{}, left{}, right{}, shoot{}, 
        jump_key{}, left_key{}, right_key{}, shoot_key{}{};
    Key_Handling(sf::Keyboard::Key j, sf::Keyboard::Key i, 
        sf::Keyboard::Key r, sf::Keyboard::Key s) 
		: jump{}, left{}, right{}, shoot{}, jump_key{j}, left_key{i}, right_key{r}, shoot_key{s}{}

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

#endif