#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include "Projectile_Behaviour.h"
#include "Projectile.h"
#include "Player.h"
#include <iostream>

class Player1_Behaviour : public Behaviour {

public:
	Player1_Behaviour():Behaviour{}{}
	
	void process(World&, Entity&, sf::Time const& ) override;
	void flip(Entity&, sf::Vector2f const&);
	void animate(Entity&);
	void shoot(World&, Player&, sf::Time) const;
	void move(Entity&, sf::Vector2f const&, sf::Time);
	void collisions(World&, Entity&);

private:
	int i{0};
	int frame{0};
};
