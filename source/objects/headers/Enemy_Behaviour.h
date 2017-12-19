#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Enemy_Behaviour ärver från Behaviour och tillhandahåller beteende för fiender.
 *
 * 
 */

class Enemy_Behaviour : public Behaviour {
public:
	Enemy_Behaviour():Behaviour{}{}
	void process(World&, Entity&, sf::Time const& ) override;
	void flip(Entity&, sf::Vector2f const&);
	void move_y(Entity&, sf::Vector2f const&, sf::Time);
	void move_x(Entity&, sf::Vector2f const&, sf::Time);
	void collision_y(World&, Entity&);
	void collision_x(World&, Entity&);
	
private:
	int i{0};
	int frame{0};
	bool jumped{false};
};
