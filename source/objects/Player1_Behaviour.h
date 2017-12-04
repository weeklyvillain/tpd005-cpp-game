#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Player1_Behaviour : public Behaviour {
public:
	Player1_Behaviour():Behaviour{}{}
	bool process(World &world, Entity &owner) override{
		sf::Vector2f dir = world.player1.direction();		
		if (world.player1.shoot){
			std::cout << "Pang!" << std::endl;
		}

		velocity.x = dir.x*5;
		if (velocity.y == 0.0f){
			velocity.y = dir.y*42;
		}
		sf::Vector2f old_pos = owner.getPosition();

		//Flipping sprite based on movement
		if (dir.x == 1.0f && owner.getScale().x == 1.0f){
			owner.setScale(-1.0f, 1.0f);
		}else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
			owner.setScale(1.0f, 1.0f);
		}

		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);

		//Checking for collisions
		if (world.am_I_Colliding(owner)){
			owner.setPosition(owner.getPosition().x, old_pos.y);
			velocity.y = 0.0f;
		}else{
			//Applying gravity
			velocity += acceleration;
		}

		if (owner.getPosition().y >= 860) {
			owner.setPosition(sf::Vector2f(owner.getPosition().x, 860));
			velocity.y = 0;
		}
		if (owner.getPosition().x <= 120) {
			owner.setPosition(sf::Vector2f(120, owner.getPosition().y));
			velocity.x = 0;
		}
		if (owner.getPosition().x >= 1480) {
			owner.setPosition(sf::Vector2f(1480, owner.getPosition().y));
			velocity.x = 0;
		}
		
		return false;
	}
};




