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
	void process(World& world, Entity& owner, sf::Time const& t) override{

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
		if(owner.getPosition().y > player_pos.y){
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

		//Moving sprite
		owner.setPosition(owner.getPosition() + velocity);

		//Movement
		velocity.x = dir.x* 80 * t.asSeconds();
		if (velocity.y == 0.0f){
			velocity.y = dir.y* 500 * t.asSeconds();
		}

		//Applying gravity
		velocity.y += acceleration.y;

		std::cout << velocity.x << std::endl;

		Entity* now = world.am_I_Colliding(owner);
		if(now->get_name() == "Player"){

		}
		if(now->get_name() == "proj") {
		}
		if (now && velocity.y >= 0.0f && now->get_name() == "Platform"
			&& (owner.getPosition().x  >= now->getPosition().x - 78.0f
			&& owner.getPosition().x <= now->getPosition().x + 78.0f)){

			owner.setPosition(owner.getPosition().x, now->getPosition().y -80.0f);
			velocity.y = 0.0f;
		}else if(now && velocity.y < 0.0f && now->get_name() == "Platform"
			&& (owner.getPosition().x  >= now->getPosition().x - 78.0f
			&& owner.getPosition().x <= now->getPosition().x + 78.0f)){

				owner.setPosition(owner.getPosition().x, now->getPosition().y +80.0f);
				velocity.y = acceleration.y;
		}
		else if (now && velocity.x > 0.0f && now->get_name() == "Platform"
			&& (owner.getPosition().y  >= now->getPosition().y - 78.0f
			&& owner.getPosition().y <= now->getPosition().y + 78.0f)){

				owner.setPosition(now->getPosition().x - 81.0f, owner.getPosition().y);
				velocity.x = -velocity.x;
		}else if(now && velocity.x < 0.0f && now->get_name() == "Platform"
			&& (owner.getPosition().y  >= now->getPosition().y - 78.0f
			&& owner.getPosition().y <= now->getPosition().y + 78.0f)){

				owner.setPosition(now->getPosition().x + 81.0f , owner.getPosition().y);
				velocity.x = -velocity.x;
		}
	}
};
