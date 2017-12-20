#pragma once

#include <SFML/Graphics.hpp>
#include "Behaviour.h"

/**
 * \brief Enemy_Behaviour2 ärver från Behaviour och tillhandahåller beteende för fiender.
 *
 * Enemy_Behaviour2 definerar beteendet för ett Enemy objekt i spelet.
 * Enemy rör sig som Player_Behaviour men följer spelaren istället
 * för att följa vad användaren anger. Den flipar också Enemy spriten om det behövs
 * och har koll på kollisioner för enemy. Enemy dödar spelaren om de kommer i kontakt med denne.
 * 
 * Enemy nummer 2 rör sig från sin startplats till en ny plats och tillbaka.
 * Detta är det enda den gör.
 *
 */

class Enemy2_Behaviour : public Behaviour {
public:
	///Vanlig Behaviour#Behaviour konstruktor.
	Enemy2_Behaviour(sf::Vector2f v, float x, float y):Behaviour{}, start_pos{v}, end_pos{x, y}{}
	///Copy konstruktor
    Enemy2_Behaviour(Enemy2_Behaviour const & other) = delete;
    ///Move konstruktor
    Enemy2_Behaviour(Enemy2_Behaviour && other) = delete;
    ///Copy operator
    Enemy2_Behaviour& operator=(Enemy2_Behaviour const & rhs) & = delete;
    ///Move operator
	Enemy2_Behaviour& operator=(Enemy2_Behaviour && rhs) = delete;
	///Default destruktor
	~Enemy2_Behaviour() = default;
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
	///Start positionen
	sf::Vector2f start_pos;
	///Slut positionen
	sf::Vector2f end_pos;
};
