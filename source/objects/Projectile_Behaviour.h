#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"

class Projectile_Behaviour : public Behaviour {
public:
	Projectile_Behaviour(float dir, float init_pos):Behaviour{}, direction{dir}, init_pos{init_pos}{}
	bool process(World& world, Entity& owner, sf::Time const& t) override{
		owner.setPosition(owner.getPosition().x+(-70.0f*direction * t.asSeconds()), owner.getPosition().y);
		if(world.am_I_Colliding(owner)){

		}
		return false;
	}

private:
	float direction{};
	float init_pos{};
};
