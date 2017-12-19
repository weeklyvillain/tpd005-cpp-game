#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Platform_Behaviour ärver från Behaviour och tillhandahåller beteendet för platformar.
 *
 * 
 */

class Platform_Behaviour : public Behaviour {
public:
	///
	Platform_Behaviour():Behaviour{}{}
	///
	void process(World&, Entity&, sf::Time const&) override{}
	
};




