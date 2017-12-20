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
	///Copy konstruktor
    Drop_Behaviour_points(Drop_Behaviour_points const & other) = delete;
    ///Move konstruktor
    Drop_Behaviour_points(Drop_Behaviour_points && other) = delete;
    ///Copy operator
    Drop_Behaviour_points& operator=(Drop_Behaviour_points const & rhs) & = delete;
    ///Move operator
	Drop_Behaviour_points& operator=(Drop_Behaviour_points && rhs) = delete;
	///Default destruktor
	~Drop_Behaviour_points() = default;
	///Process som låter hjärtat ramla ner, kollidera med platformar och sedan försvinna när det kolliderar med en spelare.
	void process(World&, Entity&, sf::Time const&) override;
};
