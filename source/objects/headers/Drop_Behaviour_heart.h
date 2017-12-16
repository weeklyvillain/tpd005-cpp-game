#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Drop_Behaviour_heart : public Behaviour {
public:
	Drop_Behaviour_heart():Behaviour{}{}
	void process(World&, Entity&, sf::Time const&) override;
};
