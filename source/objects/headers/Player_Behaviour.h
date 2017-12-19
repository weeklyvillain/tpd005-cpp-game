#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include "Projectile_Behaviour.h"
#include "Projectile.h"
#include "Player.h"

/**
 * \brief Player_Behaviour ärver från Behaviour och tillhandahåller beteendet för spelare.
 *
 * 
 */

class Player_Behaviour : public Behaviour {

public:
	///
	Player_Behaviour(Key_Handling&);
	///
	void process(World&, Entity&, sf::Time const& ) override;
	///
	void flip(Entity&, sf::Vector2f const&);
	///
	void animate(World&, Entity&);
	///
	void shoot(World&, Player&, sf::Time);
	///
	void move_y(Entity&, sf::Vector2f const&, sf::Time);
	///
	void move_x(Entity&, sf::Vector2f const&, sf::Time);
	///
	void collision_y(World&, Entity&);
	///
	void collision_x(World&, Entity&);


private:
	///
	Key_Handling& handler;
	///Filip fixa
	int i{0};
	///Filip fixa
	int frame{0};
};
