#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"

class Projectile_Behaviour : public Behaviour {
public:
	Projectile_Behaviour(float dir, float init_pos):Behaviour{}, direction{dir}, init_pos{init_pos}{}
	bool process(World& world, Entity& owner) override{
		owner.setPosition(owner.getPosition().x+(-10.0f*direction), owner.getPosition().y);

		if (( direction < 0 && owner.getPosition().x > init_pos+500.0f) || ( direction > 0 && owner.getPosition().x < init_pos-500.0f)){
			world.kill_me_now(owner);
		}
		if(world.am_I_Colliding(owner)){
			world.kill_me_now(owner);
		}
		return false;
	}

private:
	float direction{};
	float init_pos{};
};
