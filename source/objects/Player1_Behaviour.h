#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Player1_Behaviour : public Behaviour {
public:
	Player1_Behaviour():Behaviour{}{}
	bool process(World &world, Entity &owner) override{
		sf::Vector2f dir = world.player1.direction();
		velocity.x += dir.x*5;
		if (velocity.y == 0){
			velocity.y += dir.y*42;
		}

		
		owner.setPosition(owner.getPosition() + velocity);
		velocity += acceleration;
		
		if (owner.getPosition().y >= 820) {
			owner.setPosition(sf::Vector2f(owner.getPosition().x, 830));
			velocity.y = 0;
		}
		if (owner.getPosition().x <= 0) {
			owner.setPosition(sf::Vector2f(0, owner.getPosition().y));
			velocity.x = 0;
		}
		if (owner.getPosition().x >= 1520) {
			owner.setPosition(sf::Vector2f(1520, owner.getPosition().y));
			velocity.x = 0;
		}

		return false;
	}
};




