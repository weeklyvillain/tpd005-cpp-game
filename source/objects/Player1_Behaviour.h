#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Player1_Behaviour : public Behaviour {
public:
	Player1_Behaviour():Behaviour{}{}
	bool process(World &world, Entity &owner) override{
		sf::Vector2f dir = world.player1.direction();
		sf::Vector2f speed;
		if(falling){
			speed.x = dir.x*5;
			speed.y = dir.y*0;
		}else{
			speed.x = dir.x*5;
			speed.y = dir.y*100;
		}
		
		if (owner.getPosition().y <= 895-80){
			falling = true;
			owner.setPosition(owner.getPosition() + speed + gravity);
		}else{
			falling = false;
			owner.setPosition(owner.getPosition() + speed);
		}	
		return false;
	}
};




