#pragma once

#include "Entity.h"

/**
 * \brief Platform ärver från Entity och innehåller all information för en entitet av platformstyp.
 *
 * 
 */

class Platform: public Entity{
public:
    ///
    Platform(std::string, std::string, Behaviour*, sf::Vector2f, sf::Texture const&, sf::IntRect);
    ///Entity#update() override
    /// Funktion som kallas av world när det här specifika objektet ska uppdatera sig.
    /// Det gör sedan detta genom att t.ex. flytta på sig och kolla kollisioner.
    void update(World&, sf::Time const&) override;
    ///Om det här objektet har dödats så kommer kill att göra det genom att informera World om det.
    void kill(World& w) override;
};
