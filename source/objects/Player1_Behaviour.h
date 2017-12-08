#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include "Projectile_Behaviour.h"
#include "Projectile.h"
#include <iostream>


class Player1_Behaviour : public Behaviour {
int i{0};
int frame{0};
public:
	Player1_Behaviour():Behaviour{}{}
	bool process(World &world, Entity& owner) override{
		
		sf::Vector2f dir = world.player1.direction();


		//Flipping sprite based on movement
		if (dir.x == 1.0f && owner.getScale().x == 1.0f){
			owner.setScale(-1.0f, 1.0f);
		}else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
			owner.setScale(1.0f, 1.0f);
		}

		//Animation
		owner.setTextureRect(sf::IntRect(frame * 80, 0, 79, 79));
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

		//Shooting
		if (world.player1.shoot){
			world.add_entity(new Projectile("proj", 
				new Projectile_Behaviour(owner.getScale().x, 
				owner.getPosition().x), 
				owner.getPosition().x+(-50.0f*owner.getScale().x),owner.getPosition().y));
			world.player1.shoot = false;
		}
		
		//Movement
		velocity.x = dir.x*10;
		if (velocity.y == 0.0f){
			velocity.y = dir.y*42;
		}

		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);


		//Checking for collisions
		bool p_top{false};
		bool p_side{false};
		if (world.am_I_Colliding(owner, p_top, p_side)){
			if(p_top){
				owner.setPosition(owner.getPosition().x, owner.getPosition().y-velocity.y);
				velocity.y = 0.0f;			
			}
			if(p_side){
				owner.setPosition(owner.getPosition().x-velocity.x, owner.getPosition().y);
				velocity.x = 0.0f;
			}
		}else{
			//Applying gravity
			velocity += acceleration;
		}
		return false;

	}
};
