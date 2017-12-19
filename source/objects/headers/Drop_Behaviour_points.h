#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Drop_Behaviour_points ärver från Behaviour och tillhandahåller beteendet för poäng-drops.
 *
 * 
 */

class Drop_Behaviour_points : public Behaviour {
public:
	Drop_Behaviour_points():Behaviour{}{}
	void process(World&, Entity&, sf::Time const&) override;
};
