#pragma once

#include <SFML/Graphics.hpp>

#include "Behaviour.h"
#include "Projectile_Behaviour.h"
#include "Projectile.h"
#include "Player.h"

/**
 * \brief Player_Behaviour ärver från Behaviour och tillhandahåller beteendet för spelare.
 *
 * Player_Behaviour 
 * 
 */

class Player_Behaviour : public Behaviour {

public:
	///En vanlig konstruktor som tar in ett referens till en Key_Handling.
	Player_Behaviour(Key_Handling&);
	///Copy konstruktor
    Player_Behaviour(Player_Behaviour const & other) = delete;
    ///Move konstruktor
    Player_Behaviour(Player_Behaviour && other) = delete;
    ///Copy operator
    Player_Behaviour& operator=(Player_Behaviour const & rhs) & = delete;
    ///Move operator
	Player_Behaviour& operator=(Player_Behaviour && rhs) = delete;
	///Default Destruktor
	~Player_Behaviour() = default;
	///
	void process(World&, Entity&, sf::Time const& ) override;
	///Funktionen flipar spriten för enemy baserat på vilket håll den rör sig.
	void flip(Entity&, sf::Vector2f const&);
	///
	void animate(World&, Entity&);
	///
	void shoot(World&, Player&, sf::Time);
	///Förflyttning i x-led.
	void move_x(Entity&, sf::Vector2f const&, sf::Time);
	///Förflyttning i y-led.
	void move_y(Entity&, sf::Vector2f const&, sf::Time);
	///Kollisionshantering i x-led.
	void collision_x(World&, Entity&);
	///Kollisionshantering i y-led.
	void collision_y(World&, Entity&);

private:
	///En variabel som visar vilken Key_Handling
	/// Player_Behaviour objektet ska lyssna på.
	Key_Handling& handler;
	///Variabel för att simulera en klocka.
	int i{0};
	///Vilken frame som ska ritas ut.
	int frame{0};
};
