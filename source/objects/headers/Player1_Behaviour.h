#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include "Projectile_Behaviour.h"
#include "Projectile.h"
#include "Player.h"
#include <iostream>

class Player1_Behaviour : public Behaviour {
int i{0};
int frame{0};
public:
	Player1_Behaviour():Behaviour{}{}
	
	void process(World &world, Entity& owner, sf::Time const& t)  override{
		Player& o = dynamic_cast<Player&>(owner);

		sf::Vector2f dir = world.player1.direction();

		//Flipping sprite based on movement
		flip(o, dir);

		//Animation
		animate(o);

		//Shooting
		shoot(world, o, t);

		//Movement
		move(o, dir, t);

		//Collisons
		collisions(world, o);
	}

	void flip(Entity& owner, sf::Vector2f const& dir){
		if (dir.x == 1.0f && owner.getScale().x == 1.0f){
			owner.setScale(-1.0f, 1.0f);
		}else if (dir.x == -1.0f && owner.getScale().x == -1.0f ){
			owner.setScale(1.0f, 1.0f);
		}
	}

	void animate(Entity& owner){
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
	}



	void shoot(World& world, Player& owner, sf::Time t){
		if (world.player1.shoot && owner.time_since_last_shot + t.asSeconds() > 0.5f){	
			world.add_entity(new Projectile("proj", "Projectile",
				new Projectile_Behaviour(owner.getScale().x,
				owner.getPosition().x),
				owner.getPosition().x+(-50.0f*owner.getScale().x),owner.getPosition().y));
			owner.time_since_last_shot = 0.0f;
		}else{
			owner.time_since_last_shot += t.asSeconds();
		}
	}

	void move(Entity& owner, sf::Vector2f const& dir, sf::Time t){
		velocity.x = dir.x * 80 * t.asSeconds();
		if (velocity.y == 0.0f){
			velocity.y = dir.y * 500 * t.asSeconds();
		}
		owner.setPosition(owner.getPosition() + velocity);

		//Applying gravity
		velocity.y += acceleration.y;
	}

	void collisions(World& world, Entity& owner){
		Entity* now = world.am_I_Colliding(owner);
		if (now && velocity.y >= 0.0f && now->get_name() == "Platform" 
				&& owner.getPosition().y + 40 >= now->getPosition().y - 40
				&& owner.getPosition().y + 40 <=now->getPosition().y - 20){

			owner.setPosition(owner.getPosition().x, now->getPosition().y -80.0f);
			velocity.y = 0.0f;
		}

		if (owner.getPosition().y < 0 || owner.getPosition().y > 900){
			owner.setPosition(800, 50);
			velocity.y = acceleration.y;
		}
		if (owner.getPosition().x < 0 || owner.getPosition().x > 1600){
			owner.setPosition(800, 50);
			velocity.y = acceleration.y;
		}
	}
};
