#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Enemy_Behaviour ärver från Behaviour och tillhandahåller beteende för fiender.
 *
 * Enemy_Behaviour definerar beteendet för ett Enemy objekt i spelet. 
 * Enemy rör sig som Player_Behaviour men följer spelaren istället 
 * för att följa vad användaren anger. Den flipar också Enemy spriten om det behövs
 * och har koll på kollisioner för enemy. Enemy dödar spelaren om de kommer i kontakt med denne.
 * 
 */

class Enemy_Behaviour : public Behaviour {
public:
	///Vanlig Behaviour#Behaviour konstruktor.
	Enemy_Behaviour():Behaviour{}{}
	///Funktionen som låter fienden göra allting.
	void process(World&, Entity&, sf::Time const& ) override;
	///Funktionen flipar spriten för enemy baserat på vilket håll den rör sig.
	void flip(Entity&, sf::Vector2f const&);
	///Förflyttning i x-led.
	void move_x(Entity&, sf::Vector2f const&, sf::Time);
	///Förflyttning i y-led.
	void move_y(Entity&, sf::Vector2f const&, sf::Time);
	///Kollisionshantering i x-led.
	void collision_x(World&, Entity&);
	///Kollisionshantering i y-led.
	void collision_y(World&, Entity&);

private:
	///Filip fixa
	int i{0};
	///Filip fixa
	int frame{0};
};
