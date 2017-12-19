#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Projectile_Behaviour ärver från Behaviour och tillhandahåller beteendet för projektiler.
 *
 * 
 */

class Projectile_Behaviour : public Behaviour {
public:
	Projectile_Behaviour(float, float);
	void process(World&, Entity&, sf::Time const&) override;

private:
	float direction{};
	float init_pos{};
};
