#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Platform_Behaviour : public Behaviour {
public:
	Platform_Behaviour():Behaviour{}{}
	bool process(World&, Entity&, sf::Time const&) override{
        return false;
	}
	
};




