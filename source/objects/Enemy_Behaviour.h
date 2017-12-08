#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Enemy_Behaviour : public Behaviour {
int i{0};
int frame{0};
bool jumped{false};
public:
	Enemy_Behaviour():Behaviour{}{}
	bool process(World &world, Entity& owner, sf::Time const& t) override{



		sf::Vector2f dir{0.0f, 0.0f};

		Entity* player = world.get_player();
		sf::Vector2f player_pos = player->getPosition();
		if(owner.getPosition().x > player_pos.x){
			dir.x = -1.0f;
		} else if(owner.getPosition().x < player_pos.x){
			dir.x = 1.0f;
		} else {
			dir.x = 0.0f;
		}
		if(owner.getPosition().y >= player_pos.y){
			dir.y = -1.0f;
		} else {
			dir.y = 1.0f;
		}

		//Flipping sprite based on movement
		if (dir.x == 1.0f && owner.getScale().x == 1.0f){
			owner.setScale(-1.0f, 1.0f);
		}else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
			owner.setScale(1.0f, 1.0f);
		}
/*
		//Animation
		owner.setTextureRect(sf::IntRect(frame * 80, 0, 80, 80));
		if(i > 5){
			if(frame < 9){
				frame++;
			} else {
				frame = 0;
			}
			i = 0;
		} else {
			i++;
		}
*/


		//Movement
		velocity.x = dir.x*2;
		velocity.y = dir.y*2;



		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);



		return false;

	}
};
