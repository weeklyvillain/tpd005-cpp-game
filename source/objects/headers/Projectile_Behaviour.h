#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"

class Projectile_Behaviour : public Behaviour {
public:
	Projectile_Behaviour(float, float);
	void process(World&, Entity&, sf::Time const&) override;

private:
	float direction{};
	float init_pos{};
};
