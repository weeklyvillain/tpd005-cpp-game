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
		velocity.x = dir.x* 80 * t.asSeconds();
		if (velocity.y == 0.0f){
			velocity.y = dir.y* 500 * t.asSeconds();
		}


		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);

		//Applying gravity
		velocity += acceleration;
		Entity* now = world.am_I_Colliding(owner);
		if (now && velocity.y > 0 && now->get_name() == "Platform"){
			owner.setPosition(owner.getPosition().x, now->getPosition().y -81);
			velocity.y = 0.0f;
		}else if(now && velocity.y < 0 && now->get_name() == "Platform"){
			owner.setPosition(owner.getPosition().x, now->getPosition().y +81);
			velocity.y = 0.0f;
		}
		//     p_top,
		//     owner.setPosition(old_x, now.top)
		if (now && velocity.x > 0){
			owner.setPosition(now->getPosition().x + 81, owner.getPosition().y);
			velocity.x = 0.0f;
		}else if(now && velocity.x < 0){
			owner.setPosition(now->getPosition().x -81, owner.getPosition().y);
			velocity.x = 0.0f;
		}
		//     p_side,
		//     owner.setPosition(now.left eller now.right, old_y)

		// Antagande: world.collides?(owner) = false

		return false;

	}
};
