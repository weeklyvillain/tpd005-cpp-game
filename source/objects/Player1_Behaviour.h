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
	bool process(World &world, Entity& owner, sf::Time const& t)  override{

		sf::Vector2f dir = world.player1.direction();


		//Flipping sprite based on movement
		if (dir.x == 1.0f && owner.getScale().x == 1.0f){
			owner.setScale(-1.0f, 1.0f);
		}else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
			owner.setScale(1.0f, 1.0f);
		}

		//Animation
		owner.setTextureRect(sf::IntRect(frame * 80, 0, 79, 79));
		if(i > 10){
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



		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);

		//Movement
		velocity.x = dir.x* 80 * t.asSeconds();
		if (velocity.y == 0.0f){
			velocity.y = dir.y* 500 * t.asSeconds();
		}


		//Applying gravity
		velocity.y += acceleration.y;



		Entity* now = world.am_I_Colliding(owner);
		if (now && velocity.y >= 0 && now->get_name() == "Platform" && (owner.getPosition().x >= now->getPosition().x && owner.getPosition().x <= now->getPosition().x + 80)){
			owner.setPosition(owner.getPosition().x, now->getPosition().y -80);
			velocity.y = 0.0f;
		}else if(now && velocity.y < 0 && now->get_name() == "Platform" && (owner.getPosition().x >= now->getPosition().x && owner.getPosition().x <= now->getPosition().x + 80)){
			owner.setPosition(owner.getPosition().x, now->getPosition().y +80);
			velocity.y = acceleration.y;
		} else if (now && velocity.x > 0){
			owner.setPosition(now->getPosition().x - 80, owner.getPosition().y);
			velocity.x = 0.0f;
		}else if(now && velocity.x < 0){
			owner.setPosition(now->getPosition().x + 80, owner.getPosition().y);
			velocity.x = 0.0f;
		}
		return false;

	}
};
