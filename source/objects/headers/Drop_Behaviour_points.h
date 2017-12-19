#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Drop_Behaviour_points ärver från Behaviour och tillhandahåller beteendet för poäng-drops.
 *
 * Drop_Behaviour_heart ärver från de abstrakta klassen Behaviour och däför behöver den köra override på process()
 * 
 */

class Drop_Behaviour_points : public Behaviour {
public:
	///Konstruktor som bara använder Behaviours konstruktor
	Drop_Behaviour_points():Behaviour{}{}
	///Process som låter hjärtat ramla ner, kollidera med platformar och sedan försvinna när det kolliderar med en spelare.
	void process(World&, Entity&, sf::Time const&) override;
};
