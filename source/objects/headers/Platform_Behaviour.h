#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Platform_Behaviour ärver från Behaviour och tillhandahåller beteendet för platformar.
 *
 * Platformars behaviour, de gör ingenting i i dagsläget men måste ha ett behaviour.
 * Detta öppnar också upp möjligheten att skapa mobila platformar om man skulle vilja det.
 * 
 */

class Platform_Behaviour : public Behaviour {
public:
	///Använder Behaviour konstruktorn
	Platform_Behaviour():Behaviour{}{}
	///Copy konstruktor
    Platform_Behaviour(Platform_Behaviour const & other) = delete;
    ///Move konstruktor
    Platform_Behaviour(Platform_Behaviour && other) = delete;
    ///Copy operator
    Platform_Behaviour& operator=(Platform_Behaviour const & rhs) & = delete;
    ///Move operator
	Platform_Behaviour& operator=(Platform_Behaviour && rhs) = delete;
	///Default Destruktor
	~Platform_Behaviour() = default;
	///Funktionen som låter plaformen göra allting.
	void process(World&, Entity&, sf::Time const&) override{}
	
};




