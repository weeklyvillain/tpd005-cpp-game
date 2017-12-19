#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include <iostream>


class Enemy_Behaviour : public Behaviour {
public:
	Enemy_Behaviour():Behaviour{}{}
	void process(World&, Entity&, sf::Time const&) override;
	
private:
	int i{0};
	int frame{0};
	bool jumped{false};
};
