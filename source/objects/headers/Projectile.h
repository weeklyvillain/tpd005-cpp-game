#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

/**
 * \brief Projectile ärver från Entity och innehåller all information för en entitet av projektil typ.
 *
 * Projectile ärver från Entity och sparar information om dess Projectile#update() och Projectile#kill().
 * Den innehåller inget speciellt som Entity inte tillhandahåller.
 * 
 */

class Projectile : public Entity{
public:
    ///Projectile Kontruktor som tar in ett namn, en typ,
    /// 2 floats för x och y koordinater, en textur referens och vilken kvadrat i texturen som är relevant
    Projectile(std::string n, std::string t, Behaviour* b, float x, float y, sf::Texture const&, sf::IntRect);
    ///Entity#update() override
    /// Funktion som kallas av world när det här specifika objektet ska uppdatera sig.
    /// Det gör sedan detta genom att t.ex. flytta på sig och kolla kollisioner.
    void update(World&, sf::Time const& t) override;
    ///Om det här objektet har dödats så kommer kill att göra det genom att informera World om det.
    void kill(World& w) override;
};

#endif
