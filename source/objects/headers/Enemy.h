#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Drop.h"
#include "Drop_Behaviour_heart.h"
#include "Drop_Behaviour_points.h"
#include <random>

/**
 * \brief Enemy ärver från Entity och innehåller all information för en entitet av fiendetyp.
 *
 * Enemy ärver från den abstrakta klassen Entity och 
 * innehåller informationen för den instans av fiender i spelet den representerar.
 * 
 */

class Enemy : public Entity{
public:
    ///Enemy konstruktorn som tar in ett namn, en typ, en beteende pekare,
    ///2 floats för position, en textur och vilken kvadrat som ska visas.
    Enemy(std::string, std::string, Behaviour*, float, float, sf::Texture const&, sf::IntRect);
    ///Copy konstruktor
    Enemy(Enemy const & other) = delete;
    ///Move konstruktor
    Enemy(Enemy && other) = delete;
    ///Copy operator
    Enemy& operator=(Enemy const & rhs) & = delete;
    ///Move operator
	Enemy& operator=(Enemy && rhs) = delete;
	///Default destruktor
	~Enemy() = default;
    ///Entity#update() override
    /// Funktion som kallas av world när det här specifika objektet ska uppdatera sig.
    /// Det gör sedan detta genom att t.ex. flytta på sig och kolla kollisioner.
    void update(World&, sf::Time const&) override;
    ///Om det här objektet har dödats så kommer kill att göra det genom att informera World om det.
    void kill(World&) override;
};

#endif
