#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>

/**
 * \brief Drop_Behaviour_heart ärver från Behaviour och tillhandahåller beteendet för hjärt-drops.
 *
 * 
 */

class Drop_Behaviour_heart : public Behaviour {
public:
	Drop_Behaviour_heart():Behaviour{}{}
	void process(World&, Entity&, sf::Time const&) override;
};
