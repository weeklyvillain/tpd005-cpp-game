#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"

class Projectile_Behaviour : public Behaviour {
public:
	Projectile_Behaviour(float dir, float init_pos):Behaviour{}, direction{dir}, init_pos{init_pos}{}
	void process(World& world, Entity& owner, sf::Time const& t) override{
		owner.setPosition(owner.getPosition().x+(-320.0f*direction * t.asSeconds()), owner.getPosition().y);
		if(auto now = world.am_I_Colliding(owner)){
			if (now->get_type() != "Player" && now->get_type() != "Projectile"){
				world.kill_me_now(owner);
				if (now->get_type() != "Platform"){
					now->kill(world);
				}
			}
		}
	}

private:
	float direction{};
	float init_pos{};
};
