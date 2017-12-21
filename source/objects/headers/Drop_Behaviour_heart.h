#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"


/**
 * \brief Drop_Behaviour_heart ärver från Behaviour och tillhandahåller beteendet för hjärt-drops.
 *
 * Drop_Behaviour_heart ärver från de abstrakta klassen Behaviour och däför behöver den köra override på process()
 *
 */

class Drop_Behaviour_heart : public Behaviour {
public:
	///Konstruktor som bara använder Behaviours konstruktor
	Drop_Behaviour_heart():Behaviour{}{}
	///Copy konstruktor
    Drop_Behaviour_heart(Drop_Behaviour_heart const & other) = delete;
    ///Move konstruktor
    Drop_Behaviour_heart(Drop_Behaviour_heart && other) = delete;
    ///Copy operator
    Drop_Behaviour_heart& operator=(Drop_Behaviour_heart const & rhs) & = delete;
    ///Move operator
	Drop_Behaviour_heart& operator=(Drop_Behaviour_heart && rhs) = delete;
	///Default destruktor
	~Drop_Behaviour_heart() = default;
	///Process som låter hjärtat ramla ner, kollidera med platformar och sedan försvinna när det kolliderar med en spelare.
	void process(World&, Entity&, sf::Time const&) override;
};
