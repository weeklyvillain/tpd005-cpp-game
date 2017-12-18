#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Drop_Behaviour_points : public Behaviour {
public:
	Drop_Behaviour_points():Behaviour{}{}
	void process(World&, Entity&, sf::Time const&) override;
};
